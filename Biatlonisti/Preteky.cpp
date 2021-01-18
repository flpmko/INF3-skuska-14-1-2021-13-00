#include "Preteky.h"

Preteky::Preteky()
{
}

Preteky::Preteky(char* nazovSuboru)
{
	if (nazovSuboru != nullptr)
	{
		ifstream input;
		input.open(nazovSuboru);
		if (input.is_open())
		{
			//zistim pocet riadkov aby som vedel aky velky zoznam vytvorit
			int pocetRiadkov = 0;
			string riadok;
			while (getline(input, riadok)) pocetRiadkov++;

			//nastavim kurzor opat na zaciatok suboru
			input.clear();
			input.seekg(0);

			//vytvorim si novy zoznam podla poctu studentov
			pocetSporotvcov = pocetRiadkov;
			zoznam = new Biatlonista * [pocetRiadkov];

			//pomocne premenne na nacitanie zo suboru
			string meno;
			string priezvisko;
			int i = 0;

			//nacitanie zo suboru a naplnenie zoznamu studentami
			while (!input.eof())
			{
				input >> priezvisko >> meno;
				//random generovanie casov
				int randCas = rand() % 21 + 60;
				randCas += generujTrestnyCas();
				zoznam[i] = new Biatlonista((char*)meno.c_str(), (char*)priezvisko.c_str(), randCas);
				i++;
			}
		}
		input.close();
	}
}

int Preteky::generujTrestnyCas()
{
	short trafene = rand() % 9 + 2;
	int trestnyCas = 0;
	switch (trafene)
	{
	case 2:
		trestnyCas = 8 * 12;
		break;
	case 3:
		trestnyCas = 7 * 12;
		break;
	case 4:
		trestnyCas = 6 * 12;
		break;
	case 5:
		trestnyCas = 5 * 12;
		break;
	case 6:
		trestnyCas = 4 * 12;
		break;
	case 7:
		trestnyCas = 3 * 12;
		break;
	case 8:
		trestnyCas = 2 * 12;
		break;
	case 9:
		trestnyCas = 1 * 12;
		break;
	default:
		break;
	}
	return trestnyCas;
}

void Preteky::zorad()
{
	for (int i = 0; i < pocetSporotvcov - 1; i++)
	{
		for (int j = 0; j < pocetSporotvcov - i - 1; j++)
		{
			//zoradenie vzostupne
			if (this->zoznam[j]->getCas() > this->zoznam[j + 1]->getCas())
			{
				vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
		}
	}
}

void Preteky::vymen(Biatlonista& a, Biatlonista& b)
{
	Biatlonista c = a;
	a = b;
	b = c;
}

void Preteky::vypis()
{
	for (int i = 0; i < this->pocetSporotvcov; i++)
	{
		this->zoznam[i]->vypis();
	}
}

Preteky::~Preteky()
{
	for (int i = 0; i < this->pocetSporotvcov; i++)
	{
		delete this->zoznam[i];
	}
	delete[] this->zoznam;
}
