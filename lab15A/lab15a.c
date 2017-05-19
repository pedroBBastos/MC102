#include <stdio.h>

/*
Um indivíduo X que esteja numa posição (i,j) desta matriz, tem como vizinhos àqueles nas posições (i-1,j-1),
(i-1,j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1) que correspondem respectivamente aos
vizinhos v1, v2, v3, v4, v5, v6, v7, e v8 da figura.

Os cientistas concluíram que as seguintes interações modelam a relação humano/zumbi:

        Se X for humano e possuir pelo menos um vizinho zumbi, então X é infectado e se torna um zumbi no dia seguinte;
        Se X for zumbi e possuir dois ou mais vizinhos humanos, ele é caçado e morto pelos humanos;
        Se X for zumbi e não possuir nenhum vizinho humano, ele morre de fome e fica vazio no dia seguinte;
        Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos
    serem zumbis ou vazio, então um humano nasce em X no dia seguinte.
        Se nenhuma das alternativas anteriores for verdade, então X permanece como está.
*/

int main()
{
    int m, n;
    int dias;

    scanf("%d %d %d", &m, &n, &dias);

    int matriz[m+2][n+2]; // matriz extendida em que as fileiras das bordas serao todas
                          //vazias, para facilitar a verificação das células dos cantos

    //leitura da matriz de entrada
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {

        }
    }

    //----------- interacoes

    printf("interacao 0");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {

        }
    }

    //interacoes dos estados para os dias transcorridos
    for(int d=1; d<=dias; d++)
    {
        int nova_matriz[m+2][n+2];

        printf("interacao %d", d);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //verificacao das regras, colocando os resultados na nova matriz
            }
        }

        //copia dos resultados obtidos contidos na nova_matriz para a matriz
        //e printar na tela o resultado da interacao
    }

}