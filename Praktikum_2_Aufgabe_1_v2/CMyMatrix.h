#pragma once

#include <vector>
#include "CMyVektor.h"


class CMyMatrix {
private:
    std::vector<std::vector<double>> matrix;	//erstelle Vector der vectoren enthält der wiederum double enthählt

    struct Dimension {int zeilen = 0;int spalten = 0;} matrixDimension;

public:
    CMyMatrix(int zeilen, int spalten);

    void set_wert(double wert, int zeile, int spalte);

    double get_wert(int zeile, int spalte) const;

    double &operator()(int zeile, int spalte);

    CMyMatrix invers();

    friend CMyVektor operator*(CMyMatrix A, CMyVektor x);

    friend std::ostream &operator<<(std::ostream &os, CMyMatrix x);
};




