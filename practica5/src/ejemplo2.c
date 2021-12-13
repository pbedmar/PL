#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int ini, fin, i;

int main()
{
	printf("%s", "introduce numero : ");

	scanf("%i", &ini); getchar();

	printf("%s", "introduce numero : ");

	scanf("%i", &fin); getchar();

	int temp0 = ini;
	i = temp0;
etiqueta1: ;
	int temp1 = i;
	int temp2 = fin;
	bool temp3 = temp1 <= temp2;
	if (!temp3) goto etiqueta0;
	{
	{
		int temp5 = i;
		int temp6 = 2;
		int temp7 = temp5 % temp6;
		int temp8 = 0;
		bool temp9 = temp7 == temp8;
		if (!temp9) goto etiqueta3;
		int temp10 = i;
		printf("%i", temp10);
		printf("%s", " es par\n");

		goto etiqueta2;
etiqueta3: ;
		int temp11 = i;
		printf("%i", temp11);
		printf("%s", " es impar\n");

etiqueta2: ;

	}
	int temp4 = 1;
	i += temp4;
	goto etiqueta1;
	}
etiqueta0: ;

}
