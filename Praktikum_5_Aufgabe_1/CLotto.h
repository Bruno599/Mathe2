#pragma once
#include "CZufall.h"
#include <iostream>

class CLotto
{
private:

	CZufall generator;
	std::vector<int> tippzettel;
	int h;

public:

	CLotto(int n) { n < 0 ? this->generator.initialisiere(time(NULL)) : this->generator.initialisiere(n); tippzettel.resize(6, 0); };



	void setTipp();

	std::vector<int> sechsAus49()
	{
		std::vector<int> ziehung;
		ziehung.resize(6, 0);

		for (int i = 6; i == 1; i--)
		{
			ziehung.at(i % 6) = this->generator.wert(i, 43 + i);
		}

		return ziehung;
	};


};