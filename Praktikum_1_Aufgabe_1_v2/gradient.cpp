#include "CMyVector.h"

class gradientenverfahren
{

public:
	double F(CMyVector test);
	double G(CMyVector test);
	double(*funktion)(CMyVector);

	

	CMyVector gradient(CMyVector test, double(*funktion)(CMyVector test))
	{
		std::vector<double> v;
		CMyVector gradient(test.getDimension(), v);
		double h = 1e-8;

		gradient = test;
		 
		for (int index = 0; index < gradient.getDimension; index++)
		{
			gradient.setValue(gradient.getValue(index)+h, index);	//um die Wackelei zu beginnen 
			gradient.setValue((funktion(gradient) - funktion(test)) / h, index);
			gradient.setValue(test.getValue(index), index);			//um die Wackelei wieder aus der dimension zu nehmen
		}
		return gradient;

	};

	

	/*double ableitung(double test2)
	{
		double ableitung;

		ableitung = (*funktion(test2 + h) - *funktion(test2)) / h

	};
	*/

	double F(CMyVector test)
	{
		return sin(test.getValue(0)*test.getValue(1))+sin(test.getValue(0))+cos(test.getValue(1));
	}

	double G(CMyVector test)
	{
		return (-1)*(2 * (test.getValue(0)*test.getValue(0)) - 2 * test.getValue(0)*test.getValue(1)
			+ test.getValue(1)*test.getValue(1) + test.getValue(2)*test.getValue(2) - 2 * test.getValue(0)
			- 4 * test.getValue(2));
	}
};