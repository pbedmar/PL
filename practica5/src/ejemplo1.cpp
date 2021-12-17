#include <stdbool.h>
#include <stdio.h>
#include "Lista.cpp"
#include <math.h>

int n, curr;
Lista<int> pe, pe2;
int tam, elem;

int main(int argc, char* argv[])
{
	{
	printf("%s", "introduce numero : ");
	}

	{
	scanf("%i", &n); getchar();

	}

	{
	printf("%s", " ");
	int temp0 = n;
	printf("%i", temp0);
	printf("%s", " == ");
	}

	{
	int temp1 = 2;
	curr = temp1;
	}

	{
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

		{
		int temp8 = d;
		int temp9 = curr;
		int temp10 = temp8 * temp9;
		int temp11 = n;
		bool temp12 = temp10 == temp11;
		if (!temp12) goto etiqueta1;
		{
			{
			printf("%s", " * ");
			int temp13 = curr;
			printf("%i", temp13);
			}

			{
			int temp14 = n;
			int temp15 = curr;
			int temp16 = temp14 / temp15;
			n = temp16;
			}

		}
		goto etiqueta0;
etiqueta1: ;
		{
			{
			int temp17 = curr;
			int temp18 = 1;
			int temp19 = temp17 + temp18;
			curr = temp19;
			}

		}
etiqueta0: ;
		}

	}
	goto etiqueta3;
etiqueta2: ;
	}

	{
	printf("%s", "\n");
	}

	{
	Lista<int> temp20 = pe;
	int temp21 = 6;
	int temp22 = (temp21);
	int temp23 = 0;
	int temp24 = (temp23);
	Lista<int> temp25 = temp20.insertarElementoLista(temp22,temp24);
	pe = temp25;
	}

	{
	Lista<int> temp26 = pe;
	int temp27 = 2;
	int temp28 = -temp27;
	int temp29 = (temp28);
	int temp30 = 0;
	int temp31 = (temp30);
	Lista<int> temp32 = temp26.insertarElementoLista(temp29,temp31);
	pe = temp32;
	}

	{
	Lista<int> temp33 = pe;
	int temp34 = 3;
	int temp35 = (temp34);
	int temp36 = 0;
	int temp37 = (temp36);
	Lista<int> temp38 = temp33.insertarElementoLista(temp35,temp37);
	pe = temp38;
	}

	{
	Lista<int> temp39 = pe;
	int temp40 = 7;
	int temp41 = (temp40);
	Lista<int> temp42 = pe;
	int temp43 = temp42.tamLista();
	int temp44 = (temp43);
	Lista<int> temp45 = temp39.insertarElementoLista(temp41,temp44);
	pe = temp45;
	}

	{
	Lista<int> temp46 = pe;
	cout << temp46.imprimirLista();
	printf("%s", "\n");
	}

	pe.comienzoLista();
	pe.avanzarLista();
	pe.avanzarLista();
	pe.retrocederLista();
	{
	Lista<int> temp47 = pe;
	int temp48 = temp47.tamLista();
	tam = temp48;
	}

	{
	Lista<int> temp49 = pe;
	int temp50 = temp49.obtenerElementoActual();
	elem = temp50;
	}

	{
	Lista<int> temp51 = pe;
	int temp52 = 1;
	int temp53 = temp51.obtenerElementoPosicion(temp52);
	elem = temp53;
	}

	{
	Lista<int> temp54 = pe;
	int temp55 = 1;
	Lista<int> temp56 = temp54.eliminarElementoPosicion(temp55);
	pe = temp56;
	}

	{
	Lista<int> temp57 = pe;
	Lista<int> temp58 = pe;
	int temp59 = temp58.tamLista();
	int temp60 = 1;
	int temp61 = temp59 - temp60;
	int temp62 = (temp61);
	Lista<int> temp63 = temp57.eliminarListaAPartirPosicion(temp62);
	pe = temp63;
	}

	{
	Lista<int> temp64 = pe2;
	int temp65 = 14;
	int temp66 = (temp65);
	int temp67 = 0;
	int temp68 = (temp67);
	Lista<int> temp69 = temp64.insertarElementoLista(temp66,temp68);
	pe2 = temp69;
	}

	{
	Lista<int> temp70 = pe2;
	Lista<int> temp71 = pe;
	Lista<int> temp72 = temp70.concatenarListas(temp71);
	pe2 = temp72;
	}

	{
	Lista<int> temp73 = pe;
	int temp74 = 3;
	Lista<int> temp75 = temp73.sumar(temp74);
	pe = temp75;
	}

	{
	Lista<int> temp77 = pe2;
	int temp76 = 4;
	Lista<int> temp78 = temp77.sumar(temp76);
	pe2 = temp78;
	}

	{
	Lista<int> temp79 = pe;
	int temp80 = 1;
	Lista<int> temp81 = temp79.restar(temp80);
	pe = temp81;
	}

	{
	Lista<int> temp82 = pe;
	int temp83 = 2;
	Lista<int> temp84 = temp82.multiplicar(temp83);
	pe = temp84;
	}

	{
	Lista<int> temp86 = pe2;
	int temp85 = 7;
	Lista<int> temp87 = temp86.multiplicar(temp85);
	pe2 = temp87;
	}

	{
	Lista<int> temp88 = pe2;
	int temp89 = 3;
	Lista<int> temp90 = temp88.dividir(temp89);
	pe2 = temp90;
	}

}
