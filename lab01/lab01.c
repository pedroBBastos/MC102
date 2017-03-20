#include <stdio.h>

/*
	Este programa ter por objetivo calcular o valor final a ser
	pago em uma viagem, levando em consideracao como variaveis de entrada
	o valor inicial do servico (vi), as coordenadas de inicio
	do trajeto (xi e yi), as coordenadas de fim do trajeto (xf e yf) e
	a taxa cobrada por unidade de distancia (t).

	Para tanto, eh usada a distancia Manhattan para o calculo da distancia
	que sera percorrida, que se da por (xf -xi) + (yf - yi).

	Como saida, o programa calculara o valor total da viagem a ser
	realizada, dada por vi + d*t.

	Nome : Pedro Barros Bastos - RA : 204481
*/

int main()
{
	/*
		 Variaveis de entrada
			# vi ->> valor inicial
			# xi e yi ->> coordenadas do ponto inicial
			# xf e yf ->> coordenadas do ponto final
			# t ->> taxa por unidade de distancia
	*/
	int vi;
	int xi, yi;
	int xf, yf;
	int t;


	/*
		 Variaveis de calculo
			# d ->> distancia Manhattan, sendo d = (xf - xi) + (yf - yi)
			# v ->> valor total a ser pago, sendo v = vi + d*t 
	*/
	int d;
	int v;

	/*
		leitura dos dados de entrada
	*/	
	scanf("%d", &vi);
	scanf("%d", &xi);
	scanf("%d", &yi);
	scanf("%d", &xf);
	scanf("%d", &yf);
	scanf("%d", &t);

	d = (xf - xi) + (yf - yi); // calculo da distancia Manhattan
	v = vi + d*t; // calculo do valor final a ser pago

	printf("%d\n", v); // impressao do total da viagem
}
