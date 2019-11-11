
#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
public:
	Card* carti;

public:
	Deck()
	{
		carti = new Card[52];
		FillDeck();
		ShuffleDeck();
	}

	~Deck()
	{
		delete[]carti;
	}

	void FillDeck();
	void ShuffleDeck();
};

#endif // !DECK_H
