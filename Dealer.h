
#ifndef DEALER_H
#define DEALER_H

class Dealer
{
private:
	int suma;
public:
	Dealer()
	{
		suma = 0;
	}

	void SetSuma(int _suma)
	{
		suma = _suma;
	}

	int GetSuma()
	{
		return suma;
	}

	void Display()
	{
		std::cout << "> DEALER-UL ARE " << suma << " < " << std::endl;
		std::cout << std::endl;
	}
};

#endif // !DEALER_H
