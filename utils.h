
void initOptions(int& _numarPlayeri, int& _numarPachete)
{
	int numarPlayeri;
	int numarPachete;
	do
	{
		std::cout << "Introduceti numarul de playeri (maxim 7 / minim 2): " << std::endl;
		std::cin >> numarPlayeri;
		while (!std::cin) // or if(cin.fail())
		{
			// user didn't input a number
			std::cin.clear(); // reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			// next, request user reinput
			std::cout << "Introduceti numarul de playeri (maxim 7 / minim 2): " << std::endl;
			std::cin >> numarPlayeri;
		}
	} while ((numarPlayeri <= 1) || (numarPlayeri > 7));

	do
	{
		std::cout << "Introduceti numarul de pachete (maxim 8 / minim 1): " << std::endl;
		std::cin >> numarPachete;
		while (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Introduceti numarul de pachete (maxim 8 / minim 1): " << std::endl;
			std::cin >> numarPachete;
		}
	} while ((numarPachete <= 0) || (numarPachete > 8));

	_numarPlayeri = numarPlayeri;
	_numarPachete = numarPachete;
}