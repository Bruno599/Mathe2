#pragma once

class CMyVector
{
private:
	int dimension = 0;
	double * myarray = nullptr;

public:
	CMyVector();
	CMyVector(int _dimension);
	void print();
	void printdimension();
	bool set_value_for_dimension(double _value, int _dimension);
	double get_value_from_vector(int _dimension);
	int get_dimension();
	double laenge_vector();
	void insert();
	~CMyVector()
	{
		delete this;
	};
	friend CMyVector operator * (CMyVector a, double lambda);
	friend CMyVector operator + (CMyVector &a, CMyVector &b);
	//CMyVector& operator = (CMyVector &b);
};

inline CMyVector operator * (CMyVector a, double lambda)
{
	CMyVector * tmp = new CMyVector(a.get_dimension());
	for (int i = 0; i < a.get_dimension(); i++)
	{
		//tmp->set_value_for_dimension(lambda*(a.get_value_from_vector(i)), i);
		tmp->myarray[i] = a.myarray[i] * lambda;
	}
	return * tmp;
};


inline CMyVector operator + (CMyVector &a, CMyVector &b)
{
	CMyVector * tmp = new CMyVector(a.get_dimension());
	for (int i = 0; i < a.get_dimension(); i++)
	{
		tmp->set_value_for_dimension((a.get_value_from_vector(i)) + b.get_value_from_vector(i), i);
		//tmp->myarray[i] = a->myarray[i] + b->myarray[i];
	}
	return *tmp;
};

/* CMyVector& CMyVector::operator = (CMyVector &b)
{
	if (this != &b)
	{
		this->dimension = b.get_dimension();

		for (int i = 0; i < b.get_dimension() - 1; i++)
		{
			this->set_value_for_dimension(b.get_value_from_vector(i), i);
		}
	}
};
*/

/*
CMyVector operator * (CMyVector a, CMyVector b)
*/