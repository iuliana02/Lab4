#include "UI.h"
#include <iostream>
#include <fstream>
using namespace std;

UI::UI()
{
}
UI::~UI()
{
}

void UI:: meniu()
{
	cout << "\n\tSmile Apotheke\n";
	cout << "1 - Medikament einfugen\n" << "2 - Medikament loschen\n" << "3 - Medikament bearbeiten\n";
	cout << "4 - Gruppieren nach einem String\n";
	cout << "5 - Medikamente knapper als...\n";
	cout << "6 - Gruppieren nach Preis\n";
	cout << "7 - Undo\n";
	cout << "8 - Redo\n";
	cout << "0 - Exit"<<endl;

}

void UI::functii()
{
	Controller ctrl = Controller();
	while (true)
	{
		meniu();

		int optiune;
		cout << "Alegeti optiunea: \n";
		cin >> optiune;
		switch (optiune)
		{
		case 1:
		{
			string name;
			int menge;
			float konzentration, preis;
			cout << "Adaugati medicament\n" << "Nume: ";
			cin >> name;
			cout<< "Cantitate: ";
			cin >> menge;
			cout << "Concentratie: ";
			cin >> konzentration;
			cout << " Pret: ";
			cin >> preis;
			Medikament m = Medikament(name, konzentration, menge, preis);
			ctrl.add(m);
			break;
		}
		case 2:
		{
			string name;
			int menge = 0;
			float konzentration, preis = 0;
			cout << "Medicamentul pentru sters\n " << " Nume: ";
			cin >> name;
			cout << "Concentratie: ";
			cin >> konzentration;
			Medikament m= Medikament(name, konzentration, menge, preis);
			ctrl.remove(m);
			break;
		}
		case 3:
		{
			string name;
			int menge = 0;
			float konzentration, preis = 0;
			cout << "Schimbati medicamentul\n " << " Nume: ";
			cin >> name;
			cout << "Concentratie: ";
			cin >> konzentration;
			Medikament m = Medikament(name, konzentration, menge, preis);
			ctrl.modify(m);
			break;
		}
		case 4:
		{
			string s;
			cout << "Introduceti medicamentul pe care il cautati: \n";
			cout << "Primele litere din numele medicamentului: \n";
			getline(cin, s);
			getline(cin, s);
			if (s == "") //daca am string gol, afisez toate medicamentele
			{
				cout << "The string is empty!/n";
				ctrl.name_sort();
				break;
			}
			else
			{
				ctrl.show(s);
				break;
			}
		}
		case 5:
		{
			cout << "Ïntroduceti cantitate: ";
			int menge;
			cin >> menge;
			ctrl.knappe_menge(menge);
			break;
		}
		case 6:
		{
			ctrl.sort_nach_preis();
			break;
		}
		case 7:
		{
			ctrl.undo();
			cout << "Operatia de undo a reusit. " << endl;
			break;
		}
		case 8:
		{
			ctrl.redo();
			cout << "Operatia de redo a reusit." << endl;
			break;
		}
		case 0:
			return;
		}
	}

}


