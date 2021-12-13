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
			auto procedimientoE= [=]  (char e1, char e2 = 'x', char e3 = 'y') 
			{
				printf("%s", "procedimientoE: ");
				printf("%c", e2);
				printf("%s", "\n");

			}
			;

			{
			char temp31 = 'b';

			procedimientoE(temp31);
			}

			printf("%s", "procedimientoD. Inserta un entero: ");

			scanf("%f", &d1); getchar();

			printf("%s", "dato recibido: ");

			float temp32 = d1;
			float temp33 = 0.0;
			bool temp34 = temp32 > temp33;
			if (!temp34) goto etiqueta5;
			{
				int dato;
				{
				int temp35 = 2;
				dato = temp35;
				}

				{
				int temp36 = valor;
				int temp37 = 20;
				int temp38 = temp36 * temp37;
				int temp39 = dato;
				float temp40 = temp38 / temp39;
				dato = temp40;
				}

				printf("%s", "mayor que cero\n");

			}
			goto etiqueta4;
etiqueta5: ;
			{
				{
				int temp41 = valor;
				int temp42 = 100;
				int temp43 = temp41 * temp42;
				valor = temp43;
				}

				{
				float temp44 = d1;
				float temp45 = 1000.0;
				float temp46 = temp44 / temp45;
				d1 = temp46;
				}

				printf("%s", "menor o igual que cero\n");

			}
etiqueta4: ;

		}
		;

		{
		char temp47 = 'd';

		bool temp48 = false;

		procedimientoB(temp47, temp48);
		}

		{
		char temp49 = 'd';

		bool temp50 = true;

		procedimientoB(temp49, temp50);
		}

		{
		float temp51 = 3.8;

		procedimientoD(temp51);
		}

		{
		int temp52 = 1;
		x1 = temp52;
		}

		{
		int temp53 = 2;
		x2 = temp53;
		}

	}
	;

	{
	int temp54 = ve2;

	float temp55 = fff;

	char temp56 = c2;

	procedimientoA(temp54, temp55, temp56);
	}

	{
	int temp57 = 2;
	ve = temp57;
	}

	int temp58 = 5;
	if (!temp58) goto etiqueta7;
	{
		int vt;
		{
		int temp59 = 3;
		ve = temp59;
		}

	}
	goto etiqueta6;
etiqueta7: ;
	{
		int vr;
		{
		int temp60 = 4;
		vr = temp60;
		}

	}
etiqueta6: ;

	int temp61 = 0;
	ve = temp61;
etiqueta9: ;
	int temp62 = ve;
	int temp63 = 10;
	bool temp64 = temp62 <= temp63;
	if (!temp64) goto etiqueta8;
	{
	{
		{
		int temp66 = 3;
		ve2 = temp66;
		}

	}
	int temp65 = 1;
	ve += temp65;
	goto etiqueta9;
	}
etiqueta8: ;

	{
	bool temp67 = b1;
	bool temp68 = b2;
	bool temp69 = temp67 || temp68;
	b4 = temp69;
	}

	{
	bool temp70 = b1;
	bool temp71 = b4;
	bool temp72 = temp70 && temp71;
	b5 = temp72;
	}

	{
	bool temp73 = b1;
	bool temp74 = b2;
	bool temp75 = temp73 ^ temp74;
	b5 = temp75;
	}

	{
	bool temp76 = b1;
	bool temp77 = b2;
	bool temp78 = temp76 != temp77;
	b5 = temp78;
	}

	{
	bool temp79 = b1;
	bool temp80 = b2;
	bool temp81 = temp79 == temp80;
	b5 = temp81;
	}

	{
	int temp82 = ve2;
	int temp83 = ve5;
	float temp84 = temp82 / temp83;
	ve = temp84;
	}

	{
	int temp85 = ve2;
	int temp86 = ve5;
	int temp87 = temp85 * temp86;
	ve = temp87;
	}

	{
	int temp88 = ve2;
	int temp89 = ve5;
	int temp90 = temp88 + temp89;
	ve = temp90;
	}

	{
	int temp91 = ve2;
	int temp92 = ve5;
	int temp93 = temp91 - temp92;
	ve = temp93;
	}

	{
	int temp94 = ve2;
	int temp95 = --temp94;
	ve = temp95;
	}

	{
	int temp96 = ve2;
	int temp97 = ++temp96;
	ve = temp97;
	}

	{
	bool temp98 = b1;
	bool temp99 = !temp98;
	b5 = temp99;
	}

	{
	int temp100 = ve2;
	int temp101 = -temp100;
	ve = temp101;
	}

	{
	int temp102 = 2;
	int temp103 = 5;
	int temp104 = pow(temp102, temp103);
	ve = temp104;
	}

	{
	int temp105 = 0;
	ve = temp105;
	}

etiqueta11: ;
	int temp106 = ve;
	int temp107 = 5;
	bool temp108 = temp106 < temp107;
	if (!temp108) goto etiqueta10;
	{
		{
		int temp109 = ve;
		int temp110 = 1;
		int temp111 = temp109 + temp110;
		ve = temp111;
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
