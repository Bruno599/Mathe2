#pragma once
#include "CMyVector.h"

class CMyMatrix {

	private:
		int dimensions[2]; // M,N
		CMyVector** nVectors;

	public:
		CMyMatrix(int m, int n);
		//MyMatrix(int m, int n, MyVector *elems, int size);
		CMyMatrix(const CMyMatrix& matrix);
		~CMyMatrix();

		void setValue(int m, int n, double elem);
		double getValue(int m, int n);

		CMyMatrix invers();
		CMyMatrix inversTempMatrix();
		double determinante();

		std::string toString();

		CMyMatrix operator* (double a);
		CMyVector operator* (CMyVector x);
		CMyMatrix& operator= (const CMyMatrix& matrix);

		friend std::ostream& operator <<(std::ostream& stream, const CMyMatrix& a);
	};

};