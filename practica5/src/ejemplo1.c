#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int n, d;

int main(int argc, char* argv[])
{
	printf("%s", "introduce numero : ");

	scanf("%i", &n); getchar();

	printf("%s", " ");
	int temp0 = n;
	printf("%i", temp0);
	printf("%s", " == ");

	{
	int temp1 = 1;
	d = temp1;
	}

etiqueta3: ;
	int temp2 = d;
	int temp3 = n;
	bool temp4 = temp2 <= temp3;
	if (!temp4) goto etiqueta2;
	{
		int aux;
		{
		int temp5 = n;
		int temp6 = d;
		int temp7 = temp5 % temp6;
		aux = temp7;
		}

		int temp8 = aux;
		int temp9 = 0;
		bool temp10 = temp8 == temp9;
		if (!temp10) goto etiqueta1;
		printf("%s", "* ");
		int temp11 = d;
		printf("%i", temp11);
		printf("%s", " ");

etiqueta1: ;

		{
		int temp12 = d;
		int temp13 = 1;
		int temp14 = temp12 + temp13;
		d = temp14;
		}

	}
	goto etiqueta3;
etiqueta2: ;
	printf("%s", "\n");

}
