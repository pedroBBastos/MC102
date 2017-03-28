#include <stdio.h>

/*
 * Este programa tem por objetivo verificar se uma nave podera escapar de um
 * ataque enquanto vê um vazamento de antimateria, tendo como parametros o tempo de duracao
 * de seu escudo e o fluxo de antimateria e combustivel.
 *
 * As duas primeiras linhas representam, respectivamente, o tempo de duracao do escudo e a
 * capacidade de combustivel necessaria para escapar. Na terceira linha eh representado
 * o fluxo de combustivel (valores positivos) e/ou antimateria (valores negativos) que a nave
 * recebera enquanto o escudo durar.
 *
 * Como saida, o programa indica de a nave escapou. Se escapou também indica em que instante de
 * tempo isso aconteceu
 *
 * Nome : Pedro Barros Bastos  RA : 204481
 */

int main()
{
	int t; // tempo de duracao do escudo
	int c; // capacidade de combustivel necessaria para a nave entrar em dobra (escapar)
	int fluxo; // variavel que recebe o fluxo de combustivel ou antimateria recebido a cada segundo
	int acumulado = 0; // variavel que armazena a quantidade atual de combustivel atraves do tempo

	scanf("%d %d", &t, &c); // leitura do tempo de duracao do escudo e da capacidade de combustivel necessaria

	int i;
	for(i = 1; i <= t; i++) // interando atraves do tempo de duracao do escudo
	{
		scanf("%d", &fluxo); // leitura do fluxo recebido no tempo atual e posterior atribuicao
		acumulado += fluxo;

		if(acumulado >= c) // se o acumulado for igual a quantidade necessaria para a nave entrar em dobra
				   // a nave podera escapar
		{
			printf("sim\n%d\n", i);
			return 0;
		}
	}

	// se a execução do programa chegar ate aqui a nave nao sera capaz de escapar
	printf("nao\n%d\n", t + 1);
	return 0;
}
