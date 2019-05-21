#include "CMyMatrix.h"

double CMyMatrix::getValue(int m, int n) {
	if (m > this->mRows || n > this->nColumns) {
		return 0.0;
	}

	return this->values.at(m)->getValue(n);
}

void CMyMatrix::setValue(int m, int n, double value) {
	if (m > this->mRows || n > this->nColumns) {
		return;
	}

	this->values.at(m)->setValue(value, n);
}

CMyMatrix CMyMatrix::invers() {
	double det = calcDet();

	if (det == 0)
		throw "Determinante == 0";

	std::vector<CMyVector*> vector;
	CMyMatrix inver(2, 2, vector);

	double con = (1.0 / det);

	inver.setValue(0, 0, con * this->getValue(1, 1));
	inver.setValue(0, 1, (-1) * con * this->getValue(0, 1));
	inver.setValue(1, 0, (-1) * con * this->getValue(1, 0));
	inver.setValue(1, 1, con * this->getValue(0, 0));

	return inver;
}

double CMyMatrix::calcDet() {
	if (this->getNColumns() != 2 || this->getMRows() != 2)
		return 0;

	return this->getValue(0, 0) * this->getValue(1, 1) - this->getValue(0, 1) * this->getValue(1, 0);
}

CMyVector operator*(CMyMatrix A, CMyVector x) {
	if (A.getNColumns() != x.getDimension()) {
		return x;
	}

	std::vector<double> v;
	CMyVector result(A.getMRows(), v);

	double value = 0;

	for (int row = 0; row < A.getMRows(); row++) {
		value = 0;
		for (int column = 0; column < A.getNColumns(); column++) {
			value += A.getValue(row, column) * x.getValue(column);
		}
		result.setValue(value, row);
	}

	return result;
}