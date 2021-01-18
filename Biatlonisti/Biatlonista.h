#pragma once
#include <iostream>

class Biatlonista
{
private:
	char* priezvisko = nullptr;
	char* meno = nullptr;
	int cas = 0;
public:
	Biatlonista();
	Biatlonista(char* paPriezvisko, char* paMeno, int paCas);
	Biatlonista(const Biatlonista& zdroj);
	Biatlonista& operator = (const Biatlonista& zdroj);
	void vypis();
	inline int getCas() { return this->cas; };
	~Biatlonista();
};

