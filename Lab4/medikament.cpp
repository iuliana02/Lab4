#include <string>
#include <iostream>
#include "medikament.h"
using namespace std;

//constructor
Medikament::Medikament(string name, double konzentration, int menge, double preis)
{
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->preis = preis;
}
Medikament::Medikament()
{

}

//gettere
string Medikament::get_name() 
{
	return this->name;
}
double Medikament::get_konz() 
{
	return this->konzentration;
}
int Medikament::get_menge() 
{
	return this->menge;
}
double Medikament::get_preis() 
{
	return this->preis;
}
//settere
void Medikament::set_name(string name) 
{
	this->name=name;
}
void Medikament::set_konz (double k) 
{
	this->konzentration=k;
}
void Medikament::set_menge(int menge) 
{
	this->menge=menge;
}
void Medikament::set_preis (double preis) 
{
	this->preis=preis;
}

void Medikament::add_menge(int m)
{
	this->menge += m;
}
void Medikament::remove_menge(int m)
{
	this->menge -= m;
}

void Medikament::afisare()
{
	cout << "Name: " << name << "Konzentration: " << konzentration << "Menge: " << menge << "Preis: " << preis << '\n';
}

Medikament::~Medikament()
{
}