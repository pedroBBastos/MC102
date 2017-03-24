#include <stdio.h>

/*
	Lab03

		Este programa tem por objetivo verificar se com determinado tanque de forma cilindrica
	totalmente preechido de combustivel eh possivel reabastecer 3 diferentes postos com diferentes demandas de
	combustivel cada um. O caminhao que contera este tanque fara um trajeto fixo do primeiro ao ultimo posto.
		Como entrada são esperados os valores de diametro e comprimento do tanque, bem como as tres demandas
	dos tres postos.
		A saida indicara se cada um dos tres postos foi reabastecido. Se a demanda de determinado posto for
	maior que o volume corrente do tanque, este posto nao sera reabastecido

	Nome : Pedro Barros Bastos  RA : 204481
*/

int main()
{
	/*
		- Variaveis de entrada
			# d -> diametro do tanque, dado em metros
	'		# h -> comprimento do tanque, dados em metros
			# demandasPostos -> vetor de tres posiçoes que armazenara as demandas de tres postos (A, B e C)
	*/
	float d, h;
	float demandasPostos [3];

	/*
		# volumeCombustivelTotal -> variavel de controle do volume de combustivel contido no tanque.
					 No inicio, como o tanque estara completamente cheio, sera dado
					 pelo volume do tanque.
	*/
	float volumeCombustivelTotal;

	scanf("%f %f %f %f %f", &d, &h, &demandasPostos[0], &demandasPostos[1], &demandasPostos[2]); //leitura da entrada

	// Tendo o tanque formato cilindrico, seu volume eh dado por Vc = pi*r²*h
	volumeCombustivelTotal = 3.14 * (d/2)*(d/2) * h; // calculo do volume do tanque em metros cúbicos
	volumeCombustivelTotal *= 1000; // conversão para litros (1m³ = 1000L)

	//interando sobre os tres postos
	for (int i = 0; i < 3; i++)
	{
		/*
				se o volume de combustivel contido atualmente no tanque supre a necessidade do posto atual
			pode-se dizer que determinado posto foi reabastecido. Depois deve-se atualizar o volume
			de combustivel contido no tanque.
				se não, diz-se que o posto atual não foi reabastecido.
		*/
		if (volumeCombustivelTotal - demandasPostos[i] >= 0.00)
		{
			printf("posto %c foi reabastecido\n", 65 + i);
			volumeCombustivelTotal -= demandasPostos[i];
		}
		else
			printf("posto %c nao foi reabastecido\n", 65 + i);
	}
}
