#pragma once
#include <string>
#include <vector>
#include "medikament.h"
using namespace std;

class Repo
{
	friend class Controller;

private:
	Medikament* med;
	int capacity, len;

public:

	Repo();
	~Repo();

	void show();
};