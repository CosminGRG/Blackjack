
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player
{
private:
	std::string nume;
	int suma;
	bool skip;

public:
	Player() 
	{ 
		nume = " ";
		suma = 0;
		skip = false;
	}

	Player(std::string _nume, int _suma, bool _skip)
	{
		nume = _nume;
		suma = _suma;
		skip = _skip;
	}

	void SetSuma(int _suma)
	{
		suma = _suma;
	}

	void SetSkip(bool _skip)
	{
		skip = _skip;
	}

	int GetSuma()
	{
		return suma;
	}

	std::string GetName()
	{
		return nume;
	}

	bool GetSkip()
	{
		return skip;
	}

	void SetAll(std::string _nume, int _suma)
	{
		nume = _nume;
		suma = _suma;
	}

	void Display();
};

#endif // !PLAYER_H
