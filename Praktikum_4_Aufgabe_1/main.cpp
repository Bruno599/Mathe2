#include <fstream>
#include <vector>
#include "CKomplex.h"
#include <iostream>

using namespace std;

double pi = atan(1) * 4;

vector<CKomplex>  werte_einlesen(const char *dateiname);
void werte_ausgeben(const char *dateiname, vector<CKomplex> werte, double epsilon = -1);
vector<CKomplex> Fourier(vector<CKomplex> inVector, bool transDirection);
double diff(vector<CKomplex> a, vector<CKomplex> b);

int main()
{
	//char file_name = 'Daten_Original';
	vector<CKomplex> origin = werte_einlesen("Daten_original.txt");

	//werte_ausgeben("Daten_Test1", origin, 0);

	vector<CKomplex> transformed = Fourier(origin, true);

	werte_ausgeben("default_epsilon_Fourier.txt", transformed);

	werte_ausgeben("01_epsilon_Fourier.txt", transformed, 0.1);

	werte_ausgeben("10_epsilon_Fourier.txt", transformed, 1.0);

	vector<CKomplex> default_epsilon = werte_einlesen("default_epsilon_Fourier.txt");

	vector<CKomplex> epsilon_01 = werte_einlesen("01_epsilon_Fourier.txt");

	vector<CKomplex> epsilon_10 = werte_einlesen("10_epsilon_Fourier.txt");

	vector<CKomplex> origin_default_epsilon = Fourier(default_epsilon, false);

	vector<CKomplex> origin_epsilon_01 = Fourier(epsilon_01, false);

	vector<CKomplex> origin_epsilon_10 = Fourier(epsilon_10, false);

	cout << "Maximale Abweichung bei Standard-Epsilon: " << diff(origin, origin_default_epsilon) << endl;

	cout << "Maximale Abweichung bei Standard-Epsilon: " << diff(origin, origin_epsilon_01) << endl;

	cout << "Maximale Abweichung bei Standard-Epsilon: " << diff(origin, origin_epsilon_10) << endl;

	system("PAUSE");

	return 0;



};

double diff(vector<CKomplex> a, vector<CKomplex> b)
{
	double diff = 0.0;

	for (int i = 0; i < a.size(); i++)
	{
		double temp = 0.0;

		temp = abs(a[i].getReal() - b[i].getReal());

		if (temp > diff)
		{
			diff = temp;
		}
	}

	return diff;
}

vector<CKomplex> Fourier(vector<CKomplex> inVector, bool transDirection)
{
	vector<CKomplex> outVector;
	outVector.resize(inVector.size());
	int N = inVector.size();

	for (int n = 0; n < N; n++)
	{
		CKomplex temp(0, 0);

		for (int k = 0; k < N; k++)
		{
			double phi = (2 * pi*k*n) / N;

			if (transDirection)
			{
				phi = (phi * (-1));
			}

			CKomplex tempk(phi);

			temp = temp + (tempk * inVector[k]);
		}

		temp = temp * (1/sqrt(N));

		outVector[n] = temp;
	}

	return outVector;
}

vector<CKomplex>  werte_einlesen(const char *dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
	// File oeffnen
	ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i < N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const char *dateiname, vector<CKomplex> werte, double epsilon)
{
	int i;
	int N = werte.size();
	// File oeffnen
	ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].getReal() << "\t" << werte[i].getImagi() << endl;
	// File schliessen
	fp.close();
}