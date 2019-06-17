#include "CZufall.h"


void CZufall::initialisiere(int n)
{
	srand(n);
}

//void CZufall::srand(int n)
//{


//}

int CZufall::wert(int a, int b)
{
	int result;

	result = (rand() % (b - a + 1)) + a;

	/*while (result < a && result > b)
	{
		result = rand() % n;
	}
	*/

	return result;
}

std::vector<int> CZufall::test(int a, int b, int N)
{
	std::vector<int> result(b - a + 1 , 0);

	//initialisiere(time(NULL));

	for (int n = 0; n < N; n++)
	{
		result.at(wert(a, b)-a)++;
	}
	return result;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N)
{
	std::vector<int> result(b - a + 1, 0);

	for (int n = 0; n < N; n++)
	{
		initialisiere(time(NULL));
		result.at(wert(a, b)-a)++;
	}
	return result;
}