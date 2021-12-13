#include <stdbool.h>
#include <stdio.h>
#include <math.h>

float n, d;

int main()
{
	printf("%s", "introduce numero : ");

	scanf("%f", &n);

	{
	int temp0 = 1;
	d = temp0;
	}

	printf("%s", "Numeros: ");

etiqueta1: ;
	float temp1 = d;
	float temp2 = n;
	bool temp3 = temp1 < temp2;
	if (!temp3) goto etiqueta0;
	{
		printf("%s", " ");
		printf("%f", " ");

		{
		float temp6 = d;
		float temp7 = 1.0;
		float temp8 = temp6 + temp7;
		d = temp8;
		}

	}
	goto etiqueta1;
etiqueta0: ;
}
