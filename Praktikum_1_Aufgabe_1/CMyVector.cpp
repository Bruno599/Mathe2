#include "CMyVector.h"
#include <iostream>

CMyVector::CMyVector()
{
	dimension = 0;
	myarray = nullptr;
};

CMyVector::CMyVector(int _dimension)
{
	this->dimension = _dimension;
	this->myarray = new double[_dimension];


	this->insert();
};

void CMyVector::print()
{
	
	for (int i = 0; i < dimension; i++)
	{
		std::cout << this->myarray[i] << " ";

	}
	std::cout << std::endl;
};

void CMyVector::printdimension()
{
	std::cout << "Die Dimension des Vectors betraegt: " << this->dimension << std::endl;
}

bool CMyVector::set_value_for_dimension(double _value, int _dimension)
{
	if (_dimension < 1 || _dimension > this->dimension)
	{
		return false;
	}
	else
	{
		this->myarray[_dimension - 1] = _value;
		return true;
	}
}

double CMyVector::get_value_from_vector(int _dimension)
{
	if (_dimension < 1 || _dimension > this->dimension)
	{
		return 0;
	}
	else
	{
		return (this->myarray[_dimension - 1]);
	}
}

int CMyVector::get_dimension()
{
	return (this->dimension);
}

double CMyVector::laenge_vector()
{
	double laenge = 0;
	for (int i = 0; i < this->dimension; i++)
	{
		double mult = this->myarray[i] * this->myarray[i];
		laenge = laenge + mult;
	}
	laenge = sqrt(laenge);
	return laenge;
};

void CMyVector::insert()
{
	for (int i = 0; i < this->dimension; i++)
	{
		std::cout << " Bitte geben Sie den Wert für die" << i + 1 << ". Dimension ein: ";
		std::cin >> this->myarray[i];
	}
};