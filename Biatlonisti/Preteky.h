#pragma once
#include "Biatlonista.h"
#include <fstream>
#include <string>

using namespace std;

class Preteky
{
private:
	Biatlonista** zoznam = nullptr;
	int pocetSporotvcov = 0;
public:
	Preteky();
	Preteky(char* nazovSuboru);
	int generujTrestnyCas();
	void zorad();
	void vymen(Biatlonista& a, Biatlonista& b);
	void vypis();
	~Preteky();
};

