
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class GameManager 
{
private:
	Deck* Pachete;
	Player* Playeri;
	Dealer* Crupier;
	int numarPlayeri;
	int numarPachete;
	int currentDeck;
	int currentCard;
	bool handWon;

public:

	GameManager(int _numarPlayeri, int _numarPachete)
	{
		numarPlayeri = _numarPlayeri;
		numarPachete = _numarPachete;
		currentCard = 0;
		currentDeck = 0;
		handWon = false;

		Playeri = new Player[_numarPlayeri];
		Pachete = new Deck[_numarPachete];
		Crupier = new Dealer;

		initPlayers();
	}

	~GameManager()
	{
		delete[]Playeri;
		delete Crupier;
		for (size_t i = 0; i < numarPachete; i++)
		{
			Pachete[i].~Deck();
		}
		//delete[]Pachete;
	}

	void initPlayers();
	void initGame();
	void AfiseazaDecks();
	void Menu();
	void Play();
	void Reset();
	void PlayerOptions(int index);
	void DrawCard(int index);
	void CheckWinner();
	void DealerAct();
};

#endif // !GAMEMANAGER_H
