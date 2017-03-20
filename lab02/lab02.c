#include <stdio.h>

/*
	Este programa tem por objetivo calcular o tempo que se deve esperar
	para ativar um micro explosivo contido em uma bomba que sera lancada
	em uma base rebelde por uma nave do imperio. Tal micro explosivo irá
	redirecionar a bomba para a base do imperio a certa distancia
	da base rebelde.

	Para tanto, serão recebidos como entrada a altura h, em metros, da nave no momento
	do lançamento da bomba, a velocidade vb, em metros por segundo, de queda da bomba (considerada constante),
	a distancia d, em metros, da base rebelde ate a base do imperio e a força fT de empuxo do micro explosivo
	dada em Newtons. Considera-se que a massa da bomba seja de 1kg.

	Como saída, o programa retornará o tempo que se deverá esperar para ativar o micro explosivo.

	Nome : Pedro Barros Bastos - RA : 204481

*/

int main()
{
	/*
		Variaveis de entrada
			# h -> altura da nave
			# vb -> a velocidade de queda da bomba
			# d -> distancia da base rebelde ate a base do imperio
			# fT -> forca de empuxo do micro explosivo T
	*/
	double h;
	double vb;
	double d;
	double fT;

	/*
		Variaves de saida
			# vx -> velocidade da bomba no eixo coordenado X (velocidade horizontal)
			# vy -> velocidade da bomba no eixo coordena Y (velocidade vertical)
			# tChegadaX -> tempo de chegada da bomba na base do imperio apos a ativacao do micro explosivo
			# tChegadaY -> tempo de chegada da bomba ao chao
			# t -> tempo para a ativacao do micro explosivo
	*/
	double vx, vy;
	double tChegadaX, tChegadaY;
	double t;

	/*
		leitura dos dados de entrada
	*/
	scanf("%lf", &h);
	scanf("%lf", &vb);
	scanf("%lf", &d);
	scanf("%lf", &fT);

	
	vx = fT; // considerando a massa da bomba de 1kg e que a força de empuxo aplicará uma velocidade de mesmo módulo
		 // e no sentido contrário, faz-se prudente a atribuição do valor de fT a vx.

	vy = vb; // vy será a velocidade de queda da bomba

	tChegadaX = d/vx; // cálculo do tempo de chegada da bomba na base do imperio.
	tChegadaY = h/vy; // cálculo do tempo de chegada da bomba no chão.

	t = tChegadaY - tChegadaX; // tempo t a ser esperado para a ativação do micro explosivo será
				   // o tempo de chegada da bomba ao chão reduzido do tempo para a bomba
				   // chegar a base do imperio após a ativação do micro explosivo
	printf("%.3f\n", t);
}
