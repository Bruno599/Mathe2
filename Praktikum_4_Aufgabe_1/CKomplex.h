#pragma once

#include <math.h>

class CKomplex
{
private:
	double real;
	double imagi;

public:	
	CKomplex() { this->real = 0; this->imagi = 0; };
	CKomplex(double a, double b) { real = a; imagi = b;};
	CKomplex(double phi) {this->real = cos(phi); this->imagi = sin(phi);};

	double getReal() { return real; };
	double getImagi() { return imagi; };

	CKomplex operator + (CKomplex b);
	CKomplex operator * (CKomplex b);

	CKomplex operator * (double b);

	CKomplex operator = (const CKomplex b);

	double abs();
	



};