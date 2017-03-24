#include <stdio.h>

int main()
{
	int pesos [4];
	int soma = 0;
	int indiceMaisPesado = 0;

	scanf("%d %d %d %d", &pesos[0], &pesos[1], &pesos[2], &pesos[3]);

	for (int i = 0; i < 4; i++)
	{
		soma += pesos[i];

		if(pesos[i] > pesos[indiceMaisPesado])
			indiceMaisPesado = i;
	}

	if (soma % 2 == 0 && pesos[indiceMaisPesado] <= soma/2)
	{
		if (pesos[indiceMaisPesado] == soma/2)
		{
			printf("sim\n");
			return 0; //eh possivel
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (i != indiceMaisPesado)
				{
					if (pesos[indiceMaisPesado] + pesos[i] == soma/2)
					{
						printf("sim\n");
	                                        return 0;
					}
				}	
			}
			
			printf("nao\n");
			return 0; //naum eh possivel
		}
	}

	printf("nao\n");
	return 0; //naum eh possivel
}
