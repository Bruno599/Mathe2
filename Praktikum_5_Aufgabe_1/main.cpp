#include "CZufall.h"
#include "CLotto.h"
#include <iostream>

using namespace std;

double monti_tipp(int wiederholungen);
double monti_Lotto(int wiederholungen);
int main()
{
	/*CZufall test1;
		
	test1.initialisiere(10);

	vector<int> test2 = test1.test_falsch(3, 7, 10000);

	for (int i = 0; i < test2.size(); i++)
	{
		cout << i + 3 << "____" << test2.at(i) << endl;
	}
	

	CLotto test1(-1);
	vector<int> test2 = test1.sixOutOfFortynine();

		for (int i = 0; i < test2.size(); i++)
		{
			cout << i + 3 << "____" << test2.at(i) << endl;
		}
		
		CLotto test3(-1);

		test3.setTipp();

		vector<int> test4 = test3.pruefe_tipp();

		for (int i = 0; i < test4.size(); i++)
		{
			cout << i + 1 << "____" << test4.at(i) << endl;
		}

		cout << endl << "Anzahl der Übereinstimmungen: " << test4.size() << endl;
		
		CLotto test5(-1);
		
		//test3.setTipp();

		vector<int> test6 = test5.pruefe_2malLotto();

		for (int i = 0; i < test6.size(); i++)
		{
			cout << i + 1 << "____" << test6.at(i) << endl;
		}

		cout << endl << "Anzahl der Übereinstimmungen: " << test6.size() << endl;
	*/

		double ausgabe1 = monti_tipp(100000);
		 

		cout << "Die wahrscheinlickeit von genau 3 richtigen bei einer Wiederholung von 100000 mal \n und einem vorher festgelegten Tippzettel beträgt: " << ausgabe1 << endl;

		double ausgabe2 = monti_tipp(10000000);

		cout << "Die wahrscheinlickeit von genau 3 richtigen bei einer Wiederholung von 10000000 mal \n und einem vorher festgelegten Tippzettel beträgt: " << ausgabe2 << endl;

		cout << endl << endl;

		double ausgabe3 = monti_Lotto(100000);

		cout << "Die wahrscheinlickeit von genau 3 richtigen bei einer Wiederholung von 100000 mal \n und 2 Ziehungen beträgt: " << ausgabe3 << endl;

		double ausgabe4 = monti_Lotto(10000000);

		cout << "Die wahrscheinlickeit von genau 3 richtigen bei einer Wiederholung von 10000000 mal \n und 2 Ziehungen beträgt: " << ausgabe4 << endl;

	system("PAUSE");

	return 0;
}

double monti_tipp(int wiederholungen)
{
	double wahrscheinlichkeit = 0.0;
	CLotto Lotto(-1);

	//Lotto.setTipp();

	//test
	
	Lotto.setTipp_manual(13, 24, 34, 6, 15, 3);

	int counter= 0;

	for (int i = 1; i <= wiederholungen; i++)
	{
		int temp = Lotto.pruefe_tipp();

		if (temp == 3)
		{
			counter++;
		}
	}

	wahrscheinlichkeit = (counter / (double)wiederholungen )* 100;

	return wahrscheinlichkeit;
}

double monti_Lotto(int wiederholungen)
{
	double wahrscheinlichkeit = 0.0;
	CLotto Lotto(-1);

	//Lotto.setTipp();

	//test

	Lotto.setTipp_manual(13, 24, 34, 6, 15, 3);

	int counter = 0;

	for (int i = 1; i <= wiederholungen; i++)
	{
		int temp = Lotto.pruefe_2malLotto();

		if (temp == 3)
		{
			counter++;
		}
	}

	wahrscheinlichkeit = (counter / (double)wiederholungen) * 100;

	return wahrscheinlichkeit;
}