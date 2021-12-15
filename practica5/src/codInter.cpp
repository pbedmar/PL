#include <stdbool.h>
#include <stdio.h>
#include "Lista.cpp"
#include <math.h>

int n, curr;
Lista<int> pe, pe2;
Lista<float> pf;
Lista<char> pc;
Lista<bool> pb;
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
	int temp22 = 0;
	Lista<int> temp23 = temp20.insertarElementoLista(temp21,temp22);
	pe = temp23;
	}

	{
	Lista<int> temp24 = pe;
	int temp25 = 2;
	int temp26 = -temp25;
	int temp27 = 0;
	Lista<int> temp28 = temp24.insertarElementoLista(temp26,temp27);
	pe = temp28;
	}

	{
	Lista<int> temp29 = pe;
	int temp30 = 3;
	int temp31 = 0;
	Lista<int> temp32 = temp29.insertarElementoLista(temp30,temp31);
	pe = temp32;
	}

	{
	Lista<int> temp33 = pe;
	int temp34 = 7;
	Lista<int> temp35 = pe;
	int temp36 = temp35.tamLista();
	Lista<int> temp37 = temp33.insertarElementoLista(temp34,temp36);
	pe = temp37;
	}

	pe.comienzoLista();
	pe.avanzarLista();
	pe.avanzarLista();
	pe.retrocederLista();
	{
	Lista<int> temp38 = pe;
	int temp39 = temp38.tamLista();
	tam = temp39;
	}

	{
	Lista<int> temp40 = pe;
	int temp41 = temp40.obtenerElementoActual();
	elem = temp41;
	}

	{
	Lista<int> temp42 = pe;
	int temp43 = 1;
	int temp44 = temp42.obtenerElementoPosicion(temp43);
	elem = temp44;
	}

	{
	Lista<int> temp45 = pe;
	int temp46 = 1;
	Lista<int> temp47 = temp45.eliminarElementoPosicion(temp46);
	pe = temp47;
	}

	{
	Lista<int> temp48 = pe;
	Lista<int> temp49 = pe;
	int temp50 = temp49.tamLista();
	int temp51 = 1;
	int temp52 = temp50 - temp51;
	Lista<int> temp53 = temp48.eliminarListaAPartirPosicion(temp52);
	pe = temp53;
	}

	{
	Lista<int> temp54 = pe2;
	int temp55 = 14;
	int temp56 = 0;
	Lista<int> temp57 = temp54.insertarElementoLista(temp55,temp56);
	pe2 = temp57;
	}

	{
	Lista<int> temp58 = pe2;
	Lista<int> temp59 = pe;
	Lista<int> temp60 = temp58.concatenarListas(temp59);
	pe2 = temp60;
	}

	{
	Lista<int> temp61 = pe;
	int temp62 = 3;
	Lista<int> temp63 = temp61.sumar(temp62);
	pe = temp63;
	}

	{
	Lista<int> temp65 = pe2;
	int temp64 = 4;
	Lista<int> temp66 = temp65.sumar(temp64);
	pe2 = temp66;
	}

	{
	Lista<int> temp67 = pe;
	int temp68 = 1;
	Lista<int> temp69 = temp67.restar(temp68);
	pe = temp69;
	}

	{
	Lista<int> temp70 = pe;
	int temp71 = 2;
	Lista<int> temp72 = temp70.multiplicar(temp71);
	pe = temp72;
	}

	{
	Lista<int> temp74 = pe2;
	int temp73 = 7;
	Lista<int> temp75 = temp74.multiplicar(temp73);
	pe2 = temp75;
	}

	{
	Lista<int> temp76 = pe2;
	int temp77 = 3;
	Lista<int> temp78 = temp76.dividir(temp77);
	pe2 = temp78;
	}




	// Prueba para mostrar lista
	pf = pf.insertarElementoLista(3.1, 0);
	pf = pf.insertarElementoLista(1, 0);
	pf = pf.insertarElementoLista(4.6, 0);
	pf = pf.insertarElementoLista(-3, 0);
	pf = pf.insertarElementoLista(7, 0);
	cout << pf.imprimirLista() << endl;


	pb = pb.insertarElementoLista(true, 0);
	pb = pb.insertarElementoLista(true, 0);
	pb = pb.insertarElementoLista(false, 0);
	cout << pb.imprimirLista() << endl;


	pc = pc.insertarElementoLista('a', 0);
	pc = pc.insertarElementoLista('b', 0);
	pc = pc.insertarElementoLista('c', 0);
	cout << pc.imprimirLista() << endl;
}
