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
	pe = temp20;
	}

	{
	Lista<int> temp25 = pe;
	int temp26 = 2;
	int temp27 = -temp26;
	int temp28 = (temp27);
	int temp29 = 0;
	int temp30 = (temp29);
	Lista<int> temp31 = temp25.insertarElementoLista(temp28,temp30);
	pe = temp31;
	}

	{
	Lista<int> temp32 = pe;
	int temp33 = 3;
	int temp34 = (temp33);
	int temp35 = 0;
	int temp36 = (temp35);
	Lista<int> temp37 = temp32.insertarElementoLista(temp34,temp36);
	pe = temp37;
	}

	{
	Lista<int> temp38 = pe;
	int temp39 = 7;
	int temp40 = (temp39);
	Lista<int> temp41 = pe;
	int temp42 = temp41.tamLista();
	int temp43 = (temp42);
	Lista<int> temp44 = temp38.insertarElementoLista(temp40,temp43);
	pe = temp44;
	}

	{
	Lista<int> temp45 = pe;
	printf("%s", temp45.imprimirLista());
	printf("%s", "\n");
	}

	pe.comienzoLista();
	pe.avanzarLista();
	pe.avanzarLista();
	pe.retrocederLista();
	{
	Lista<int> temp46 = pe;
	int temp47 = temp46.tamLista();
	tam = temp47;
	}

	{
	Lista<int> temp48 = pe;
	int temp49 = temp48.obtenerElementoActual();
	elem = temp49;
	}

	{
	Lista<int> temp50 = pe;
	int temp51 = 1;
	int temp52 = temp50.obtenerElementoPosicion(temp51);
	elem = temp52;
	}

	{
	Lista<int> temp53 = pe;
	int temp54 = 1;
	Lista<int> temp55 = temp53.eliminarElementoPosicion(temp54);
	pe = temp55;
	}

	{
	Lista<int> temp56 = pe;
	Lista<int> temp57 = pe;
	int temp58 = temp57.tamLista();
	int temp59 = 1;
	int temp60 = temp58 - temp59;
	int temp61 = (temp60);
	Lista<int> temp62 = temp56.eliminarListaAPartirPosicion(temp61);
	pe = temp62;
	}

	{
	Lista<int> temp63 = pe2;
	int temp64 = 14;
	int temp65 = (temp64);
	int temp66 = 0;
	int temp67 = (temp66);
	Lista<int> temp68 = temp63.insertarElementoLista(temp65,temp67);
	pe2 = temp68;
	}

	{
	Lista<int> temp69 = pe2;
	Lista<int> temp70 = pe;
	Lista<int> temp71 = temp69.concatenarListas(temp70);
	pe2 = temp71;
	}

	{
	Lista<int> temp72 = pe;
	int temp73 = 3;
	Lista<int> temp74 = temp72.sumar(temp73);
	pe = temp74;
	}

	{
	Lista<int> temp76 = pe2;
	int temp75 = 4;
	Lista<int> temp77 = temp76.sumar(temp75);
	pe2 = temp77;
	}

	{
	Lista<int> temp78 = pe;
	int temp79 = 1;
	Lista<int> temp80 = temp78.restar(temp79);
	pe = temp80;
	}

	{
	Lista<int> temp81 = pe;
	int temp82 = 2;
	Lista<int> temp83 = temp81.multiplicar(temp82);
	pe = temp83;
	}

	{
	Lista<int> temp85 = pe2;
	int temp84 = 7;
	Lista<int> temp86 = temp85.multiplicar(temp84);
	pe2 = temp86;
	}

	{
	Lista<int> temp87 = pe2;
	int temp88 = 3;
	Lista<int> temp89 = temp87.dividir(temp88);
	pe2 = temp89;
	}

}
