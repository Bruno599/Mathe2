#include "CMyMatrix.h"
#include "CMyVector.h"



int main()
{

}
CMyMatrix jacobi(CMyVector x, CMyVector(*funktion)(CMyVector x))
{
	std::vector<double> value;

	double h = 1e-4;

	CMyVector fVec(x.getDimension(), value);
	fVec = funktion(x) ;

	CMyMatrix resultM(fVec.getDimension(), x.getDimension(), value);


	for (int m = 0; m < resultM.getMRows(); m++) { //3 f
		for (int n = 0; n < resultM.getNColumns(); n++) { //4 x
			double tmp = x.getValue(n);
			x.setValue(x.getValue(n) + h, n);
			double y = (funktion(x).getValue(m) - fVec.getValue(m)) / h;
			x.setValue(tmp, n);

			resultM.setValue(m, n, y);
		}
	}
	return resultM;

	/*
	for (int n = 0; n < resultM.getDimension(1); n++)
	{
		CMyVector VecInacc{ x };

		VecInacc[n] = VecInacc[n] + h;

		CMyVector fVecInacc{ funktion(VecInacc) };

		for (int m = 0; m < resultM.getDimension(0); m++)
		{
			resultM.setElem(m, n, (fVecInacc[m] - fVec[m]) / h);
		}
	}

	return resultM;
	*/
}


CMyVector F1(CMyVector Vec)
{
	std::vector<double> value;

	CMyVector result(3, value);

	result.setValue(Vec.getValue(0) * Vec.getValue(1) * exp(Vec.getValue(2)),0);
	result.setValue(Vec.getValue(1) * Vec.getValue(2) * Vec.getValue(3),0);
	result.setValue(Vec.getValue(3),2);

	return result;
}