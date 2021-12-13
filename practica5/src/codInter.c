#include <stdbool.h>
#include <stdio.h>
#include "Lista.cpp"
#include <math.h>

int n, curr;
float f;
Lista<int> pe, pe2;
int tam;

int main(int argc, char* argv[])
{
	printf("%s", "introduce numero : ");

	scanf("%i", &n); getchar();

	printf("%s", " ");
	int temp0 = n;
	printf("%i", temp0);
	printf("%s", " == ");

	{
	int temp1 = 2;
	curr = temp1;
	}

etiqueta3: ;
	int temp2 = curr;
	int temp3 = n;
	bool temp4 = temp2 <= temp3;
	if (!temp4) goto etiqueta2;
	{
		int d;
		{
		int temp5 = n;
		int temp6 = curr;
		int temp7 = temp5 / temp6;
		d = temp7;
		}

		int temp8 = d;
		int temp9 = curr;
		int temp10 = temp8 * temp9;
		int temp11 = n;
		bool temp12 = temp10 == temp11;
		if (!temp12) goto etiqueta1;
		printf("%s", "* ");
		int temp13 = curr;
		printf("%i", temp13);
		printf("%s", " ");

		goto etiqueta0;
etiqueta1: ;
		{
			{
			int temp14 = curr;
			int temp15 = 1;
			int temp16 = temp14 + temp15;
			curr = temp16;
			}

		}
etiqueta0: ;

	}
	goto etiqueta3;
etiqueta2: ;
	printf("%s", "\n");

	{
	Lista<int> temp17 = pe;
	int temp18 = 6;
	int temp19 = 0;
	Lista<int> temp20 = temp17.insertarElementoLista(temp18,temp19);
	pe = temp20;
	}

	pe.comienzoLista();
	pe.avanzarLista();
	pe.avanzarLista();
	pe.retrocederLista();
	{
	Lista<int> temp21 = pe;
	temp21.tamLista();
	tam = temp21;
	}

}
