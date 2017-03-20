#include <stdio.h>

int main()
{
	float d, h; // a, b, c;
	float volumeTotalCilindro;
	float combustivelPosto [3];

	scanf("%f %f %f %f %f", &d, &h, &combustivelPosto[0], &combustivelPosto[1], &combustivelPosto[2]);

	// Vc = pi*r²*h
	volumeTotalCilindro = 3.14 * (d/2)*(d/2) * h; // calculo em metros cúbicos
	volumeTotalCilindro *= 1000; // conversão para litros (1m³ = 1000L)

	for (int i = 0; i < 3; i++)
	{
		if (volumeTotalCilindro - combustivelPosto[i] >= 0.00)
		{
			printf("posto %c foi abastecido\n", 65 + i);
			volumeTotalCilindro -= combustivelPosto[i];
		}
		else
			printf("posto %c nao foi abastecido\n", 65 + i);
	}
}
