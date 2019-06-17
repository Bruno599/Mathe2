#include <stdlib.h>
#include <vector>
#include <time.h>


class CZufall
{
private:
	//int n;

public:
	CZufall(){};
	void initialisiere(int n); 
	//void srand(int n);

	int wert(int a, int b);

	std::vector<int> test(int a, int b, int N);
	std::vector<int> test_falsch(int a, int b, int N);

};