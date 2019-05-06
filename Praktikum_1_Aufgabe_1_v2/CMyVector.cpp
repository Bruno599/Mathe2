#include "CMyVector.h"

CMyVector::CMyVector(int dimension, std::vector<double> values) 
{
	this->dimension = dimension;

	for (int index = 0; index < this->dimension; index++) 
	{
		values.push_back(0);
	}

	this->values = values;
}

int CMyVector::getDimension() 
{
	return dimension;
}

double CMyVector::getValue(int position)  
{
	return this->values.at(position);
}

void CMyVector::setValue(double value, int position) 
{
	this->values.at(position) = value;
}

double CMyVector::getLength() 
{
	double length = 0;

	for (int index = 0; index < this->values.size(); index++) 
	{
		length += this->values.at(index) * this->values.at(index);
	}

	return sqrt(length);
}




CMyVector operator+(CMyVector a, CMyVector b) 
{

	if (a.getDimension() != b.getDimension()) 
	{
		return a;
	}

	std::vector<double> v;

	for (int index = 0; index < a.getDimension(); index++) 
	{
		double val = a.getValue(index) + b.getValue(index);
		v.push_back(val);
	}

	CMyVector result(a.getDimension(), v);

	return result;
}

CMyVector operator*(double lambda, CMyVector a) 
{
	std::vector<double> v;

	for (int index = 0; index < a.getDimension(); index++) 
	{
		double value = a.getValue(index) * lambda;
		v.push_back(value);
	}

	CMyVector result(a.getDimension(), v);

	return result;
}

