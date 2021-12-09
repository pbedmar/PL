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
	{
	int temp7 = 2;
	ve = temp7;
	}

	int temp8 = 5;
	if (!temp8) goto etiqueta1;
	{
		int vt;
		{
		int temp9 = 3;
		ve = temp9;
		}

	}
	goto etiqueta0;
etiqueta1: ;
	{
		int vr;
		{
		int temp10 = 4;
		vr = temp10;
		}

	}
etiqueta0: ;

	int temp11 = 0;
	ve = temp11;
etiqueta3: ;
	int temp12 = ve;
	int temp13 = 10;
	bool temp14 = temp12 <= temp13;
	if (!temp14) goto etiqueta2;
	{
	{
		{
		int temp16 = 3;
		ve2 = temp16;
		}

	}
	int temp15 = 1;
	ve += temp15;
	goto etiqueta3;
	}
etiqueta2: ;

	{
	bool temp17 = b1;
	bool temp18 = b2;
	bool temp19 = temp17 || temp18;
	b4 = temp19;
	}

	{
	bool temp20 = b1;
	bool temp21 = b4;
	bool temp22 = temp20 && temp21;
	b5 = temp22;
	}

	{
	bool temp23 = b1;
	bool temp24 = b2;
	bool temp25 = temp23 ^ temp24;
	b5 = temp25;
	}

	{
	bool temp26 = b1;
	bool temp27 = b2;
	bool temp28 = temp26 != temp27;
	b5 = temp28;
	}

	{
	bool temp29 = b1;
	bool temp30 = b2;
	bool temp31 = temp29 == temp30;
	b5 = temp31;
	}

	{
	int temp32 = ve2;
	int temp33 = ve5;
	float temp34 = temp32 / temp33;
	ve = temp34;
	}

	{
	int temp35 = ve2;
	int temp36 = ve5;
	int temp37 = temp35 * temp36;
	ve = temp37;
	}

	{
	int temp38 = ve2;
	int temp39 = ve5;
	int temp40 = temp38 + temp39;
	ve = temp40;
	}

	{
	int temp41 = ve2;
	int temp42 = ve5;
	int temp43 = temp41 - temp42;
	ve = temp43;
	}

	{
	int temp44 = ve2;
	int temp45 = --temp44;
	ve = temp45;
	}

	{
	int temp46 = ve2;
	int temp47 = ++temp46;
	ve = temp47;
	}

	{
	bool temp48 = b1;
	bool temp49 = !temp48;
	b5 = temp49;
	}

	{
	int temp50 = ve2;
	int temp51 = -temp50;
	ve = temp51;
	}

	{
	int temp52 = 2;
	int temp53 = 5;
	int temp54 = pow(temp52, temp53);
	ve = temp54;
	}

	{
	int temp55 = 0;
	ve = temp55;
	}

etiqueta5: ;
	int temp56 = ve;
	int temp57 = 5;
	bool temp58 = temp56 < temp57;
	if (!temp58) goto etiqueta4;
	{
		{
		int temp59 = ve;
		int temp60 = 1;
		int temp61 = temp59 + temp60;
		ve = temp61;
		}

	}
	goto etiqueta5;
etiqueta4: ;
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
