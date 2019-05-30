#include <iostream>
#include "CMyMatrix.h"

using namespace std;



CMyMatrix jacobi(const CMyVektor &x, CMyVektor (*funktion)(CMyVektor));   

void newtonverfahren(CMyVektor x, CMyVektor (*funktion)(CMyVektor));  

void gradientenverfahren(CMyVektor x, double(*funktion)(CMyVektor), double lambda = 1.0);

CMyVektor f(CMyVektor x) 
{
	CMyVektor a(3);
	
	a.set_wert(0, x[0] * x[1] * exp(x[2]));
	a.set_wert(1, x[1] * x[2] * x[3]);
	a.set_wert(2, x[3]);

	return a;
}

CMyVektor g(CMyVektor y)
{
	CMyVektor b(2);

	b.set_wert(0, pow(y[0], 3) * pow(y[1], 3) - 2 * y[1]);
	b.set_wert(1, y[0] - 2);

	return b;
}

int main() {

	int auswahl = 0;

	CMyVektor y(4);
	CMyVektor z(2);

	y.set_wert(0, 1);
	y.set_wert(1, 2);
	y.set_wert(2, 0);
	y.set_wert(3, 3);

	z.set_wert(0, 1);
	z.set_wert(1, 1);

	cout << "Aufgabe_2 :\n" << jacobi(y, f) << endl;;

	newtonverfahren(z, g);

		/*
	cout << "inverse Berechnen, wenn ja bitte 1 eingeben." << endl;
	cin >> auswahl;

	if (auswahl == 1)
	{
		invers
	}

	*/
	system("Pause");
	return 0;
}

CMyVektor gradient(const CMyVektor &x, double(*funktion)(CMyVektor))
{
	const double h = 1e-8;
	CMyVektor ergebnis{ x.dimension };
	for (int i = 0; i < ergebnis.dimension; i++)
	{
		CMyVektor tmp{ x };
		tmp[i] += h;		//um die Wackelei zu beginnen  ....überladen von operatoren [] wäre besser
		ergebnis[i] = (funktion(tmp) - funktion(x)) / h;
	}
	return ergebnis;
}


void gradientenverfahren(CMyVektor x, double(*funktion)(CMyVektor), double lambda)
{
	using namespace std;

	int schritt = 0;
	while (schritt != 25 && gradient(x, funktion).laenge() >= 1e-5) {
		cout << "Schritt " << schritt << ":"
			<< "\n\t x = " << fixed << x << defaultfloat
			<< "\n\t lambda = " << lambda
			<< "\n\t f(x) = " << funktion(x)
			<< "\n\t grad f(x) = " << fixed << gradient(x, funktion) << defaultfloat
			<< "\n\t ||grad f(x)|| = " << gradient(x, funktion).laenge() << endl;

		CMyVektor x_neu = x + lambda * gradient(x, funktion);

		cout << "\n\t x_neu = " << fixed << x_neu << defaultfloat
			<< "\n\t f(x_neu) = " << funktion(x_neu) << endl;

		if (funktion(x_neu) > funktion(x))
		{
			cout << "\n\t Test mit doppelter Schrittweite (lambda = " << lambda * 2 << "):";
			CMyVektor x_test = x + (2 * lambda) * gradient(x, funktion);
			cout << "\n\t x_test = " << fixed << x_test << defaultfloat
				<< "\n\t f(x_test) = " << funktion(x_test);
			if (funktion(x_test) > funktion(x_neu))
			{
				x = x_test;
				lambda *= 2;
				cout << "\n\t verdoppele Schrittweite!" << endl;
			}
			else
			{
				x = x_neu;
				cout << "\n\t behalte alte Schrittweite!" << endl;
			}
		}
		else
		{
			while (funktion(x_neu) <= funktion(x))
			{
				lambda /= 2;
				x_neu = x + lambda * gradient(x, funktion);
				cout << "\n\t halbiere Schrittweite (lambda = " << lambda << "):"
					<< "\n\t x_neu = " << fixed << x_neu << defaultfloat
					<< "\n\t f(x_neu) = " << funktion(x_neu) << endl;
			}
			x = x_neu;
		}
		cout << endl;
		schritt++;
		if (gradient(x, funktion).laenge() < pow(10, -5))
		{
			cout << "Ende wegen ||grad f(x)||<1e-5 bei";
			goto ende;
		}
		else if (schritt == 25)
		{
			cout << "Ende wegen Schrittanzahl = 25 bei";
		ende:
			cout << "\n\t x = " << fixed << x << defaultfloat
				<< "\n\t lambda = " << lambda
				<< "\n\t f(x) = " << funktion(x)
				<< "\n\t grad f(x) = " << fixed << gradient(x, funktion) << defaultfloat
				<< "\n\t ||grad f(x)|| = " << gradient(x, funktion).laenge() << endl;
		}
	}
}

CMyMatrix jacobi(const CMyVektor &x, CMyVektor(*funktion)(CMyVektor))
{
	double const h = 1e-4;
	CMyVektor funktion_x = funktion(x);
	CMyMatrix jacobiM{ funktion_x.get_dimension(), x.get_dimension() };

	for (int i = 0; i < funktion_x.get_dimension(); ++i)
	{
		for (int j = 0; j < x.get_dimension(); ++j)
		{
			CMyVektor tmp{ x };
			tmp[j] += h;
			jacobiM(i, j) = (funktion(tmp)[i] - funktion_x[i]) / h;
		}
	}
	return jacobiM;
};

void newtonverfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor)) //libro pagina 221
{

	int schritt = 0;
	CMyVektor funktion_x = funktion(x);
	CMyMatrix jacobi_x = jacobi(x, funktion);
	CMyMatrix jacobiInvers = jacobi_x.invers();
	double funktionLaenge = funktion_x.laenge();

	while (schritt != 50 && funktionLaenge >= 1e-5)
	{

		std::cout << "Schritt " << schritt << ":"
			<< "\n\t x = " << x
			<< "\n\t f(x) = " << funktion_x << "\n\t f'(x) = \n" << jacobi_x
			<< "\n\t (f'(x))^(-1) = \n" << jacobiInvers
			<< "\n\t dx = " << -1 * (jacobiInvers * funktion_x) //dx = -f(x) * 1/f'(x)
			<< "\n\t ||f(x)|| = " << funktionLaenge << std::endl << std::endl;

		x = x + -1 * (jacobiInvers * funktion_x);  //x(1) = x(0) + dx;

		schritt++;
		funktion_x = funktion(x);
		jacobi_x = jacobi(x, funktion);
		jacobiInvers = jacobi_x.invers();
		funktionLaenge = funktion_x.laenge();

		if (schritt == 50)
		{
			std::cout << "Ende wegen Schrittanzahl = 50 bei";
			std::cout << "\n\t x = " << x
				<< "\n\t f(x) = " << funktion_x
				<< "\n\t ||f(x) || = " << funktionLaenge << std::endl;
		}
		else if (funktionLaenge < 1e-5)
		{
			std::cout << "Ende wegen ||f(x)||<1e-5 bei";
			std::cout << "\n\t x = " << x
				<< "\n\t f(x) = " << funktion_x
				<< "\n\t ||f(x) || = " << funktionLaenge << std::endl;
		}
	}
};