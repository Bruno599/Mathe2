#include "C_DGLSolver.h"
#include "CMyVektor.h"
#include <iostream>


CMyVektor F(CMyVektor y, double x)
{
	CMyVektor V2(2);

	V2.set_wert(0,(2 * y.get_wert(1)) - (x * y.get_wert(0)));
	V2.set_wert(1,(y.get_wert(0) * y.get_wert(1)) - (2 * pow(x, 3)));
	

	return V2;

}

double G(CMyVektor y, double x)
{
	double result;

	result =(2 * x*y.get_wert(1)*y.get_wert(2)) + (2 * pow(y.get_wert(0), 2)*y.get_wert(1));

	return result;

}

int main()
{
	double XENDE = 2;
	int schritte = 100;

	CMyVektor V1(2);

	V1.set_wert(0, 0);
	V1.set_wert(1, 1);

	CMyVektor V2(3);

	V2.set_wert(0, 1);
	V2.set_wert(1, (-1));
	V2.set_wert(2, 2);


	C_DGLSolver Solve(G);

	//Solve.C_DGLSolver_Euler(0, 2, 100, V1);

	//Solve.C_DGLSolver_Euler(1, 2, 10, V2);

	//Solve.C_DGLSolver_Heun(0, 2, 100, V1);

	//Solve.C_DGLSolver_Heun(1, 2, 100, V2);

	system("PAUSE");

	return 0;
}