#pragma once
#include "CMyVektor.h"
#include <iostream>
#include <iomanip>

class C_DGLSolver {

private:

	CMyVektor(*f_DGL_System)(CMyVektor y, double x);
	double(*F_DGL_nterOrdnung)(CMyVektor y, double x);
	bool dgl_first_order;

	CMyVektor derivation(CMyVektor y, double x)
	{
		CMyVektor V1(y.get_dimension());

		if (dgl_first_order)
		{
			V1 = f_DGL_System(y, x);
		}
		else
		{
			for (int i = 0; i < y.get_dimension() - 1; i++)
			{
				V1.set_wert(i,y.get_wert(i+1));
			}
			
			V1.set_wert(y.get_dimension() - 1, F_DGL_nterOrdnung(y, x));

			/*for (int i = 1; i < y.getDimension(); i++)         
			{             
			result[i - 1] = y[i];         
			}          
			
			result[y.getDimension() - 1] = dglNOrder(y, x);*/
		}

		return V1;
	}

public:

	C_DGLSolver(CMyVektor(*funktion)(CMyVektor y, double x)) { this->f_DGL_System = funktion; this->dgl_first_order = true; };
	C_DGLSolver(double(*funktion)(CMyVektor y, double x)) { this->F_DGL_nterOrdnung = funktion;  this->dgl_first_order = false; };

	void C_DGLSolver_Euler(double Xstart, double Xend, int steps, CMyVektor y_start)
	{
		double h = (Xend - Xstart) / steps;

		std::cout << "h = " << h << std::endl << std::endl;

		double x = 0;
		CMyVektor y = y_start;
		CMyVektor y_strich = y_start;

		for (int i = 0; i < steps; i++)
		{

			std::cout << "Schritt " << i << ":" << std::endl;

			x = Xstart + (i*h);

			std::cout << "\t x = " << x << std::endl;

			std::cout << std::setprecision(8) << "\t y = " << y.toString() << std::endl; //"\t y = ( " << y.get_wert(0) << "; " << y.get_wert(1) << ")" << std::endl;

			y_strich = derivation(y, x);

			std::cout << std::setprecision(8) << "\t y' = " << y_strich.toString() << std::endl; //"\t y' = ( " << y_strich.get_wert(0) << "; " << y_strich.get_wert(1) << ")" << std::endl;

			y = y + (h * derivation(y, x));
			
		};

		std::cout << "Ende bei " << std::endl;

		std::cout << "\t x = " << x + h << std::endl;

		std::cout << std::setprecision(8) << "\t y = " << y.toString() << std::endl; //"\t y = ( " << y.get_wert(0) << "; " << y.get_wert(1) << ")" << std::endl;
	}

	void C_DGLSolver_Heun(double Xstart, double Xend, int steps, CMyVektor y_start)
	{
		double h = (Xend - Xstart) / steps;

		std::cout << "h = " << h << std::endl << std::endl;

		double x = 0;
		double x2 = 0;
		CMyVektor y = y_start;
		CMyVektor y_sec = y_start;
		CMyVektor y_strich = y_start;
		CMyVektor y_test = y_start;
		CMyVektor y_strich_test = y_start;
		CMyVektor y_strich_mitte = y_start;

		for (int i = 0; i < steps; i++)
		{
			//Euler
			std::cout << "Schritt " << i << ":" << std::endl;

			x = Xstart + (i*h);

			std::cout << "\t x = " << x << std::endl;

			std::cout << std::setprecision(8) << "\t y = " << y.toString() << std::endl;						//"\t y = ( " << y.get_wert(0) << "; " << y.get_wert(1) << ")" << std::endl;

			y_strich = derivation(y, x);

			std::cout << std::setprecision(8) << "\t y'_orig = " << y_strich.toString() << std::endl << std::endl;			//<< "\t y'_orig = ( " << y_strich.get_wert(0) << "; " << y_strich.get_wert(1) << ")" << std::endl;

			y_sec = y + (h * y_strich);

			//Heun Test

			std::cout << std::setprecision(8) << "\t y_test = " << y_sec.toString() << std::endl;				//"\t y_test = ( " << y_sec.get_wert(0) << "; " << y_sec.get_wert(1) << ")" << std::endl;


			x2 = Xstart + ((i + 1) * h);		//Schrittweite für den Test = doppelte vom Ursprung
			y_strich_test = derivation(y_sec, x2);

			std::cout << std::setprecision(8) << "\t y'_test = " << y_strich_test.toString() << std::endl << std::endl;		//"\t y'_test = ( " << y_strich_test.get_wert(0) << "; " << y_strich_test.get_wert(1) << ")" << std::endl;

			y_test = y_sec + (h * y_strich_test);

			y_strich_mitte = (0.5 * (y_strich + y_strich_test));
			/*
			y_strich_mitte.set_wert(0, ((y_strich.get_wert(0) + y_strich_test.get_wert(0)) / 2));
			y_strich_mitte.set_wert(1, ((y_strich.get_wert(1) + y_strich_test.get_wert(1)) / 2));
			*/

			std::cout << std::setprecision(8) << "\t y'_Mitte = " << y_strich_mitte.toString() << std::endl << std::endl << std::endl;	//"\t y'_Mitte = ( " << y_strich_mitte.get_wert(0) << "; " << y_strich_mitte.get_wert(1) << ")" << std::endl;

			y = y + (h*y_strich_mitte);
			
		};

		std::cout << "Ende bei " << std::endl;

		std::cout << "\t x = " << x + h << std::endl;

		std::cout << std::setprecision(8) << "\t y = " << y.toString() << std::endl;		//std::cout << std::setprecision(8) << "\t y = ( " << y.get_wert(0) << "; " << y.get_wert(1) << ")" << std::endl;
	}

};