#include <stdio.h>

void desenhaQuadrado(int altura)
{
	int larguraMoldura = (2*altura-1)+4;
	int alturaMoldura = altura+2;

	for(int i=1; i<=alturaMoldura; i++)
		if(i == 1 || i == alturaMoldura)
		{
			for(int j=1; j<=larguraMoldura; j++)
				printf(".");

			printf("\n");
		}
		else
		{
			for(int j=1; j<=larguraMoldura; j++)
			{
				if(j == 1 || j == larguraMoldura)
					printf(".");
				else
				{
					if(j % 2 == 0)
						printf(" ");
					else
						printf("*");
				}
			}

			printf("\n");
		}

	printf("\n");
}

void desenhaTriangulo(int altura)
{
	int larguraMoldura = (2*altura-1)+4;
	int alturaMoldura = altura+2;

	int centro = larguraMoldura / 2;
	int qtdAsteriscos = 1;

	for(int i=1; i<=alturaMoldura; i++)
		if(i == 1 || i == alturaMoldura)
		{
			for(int j=1; j<=larguraMoldura; j++)
				printf(".");

			printf("\n");
		}
		else
		{
			int qtdEspacos = larguraMoldura-2-qtdAsteriscos;

			for(int j=1; j<=qtdEspacos; j++)
				printf(" ");

			//desenhar os asteriscos aqui

			for(int j=1; j<=qtdEspacos; j++)
				printf(" ");

			printf("\n");
			qtdAsteriscos++;
		}

	printf("\n");
}

void desenhaLosango(int altura)
{
	if(altura % 2 != 0)
	{
	}
	else
		printf("entrada invalida\n");
}

int main()
{
	char figura;
	int h;

	scanf("%c %d", &figura, &h);

	switch(figura)
	{
		case 'Q':
			desenhaQuadrado(h);
			break;
		case 'q':
			desenhaQuadrado(h);
			break;
		case 'T':
			desenhaTriangulo(h);
			break;
		case 't':
			desenhaTriangulo(h);
			break;
		case 'L':
			desenhaLosango(h);
			break;
		case 'l':
			desenhaLosango(h);
			break;
	}
}
