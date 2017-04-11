#include <stdio.h>

/*
 * 	Este programa ter por objetivo computar a pontuação de cada round de uma luta entre Ken e Ryu,
 * sendo o vencedor da luta o lutador que vencer a maior quantidade de rounds ao final.
 * 	Como entrada, o programa recebe uma sequencia de inteiros, um em cada linha, que representam
 * os golpes aplicados por Ryu (que terao valores positivos) e os golpes aplicados por Ken (que terao
 * valores negativos). Um round terminara quando todos os valores negativos pararem de ser computados
 * e passarem a ser lidos valores positivos. Ao receber 0 como entrada, a luta termina.
 * 	Os golpes podem ser combos. Se o valor de um golpe for um numero perfeito, seu valor sera multiplicado
 * por 3. Se o valor de um golpe for triangular e não perfeito, se valor sera multiplicado por 2.
 *	Como saida, o programa indica quem foi o vencedor da luta.
 *
 * 	Nome : Pedro Barros Bastos   RA : 204481
 */

int main()
{
	int roundsRyu = 0, roundsKen = 0; // variaveis que controlam a quantidade de rounds vencidas por ambos lutadores
	int totalDanoRoundRyu = 0, totalDanoRoundKen = 0; // variaveis que armazenam a quantidade total de dano aplicado por
							  // round de cada lutador.
	int ehGolpeAplicado = 1; // variavel que controla de as entradas que estao sendo lidas sao golpes aplicados por Ryu ou por Ken

	for(;;)
	{
		int golpe;
		scanf("%d", &golpe); // leitura de um golpe

		if(golpe != 0) // se nao for o fim da luta
		{
			int somaInteiros = 0, somaDivisores = 0; // variaveis para verificacao de propriedades do valor recebido
								 // como entrada (se for perfeito e/ou triangular)
			int modulo = golpe > 0 ? golpe : -1*golpe; // modulo do valor recebido

			for(int i=1; i < modulo; i++) // loop para verificacao de propriedades mediantes soma de inteiros de
						      // 1 a modulo.
			{
				if(i <= modulo/2 && modulo % i == 0)
					somaDivisores += i;

				if(somaInteiros < modulo)
					somaInteiros += i;
			}

			if(somaDivisores == modulo) // se for um numero perfeito
				modulo = modulo*3;
			else
				if(somaInteiros == modulo) // se for um numero triangular
					modulo = modulo*2;

			if(golpe > 0)
			{
				if(!ehGolpeAplicado) //contabilização do round anterior
				{
					ehGolpeAplicado = 1;

					//atribuicao de marcador para quem venceu o round anterior
					if(totalDanoRoundRyu > totalDanoRoundKen)
						roundsRyu++;
					else
						if(totalDanoRoundRyu < totalDanoRoundKen) //a verificação do oposto eh necessaria
							roundsKen++;			  //pois o round pode ter empatado

					totalDanoRoundRyu = 0;
					totalDanoRoundKen = 0;
				}

				totalDanoRoundRyu += modulo; // somando valores dos golpes aplicados por Ryu
			}
			else
			{
				if(ehGolpeAplicado)
					ehGolpeAplicado = 0;

				totalDanoRoundKen += modulo; // somando valores dos golpes aplicados por Ken
			}
		}
		else
		{
			//fim da luta.
			//Contabilizacao dos pontos do ultimo round.

			if(totalDanoRoundRyu > totalDanoRoundKen)
				roundsRyu++;
			else
				roundsKen++;

			break;
		}
	}

	//Verificacao de quem ganhou a luta, a partir de quem ganhou mais rounds
	if(roundsRyu > roundsKen)
		printf("Ryu venceu\n");
	else
		if(roundsRyu < roundsKen)
			printf("Ken venceu\n");
		else
			printf("empatou\n");
}
