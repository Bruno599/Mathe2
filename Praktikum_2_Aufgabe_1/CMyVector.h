#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>


class CMyVector {
private:
	int dimension;
	std::vector<double> values;

public:
	CMyVector(int dimension, std::vector<double> vector);

	int getDimension();
	double getValue(int position);
	void setValue(double value, int position);
	double getLength();
	CMyVector & operator=(CMyVector a);
	//void Printvec();

};


CMyVector operator+(CMyVector a, CMyVector b);
CMyVector operator*(double lambda, CMyVector a);
CMyVector & operator=(CMyVector a);
double& operator[](int i);

