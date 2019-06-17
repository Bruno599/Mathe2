#include "CKomplex.h"

//#include <math.h>

CKomplex CKomplex::operator+(CKomplex b)
{
	double a;
	double c;

	a = this->real + b.real;
	c = this->imagi + b.imagi;

	CKomplex result(a, c);

	return result;
}

CKomplex CKomplex::operator*(CKomplex b)
{
	double a;
	double c;

	a = ((this->real * b.real) - (this->imagi * b.imagi));
	c = ((this->real * b.imagi) + (this->imagi * b.real));

	CKomplex result(a, c);

	return result;
}

CKomplex CKomplex::operator*(double b)
{
	double a;
	double c;

	a = this->real * b;
	c = this->imagi * b;

	CKomplex result(a, c);

	return result;
}

CKomplex CKomplex::operator= (const CKomplex b)
{
	this->real = b.real;
	this->imagi = b.imagi;

	return *this;

}

double CKomplex::abs()
{
	return sqrt(((this->real)*(this->real) + (this->imagi)*(this->imagi)));
}