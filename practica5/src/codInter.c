#include <stdbool.h>

int ve;
int ve2 = 2;
int ve3, ve4;
int ve5 = 2, ve6 = 5;
int ve7, ve8 = 2, ve9;
bool b1 = true, b2 = false, b4, b5;

int main()
{
	{
	int temp6 = 2;
	ve = temp6;
	}

	int temp7 = 5;
	if (!temp7) goto etiqueta1;
	{
		int vt;
		{
		int temp8 = 3;
		ve = temp8;
		}

	}
	goto etiqueta0;
etiqueta1: ;
	{
		int vr;
		{
		int temp9 = 4;
		vr = temp9;
		}

	}
etiqueta0: ;

	int temp10 = 0;
	ve = temp10;
etiqueta3: ;
	int temp11 = ve;
	int temp12 = 10;
	bool temp13 = temp11 <= temp12;
	if (!temp13) goto etiqueta2;
	{
	{
		{
		int temp15 = 3;
		ve2 = temp15;
		}

	}
	int temp14 = 1;
	ve += temp14;
	goto etiqueta3;
	}
etiqueta2: ;

	{
	bool temp16 = b1;
	bool temp17 = b2;
	bool temp18 = temp16 || temp17;
	b4 = temp18;
	}

	{
	bool temp19 = b1;
	bool temp20 = b4;
	bool temp21 = temp19 && temp20;
	b5 = temp21;
	}

	{
	bool temp22 = b1;
	bool temp23 = b2;
	bool temp24 = temp22 ^ temp23;
	b5 = temp24;
	}

	{
	bool temp25 = b1;
	bool temp26 = b2;
	bool temp27 = temp25 != temp26;
	b5 = temp27;
	}

	{
	bool temp28 = b1;
	bool temp29 = b2;
	bool temp30 = temp28 == temp29;
	b5 = temp30;
	}

	{
	int temp31 = ve2;
	int temp32 = ve5;
	float temp33 = temp31 / temp32;
	ve = temp33;
	}

	{
	int temp34 = ve2;
	int temp35 = ve5;
	int temp36 = temp34 * temp35;
	ve = temp36;
	}

}
