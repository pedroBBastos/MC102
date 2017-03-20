#include <stdio.h>

int main()
{
	int pesos [4];
	int soma = 0;	
	int* maisPesado = &soma;

	scanf("%d %d %d %d", &pesos[0], &pesos[1], &pesos[2], &pesos[3]);

	for (int i = 0; i < 4; i++)
	{
		if(pesos[i] > *maisPesado)
			maisPesado = &pesos[i];

		soma += pesos[i];
	}


	if (soma % 2 == 0 && *maisPesado <= soma/2)
	{
		if(*maisPesado == soma/2)
		{
			printf("sim\n");
			return 0; //eh possivel
		}
		else
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					if (&pesos[i] == maisPesado && i != j && *maisPesado + pesos[j] == soma/2)
					{
						//eh possivel
						printf("sim\n");
						return 0;
					}
				}
			
			printf("nao\n");
			return 0; //naum eh possivel
		}
	}

	printf("nao\n");
	return 0; //naum eh possivel
}
