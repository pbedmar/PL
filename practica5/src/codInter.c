#include <stdbool.h>

int ve;
int ve2 = 2;
int ve3, ve4;
int ve5 = 2, ve6 = 5;
int ve7, ve8 = 2, ve9;

int main()
{
	{
	int temp4 = 2;
	ve = temp4;
	}

	int temp5 = 5;
	if (!temp5) goto etiqueta1;
	{
		int vt;
		{
		int temp6 = 3;
		ve = temp6;
		}

	}
	goto etiqueta0;
etiqueta1:
	{
		int vr;
		{
		int temp7 = 4;
		vr = temp7;
		}

	}
etiqueta0:

	int temp8 = 0;
	ve = temp8;
etiqueta3:
	int temp9 = ve;
	int temp10 = 10;
	bool temp11 = temp9 < temp10;
	if (!temp11) goto etiqueta2;
	{
	{
		{
		int temp13 = 3;
		ve2 = temp13;
		}

	}
	int temp12 = 1;
	ve += temp12;
	goto etiqueta3;
	}
etiqueta2:

}
