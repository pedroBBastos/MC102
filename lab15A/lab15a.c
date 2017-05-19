#include <stdio.h>

int main()
{
    int m, n, mE, nE;
    int dias;

    scanf("%d %d %d", &m, &n, &dias);
    mE = m+2;
    nE = n+2;

    int matriz[mE][nE]; // matriz extendida em que as fileiras das bordas serao todas
                          //vazias, para facilitar a verificação das células dos cantos

    //leitura da matriz de entrada
    for(int i=0; i<mE; i++)
    {
        for(int j=0; j<nE; j++)
        {
            if((i == 0 || i == mE-1) || (j == 0 || j == nE-1)) // preenchimento das bordas
                matriz[i][j] = 0;
            else
                scanf("%d", &matriz[i][j]);            
        }
    }

    /*
    for(int i=0; i<mE; i++)
    {
        for(int j=0; j<nE; j++)
            printf("%d", matriz[i][j]);

        printf("\n");
    }

    printf("###########################\n");*/

    //interacoes dos estados para os dias transcorridos
    for(int d=0; d<=dias; d++)
    {
        printf("iteracao %d\n", d);

        if(d == 0)
        {
            for(int i=1; i<mE-1; i++)
            {
                for(int j=1; j<nE-1; j++)
                    printf("%d", matriz[i][j]);

                printf("\n");
            }
        }
        else
        {
            int nova_matriz[mE][nE];            
            for(int i=0; i<mE; i++)
                for(int j=0; j<nE; j++)
                    nova_matriz[i][j] = 0;                

            for(int i=1; i<mE-1; i++)
            {
                for(int j=1; j<nE-1; j++)
                {
                    /*
                    verificacao das regras, colocando os resultados na nova matriz
                    
                    Um indivíduo X que esteja numa posição (i,j) desta matriz,
                    tem como vizinhos àqueles nas posições (i-1,j-1), (i-1,j),
                    (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1)
                    */

                    /*
                    Se X for humano e possuir pelo menos um vizinho zumbi, então X é infectado e se torna um zumbi no dia seguinte;
                    Se X for zumbi e possuir dois ou mais vizinhos humanos, ele é caçado e morto pelos humanos;
                    Se X for zumbi e não possuir nenhum vizinho humano, ele morre de fome e fica vazio no dia seguinte;
                    Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos
                serem zumbis ou vazio, então um humano nasce em X no dia seguinte.
                    Se nenhuma das alternativas anteriores for verdade, então X permanece como está.

                    0 - vazio
                    1 - humano
                    2 - zumbi
                    */

                    int vizinhos[8] = {
                        matriz[i-1][j-1],
                        matriz[i-1][j],
                        matriz[i-1][j+1],
                        matriz[i][j-1],
                        matriz[i][j+1],
                        matriz[i+1][j-1],
                        matriz[i+1][j],
                        matriz[i+1][j+1]
                    };

                    switch(matriz[i][j])
                    {
                        case 0:
                        {
                            int vizinhosHumanos = 0;
                            for(int v=0; v<8; v++)
                                if(vizinhos[v] == 1)
                                    vizinhosHumanos++;

                            if(vizinhosHumanos == 2)
                                nova_matriz[i][j] = 1;
                            
                            break;
                        }
                        case 1:
                        {
                            for(int v=0; v<8; v++)
                                if(vizinhos[v] == 2)
                                {
                                    nova_matriz[i][j] = 2;
                                    break;
                                }
                            break;
                        }
                        case 2:
                        {
                            //acho que o problema esta aqui

                            int vizinhosHumanos = 0;
                            for(int v=0; v<8; v++)
                                if(vizinhos[v] == 1)
                                    vizinhosHumanos++;

                            if(vizinhosHumanos == 0 || vizinhosHumanos >= 2)
                                nova_matriz[i][j] = 0;

                            break;
                        }
                    }

                    
                }
            }

            //copia dos resultados obtidos contidos na nova_matriz para a matriz
            //e printar na tela o resultado da interacao
            for(int i=1; i<mE-1; i++)
            {
                for(int j=1; j<nE-1; j++)
                {
                    printf("%d", nova_matriz[i][j]);
                    matriz[i][j] = nova_matriz[i][j];
                }

                printf("\n");
            }

        }
    }

}