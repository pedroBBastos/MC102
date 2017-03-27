#include <stdio.h>

/*
 * Este programa tem por objetivo ajudar no controle de um estacionamento
 * para verificar se, dada a capacidade do estacionamento, determinado carro
 * consegue entrar neste estacionamento.
 *
 * A primeira entrada recebe um inteiro que indica a capacidade do estacionamento. As entradas seguintes,
 * tambem numeros inteiros, indicarao a entrada (inteiro positivo) ou a saida (inteiro negativo) de um veiculo.
 * Um carro que possuir tamanho maior que a capacidade atual do estacionamento nao podera entrar. Ao receber
 * como entrada 0, o computo da capacidade atual e a entrada e saida de carros terminara.
 *
 * Como saida, o programa indicara, para cada entrada recebida, se um carro entrou, não entrou ou saiu do estacionamento,
 * bem como a capacidade restante para cada fluxo.
 *
 * Nome : Pedro Barros Bastos  RA : 204481
 *
 */

int main()
{
	int capacidadeAtual; // variavel que controlara a capacidade atual do estacionamento conforme
			     // o fluxo de carros dentro do estacionamento. Antes da entrada de carros
			     // recebera a capacidade total do estacionamento (que estara vazio)

	int carSize; // variavel que armazenara o tamanho do carro positivo (entrando) ou negativo (saindo)
	scanf("%d", &capacidadeAtual);

	for(;;) // laco de repeticao ate receber 0 como entrada
	{
		scanf("%d", &carSize);

		if(carSize != 0)
		{
			if(carSize > 0) // carro entrando
			{
				if(carSize <= capacidadeAtual) // verificando se eh possivel do carro atual
							       // entrar no estacionamento
					printf("Seja bem-vindo! Capacidade restante: %d\n", capacidadeAtual -= carSize);
				else
					// tamanho do carro maior que a capacidade atual do estacionamento
					printf("Veiculo muito grande! Capacidade restante: %d\n", capacidadeAtual);
			}
			else
				//carro saindo do estacionamento
				printf("Volte sempre! Capacidade restante: %d\n", capacidadeAtual += -1*carSize);
		}
		else
			break;
	}
}
