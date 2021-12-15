#include <stdbool.h>
#include <stdio.h>
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
				printf("%s", "Estos son los valores ");
				char temp22 = e1;
				printf("%c", temp22);
				printf("%s", " ");
				char temp23 = e2;
				printf("%c", temp23);
				}

				{
				char temp24 = e1;
				char temp25 = 'a';
				bool temp26 = temp24 == temp25;
				if (!temp26) goto etiqueta5;
				{
					{
					char temp27 = e1;
					printf("%c", temp27);
					}

				}
				goto etiqueta4;
etiqueta5: ;
				{
				char temp28 = e1;
				char temp29 = 'b';
				bool temp30 = temp28 == temp29;
				if (!temp30) goto etiqueta7;
				{
					{
					char temp31 = e2;
					printf("%c", temp31);
					}

				}
				goto etiqueta6;
etiqueta7: ;
				{
					{
					char temp32 = ' ';
					printf("%c", temp32);
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
			float temp33 = d1;
			float temp34 = 0.0;
			bool temp35 = temp33 > temp34;
			if (!temp35) goto etiqueta9;
			{
				int dato;
				{
				int temp36 = 2;
				dato = temp36;
				}

				{
				int temp37 = valor;
				int temp38 = 20;
				int temp39 = temp37 * temp38;
				int temp40 = dato;
				int temp41 = temp39 / temp40;
				dato = temp41;
				}

			}
			goto etiqueta8;
etiqueta9: ;
			{
				{
				int temp42 = valor;
				int temp43 = 100;
				int temp44 = temp42 * temp43;
				valor = temp44;
				}

				{
				float temp45 = d1;
				float temp46 = 1000.0;
				float temp47 = temp45 / temp46;
				d1 = temp47;
				}

			}
etiqueta8: ;
			}

			{
			char temp48 = 'd';

			char temp49 = 'e';

			procedimientoE(temp48, temp49);
			}

		}
		;

		{
		float temp50 = 0.1;

		procedimientoD(temp50);
		}

		{
		int temp51 = 1;
		x1 = temp51;
		}

		{
		int temp52 = 2;
		x2 = temp52;
		}

	}
	;

	{
	int temp53 = 1;

	float temp54 = 0.1;

	char temp55 = 'a';

	procedimientoA(temp53, temp54, temp55);
	}

	{
	int temp56 = 0;
	ve = temp56;
	}

}
