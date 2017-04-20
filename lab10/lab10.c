#include <stdio.h>

/*
        Este programa tem por objetivo avaliar os valores diarios de quatro blocos de ações, referentes a quatro
    diferentes empresas, afim de decidir quais são os melhores dias para compra e venda das ações para o
    maior lucro possível.
        A primeira entrada que o programa recebe eh a quantidade de dias em que as acoes estarao sob analise,
    sendo que as linhas subsequentes informam os valores das acoes de cada empresa na dada duracao
    de analise.
        Como saida o programa apresentara, para o maior lucro possivel, os dias de compra e venda das
    acoes, bem como apresentando o maior lucro possivel atraves dessas compras e vendas

    Nome : Pedro Barros Bastos      RA : 204481
*/

int main()
{
    int d; // variavel que representara os dias de analise
    scanf("%d", &d);

    //vetor tamanho d + 1, para que a primeira posicao seja 0, ou seja, quando nao se compra a acao
    float empresa1[d+1], empresa2[d+1], empresa3[d+1], empresa4[d+1];

    empresa1[0] = 0.0;
    empresa2[0] = 0.0;
    empresa3[0] = 0.0;
    empresa4[0] = 0.0;

    for(int i=1; i<d+1; i++) //empresa1
        scanf("%f", &empresa1[i]);

    for(int i=1; i<d+1; i++) //empresa2
        scanf("%f", &empresa2[i]);

    for(int i=1; i<d+1; i++) //empresa3
        scanf("%f", &empresa3[i]);

    for(int i=1; i<d+1; i++) //empresa4
        scanf("%f", &empresa4[i]);


    /*
        ---------------------
    */

    float maiorLucro = 0.0; // variavel que armazenara o maior lucro possivel atraves dos iteracoes dos lacos
                            //encadeados abaixo

    int cI = 0, cJ = 0, cK = 0, cL = 0; //variaveis que identificarao os dias de compra das acoes de cada empresa para o maior lucro total obtido
    int vI = 0, vJ = 0, vK = 0, vL = 0; //variaveis que identificarao os dias de venda das acoes de cada empresa para o maior lucro total obtido

    //os indices dos loops abaixo serao considerados como os indices da compra do
    //bloco das acoes
    for(int i=0; i<d+1; i++) // dias de compra para acoes da empresa1
    {
        for(int j=0; j<d+1; j++) // // dias de compra para acoes da empresa2
        {
            for(int k=0; k<d+1; k++) // // dias de compra para acoes da empresa3
            {
                for(int l=0; l<d+1; l++) // // dias de compra para acoes da empresa4
                {
                    //printf("--------------------------------------------------------\n");

                    //neste for tem-se a combinacao de todos os indices possiveis
                    
                    float lucro = 0.0;
                    int cIp = 0, cJp = 0, cKp = 0, cLp = 0;
                    int vIp = 0, vJp = 0, vKp = 0, vLp = 0;

                    //printf("i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);

                    //verificando a igualdade entre os indices que nao sao zero, mas zero pode passar
                    //pois indica a nao compra de determinada acao
                    if( (i != 0 && i == j) || (i != 0 && i == k) || (i != 0 && i == l) ||
                        (j != 0 && j == k) || (j != 0 && j == l) || (k != 0 && k == l) )
                    {
                        //printf("igualdades que sao invalidas\n");
                        continue;
                    }
                    else
                    {
                        float valorUltimaCompra = 0, valorCompraAtual = 0;
                        int empresaAnterior = 0, empresaAtual = 0;
                        int comprarBloco = 0;

                        //quando comprar uma acao, testar todos os dias de venda
                        //nao so a venda no dia de compra da prox acao,
                        //mas testar os lucros para aquela acao ate o dia
                        //da compra da proxima acao

                        if(i != 0 || j != 0 || k != 0 || l != 0) // se ha pelo menos um dia de compra de acoes
                        {
                            float lucroAcaoComprada = 0.0;

                            for(int m=1; m<d+1; m++) // dia 1 a dia d+1 -> simulador de dias
                            {
                                if(m == i) //empresa1
                                {
                                    cIp = i;

                                    //nada impede o cara apenas vender a acao em um dia, nao
                                    //comprando outra no exato mesmo dia

                                    comprarBloco = 1;

                                    empresaAtual = 1;
                                    valorCompraAtual = empresa1[i];
                                }
                                else
                                    if(m == j) //empresa2
                                    {
                                        cJp = j;

                                        comprarBloco = 1;

                                        empresaAtual = 2;
                                        valorCompraAtual = empresa2[j];
                                    }
                                    else
                                        if(m == k) //empresa3
                                        {
                                            cKp = k;

                                            comprarBloco = 1;

                                            empresaAtual = 3;
                                            valorCompraAtual = empresa3[k];
                                        }
                                        else
                                            if(m == l) //empresa4
                                            {
                                                cLp = l;

                                                comprarBloco = 1;

                                                empresaAtual = 4;
                                                valorCompraAtual = empresa4[l];
                                            }
                                            else
                                            {
                                                //nenhuma operacao de compra a se realizar neste dia
                                            }
                                

                                //mas se ha um bloco de acoes na carteira de aplicacao
                                //verificar o lucro caso a venda se efetue no dia atual
                                //e atualizar caso o lucro com a venda no dia atual caso seja maior
                                //que a em dias anteriores
                                if(empresaAnterior != 0)
                                {
                                    float lucroVendaDiaAtual = 0.0;
                                    switch(empresaAnterior)
                                    {
                                        case 1 : lucroVendaDiaAtual = empresa1[m] - valorUltimaCompra; break;
                                        case 2 : lucroVendaDiaAtual = empresa2[m] - valorUltimaCompra; break;
                                        case 3 : lucroVendaDiaAtual = empresa3[m] - valorUltimaCompra; break;
                                        case 4 : lucroVendaDiaAtual = empresa4[m] - valorUltimaCompra; break;
                                    }

                                    if(lucroAcaoComprada < lucroVendaDiaAtual)
                                    {
                                        lucroAcaoComprada = lucroVendaDiaAtual;

                                        switch(empresaAnterior)
                                        {
                                            //atualizando vI, vJ, vK ou vL instantaneos
                                            case 1 : vIp = m; break;
                                            case 2 : vJp = m; break;
                                            case 3 : vKp = m; break;
                                            case 4 : vLp = m; break;
                                        }    
                                    }
                                }

                                if(comprarBloco || m == d) // se for o dia para se realizar uma compra
                                                           //ou o ultimo dos dias, contabilizar
                                {   
                                    lucro += lucroAcaoComprada;
                                    lucroAcaoComprada = 0.0;
                                    empresaAnterior = empresaAtual;
                                    valorUltimaCompra = valorCompraAtual;
                                    comprarBloco = 0;
                                }
                            }
                        }
                    }

                    //printf("lucro -> %.2f\n", lucro);

                    if(maiorLucro < lucro) //armazenar o maior lucro ate o momento
                    {
                        maiorLucro = lucro;

                        //aqui atualizar variaveis marcadoras de dias de compra e venda
                        //a partir das respectivas instantaneas

                        //dias de compra das acoes
                        cI = cIp;
                        cJ = cJp;
                        cK = cKp;
                        cL = cLp;

                        //dias de venda das acoes
                        vI = vIp;
                        vJ = vJp;
                        vK = vKp;
                        vL = vLp;
                    }
                }
            }
        }
    }

    /*
    printf("--------------------------------------------------------\n");
    printf("Fim dos loops encadeados\n");
    printf("--------------------------------------------------------\n");

    printf("cI = %d, cJ = %d, cK = %d, cL = %d\n", cI, cJ, cK, cL);
    printf("vI = %d, vJ = %d, vK = %d, vL = %d\n", vI, vJ, vK, vL);

    printf("--------------------------------------------------------\n");*/


    //------------------
    //printando os resultados obtidos
    //------------------
    
    if(cI != 0 && vI != 0)
        printf("acao 1: compra %d, venda %d, lucro %.2f\n", cI, vI, empresa1[vI] - empresa1[cI]);

    if(cJ != 0 && vJ != 0)
        printf("acao 2: compra %d, venda %d, lucro %.2f\n", cJ, vJ, empresa2[vJ] - empresa2[cJ]);

    if(cK != 0 && vK != 0)
        printf("acao 3: compra %d, venda %d, lucro %.2f\n", cK, vK, empresa3[vK] - empresa3[cK]);

    if(cL != 0 && vL != 0)
        printf("acao 4: compra %d, venda %d, lucro %.2f\n", cL, vL, empresa4[vL] - empresa4[cL]);

    printf("Lucro: %.2f\n", maiorLucro);
}
