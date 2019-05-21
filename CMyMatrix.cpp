#include "CMyMatrix.h"
#include <string>

using namespace std;

CMyMatrix::CMyMatrix(int m, int n)
{
	dimensions[0] = m;
	dimensions[1] = n;
	nVectors = new CMyVector *[n];

	for (int i = 0; i < n; i++)
	{
		nVectors[i] = new CMyVector(m);
	}
}

CMyMatrix::CMyMatrix(const CMyMatrix& matrix)
{
	dimensions[0] = matrix.dimensions[0];
	dimensions[1] = matrix.dimensions[1];
	nVectors = new CMyVector *[matrix.dimensions[1]];

	for (int i = 0; i < dimensions[1]; i++)
	{
		nVectors[i] = new CMyVector(matrix.dimensions[0]);

		for (int k = 0; k < dimensions[0]; k++)
		{
			nVectors[i]->setValue(k, matrix.nVectors[i]->getValue(k));
		}
	}
}

CMyMatrix::~CMyMatrix()
{
	for (int i = 0; i < dimensions[1]; i++)
	{
		delete nVectors[i];
	}
	delete[] nVectors;
}

void CMyMatrix::setValue(int m, int n, double elem)
{
	nVectors[n]->setValue(m, elem);
}

double CMyMatrix::getValue(int m, int n)
{
	return nVectors[n]->getValue(m);
}

CMyMatrix CMyMatrix::invers()
{
	try
	{
		if (dimensions[0] != 2 && dimensions[1] != 2)
		{
			throw "Matrix is not 2 x 2!";
		}
		if (determinante() == 0)
		{
			throw "Determinant is 0!";
		}
		CMyMatrix resultM{ dimensions[0], dimensions[1] };

		resultM = inversTempMatrix() * (1 / determinante());

		return resultM;
	}
	catch (const char* msg)
	{
		cout << red << "Error: " << msg << white << endl;
	}
}

CMyMatrix CMyMatrix::inversTempMatrix()
{
	CMyMatrix resultM{ this->dimensions[0], this->dimensions[1] };

	double tempA = this->getValue(0, 0);

	resultM.setValue(0, 0, this->getValue(1, 1));
	resultM.setValue(0, 1, (-1 * this->getValue(0, 1)));
	resultM.setValue(1, 0, (-1 * this->getValue(1, 0)));
	resultM.setValue(1, 1, tempA);

	return resultM;
}

double CMyMatrix::determinante()
{
	double result = 0;

	result = this->getValue(0, 0) * this->getValue(1, 1);
	result -= this->getValue(0, 1) * this->getValue(1, 0);

	return result;
}

std::string CMyMatrix::toString()
{
	string result = "";

	for (int m = 0; m < dimensions[0]; m++)
	{
		result += "( ";

		for (int n = 0; n < dimensions[1]; n++)
		{
			result += to_string(nVectors[n]->getValue(m));

			if (n < dimensions[1] - 1)
			{
				result += "; ";
			}
		}

		result += ")\n";
	}

	return result;
}

CMyMatrix CMyMatrix::operator*(double a)
{
	CMyMatrix resultM{ *this };
	for (int n = 0; n < resultM.dimensions[1]; n++)
	{
		for (int m = 0; m < resultM.dimensions[0]; m++)
		{
			resultM.nVectors[n]->setValue(m, getValue(m, n) * a);
		}
	}
	return resultM;
}

CMyVector CMyMatrix::operator*(CMyVector x)
{
	CMyVector result(x.getDimension());
	double elemResult = 0;

	for (int i = 0; i < dimensions[0]; i++)
	{
		for (int k = 0; k < dimensions[1]; k++)
		{
			elemResult += (nVectors[k]->getValue(i) * x[k]);
		}

		result[i] = elemResult;
		elemResult = 0;
	}

	return result;
}

CMyMatrix& CMyMatrix::operator=(const CMyMatrix& matrix)
{
	if (this != &matrix)
	{
		for (int i = 0; i < matrix.dimensions[1]; i++)
		{
			for (int k = 0; k < dimensions[0]; k++)
			{
				nVectors[i]->setValue(k, matrix.nVectors[i]->getValue(k));
			}
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const CMyMatrix& a)
{
	for (int i = 0; i < a.dimensions[1]; i++)
	{
		//stream << a.toString() << endl;
	}

	return stream;
}