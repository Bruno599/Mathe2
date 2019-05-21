#include "CMyMatrix.h"

CMyMatrix::CMyMatrix(int zeilen, int spalten) : matrixDimension{zeilen, spalten} 
{
    matrix.resize(zeilen);
    for (int i = 0; i < zeilen; ++i)
        matrix[i].resize(spalten);
}

void CMyMatrix::set_wert(double wert, int zeile, int spalte) 
{
    matrix[zeile][spalte] = wert;
}

double CMyMatrix::get_wert(int zeile, int spalte) const 
{
    return matrix[zeile][spalte];
}

double &CMyMatrix::operator()(int zeile, int spalte) 
{
    return matrix[zeile][spalte];
}

CMyMatrix CMyMatrix::invers() 
{
    if (matrixDimension.zeilen != 2 || matrixDimension.spalten != 2)
        throw std::runtime_error("Matrix kann nicht invertiert werden. Die Matrix muss 2x2 sein!");
    double det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]; //determinante von oben link mal unten rechts minus unten links mal obenrechts 
    if (det == 0)
        throw std::runtime_error("Matrix kann nicht invertiert werden. Keine Division durch Null! (detA == 0)");

    CMyMatrix x{*this};
    x(0, 0) = (1 / det) * matrix[1][1];
    x(0, 1) = (1 / det) * -matrix[0][1];
    x(1, 0) = (1 / det) * -matrix[1][0];
    x(1, 1) = (1 / det) * matrix[0][0];

    return x;
}

CMyVektor operator*(CMyMatrix A, CMyVektor x) 
{
	if (A.matrixDimension.spalten != x.get_dimension())
		throw std::runtime_error("Multiplikation kann nicht ausgeführt werden, da Spalten der Matrix und Zeilen des Vectors ungleich");

    CMyVektor ergebnis{A.matrixDimension.zeilen};
    for (int i = 0; i < A.matrixDimension.zeilen; i++) //m
	{ 
        for (int j = 0; j < A.matrixDimension.spalten; j++) //n
            ergebnis[i] += A(i, j) * x[j];
    }
    return ergebnis;
}

std::ostream &operator<<(std::ostream &os, CMyMatrix x) 
{
    os << "\t\t\t( ";
    for (int i = 0; i < x.matrixDimension.zeilen; ++i) 
	{
        for (int j = 0; j < x.matrixDimension.spalten; ++j)
            j == x.matrixDimension.spalten - 1 ? os << x(i, j) : os << x(i, j) << " ; ";
        i == x.matrixDimension.zeilen - 1 ? os << " )" : os << "\n\t\t\t";
    }
    return os;
}




