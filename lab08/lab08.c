#include <stdio.h>

/*
		Este programa tem por objetivo desenhar figuras geométricas simétricas tendo como base
	a altura dada na entrada. O programa consegue desenhar quadrados, triangulo e losangos, sendo
	que este ultimo deve ter uma altura impar.
		Como saida, o programa apresenta a figura requisitada na entrada com sua respectiva altura
	formada por '*'s dentro de uma moldura de '.'s

	Nome : Pedro Barros Bastos		RA : 204481
*/

void desenhaLinhaQuadrado(int larguraMoldura)
{
	//desenho dos asteriscos neste loop
	for(int j=1; j<=larguraMoldura; j++)
			{
				if(j == 1 || j == larguraMoldura)
					printf(".");
				else
				{
					if(j % 2 == 0) //desenho dos espacos
						printf(" ");
					else
						printf("*");
				}
			}
}

void desenhaLinhaTriangulo(int larguraMoldura, int linhaAtual)
{
	int qtdCaracteresParaDesenho = 2*(linhaAtual-2) + 1;

	//calculo da quantidade de espacos que deverao ser desenhados
	int qtdEspacos = (larguraMoldura - 2) - qtdCaracteresParaDesenho;

	printf(".");

	//desenho dos espacos
	for(int j=1; j <= qtdEspacos/2; j++)
		printf(" ");

	//desenho dos asteriscos neste loop
	for(int k=1; k <= qtdCaracteresParaDesenho; k++)
		if(k % 2 != 0)
			printf("*");
		else
			printf(" ");

	//desenho dos espacos
	for(int j=1; j <= qtdEspacos/2; j++)
		printf(" ");

	printf(".");
}

void desenhaLinhaLosango(int larguraMoldura, int linhaAtual, int alturaLosango)
{
	int qtdCaracteresParaDesenho;

	if(linhaAtual <= (alturaLosango/2)+2)
		//funçao para calculo da quantidade de caracteres por linha
		//f(linha) = 2*(linhaAtual-2) + 1; ->> f(linha) = 2*linhaAtual - 3
		qtdCaracteresParaDesenho = 2*linhaAtual - 3;
	else
	{
		//como a linha atual ja passou da linha central, deve-se pegar
		//o numero da linha oposta ao centro para que consigamos decrementar a
		//quantidade de caracteres que deverao ser desenhados por linha

		int distanciaCentroHorizontal = linhaAtual - ((alturaLosango/2)+2);
		int linhaOpostaAoCentroHorizontal = linhaAtual-2*distanciaCentroHorizontal;
		qtdCaracteresParaDesenho = 2*linhaOpostaAoCentroHorizontal - 3;
	}

	//calculo da quantidade de espacos que deverao ser desenhados
	int qtdEspacos = (larguraMoldura - 2) - qtdCaracteresParaDesenho;

	printf(".");

	//desenho dos espacos
	for(int j=1; j <= qtdEspacos/2; j++)
		printf(" ");

	//desenho dos asteriscos neste loop
	for(int k=1; k <= qtdCaracteresParaDesenho; k++)
		if(k % 2 != 0)
			printf("*");
		else
			printf(" ");

	//desenho dos espacos
	for(int j=1; j <= qtdEspacos/2; j++)
		printf(" ");

	printf(".");
}

int main()
{
	char figura;
	int altura;

	scanf("%c %d", &figura, &altura);

	if(altura < 2)
		printf("entrada invalida\n");
	else
	{

		if(figura == 'Q' || figura == 'q' ||
		   figura == 'T' || figura == 't' ||
		   figura == 'L' || figura == 'l')
		{
			//definicao das medidas da moldura, com base na altura e no tipo de
			//figura passadas

			int alturaMoldura = altura + 2;
			int larguraMoldura;

			if(figura == 'L' || figura == 'l')
			{
				if(altura % 2 != 0)
					larguraMoldura = altura + 4;
				else
				{
					printf("entrada invalida\n");
					return 0;
				}
			}
			else
				larguraMoldura = (2*altura-1)+4;

			//inicio dos processos para desenho de figuras

			for(int i=1; i<=alturaMoldura; i++) //loop gerenciador de linhas
				if(i == 1 || i == alturaMoldura) //se for a primeira ou a ultima linha, so desenha pontos
				{
					for(int j=1; j<=larguraMoldura; j++)
						printf(".");

					printf("\n");
				}
				else
				{
					// se nao for a primeira ou ultima linha, deve-se verificar qual objeto
					//se deve desenhar

					switch(figura) //switch para designar a funcao que desenhara a linha atual
								   //de acordo com a figura desejada
					{
						case 'Q':
							desenhaLinhaQuadrado(larguraMoldura);
							break;
						case 'q':
							desenhaLinhaQuadrado(larguraMoldura);
							break;
						case 'T':
							desenhaLinhaTriangulo(larguraMoldura, i);
							break;
						case 't':
							desenhaLinhaTriangulo(larguraMoldura, i);
							break;
						case 'L':
							desenhaLinhaLosango(larguraMoldura, i, altura);
							break;
						case 'l':
							desenhaLinhaLosango(larguraMoldura, i, altura);
							break;
					}

					printf("\n");
				}

		}
		else
			printf("entrada invalida\n");
	}
}
