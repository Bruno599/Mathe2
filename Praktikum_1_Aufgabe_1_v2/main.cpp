#include "CMyVector.h"
//#include "gradient.cpp"

double F(CMyVector test);
double G(CMyVector test);
double(*funktion)(CMyVector);

double(*ptrf)(CMyVector test) = F;
double(*ptrg)(CMyVector test) = G;

void Printvec(CMyVector test)
{
	int j = 0;
	std::cout << " ( ";
	for (int i = 0; i < test.getDimension(); i++, j=i)
	{
		std::cout << test.getValue(i) << "; ";

	}
	std::cout << ")" << std::endl;
}

void Print(int schritt, CMyVector test, double lamda1, double fvonx, CMyVector grad, double laengegrad, CMyVector xneu, double fvonxneu)
{
	std::cout << "Schritt: " << schritt << std::endl;
	std::cout << "x = ";
	Printvec(test);
	std::cout << "lamda = " << lamda1 << std::endl;
	std::cout << " f(x) = " << fvonx << std::endl;
	std::cout << "grad f(x) = ";
	Printvec(grad);
	std::cout << "||grad f(x)|| = " << laengegrad << std::endl << std::endl;
	std::cout << "x_neu = ";
	Printvec(xneu);
	std::cout << "f(x_neu) = " << fvonxneu << std::endl << std::endl;
}

CMyVector gradient(CMyVector test, double(*funktion)(CMyVector test))
{
	std::vector<double> v;
	CMyVector gradient(test.getDimension(), v);
	CMyVector rueckgabe(test.getDimension(), v);
	double h = 1e-8;

	gradient = test;
	double funkvonF = funktion(test);

	for (int index = 0; index < gradient.getDimension(); index++)
	{
		gradient.setValue(gradient.getValue(index) + h, index);	//um die Wackelei zu beginnen 
		rueckgabe.setValue((funktion(gradient) - funkvonF) / h, index);
		gradient.setValue(test.getValue(index), index);			//um die Wackelei wieder aus der dimension zu nehmen
	}
	return rueckgabe;

};

void gradientenverfahren(CMyVector test, double(*funktion)(CMyVector test), double wertfuerlamda = 1.0)
{
	std::vector<double> v;
	CMyVector oldvector(test.getDimension(), v);
	CMyVector newvector(test.getDimension(), v);
	CMyVector gradient1(test.getDimension, v);
	CMyVector testvector(test.getDimension(), v);

	double lamda = wertfuerlamda;

	oldvector = test;

	//gradient1 = gradient(test, funktion);

	for (int schritt = 0; schritt <= 25; schritt++)
	{
		newvector = oldvector + lamda * gradient(oldvector, funktion);
	
		if (newvector.getLength() < 1e-5)
		{
			//newvector.
			break;
		}

		gradient1 = gradient(test, funktion);

		Print(schritt, oldvector, lamda, funktion(oldvector), gradient(oldvector, funktion), newvector.getLength(), newvector, funktion(newvector));

		if (funktion(newvector) > funktion(oldvector))
		{
			testvector = newvector + 2 * lamda * gradient(newvector, funktion);
				if (funktion(testvector) > funktion(newvector))
				{
					lamda = lamda * 2;
					oldvector = testvector;
					std::cout << "Test mit doppelter Schrittweite(lambda = " << lamda << "):" << std::endl;
					std::cout << "x_Test = ";
					Printvec(testvector);
					std::cout << "f(x_test) = " << funktion(testvector) << std::endl;
					std::cout << "verdoppele Schrittweite!" << std::endl;
				}
				else
				{
					lamda = lamda;
					oldvector = newvector;
					std::cout << "Test mit doppelter Schrittweite (lambda = " << lamda << "):" << std::endl;
					std::cout << "x_Test = ";
					Printvec(testvector);
					std::cout << "f(x_test) = " << funktion(testvector) << std::endl;
					std::cout << "behalte alte Schrittweite!" << std::endl;
				}
				
				continue;
		}

		if (funktion(newvector) < funktion(oldvector))
		{
			while (funktion(testvector) < funktion(oldvector))
			{
				lamda = lamda / 2;
				testvector = oldvector + lamda * gradient(oldvector, funktion);
			}
			std::cout << "halbiere Schrittweite (lambda = "  << lamda << "):" << std::endl;
			std::cout << "x_neu = ";
			Printvec(testvector);
			std::cout << "f(x_test) = " << funktion(testvector) << std::endl;
			//std::cout << "behalte alte Schrittweite!" << std::endl;
			oldvector = testvector;
			continue;
		}
	}
}
/*double CMyVector::getLength()
{
	double length = 0;
	for (int i = 0; i < this->dimension; i++)
	{
		length += this->getValue(i)*this->getValue(i);
	}
	
	length = sqrt(length);

	return length;
}
*/
/*
double betragvector(CMyVector test)
{
	double wert = 0.0;
	for 
	test.getValu
	return wert;
}
*/

/*double ableitung(double test2)
{
	double ableitung;

	ableitung = (*funktion(test2 + h) - *funktion(test2)) / h

};
*/

double F(CMyVector test)
{
	return sin(test.getValue(0)*test.getValue(1)) + sin(test.getValue(0)) + cos(test.getValue(1));
}

double G(CMyVector test)
{
	return (-1)*(2 * (test.getValue(0)*test.getValue(0)) - 2 * test.getValue(0)*test.getValue(1)
		+ test.getValue(1)*test.getValue(1) + test.getValue(2)*test.getValue(2) - 2 * test.getValue(0)
		- 4 * test.getValue(2));
}


int main()
{
	std::vector<double> v;

	CMyVector vector1(2, v);
	vector1.setValue(0.200000, 0);
	vector1.setValue(-2.100000, 1);

	CMyVector vector2(3, v);
	vector2.setValue(0.00000, 0);
	vector2.setValue(0.00000, 1);
	vector2.setValue(0.00000, 2);

	gradientenverfahren(vector1, ptrf);
	//gradientenverfahren(vector2, ptrg, 0.1);

	system("PAUSE");

	return 0;
}