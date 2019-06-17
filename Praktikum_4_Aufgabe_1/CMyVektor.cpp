#include "CMyVektor.h"



CMyVektor::CMyVektor(int dimension) : dimension{dimension} 
{ 
	werte.resize(dimension); 
}

CMyVektor::CMyVektor(const std::vector<double> &werte) : werte{werte}, dimension{int(werte.size())} {}

int CMyVektor::get_dimension() const { return dimension; }

void CMyVektor::set_wert(int index, double wert) { werte[index] = wert; }

double CMyVektor::get_wert(int index) const { return werte[index]; }

double &CMyVektor::operator[](int index) 
{
    return werte[index];
}

double CMyVektor::laenge() const 
{
    double laenge{0};
    for (int i = 0; i < dimension; i++)
        laenge += pow(werte[i], 2);
    return sqrt(laenge);
}

std::ostream &operator<<(std::ostream &os, const CMyVektor &v) 
{
    os << "( ";
    for (int i = 0; i < v.dimension; i++)
        i != v.dimension - 1 ? os << v.werte[i] << " ; " : os << v.werte[i];
    os << " )";
    return os;
}

CMyVektor operator+(CMyVektor a, CMyVektor b) 
{
    for (int i = 0; i < a.dimension; i++)
        a[i] += b[i];
    return a;
}

CMyVektor operator*(double lambda, CMyVektor a) 
{
    for (int i = 0; i < a.dimension; i++)
        a[i] *= lambda;
    return a;
}

std::string CMyVektor::toString()
{
	std::string result = "( ";

	for (int i = 0; i < dimension; i++)
	{
		result += std::to_string(this->get_wert(i));
		if (i < this->dimension - 1)
		{
			result += "; ";
		}

	}

	result += ")";

	return result;

}
