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

	void setTipp_manual(int a, int b, int c, int d, int e, int f);

	std::vector<int> sechsAus49();

	std::vector<int> sixOutOfFortynine();

	std::vector<int> pruefe_tipp_mit_vector();

	int pruefe_tipp();

	int pruefe_2malLotto();

	std::vector<int> pruefe_2malLotto_mit_vector();
	


};