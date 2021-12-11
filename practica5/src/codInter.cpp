#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int ve;
int ve2 = 2;
int ve3, ve4;
int ve5 = 2, ve6 = 5;
int ve7, ve8 = 2, ve9;
bool b1 = true, b2 = false, b4, b5;
char c1, c2 = 'h';
float fff = 3.3;

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
				float temp8 = 1.3;
				x1 = temp8;
				}

				int temp9 = c2;
				int temp10 = 10;
				bool temp11 = temp9 > temp10;
				if (!temp11) goto etiqueta1;
				{
				int temp12 = c2;
				int temp13 = 1;
				int temp14 = temp12 - temp13;
				c2 = temp14;
				}

				goto etiqueta0;
etiqueta1: ;
				{
				float temp15 = 3.1;
				x1 = temp15;
				}

etiqueta0: ;

			}
			;

			{
			bool temp16 = true;

			int temp17 = 10;

			procedimientoC(temp16, temp17);
			}

			{
			bool temp18 = false;

			int temp19 = 1;

			procedimientoC(temp18, temp19);
			}

			{
			bool temp20 = true;

			int temp21 = 23;

			procedimientoC(temp20, temp21);
			}

etiqueta3: ;
			float temp22 = x2;
			float temp23 = xf;
			float temp24 = temp22 - temp23;
			float temp25 = 10.0;
			bool temp26 = temp24 < temp25;
			if (!temp26) goto etiqueta2;
			{
			float temp27 = x2;
			float temp28 = xf;
			float temp29 = temp27 * temp28;
			x2 = temp29;
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
				printf("%s", "procedimientoE: ");
				printf("%c", e2);
				printf("%s", "\n");

			}
			;

			{
			char temp31 = 'b';

			char temp32 = c2;

			procedimientoE(temp31, temp32);
			}

			printf("%s", "procedimientoD. Inserta un entero: ");

			scanf("%f", &d1); getchar();

			printf("%s", "dato recibido: ");

			float temp33 = d1;
			float temp34 = 0.0;
			bool temp35 = temp33 > temp34;
			if (!temp35) goto etiqueta5;
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
				float temp41 = temp39 / temp40;
				dato = temp41;
				}

				printf("%s", "mayor que cero\n");

			}
			goto etiqueta4;
etiqueta5: ;
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

				printf("%s", "menor o igual que cero\n");

			}
etiqueta4: ;

		}
		;

		{
		char temp48 = 'd';

		bool temp49 = false;

		procedimientoB(temp48, temp49);
		}

		{
		char temp50 = 'd';

		bool temp51 = true;

		procedimientoB(temp50, temp51);
		}

		{
		float temp52 = 3.8;

		procedimientoD(temp52);
		}

		{
		int temp53 = 1;
		x1 = temp53;
		}

		{
		int temp54 = 2;
		x2 = temp54;
		}

	}
	;

	{
	int temp55 = ve2;

	float temp56 = fff;

	char temp57 = c2;

	procedimientoA(temp55, temp56, temp57);
	}

	{
	int temp58 = 2;
	ve = temp58;
	}

	int temp59 = 5;
	if (!temp59) goto etiqueta7;
	{
		int vt;
		{
		int temp60 = 3;
		ve = temp60;
		}

	}
	goto etiqueta6;
etiqueta7: ;
	{
		int vr;
		{
		int temp61 = 4;
		vr = temp61;
		}

	}
etiqueta6: ;

	int temp62 = 0;
	ve = temp62;
etiqueta9: ;
	int temp63 = ve;
	int temp64 = 10;
	bool temp65 = temp63 <= temp64;
	if (!temp65) goto etiqueta8;
	{
	{
		{
		int temp67 = 3;
		ve2 = temp67;
		}

	}
	int temp66 = 1;
	ve += temp66;
	goto etiqueta9;
	}
etiqueta8: ;

	{
	bool temp68 = b1;
	bool temp69 = b2;
	bool temp70 = temp68 || temp69;
	b4 = temp70;
	}

	{
	bool temp71 = b1;
	bool temp72 = b4;
	bool temp73 = temp71 && temp72;
	b5 = temp73;
	}

	{
	bool temp74 = b1;
	bool temp75 = b2;
	bool temp76 = temp74 ^ temp75;
	b5 = temp76;
	}

	{
	bool temp77 = b1;
	bool temp78 = b2;
	bool temp79 = temp77 != temp78;
	b5 = temp79;
	}

	{
	bool temp80 = b1;
	bool temp81 = b2;
	bool temp82 = temp80 == temp81;
	b5 = temp82;
	}

	{
	int temp83 = ve2;
	int temp84 = ve5;
	float temp85 = temp83 / temp84;
	ve = temp85;
	}

	{
	int temp86 = ve2;
	int temp87 = ve5;
	int temp88 = temp86 * temp87;
	ve = temp88;
	}

	{
	int temp89 = ve2;
	int temp90 = ve5;
	int temp91 = temp89 + temp90;
	ve = temp91;
	}

	{
	int temp92 = ve2;
	int temp93 = ve5;
	int temp94 = temp92 - temp93;
	ve = temp94;
	}

	{
	int temp95 = ve2;
	int temp96 = --temp95;
	ve = temp96;
	}

	{
	int temp97 = ve2;
	int temp98 = ++temp97;
	ve = temp98;
	}

	{
	bool temp99 = b1;
	bool temp100 = !temp99;
	b5 = temp100;
	}

	{
	int temp101 = ve2;
	int temp102 = -temp101;
	ve = temp102;
	}

	{
	int temp103 = 2;
	int temp104 = 5;
	int temp105 = pow(temp103, temp104);
	ve = temp105;
	}

	{
	int temp106 = 0;
	ve = temp106;
	}

etiqueta11: ;
	int temp107 = ve;
	int temp108 = 5;
	bool temp109 = temp107 < temp108;
	if (!temp109) goto etiqueta10;
	{
		{
		int temp110 = ve;
		int temp111 = 1;
		int temp112 = temp110 + temp111;
		ve = temp112;
		}

	}
	goto etiqueta11;
etiqueta10: ;
	printf("%s", "Inserta dos caracteres: ");

	scanf("%c", &c1); getchar();
	scanf("%c", &c2);

	printf("%s", "\n");

	printf("%i", ve);
	printf("%s", " ");
	printf("%c", c2);
	printf("%s", " ");
	printf("%i", b2);
	printf("%s", "\n");

}
