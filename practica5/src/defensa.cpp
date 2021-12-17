#include <stdbool.h>
#include <stdio.h>
#include "Lista.cpp"
#include <math.h>

int n;
Lista<int> le, le2, leFinal;

int main(int argc, char* argv[])
{
	auto calcularPrimos= [=] (int nPrimos)
	{
		int contPrimo = 0;
		int divisor;
		int primoActual = 2;
		bool esPrimo;
		auto insertarLista= [=] (int primoAInsertar)
		{
			auto imprimirLista= [=]  () 
			{
				{
				Lista<int> temp2 = le;
				cout << temp2.imprimirLista();
				printf("%s", "\n");
				}

			}
			;

			{
			Lista<int> temp3 = le;
			int temp4 = primoAInsertar;
			int temp5 = (temp4);
			Lista<int> temp6 = le;
			int temp7 = temp6.tamLista();
			int temp8 = (temp7);
			Lista<int> temp9 = temp3.insertarElementoLista(temp5,temp8);
			le = temp9;
			}

			{
			imprimirLista();
			}

		}
		;

		{
etiqueta7: ;
		int temp10 = contPrimo;
		int temp11 = nPrimos;
		bool temp12 = temp10 != temp11;
		if (!temp12) goto etiqueta6;
		{
			{
			int temp13 = 2;
			divisor = temp13;
			}

			{
			bool temp14 = true;
			esPrimo = temp14;
			}

			{
etiqueta3: ;
			int temp15 = divisor;
			int temp16 = primoActual;
			int temp17 = 2;
			int temp18 = temp16 / temp17;
			bool temp19 = temp15 <= temp18;
			bool temp20 = (temp19);
			bool temp21 = esPrimo;
			bool temp22 = temp20 && temp21;
			if (!temp22) goto etiqueta2;
			{
				{
				int temp23 = primoActual;
				int temp24 = divisor;
				int temp25 = temp23 % temp24;
				int temp26 = 0;
				bool temp27 = temp25 == temp26;
				if (!temp27) goto etiqueta1;
				{
					{
					bool temp28 = false;
					esPrimo = temp28;
					}

				}
etiqueta1: ;
				}

				{
				int temp29 = divisor;
				int temp30 = 1;
				int temp31 = temp29 + temp30;
				divisor = temp31;
				}

			}
			goto etiqueta3;
etiqueta2: ;
			}

			{
			bool temp32 = esPrimo;
			if (!temp32) goto etiqueta5;
			{
				{
				int temp33 = primoActual;

				insertarLista(temp33);
				}

				{
				int temp34 = contPrimo;
				int temp35 = 1;
				int temp36 = temp34 + temp35;
				contPrimo = temp36;
				}

			}
etiqueta5: ;
			}

			{
			int temp37 = primoActual;
			int temp38 = 1;
			int temp39 = temp37 + temp38;
			primoActual = temp39;
			}

		}
		goto etiqueta7;
etiqueta6: ;
		}

	}
	;

	{
	printf("%s", "introduce numero : >>");
	}

	{
	scanf("%i", &n); getchar();

	}

	{
	int temp40 = n;

	calcularPrimos(temp40);
	}

	{
	Lista<int> temp41 = le;
	int temp42 = 2;
	Lista<int> temp43 = temp41.multiplicar(temp42);
	le2 = temp43;
	}

	{
	Lista<int> temp44 = le2;
	cout << temp44.imprimirLista();
	printf("%s", "\n");
	}

	{
	Lista<int> temp45 = le;
	Lista<int> temp46 = le2;
	Lista<int> temp47 = temp45.concatenarListas(temp46);
	leFinal = temp47;
	}

	{
	Lista<int> temp48 = leFinal;
	cout << temp48.imprimirLista();
	printf("%s", "\n");
	}

}
