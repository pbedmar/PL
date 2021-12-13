#include <stdbool.h>
#include <stdio.h>
#include <math.h>

float n, d;

int main()
{
	printf("%s", "introduce numero : ");

	scanf("%f", &n); getchar();

	{
	float temp0 = 2.0;
	d = temp0;
	}

	printf("%s", "Numeros: ");
	float temp1 = n;
	float temp2 = d;
	float temp3 = temp1 * temp2;
	printf("%f", temp3);

}
