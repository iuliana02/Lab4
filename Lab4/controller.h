#pragma once
#include "repo.h"
#include <iostream>

struct action
{
	Medikament m;
	int act;
};

class Controller 
{
	friend class UI;
private:
	Repo repo;
	vector <action> istoric_undo;
	vector <action> istoric_redo;

public:
	Controller();
	~Controller();

	bool is_empty();
	bool search(Medikament m);

	void add(Medikament m);
	void remove(Medikament m);
	void modify(Medikament m);

	void show(string s);

	void knappe_menge(int menge);
	
	void sort_nach_preis();

	void undo();
	void redo();

	void undo_remove(Medikament m);
	void undo_add(Medikament m);
	void undo_update(Medikament m);

};
