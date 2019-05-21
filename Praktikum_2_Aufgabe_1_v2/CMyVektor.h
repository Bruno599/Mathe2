#pragma once

#include <vector>
#include <iostream>
#include <cmath>

class CMyVektor {
private:
    int dimension;
    std::vector<double> werte;
public:
    CMyVektor(int dimension);

    CMyVektor(const std::vector<double> &werte);

    int get_dimension() const;

    void set_wert(int index, double wert);

    double get_wert(int index) const;

    double &operator[](int index);

    double laenge() const;  //Länge des Vektors
    friend std::ostream &operator<<(std::ostream &os, const CMyVektor &v);      //vektor ausgeben
    friend CMyVektor operator*(double lambda, CMyVektor a);     //skalare Multiplikation
    friend CMyVektor operator+(CMyVektor a, CMyVektor b);     //vektor-Addition
    friend CMyVektor gradient(const CMyVektor &x, double (*funktion)(CMyVektor));
};




