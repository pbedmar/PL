#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int ve;
int ve2 = 2;
int ve3, ve4;
int ve5 = 2, ve6 = 5;
int ve7, ve8 = 2, ve9;
bool b1 = true, b2 = false, b4, b5;
char c1;

int main()
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
				float temp6 = 1.3;
				x1 = temp6;
				}

				int temp7 = c2;
				int temp8 = 10;
				bool temp9 = temp7 > temp8;
				if (!temp9) goto etiqueta1;
				{
				int temp10 = c2;
				int temp11 = 1;
				int temp12 = temp10 - temp11;
				c2 = temp12;
				}

				goto etiqueta0;
etiqueta1: ;
				{
				float temp13 = 3.1;
				x1 = temp13;
				}

etiqueta0: ;

			}
			;

			{
			bool temp14 = true;

			int temp15 = 10;

			procedimientoC(temp14, temp15);
			}

			{
			bool temp16 = false;

			int temp17 = 1;

			procedimientoC(temp16, temp17);
			}

			{
			bool temp18 = true;

			int temp19 = 23;

			procedimientoC(temp18, temp19);
			}

etiqueta3: ;
			float temp20 = x2;
			float temp21 = xf;
			float temp22 = temp20 - temp21;
			float temp23 = 10.0;
			bool temp24 = temp22 < temp23;
			if (!temp24) goto etiqueta2;
			{
			float temp25 = x2;
			float temp26 = xf;
			float temp27 = temp25 * temp26;
			x2 = temp27;
			}

			goto etiqueta3;
etiqueta2: ;
		}
		;

		auto procedimientoD= [=] (float d1)
		{
			char dato;
			int valor;
			scanf("%i", &valor);

			float temp28 = d1;
			float temp29 = 0.0;
			bool temp30 = temp28 > temp29;
			if (!temp30) goto etiqueta5;
			{
				int dato;
				{
				int temp31 = 2;
				dato = temp31;
				}

				{
				int temp32 = valor;
				int temp33 = 20;
				int temp34 = temp32 * temp33;
				int temp35 = dato;
				float temp36 = temp34 / temp35;
				dato = temp36;
				}

			}
			goto etiqueta4;
etiqueta5: ;
			{
				{
				int temp37 = valor;
				int temp38 = 100;
				int temp39 = temp37 * temp38;
				valor = temp39;
				}

				{
				float temp40 = d1;
				float temp41 = 1000.0;
				float temp42 = temp40 / temp41;
				d1 = temp42;
				}

			}
etiqueta4: ;

		}
		;

		{
		char temp43 = 'd';

		bool temp44 = false;

		procedimientoB(temp43, temp44);
		}

		{
		float temp45 = 3.8;

		procedimientoD(temp45);
		}

		{
		int temp46 = 1;
		x1 = temp46;
		}

		{
		int temp47 = 2;
		x2 = temp47;
		}

	}
	;

	{
	int temp48 = 2;
	ve = temp48;
	}

	int temp49 = 5;
	if (!temp49) goto etiqueta7;
	{
		int vt;
		{
		int temp50 = 3;
		ve = temp50;
		}

	}
	goto etiqueta6;
etiqueta7: ;
	{
		int vr;
		{
		int temp51 = 4;
		vr = temp51;
		}

	}
etiqueta6: ;

	int temp52 = 0;
	ve = temp52;
etiqueta9: ;
	int temp53 = ve;
	int temp54 = 10;
	bool temp55 = temp53 <= temp54;
	if (!temp55) goto etiqueta8;
	{
	{
		{
		int temp57 = 3;
		ve2 = temp57;
		}

	}
	int temp56 = 1;
	ve += temp56;
	goto etiqueta9;
	}
etiqueta8: ;

	{
	bool temp58 = b1;
	bool temp59 = b2;
	bool temp60 = temp58 || temp59;
	b4 = temp60;
	}

	{
	bool temp61 = b1;
	bool temp62 = b4;
	bool temp63 = temp61 && temp62;
	b5 = temp63;
	}

	{
	bool temp64 = b1;
	bool temp65 = b2;
	bool temp66 = temp64 ^ temp65;
	b5 = temp66;
	}

	{
	bool temp67 = b1;
	bool temp68 = b2;
	bool temp69 = temp67 != temp68;
	b5 = temp69;
	}

	{
	bool temp70 = b1;
	bool temp71 = b2;
	bool temp72 = temp70 == temp71;
	b5 = temp72;
	}

	{
	int temp73 = ve2;
	int temp74 = ve5;
	float temp75 = temp73 / temp74;
	ve = temp75;
	}

	{
	int temp76 = ve2;
	int temp77 = ve5;
	int temp78 = temp76 * temp77;
	ve = temp78;
	}

	{
	int temp79 = ve2;
	int temp80 = ve5;
	int temp81 = temp79 + temp80;
	ve = temp81;
	}

	{
	int temp82 = ve2;
	int temp83 = ve5;
	int temp84 = temp82 - temp83;
	ve = temp84;
	}

	{
	int temp85 = ve2;
	int temp86 = --temp85;
	ve = temp86;
	}

	{
	int temp87 = ve2;
	int temp88 = ++temp87;
	ve = temp88;
	}

	{
	bool temp89 = b1;
	bool temp90 = !temp89;
	b5 = temp90;
	}

	{
	int temp91 = ve2;
	int temp92 = -temp91;
	ve = temp92;
	}

	{
	int temp93 = 2;
	int temp94 = 5;
	int temp95 = pow(temp93, temp94);
	ve = temp95;
	}

	{
	int temp96 = 0;
	ve = temp96;
	}

etiqueta11: ;
	int temp97 = ve;
	int temp98 = 5;
	bool temp99 = temp97 < temp98;
	if (!temp99) goto etiqueta10;
	{
		{
		int temp100 = ve;
		int temp101 = 1;
		int temp102 = temp100 + temp101;
		ve = temp102;
		}

	}
	goto etiqueta11;
etiqueta10: ;
	printf("%s", "Inserta un caracter: ");

	scanf("%c", &c1);

	printf("%s", "Hola\n");

	printf("%i", ve);
	printf("%s", " ");
	printf("%c", c1);
	printf("%s", " ");
	printf("%i", b1);
	printf("%s", "\n");

}
