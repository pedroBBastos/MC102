#include <stdio.h>

/*
	Lab04

	Este programa tem por objetivo verificar se eh possivel fazer um balanceamento de
	carga perfeito para uma nave, tendo como entrada 4 valores representando respectivamente
	o peso de 4 cargas a serem perfeitamente equilibradas no bagageiro da nave. Ou seja, deve-se verificar
	se é possível, com as 4 cargas, colocar uma mesma quantidade de peso dos dois lados.

	Nome : Pedro Barros Bastos  RA : 204481

*/

int main()
{
	/*

		Variaveis de entrada
			# c1, c2, c3, c4 ->> representar o peso, em números inteiros,
					     de 4 cargas a se verificar seu possível balanceamento perfeito

	*/
	int c1, c2, c3, c4;

	/*
		# soma ->> soma dos pesos das 4 cargas fornecidas
	*/
	int soma = 0;


	scanf("%d %d %d %d", &c1, &c2, &c3, &c4); // leitura dos dados
	soma = c1 + c2 + c3 + c4; // calculo da soma


	/*
		Se a soma for impar já podemos dizer que eh impossivel
		dividir igualmente as 4 cargas.
	*/

	if (soma % 2 == 0)
	{
		/*
			Se a soma for par haverao apenas duas opçoes de destribuiçao das 4 cargas:
				A - uma carga tem o mesmo peso que a soma das outras 3
					ou
				B - duas cargas tem o mesmo peso que a soma das outras 2
		*/

		int metade = soma / 2;
		
		if (c1 == metade || c2 == metade || c3 == metade || c4 == metade) //testando a condiçao A
			printf("sim\n");
		else
		{
			/*
				Se chegar ate aqui só restaram estas possibilidades (condiçao B)

				a + b == c + d
				a + c == b + d
				a + d == b + c
			*/

			if (c1 + c2 == c3 + c4 ||
			    c1 + c3 == c2 + c4 ||
			    c1 + c4 == c2 + c3)
				printf("sim\n");
			else
				printf("nao\n");
		}
	}
	else
		printf("nao\n");
}
