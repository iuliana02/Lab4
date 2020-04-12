#pragma once
#include <string>
#include <iostream>
using namespace std;

class Medikament
{
private:
	string name;
	double konzentration;
	int menge;
	double preis;

public:
	Medikament();
	Medikament(string name, double konzentration, int menge, double preis);
	
	string get_name() ;
	double get_konz() ;
	int get_menge() ;
	double get_preis() ;
	void set_name (string name);
	void set_konz(double k);
	void set_menge(int menge);
	void set_preis (double preis);

	void add_menge(int m);
	void remove_menge(int m);

	void afisare();

	~Medikament();

	Medikament& operator +=(int menge);
	Medikament& operator -=(int menge);

};