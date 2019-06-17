#include "CZufall.h"
#include "CLotto.h"
#include <iostream>

using namespace std;

int main()
{
	/*CZufall test1;
		
	test1.initialisiere(10);

	vector<int> test2 = test1.test_falsch(3, 7, 10000);

	for (int i = 0; i < test2.size(); i++)
	{
		cout << i + 3 << "____" << test2.at(i) << endl;
	}
	*/

	CLotto test1(10);
	vector<int> test2 = test1.sechsAus49();

		for (int i = 0; i < test2.size(); i++)
		{
			cout << i + 3 << "____" << test2.at(i) << endl;
		}

	

	system("PAUSE");

	return 0;
}