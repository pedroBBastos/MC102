#include <stdio.h>

/*
    # Somente quatro empresas terão ações disponíveis para compra/venda;
    # A compra e venda se dá por um bloco de ações inteiras, e a entrada do programa contém
exatamente o valor do bloco de ações de cada empresa em cada dia;
    # A carteira de aplicações deve possuir a cada dia ações de no máximo uma empresa, ou seja,
para comprar ações de uma empresa deve-se vender as ações previamente compradas de outra empresa;
    # Pode-se comprar e vender ações de cada empresa no máximo uma vez no período avaliado, ou seja,
após vendido o bloco de ações de uma empresa, não se pode mais realizar a compra de uma ação dela no futuro;
    # A compra de um bloco de ações é feita no fim do dia e a venda é feita no começo, de modo que pode-se
vender as ações de uma empresa e comprar a de outra no mesmo dia;
        - venda primeira, compra depois


        o ganho com cada bloco de ações definido como o valor que se vendeu aquele bloco menos o
    valor que ele foi comprado.
*/

int main()
{
    int d;
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

    //printf("d+1 = %d\n", d+1);

    float maiorLucro = 0.0;

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

                    //aqui tem-se a combinacao de todos os indices possiveis
                    //pensar nas regras do problema para elaboracao dos ifs e das somas/substracoes
                    //faz as atribuicoes finais
                    float lucro = 0.0;
                    int cIp = 0, cJp = 0, cKp = 0, cLp = 0;
                    int vIp = 0, vJp = 0, vKp = 0, vLp = 0;

                    //printf("i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);

                    //deve-se pensar um jeito de se verificar a igualdade
                    //entre os indices que nao sao zero

                    if( (i != 0 && i == j) || (i != 0 && i == k) || (i != 0 && i == l) ||
                        (j != 0 && j == k) || (j != 0 && j == l) || (k != 0 && k == l))
                    {
                        //printf("igualdades que sao invalidas\n");
                        continue;
                    }
                    else
                    {
                        float valorUltimaCompra = 0, valorCompraAtual = 0;
                        int empresaAnterior = 0, empresaAtual = 0;
                        int contabilizar = 0;

                        if(i != 0 || j != 0 || k != 0 || l != 0) // se ha pelo menos um dia de compra de acoes
                            for(int m=1; m<d+1; m++) // dia 1 a dia d+1 -> simulador de dias
                            {
                                if(m == i) //empresa1
                                {
                                    cIp = i;

                                    if(empresaAnterior != 0) //naum eh o 1o dia => fazer contabilizacao de lucro
                                        contabilizar = 1;
                                    
                                    empresaAtual = 1;
                                    valorCompraAtual = empresa1[i];
                                }
                                else
                                    if(m == j) //empresa2
                                    {
                                        cJp = j;

                                        if(empresaAnterior != 0) //naum eh o 1o dia
                                            contabilizar = 1;

                                        empresaAtual = 2;
                                        valorCompraAtual = empresa2[j];
                                    }
                                    else
                                        if(m == k) //empresa3
                                        {
                                            cKp = k;

                                            if(empresaAnterior != 0) //naum eh o 1o dia
                                                contabilizar = 1;

                                            empresaAtual = 3;
                                            valorCompraAtual = empresa3[k];
                                        }
                                        else
                                            if(m == l) //empresa4
                                            {
                                                cLp = l;

                                                if(empresaAnterior != 0) //naum eh o 1o dia
                                                    contabilizar = 1;

                                                empresaAtual = 4;
                                                valorCompraAtual = empresa4[l];
                                            }
                                            else
                                            {
                                                //nenhuma operacao a se realizar neste dia
                                                continue;
                                            }

                                if(contabilizar)
                                {
                                    float novoValorAcaoEmpresaAnterior;
                                    switch(empresaAnterior)
                                    {
                                        //aqui atualizar vI, vJ, vK ou vL instantaneos
                                        case 1 : novoValorAcaoEmpresaAnterior = empresa1[m]; vIp = m; break;
                                        case 2 : novoValorAcaoEmpresaAnterior = empresa2[m]; vJp = m; break;
                                        case 3 : novoValorAcaoEmpresaAnterior = empresa3[m]; vKp = m; break;
                                        case 4 : novoValorAcaoEmpresaAnterior = empresa4[m]; vLp = m; break;
                                    }

                                    lucro += novoValorAcaoEmpresaAnterior-valorUltimaCompra;
                                    contabilizar = 0;
                                }
                    
                                empresaAnterior = empresaAtual;
                                valorUltimaCompra = valorCompraAtual;
                            }
                    }

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

    printf("--------------------------------------------------------\n");
    */

    //------------------
    //printar os dados
    //------------------


    
    if(cI != 0 && vI != 0)
        printf("acao 1: compra %d, venda %d, lucro %.2f\n", cI, vI, empresa1[vI] - empresa1[cI]);

    if(cJ != 0 && vJ != 0)
        printf("acao 2: compra %d, venda %d, lucro %.2f\n", cJ, vJ, empresa2[vJ] - empresa2[cJ]);

    if(cK != 0 && vK != 0)
        printf("acao 3: compra %d, venda %d, lucro %.2f\n", cK, vK, empresa3[vK] - empresa3[cK]);

    if(cL != 0 && vL != 0)
        printf("acao 4: compra %d, venda %d, lucro %.2f\n", cL, vL, empresa4[vL] - empresa4[cL]);

    if(maiorLucro >= 0.0)
        printf("Lucro: %.2f\n", maiorLucro);
}
