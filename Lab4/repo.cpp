#include "repo.h"
#include "medikament.h"
#include <iostream>
#include <algorithm>
using namespace std;

Repo::Repo()
{
	this->capacity = 100;
	this->len = 0;
	this->med = new Medikament[capacity];
}


void Repo::show()
{
	for (int i = 0; i < this->len; ++i)
	{
		cout << med[i].get_name() << " " << med[i].get_konz() << " " << med[i].get_menge() << " " << med[i].get_preis() << "\n";
	}
}

Repo::~Repo()
{
}