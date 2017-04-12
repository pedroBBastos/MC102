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
}

void desenhaTriangulo(int altura)
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
			int qtdCaracteresParaDesenho = 2*(i-2) + 1;
			int qtdEspacos = (larguraMoldura - 2) - qtdCaracteresParaDesenho;

			printf(".");

			for(int j=1; j <= qtdEspacos/2; j++)
				printf(" ");

			//desenhar os asteriscos aqui
			for(int k=1; k <= qtdCaracteresParaDesenho; k++)
				if(k % 2 != 0)
					printf("*");
				else
					printf(" ");

			for(int j=1; j <= qtdEspacos/2; j++)
				printf(" ");

			printf(".");
			printf("\n");
		}
}

void desenhaLosango(int altura)
{
	if(altura % 2 != 0)
	{
		int larguraMoldura = altura+4;
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
				int qtdCaracteresParaDesenho;
				if(i <= (altura/2)+2)
					//qtdCaracteresParaDesenho = 2*(i-2) + 1;
					qtdCaracteresParaDesenho = 2*i - 3;
				else
				{
					int distanciaCentroHorizontal = i - ((altura/2)+2);
					int linhaOpostaAoCentroHorizontal = i-2*distanciaCentroHorizontal;
					//qtdCaracteresParaDesenho = 2*(i-2*distanciaCentroHorizontal) - 3;
					qtdCaracteresParaDesenho = 2*linhaOpostaAoCentroHorizontal - 3;
				}

				int qtdEspacos = (larguraMoldura - 2) - qtdCaracteresParaDesenho;

				printf(".");

				for(int j=1; j <= qtdEspacos/2; j++)
					printf(" ");

				//desenhar os asteriscos aqui
				for(int k=1; k <= qtdCaracteresParaDesenho; k++)
					if(k % 2 != 0)
						printf("*");
					else
						printf(" ");

				for(int j=1; j <= qtdEspacos/2; j++)
					printf(" ");

				printf(".");
				printf("\n");
			}
	}
	else
		printf("entrada invalida\n");
}

int main()
{
	char figura;
	int h;

	scanf("%c %d", &figura, &h);

	if(h < 2)
		printf("entrada invalida\n");
	else
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
			default :
				printf("entrada invalida\n");
		}
}
