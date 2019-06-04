#pragma once
#include "CMyVektor.h"
#include <iostream>
#include <iomanip>

class C_DGLSolver {

private:

	CMyVektor(*f_DGL_System)(CMyVektor y, double x);
	double(*F_DGL_nterOrdnung)(CMyVektor y, double x);
	bool dgl_first_order;

	CMyVektor derivation(CMyVektor y, double x);

	

public:

	C_DGLSolver(CMyVektor(*funktion)(CMyVektor y, double x)) { this->f_DGL_System = funktion; this->dgl_first_order = true; };
	C_DGLSolver(double(*funktion)(CMyVektor y, double x)) { this->F_DGL_nterOrdnung = funktion;  this->dgl_first_order = false; };

	CMyVektor C_DGLSolver_Euler(double Xstart, double Xend, int steps, CMyVektor y_start);
	CMyVektor C_DGLSolver_Heun(double Xstart, double Xend, int steps, CMyVektor y_start);

	
};