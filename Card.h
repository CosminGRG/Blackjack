#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
private:
	int suita;
	int valoare;
	bool stare;

public:
	Card()
	{
		suita = 0;
		valoare = 0;
		stare = false;
	}

	void SetAll(int _suita, int _valoare, bool _stare)
	{
		suita = _suita;
		valoare = _valoare;
		stare = _stare;
	}

	void SetStare(bool _stare)
	{
		stare = _stare;
	}

	int GetValoare()
	{
		return valoare;
	}

	void Display();
};

#endif // !CARD_H