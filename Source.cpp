
#include <iostream>
#include <time.h>
#include "GameManager.h"
#include "utils.h"

int main()
{
	srand(time(NULL));

	int numarPlayeri = 2;
	int numarPachete = 2;

	initOptions(numarPlayeri, numarPachete);

	GameManager* Joc;
	Joc = new GameManager(numarPlayeri, numarPachete);

	int opt;

	do
	{
		Joc->Menu();
		std::cin >> opt;

		while (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Bad input. " << std::endl << std::endl;
			Joc->Menu();
			std::cin >> opt;
		}

		switch (opt)
		{
		case 1:
			Joc->Play();
			break;
		case 2:
			Joc->~GameManager();
			initOptions(numarPlayeri, numarPachete);
			Joc = new GameManager(numarPlayeri, numarPachete);
			break;
		case 3:
			Joc->AfiseazaDecks();
			break;
		default:
			break;
		}
	} while (opt != 5);

	Joc->~GameManager();
}