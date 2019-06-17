#include "CLotto.h"

void CLotto::setTipp()
{

	int counter = 1;
	while (counter < 7)
	{
		int n = 0;
		std::cout << "Bitte geben Sie den " << counter << ". Tipp ihres Stimmzettels ein: ";
		std::cin >> n;

		if (n < 0 || n > 49)
		{
			continue;
		}
		else
		{
			counter++;
		}

	}
}