#include "C_DGLSolver.h"
#include "CMyVektor.h"
#include <iostream>


CMyVektor F(CMyVektor y, double x)
{
	CMyVektor V2(2);

	V2.set_wert(0,(2 * y.get_wert(1)) - (x * y.get_wert(0)));
	V2.set_wert(1,(y.get_wert(0) * y.get_wert(1)) - (2 * pow(x, 3)));

	return V2;
}

double G(CMyVektor y, double x)
{
	double result;

	result =(2 * x*y.get_wert(1)*y.get_wert(2)) + (2 * pow(y.get_wert(0), 2)*y.get_wert(1));

	return result;

}

int menu()
{
	int auswahl = 0;

		std::cout << "Hallo, herzlich Willkommen zum interaktiven Abfrageprogramm fuer Praktikum 3 \n \n" << std::endl;
		std::cout << "An dieser Stelle bieten sich Ihnen folgende Moeglichkeiten: \n" << std::endl;
		std::cout << "\t Fuer das die Anwendung des Eulerverfahrens auf einen DGL-System 1. Ordung \n \t mit der Genauigkeit von 100 Schritten waehlen Sie bitte die: \t \t  \t \t 1 \n" << std::endl;
		std::cout << "\t Fuer das die Anwendung des Heunverfahrens auf einen DGL-System 1. Ordung \n \t mit der Genauigkeit von 100 Schritten waehlen Sie bitte die: \t \t  \t \t 2 \n" << std::endl;
		std::cout << "\t Fuer die Anwendung des Euler- und des Heunverfahrens auf ein DGL hoeherer Ordnung \n \t  mit der Genauigkeit von 10, 100, 1000, und 10000 Schritten waehlen Sie bitte die: \t 3 \n" << std::endl;
		//std::cout << << std::endl;

		std::cout << "Bitte sagen Sie mir nun was Sie machen moechten, geben Sie hierfuer die Nummer hinter Ihrer Wahl ein: ";
			std::cin >> auswahl;

		while(auswahl < 1 || auswahl > 3)
		{
			std::cout << "Ich konnte Ihre Eingabe leider nicht erkennen, bitte versuchen Sie es nochmal: ";
			std::cin >> auswahl;
		}
		return auswahl;
}

int main()
{
	
	double XENDE = 2;
	int schritte = 100;

	CMyVektor V1(2);

	V1.set_wert(0, 0);
	V1.set_wert(1, 1);

	CMyVektor V2(3);

	V2.set_wert(0, 1);
	V2.set_wert(1, (-1));
	V2.set_wert(2, 2);

	bool again = true;

	while (again)
	{

		switch (menu())
		{
		case 1:
		{
			C_DGLSolver SolveF(F);
			SolveF.C_DGLSolver_Euler(0, 2, 100, V1);
			break;
		}
		case 2:
		{
			C_DGLSolver SolveF(F);
			SolveF.C_DGLSolver_Heun(0, 2, 100, V1);
			break;
		}

		case 3:
		{
			CMyVektor V11(V2.get_dimension());
			CMyVektor V21(V2.get_dimension());
			
			C_DGLSolver SolveG(G);
			for (int i = 10; i <= 10000; i *= 10)
			{
				V11 = SolveG.C_DGLSolver_Euler(1, 2, i, V2);

				std::cout << std::setprecision(7) << "Abweichung bei Euler bei " << i << " Schritten: " << V11.get_wert(0)-0.5 << std::endl;

				V21 = SolveG.C_DGLSolver_Heun(1, 2, i, V2);

				std::cout << std::setprecision(7) << "Abweichung bei Heun bei " << i << " Schritten: " << V21.get_wert(0)-0.5 << std::endl;
			}
			
			break;
		}
		default:
			break;
		}

		int auswahl = 0;

		std::cout << "Moechten Sie noch eine andere Option ausprobieren ? (1 fuer Ja, 0 fuer Nein): ";
		std::cin >> auswahl;
		
			if (auswahl == 1)
			{
				again = true;
			}
			else
			{
				again = false;
			}



	}

	std::cout << "\n \n GoodBye" << std::endl;
	//C_DGLSolver Solve(G);

	//Solve.C_DGLSolver_Euler(0, 2, 100, V1);

	//Solve.C_DGLSolver_Euler(1, 2, 10, V2);

	//Solve.C_DGLSolver_Heun(0, 2, 100, V1);

	//Solve.C_DGLSolver_Heun(1, 2, 100, V2);

	system("PAUSE");

	return 0;
}