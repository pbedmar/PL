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
		;

		auto procedimientoD= [=] (float d1)
		{
			char dato;
			int valor;
			auto procedimientoE= [=] (char e1, char e2)
			{
				scanf("%c", &e1); getchar();
				scanf("%c", &e2);

			}
			;

			scanf("%i", &valor); getchar();

			float temp22 = d1;
			float temp23 = 0.0;
			bool temp24 = temp22 > temp23;
			if (!temp24) goto etiqueta5;
			{
				int dato;
				{
				int temp25 = 2;
				dato = temp25;
				}

				{
				int temp26 = valor;
				int temp27 = 20;
				int temp28 = temp26 * temp27;
				int temp29 = dato;
				int temp30 = temp28 / temp29;
				dato = temp30;
				}

			}
			goto etiqueta4;
etiqueta5: ;
			{
				{
				int temp31 = valor;
				int temp32 = 100;
				int temp33 = temp31 * temp32;
				valor = temp33;
				}

				{
				float temp34 = d1;
				float temp35 = 1000.0;
				float temp36 = temp34 / temp35;
				d1 = temp36;
				}

			}
etiqueta4: ;

		}
		;

		{
		int temp37 = 1;
		x1 = temp37;
		}

		{
		int temp38 = 2;
		x2 = temp38;
		}

	}
	;

	{
	int temp39 = 0;
	ve = temp39;
	}

}
