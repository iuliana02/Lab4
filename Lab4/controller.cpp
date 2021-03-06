#include <iostream>
#include <fstream>
#include <string>
#include "controller.h"
#include <algorithm>
using namespace std;

Controller::Controller() 
{
	repo = Repo();
}

bool Controller::is_empty()
{
	if (repo.len == 0)
		return true;
	return false;
}

bool Controller::search(Medikament m)
{
	if (is_empty())
	{
		return false;
	}
	for (int i = 0; i < repo.len; ++i)
	{
		//Caut dupa nume si concentratie
		if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
			return true;
	}
	return false;
}

void Controller::add(Medikament m)
{
	if (search(m) == false)
	{
		repo.med[repo.len] = m; //daca medicamentul nu exista, il adaug pe ultima pozitie
		repo.len++;
		if (repo.len == repo.capacity) 
		{
			//resize
			repo.capacity *= 2;
			Medikament* n = new Medikament[repo.capacity];
			for (int i = 0; i < repo.len; ++i)
				n[i] = repo.med[i];
			delete repo.med;
			repo.med = n;
		}
	}
	else //daca medicamentul exista deja, cresc doar cantitatea
	{
		for (int i = 0; i < repo.len; ++i)
		{
			if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
				repo.med[i].set_menge(repo.med[i].get_menge() + m.get_menge());
		}
	}
	//cout << repo.len << endl;
	action a;
	a.act = 1;
	a.m = m;
	istoric_undo.push_back(a);
}

void Controller::undo_add(Medikament m)
{
	if (search(m) == false)
	{
		repo.med[repo.len] = m;
		repo.len++;
		if (repo.len == repo.capacity) //container full
		{
			repo.capacity *= 2;
			Medikament* n = new Medikament[repo.capacity];
			for (int i = 0; i < repo.len; ++i)
				n[i] = repo.med[i];
			delete repo.med;
			repo.med = n;
		}
	}
	else
	{
		for (int i = 0; i < repo.len; ++i)
			if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
				repo.med[i].set_menge(repo.med[i].get_menge() + m.get_menge());
	}
	action a;
	a.act = 1;
	a.m = m;
	istoric_redo.push_back(a);
}

void Controller::remove(Medikament m)
{
	if (is_empty())
	{
		cout << "Apotheke leer\n";
		return;
	}
	if (search(m) == false)
	{
		cout << "Dieser Medikament existiert nicht.\n";
		return;
	}
	Medikament n;
	for (int i = 0; i < repo.len; ++i)
	{
		if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
		{
			m = repo.med[i];
			for (int k = i + 1; k <= repo.len; ++k)
				repo.med[k - 1] = repo.med[k];
			repo.len--;
			cout << "Medikament geloschen!\n";
		}
	}
	action a;
	a.act = 3;
	a.m = n;
	istoric_undo.push_back(a);
}

void Controller::undo_remove(Medikament m)
{
	if (is_empty())
	{
		cout << "Apotheke leer\n";
		return;
	}
	if (search(m) == false)
	{
		cout << "Dieser Medikament existiert nicht\n";
		return;
	}
	for (int i = 0; i < repo.len; ++i)
	{
		if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
		{
			for (int k = i + 1; k < repo.len; k++)
				repo.med[k - 1] = repo.med[k];
			repo.len--;
		}
	}
	action a;
	a.act = 3;
	a.m = m;
	istoric_redo.push_back(a);
}

void Controller::modify(Medikament m)
{
	Medikament mm;
	if (search(m) == false)
	{
		cout << "Der Medikament existiert nicht!\n";
		//add(m);
	}
	else
	{
		for (int i = 0; i < repo.len; ++i)
		{
			if ((m.get_konz() == repo.med[i].get_konz()) and (m.get_name() == repo.med[i].get_name()))
			{
				mm = repo.med[i];
				std::string w;

				//update pretului
				std::cout << "Aktueller Preis des Medikament ist " << repo.med[i].get_preis() << "\n M�chten Sie es aktualisieren? (y/n)";
				std::cin >> w;
				if (w == "y")
				{
					float x;
					std::cout << "Der neue Preis ist ";
					std::cin >> x;
					repo.med[i].set_preis(x);
				}

				//update cantitatii
				std::cout << "Aktuelle Menge des Arzneimittels ist " << repo.med[i].get_menge() << "\n M�chten Sie es aktualisieren? (y/n)";
				std::cin >> w;
				if (w == "y")
				{
					int x;
					std::cout << "Die neue Menge ist ";
					std::cin >> x;
					repo.med[i].set_menge(x);
				}
			}
		}
	}
	action a;
	a.act = 2;
	a.m = mm;
	istoric_undo.push_back(a);
}



