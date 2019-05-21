#pragma once
#include <vector>
#include "CMyVector.h"

class CMyMatrix {
private:
	int mRows;
	int nColumns;

	std::vector<CMyVector*> values;

public:
	CMyMatrix(int mRows, int nColumns, std::vector<CMyVector*> values) {
		this->mRows = mRows;
		this->nColumns = nColumns;

		std::vector<double> v;


		for (int i = 0; i < this->nColumns; i++) {
			CMyVector *vector = new CMyVector(this->mRows, v);
			values.push_back(vector);
		}

		this->values = values;
	}

	double getValue(int m, int n);
	void setValue(int m, int n, double value);
	double calcDet();

	int getMRows() const {
		return mRows;
	}

	void setMRows(int mRows) {
		CMyMatrix::mRows = mRows;
	}

	int getNColumns() const {
		return nColumns;
	}

	void setNColumns(int nColumns) {
		CMyMatrix::nColumns = nColumns;
	}

	CMyMatrix invers();
};

CMyVector operator*(CMyMatrix A, CMyVector x);

