#include <stdbool.h>
#include <stdio.h>
#include "Lista.cpp"
#include <math.h>

int n, curr;
float f;
Lista<int> pe, pe2;
int tam, elem;

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

	{
	Lista<int> temp21 = pe;
	int temp22 = 2;
	int temp23 = -temp22;
	int temp24 = 0;
	Lista<int> temp25 = temp21.insertarElementoLista(temp23,temp24);
	pe = temp25;
	}

	{
	Lista<int> temp26 = pe;
	int temp27 = 3;
	int temp28 = 0;
	Lista<int> temp29 = temp26.insertarElementoLista(temp27,temp28);
	pe = temp29;
	}

	{
	Lista<int> temp30 = pe;
	int temp31 = 7;
	Lista<int> temp32 = pe;
	int temp33 = temp32.tamLista();
	Lista<int> temp34 = temp30.insertarElementoLista(temp31,temp33);
	pe = temp34;
	}

	pe.comienzoLista();
	pe.avanzarLista();
	pe.avanzarLista();
	pe.retrocederLista();
	{
	Lista<int> temp35 = pe;
	int temp36 = temp35.tamLista();
	tam = temp36;
	}

	{
	Lista<int> temp37 = pe;
	int temp38 = temp37.obtenerElementoActual();
	elem = temp38;
	}

	{
	Lista<int> temp39 = pe;
	int temp40 = 1;
	int temp41 = temp39.obtenerElementoPosicion(temp40);
	elem = temp41;
	}

	{
	Lista<int> temp42 = pe;
	int temp43 = 1;
	Lista<int> temp44 = temp42.eliminarElementoPosicion(temp43);
	pe = temp44;
	}

	{
	Lista<int> temp45 = pe;
	Lista<int> temp46 = pe;
	int temp47 = temp46.tamLista();
	int temp48 = 1;
	int temp49 = temp47 - temp48;
	Lista<int> temp50 = temp45.eliminarListaAPartirPosicion(temp49);
	pe = temp50;
	}

	{
	Lista<int> temp51 = pe2;
	int temp52 = 14;
	int temp53 = 0;
	Lista<int> temp54 = temp51.insertarElementoLista(temp52,temp53);
	pe2 = temp54;
	}

	{
	Lista<int> temp55 = pe2;
	Lista<int> temp56 = pe;
	Lista<int> temp57 = temp55.concatenarListas(temp56);
	pe2 = temp57;
	}

	{
	Lista<int> temp58 = pe;
	int temp59 = 3;
	Lista<int> temp60 = temp58.sumar(temp59);
	pe = temp60;
	}

	{
	Lista<int> temp62 = pe2;
	int temp61 = 4;
	Lista<int> temp63 = temp62.sumar(temp61);
	pe2 = temp63;
	}

	{
	Lista<int> temp64 = pe;
	int temp65 = 1;
	Lista<int> temp66 = temp64.restar(temp65);
	pe = temp66;
	}

	{
	Lista<int> temp67 = pe;
	int temp68 = 2;
	Lista<int> temp69 = temp67.multiplicar(temp68);
	pe = temp69;
	}

	{
	Lista<int> temp71 = pe2;
	int temp70 = 7;
	Lista<int> temp72 = temp71.multiplicar(temp70);
	pe2 = temp72;
	}

	{
	Lista<int> temp73 = pe2;
	int temp74 = 3;
	Lista<int> temp75 = temp73.dividir(temp74);
	pe2 = temp75;
	}

}
