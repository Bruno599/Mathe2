#include <iostream>
#include "CMyVector.h"

using namespace std;

int main()
{
	int dimension = 0;

	cout << "Bitte gebe die Dimension deines Vectors an: ";
	cin >>dimension;

	CMyVector * Vector1 = new CMyVector (dimension);

	CMyVector * Vector2 = new CMyVector(dimension);

	CMyVector * Vector3 = new CMyVector(dimension);
	Vector3 = Vector1 + Vector2;


	Vector1->print();
	Vector1->printdimension();

	//Vector1->set_value_for_dimension(3.3, 1);

	cout << "Laenge deines Vectors beträgt: " << Vector1->laenge_vector() << endl;
	Vector1->print();
	Vector1->printdimension();


	system("PAUSE");
	return 0;
}