
#include "GameManager.h"
#include <Windows.h>

void GameManager::initPlayers()
{
	std::string nume;
	for (size_t i = 0; i < numarPlayeri; i++)
	{
		std::cout << "Introduceti numele player-ului " << i + 1 << std::endl;
		std::cin >> nume;
		std::cin.ignore();
		Playeri[i].SetAll(nume, 0);
	}
}

void GameManager::AfiseazaDecks()
{
	for (size_t i = 0; i < numarPachete; i++)
	{
		for (size_t j = 0; j < 52; j++)
		{
			//std::cout << j << std::endl;
			Pachete[i].carti[j].Display();
		}
	}
}

void GameManager::Menu()
{
	std::cout << std::endl;
	std::cout << "1. Incepe jocul" << std::endl;
	std::cout << "2. Schimba optiunile" << std::endl;
	std::cout << "3. Afiseaza cartile" << std::endl;
	std::cout << "4. Inchide joc" << std::endl;
	std::cout << std::endl;
}

void GameManager::PlayerOptions(int index)
{
	std::cout << "RANDUL LUI " << Playeri[index].GetName() << " -> " << Playeri[index].GetSuma() << std::endl;
	std::cout << "1. Hit" << std::endl;
	std::cout << "2. Stand" << std::endl;
	std::cout << "3. Abandon Game" << std::endl;
}

void GameManager::initGame()
{
	std::cout << "DEALER-UL TRAGE CARTE PE 16 SI STA PE 17" << std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	int sum = 0;
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < numarPlayeri; j++)
		{
			if (currentCard == 51)
			{
				currentDeck++;
			}
			if (currentDeck >= numarPachete)
			{
				AfiseazaDecks();
				std::cout << "S-au terminat cartile. Adauga alte pachete din optiuni.";
				handWon = true;
				break;
			}
			sum = Playeri[j].GetSuma();
			sum += Pachete[currentDeck].carti[currentCard].GetValoare();
			Playeri[j].SetSuma(sum);
			Playeri[j].Display();
			Pachete[currentDeck].carti[currentCard].SetStare(true);
			currentCard++;

			if (sum == 21)
			{
				std::cout << Playeri[j].GetName() << " " << "BLACKJACK!" << std::endl;
				std::cout << std::endl;
				Playeri[j].SetSkip(true);
			}

			sum = 0;

			Sleep(1000);	
		}

		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << std::endl;

		if (currentDeck > numarPachete)
		{
			handWon = true;
			break;
		}
	}
	sum = Crupier->GetSuma();
	sum += Pachete[currentDeck].carti[currentCard].GetValoare();
	Crupier->SetSuma(sum);
	Crupier->Display();
	Pachete[currentDeck].carti[currentCard].SetStare(true);
	currentCard++;
}

void GameManager::DrawCard(int index)
{
	if (currentCard >= 51)
	{
		currentDeck++;
	}
	if (currentDeck > numarPachete)
	{
		handWon = true;
	}
	else
	{
		int sum = 0;
		sum = Playeri[index].GetSuma();
		sum += Pachete[currentDeck].carti[currentCard].GetValoare();
		Playeri[index].SetSuma(sum);
		Pachete[currentDeck].carti[currentCard].SetStare(true);
		currentCard++;
		Playeri[index].Display();
	}
}

void GameManager::Play()
{
	int choose;
	handWon = false;
	while (!handWon)
	{
		initGame();

		for (size_t i = 0; i < numarPlayeri; i++)
		{
			if (Playeri[i].GetSkip() == false)
			{
				PlayerOptions(i);
				do
				{
					std::cin >> choose;

					if (choose == 1)
					{
						DrawCard(i);
					}
					else if (choose == 2)
					{
						break;
					}
					else if (choose == 3)
					{
						handWon = true;
						break;
					}

				} while ((Playeri[i].GetSuma() < 21));
			}
		}
		DealerAct();

		CheckWinner();

		Reset();
	}
}

void GameManager::CheckWinner()
{
	int sum = 0;

	for (size_t i = 0; i < numarPlayeri; i++)
	{
		sum = Playeri[i].GetSuma();
		if (sum > 21)
		{
			std::cout << Playeri[i].GetName() << " -> " << sum << " BUST!" << std::endl;
		}
		else if (((sum <= 21) && (Crupier->GetSuma() > 21)) || ((sum <= 21) && (sum > Crupier->GetSuma())))
		{
			std::cout << Playeri[i].GetName() << " -> " << sum << " WINNER!" << std::endl;
		}
		else if (sum == Crupier->GetSuma())
		{
			std::cout << Playeri[i].GetName() << " -> " << sum << " PUSH!" << std::endl;
		}
		else if ((sum < Crupier->GetSuma()) && (sum < 21) && (Crupier->GetSuma() <= 21))
		{
			std::cout << Playeri[i].GetName() << " -> " << sum << " LOST!" << std::endl;
		}
		std::cout << std::endl;
	}
}

void GameManager::Reset()
{
	for (size_t i = 0; i < numarPlayeri; i++)
	{
		Playeri[i].SetSuma(0);
		Playeri[i].SetSkip(false);
	}
	Crupier->SetSuma(0);
}

void GameManager::DealerAct()
{
	int sum;

	sum = Crupier->GetSuma();
	sum += Pachete[currentDeck].carti[currentCard].GetValoare();
	Crupier->SetSuma(sum);
	Crupier->Display();
	Pachete[currentDeck].carti[currentCard].SetStare(true);
	currentCard++;

	while (Crupier->GetSuma() < 17)
	{
		if (currentCard == 51)
		{
			currentDeck++;
		}
		if (currentDeck >= numarPachete)
		{
			AfiseazaDecks();
			std::cout << "S-au terminat cartile. Adauga alte pachete din optiuni.";
			handWon = true;
			break;
		}

		std::cout << "Dealer-ul trage carte!" << std::endl;
		sum = Crupier->GetSuma();
		sum += Pachete[currentDeck].carti[currentCard].GetValoare();
		Crupier->SetSuma(sum);
		Crupier->Display();
		Pachete[currentDeck].carti[currentCard].SetStare(true);
		currentCard++;
	}
	if (Crupier->GetSuma() == 21)
	{
		std::cout << "BLACKJACK LA DEALER!" << std::endl;
	}
}