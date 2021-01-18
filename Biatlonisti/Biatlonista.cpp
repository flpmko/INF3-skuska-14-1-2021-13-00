#include "Biatlonista.h"

Biatlonista::Biatlonista()
{
}

Biatlonista::Biatlonista(char* paPriezvisko, char* paMeno, int paCas)
{
	if (paPriezvisko && *paPriezvisko && paMeno && *paMeno)
	{
		priezvisko = new char[strlen(paPriezvisko) + 1];
		strcpy(priezvisko, paPriezvisko);

		meno = new char[strlen(paMeno) + 1];
		strcpy(meno, paMeno);

		cas = paCas;
	}
}

Biatlonista::Biatlonista(const Biatlonista& zdroj)
{
	if (this != &zdroj)
	{
		priezvisko = new char[strlen(zdroj.priezvisko) + 1];
		strcpy(priezvisko, zdroj.priezvisko);

		meno = new char[strlen(zdroj.meno) + 1];
		strcpy(meno, zdroj.meno);

		cas = zdroj.cas;
	}
}

Biatlonista& Biatlonista::operator=(const Biatlonista& zdroj)
{
	if (this != &zdroj)
	{
		Biatlonista::~Biatlonista();

		priezvisko = new char[strlen(zdroj.priezvisko) + 1];
		strcpy(priezvisko, zdroj.priezvisko);

		meno = new char[strlen(zdroj.meno) + 1];
		strcpy(meno, zdroj.meno);

		cas = zdroj.cas;
	}
	return *this;
}

void Biatlonista::vypis()
{
	printf("%s %s %d:%02d\n", this->priezvisko, this->meno, this->cas / 60, this->cas % 60);
}

Biatlonista::~Biatlonista()
{
	delete[] this->priezvisko;
	delete[] this->meno;
	this->cas = 0;
}
