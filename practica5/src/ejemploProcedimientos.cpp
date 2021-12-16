#include <stdbool.h>
#include <stdio.h>
#include "Lista.cpp"
#include <math.h>

int ve;
float vf;
char vc;
bool vl;

int main(int argc, char* argv[])
{
	auto procedimientoA= [=] (int a1, float a2, char a3)
	{
		int x1, x2;
		auto procedimientoB= [=] (char b1, bool b2)
		{
			float xf, x2;
			auto procedimientoC= [=] (bool c1, int c2)
			{
				float x1;
				{
				float temp0 = 1.3;
				x1 = temp0;
				}

				{
				int temp1 = c2;
				int temp2 = 10;
				bool temp3 = temp1 > temp2;
				if (!temp3) goto etiqueta1;
				{
				int temp4 = c2;
				int temp5 = 1;
				int temp6 = temp4 - temp5;
				c2 = temp6;
				}

				goto etiqueta0;
etiqueta1: ;
				{
				float temp7 = 3.1;
				x1 = temp7;
				}

etiqueta0: ;
				}

			}
			;

			{
			bool temp8 = true;

			int temp9 = 10;

			procedimientoC(temp8, temp9);
			}

			{
			bool temp10 = false;

			int temp11 = 1;

			procedimientoC(temp10, temp11);
			}

			{
			bool temp12 = true;

			int temp13 = 23;

			procedimientoC(temp12, temp13);
			}

			{
etiqueta3: ;
			float temp14 = x2;
			float temp15 = xf;
			float temp16 = temp14 - temp15;
			float temp17 = 10.0;
			bool temp18 = temp16 < temp17;
			if (!temp18) goto etiqueta2;
			{
			float temp19 = x2;
			float temp20 = xf;
			float temp21 = temp19 * temp20;
			x2 = temp21;
			}

			goto etiqueta3;
etiqueta2: ;
			}

		}
		;

		auto procedimientoD= [=] (float d1)
		{
			char dato;
			int valor;
			auto procedimientoE= [=] (char e1, char e2)
			{
				{
				printf("%s", "Introduzca dos caracteres: ");
				}

				{
				scanf("%c", &e1); getchar();
				scanf("%c", &e2); getchar();

				}

				{
				char temp22 = e1;
				char temp23 = 'a';
				bool temp24 = temp22 == temp23;
				if (!temp24) goto etiqueta5;
				{
					{
					char temp25 = e1;
					printf("%c", temp25);
					}

				}
				goto etiqueta4;
etiqueta5: ;
				{
				char temp26 = e1;
				char temp27 = 'b';
				bool temp28 = temp26 == temp27;
				if (!temp28) goto etiqueta7;
				{
					{
					char temp29 = e2;
					printf("%c", temp29);
					}

				}
				goto etiqueta6;
etiqueta7: ;
				{
					{
					char temp30 = ' ';
					printf("%c", temp30);
					}

				}
etiqueta6: ;
				}

etiqueta4: ;
				}

			}
			;

			{
			printf("%s", "Introduzca un valor: ");
			}

			{
			scanf("%i", &valor); getchar();

			}

			{
			float temp31 = d1;
			float temp32 = 0.0;
			bool temp33 = temp31 > temp32;
			if (!temp33) goto etiqueta9;
			{
				int dato;
				{
				int temp34 = 2;
				dato = temp34;
				}

				{
				int temp35 = valor;
				int temp36 = 20;
				int temp37 = temp35 * temp36;
				int temp38 = dato;
				int temp39 = temp37 / temp38;
				dato = temp39;
				}

			}
			goto etiqueta8;
etiqueta9: ;
			{
				{
				int temp40 = valor;
				int temp41 = 100;
				int temp42 = temp40 * temp41;
				valor = temp42;
				}

				{
				float temp43 = d1;
				float temp44 = 1000.0;
				float temp45 = temp43 / temp44;
				d1 = temp45;
				}

			}
etiqueta8: ;
			}

			{
			char temp46 = 'd';

			char temp47 = 'e';

			procedimientoE(temp46, temp47);
			}

		}
		;

		{
		float temp48 = 0.1;

		procedimientoD(temp48);
		}

		{
		int temp49 = 1;
		x1 = temp49;
		}

		{
		int temp50 = 2;
		x2 = temp50;
		}

	}
	;

	{
	int temp51 = 1;

	float temp52 = 0.1;

	char temp53 = 'a';

	procedimientoA(temp51, temp52, temp53);
	}

	{
	int temp54 = 0;
	ve = temp54;
	}

}
