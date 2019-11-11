
#include <iostream>
#include "Deck.h"

void Deck::FillDeck()
{
	int suita = 1;
	int val = 2;
	for (size_t i = 0; i < 52; i++)
	{
		carti[i].SetAll(suita, val, false);
		suita++;
		if (suita > 4)
		{
			suita = 1;
			val++;
			if (val > 10)
			{
				val = 10;
			}
		}
	}
	suita = 1;
	val = 11;
	for (size_t i = 48; i < 52; i++)
	{
		carti[i].SetAll(suita, val, false);
		suita++;
	}
}

void Deck::ShuffleDeck()
{
	Card temp;
	int randomIndex = 0;

	for (size_t i = 0; i < 52; i++)
	{
		randomIndex = rand() % 52;
		temp = carti[i];
		carti[i] = carti[randomIndex];
		carti[randomIndex] = temp;
	}
}
