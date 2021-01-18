#include "Biatlonista.h"
#include "Preteky.h"
#include <time.h>

#define _CRT_SECURE_NO_DEPRECATE

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //na kontrolu memory leakov
	srand(time(NULL)); //inicializacia random generatora

	char input[100];
	scanf("%s", input);

	Preteky grandprix((char*)input);
	grandprix.zorad();
	grandprix.vypis();

	return 0;
}