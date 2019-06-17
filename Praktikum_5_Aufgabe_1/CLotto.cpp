#include "CLotto.h"

void CLotto::setTipp()
{

	int counter = 1;
	while (counter < 7)
	{
		int n = 0;
		std::cout << "Bitte geben Sie den " << counter << ". Tipp ihres Stimmzettels ein: ";
		std::cin >> n;

		if (n < 0 || n > 49)
		{
			continue;
		}
		else
		{
			tippzettel[counter - 1] = n;
			counter++;

		}

	}
}

void CLotto::setTipp_manual(int a, int b, int c, int d, int e, int f)
{
	tippzettel[0] = a;
	tippzettel[1] = b;
	tippzettel[2] = c;
	tippzettel[3] = d;
	tippzettel[4] = e;
	tippzettel[5] = f;
};

std::vector<int> CLotto::sixOutOfFortynine()
{
	std::vector<int> pool(49);
	std::vector<int> ziehung;
	ziehung.resize(6, 0);
	int index = 0;
	//int werte = 0;


	for (int i = 0; i < pool.size(); i++)
	{
		pool.at(i) = i + 1;
	}

	for (int i = 0; i < 6; i++)
	{
		index = generator.wert(0, pool.size()-1);
		//werte = pool.at(index);
		ziehung[i] = pool.at(index);
		pool.erase(pool.begin() + index);
	}

	return ziehung;

}

std::vector<int> CLotto::sechsAus49()
{
	std::vector<int> ziehung;
	ziehung.resize(6, 0);

	for (int i = 6; i >= 1; i--)
	{
		int temp = this->generator.wert(i, 43 + i);

		for (int b = 0; b < ziehung.size(); b++)
		{
			if (ziehung.at(b) == temp)
			{
				break;
			}

		}

		ziehung.at(i % 6);
	}

	return ziehung;
};

std::vector<int> CLotto::pruefe_tipp_mit_vector()
{
	//test
	/*
	std::vector<int> test;
	test.push_back(13);
	test.push_back(24);
	test.push_back(34);
	test.push_back(15);
	test.push_back(3);
	test.push_back(6);
	*/
	std::vector<int> ziehung = this->sixOutOfFortynine();
	
	std::vector<int> check;

	for (int i = 0; i < 6; i++)
	{
		for (int b = 0; b < 6; b++)
		{
			if (ziehung[i] == tippzettel[b])
			{
				check.push_back(ziehung[i]);
				break;
			}
		}
	}

	return check;
};

int CLotto::pruefe_tipp()
{
	//test
	/*
	std::vector<int> test;
	test.push_back(13);
	test.push_back(24);
	test.push_back(34);
	test.push_back(15);
	test.push_back(3);
	test.push_back(6);
	*/
	std::vector<int> ziehung = this->sixOutOfFortynine();

	int count = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int b = 0; b < 6; b++)
		{
			if (ziehung[i] == tippzettel[b])
			{
				count++;
				break;
			}
		}
	}

	return count;
};

int CLotto::pruefe_2malLotto()
{
	//test
	/*
	std::vector<int> test;
	test.push_back(13);
	test.push_back(24);
	test.push_back(34);
	test.push_back(15);
	test.push_back(3);
	test.push_back(6);
	*/
	std::vector<int> ziehung1 = this->sixOutOfFortynine();

	std::vector<int> ziehung2 = this->sixOutOfFortynine();

	int count = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int b = 0; b < 6; b++)
		{
			if (ziehung1[i] == ziehung2[b])
			{
				count++;
				break;
			}
		}
	}

	return count;
};

std::vector<int> CLotto::pruefe_2malLotto_mit_vector()
{
	//test
	/*
	std::vector<int> test;
	test.push_back(13);
	test.push_back(24);
	test.push_back(34);
	test.push_back(15);
	test.push_back(3);
	test.push_back(6);
	*/
	std::vector<int> ziehung1 = this->sixOutOfFortynine();

	std::vector<int> ziehung2 = this->sixOutOfFortynine();

	std::vector<int> check;

	for (int i = 0; i < 6; i++)
	{
		for (int b = 0; b < 6; b++)
		{
			if (ziehung1[i] == ziehung2[b])
			{
				check.push_back(ziehung1[i]);
				break;
			}
		}
	}

	return check;
};