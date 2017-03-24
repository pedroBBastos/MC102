#include <stdio.h>

int main()
{
	float d, h, a, b, c;
	float volumeTotalCilindro;

	scanf("%f %f %f %f %f", &d, &h, &a, &b, &c);

	// Vc = pi*r²*h
	volumeTotalCilindro = 3.14 * (d/2)*(d/2) * h; // calculo em metros cúbicos
	volumeTotalCilindro *= 1000; // conversão para litros (1m³ = 1000L)

	if(volumeTotalCilindro - a >= 0)
	{
		volumeTotalCilindro -= a;
		printf("posto A foi reabastecido\n");
	}
	else
		printf("posto A nao foi reabastecido\n");

	if(volumeTotalCilindro - b >= 0)
	{
		volumeTotalCilindro -= b;
		printf("posto B foi reabastecido\n");
	}
	else
		printf("posto B nao foi reabastecido\n");

	if(volumeTotalCilindro - c >= 0)
	{
		volumeTotalCilindro -= c;
		printf("posto C foi reabastecido\n");
	}
	else
		printf("posto C nao foi reabastecido\n");
}