bool Controller::update(Medikament m, int menge, double preis)
{
	Medikament mm;
	if (search(m) == false)
	{
		cout << "Der Medikament existiert nicht!\n";
		//add(m);
	}
	else
	{
		for (int i = 0; i < repo.len; ++i)
		{
			if ((m.get_konz() == repo.med[i].get_konz()) and (m.get_name() == repo.med[i].get_name()))
			{
				mm = repo.med[i];
				repo.med[i].set_menge(menge);
				repo.med[i].set_preis(preis);
				return true;
			}
		}
	}
	return false;
}

void Controller::undo_update(Medikament m)
{
	for (int i = 0; i < repo.len; ++i)
	{
		if ((m.get_konz() == repo.med[i].get_konz()) and (m.get_name() == repo.med[i].get_name()))
		{
			repo.med[i].set_preis(m.get_preis());
			repo.med[i].set_menge(m.get_menge());
		}
	}
	action a;
	a.act = 3;
	a.m = m;
	istoric_redo.push_back(a);
}

//punctul 2: afisarea medicamentelor care incep cu niste litere anume
void Controller::show(std::string s)
{
	if (s.length() == 0)
	{
		repo.show();
	}
	else
	{
		Repo r;
		for (int i = 0; i < repo.len; ++i)
		{
			if (repo.med[i].get_name().find(s)==0)
			{
				repo.med[i].afisare();
			}
		}
		r.show();
	}
}

//zeigt die Medikamente mit einer kleineren Menge als eine gegebene
void Controller::knappe_menge(int menge)
{
	if (is_empty() == true)
	{
		std::cout << "Es existiert nicht!\n";
	}
	else
	{
		for (int i = 0; i < repo.len; i++)
		{
			if (repo.med[i].get_menge() < menge)
				repo.med[i].afisare();
		}
	}
}

//sorteaza dupa pret
void Controller::sort_nach_preis()
{
	auto relation = [](Medikament a, Medikament b) { return a.get_preis() < b.get_preis(); };
	sort(repo.med, repo.med + repo.len, relation); //sorteaza elementele de la inceput si pana la sfarsit dupa relatia data

	for (int i = 0; i < repo.len; i++)
		repo.med[i].afisare();
}

//undo ultima operatie
void Controller::undo()
{
	if (istoric_undo.size() != 0)
	{
		action med = istoric_undo.at(istoric_undo.size() - 1); //ultima operatie pt undo din vectorul istoric_undo
		if (med.act == 1)
		{
			undo_remove(med.m);
		}
		else if (med.act == 2)
		{
			undo_update(med.m);
		}
		else
		{
			undo_add(med.m);
		}
		istoric_undo.pop_back();
		return;
	}
	else
		std::cout << " Undo ist nicht m�glich! " << endl;
}

//redo ultima operatie
void Controller::redo()
{
	if (istoric_redo.size() != 0)
	{
		action med = istoric_redo.at(istoric_redo.size() - 1);
		if (med.act == 1)
		{
			remove(med.m);
		}
		else if (med.act == 2)
		{
			modify(med.m);
		}
		else
		{
			add(med.m);
		}
		istoric_redo.pop_back();
		return;
	}
	else
		std::cout << " Redo ist nicht m�glich! " << endl;
}

void Controller::name_sort()
{
	auto relation = [](Medikament a, Medikament b) {return a.get_name() < b.get_name();  };
	sort(repo.med, repo.med + repo.len, relation);

	for (int i = 0; i < repo.len; i++)
		repo.med[i].afisare();
}


Controller::~Controller()
{
//	delete repo.med;
}