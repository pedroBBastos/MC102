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
int haIgualdadesIncapacitadoras(int i, int j, int k, int l)
{
    //verificar se da pra passar
}

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

    float maiorLucro = 0.0;

    int cI, cJ, cK, cL = 0; //variaveis que identificarao os dias de compra das acoes de cada empresa
    int vI, vJ, vK, vL = 0; //variaveis que identificarao os dias de venda das acoes de cada empresa

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
                    //aqui tem-se a combinacao de todos os indices possiveis
                    //pensar nas regras do problema para elaboracao dos ifs e das somas/substracoes
                    //faz as atribuicoes finais

                    //verificar possiveis igualdades
                    if(i == j || i == k || i == l ||
                       j == k || j == l || l == k) // igualdade vista -> usar a funcao
                    {
                        //analisar os outros casos
                    }
                    else
                    {
                        float lucro;
                        float valorUltimaCompra, valorCompraAtual;
                        int empresaAnterior, empresaAtual = 0;
                        int contabilizar = 0;

                        for(int m=0; m<d+1; m++) // 0 a d+1 -> simulador de dias
                        {
                            if(m == i && m != 0) //empresa1
                            {
                                //pensar no caso de ser 0
                                if(m != 1) //naum eh o 1o dia => fazer contabilizacao de lucro
                                    contabilizar = 1;
                                
                                empresaAtual = 1;
                                valorCompraAtual = empresa1[i];
                            }
                            else
                                if(m == j && m != 0) //empresa2
                                {
                                    if(m != 1) //naum eh o 1o dia
                                        contabilizar = 1;

                                    empresaAtual = 2;
                                    valorCompraAtual = empresa2[j];
                                }
                                else
                                    if(m == k && m != 0) //empresa3
                                    {
                                        if(m != 1) //naum eh o 1o dia
                                            contabilizar = 1;

                                        empresaAtual = 3;
                                        valorCompraAtual = empresa3[k];
                                    }
                                    else
                                        if(m == l && m != 0) //empresa2
                                        {
                                            if(m != 1) //naum eh o 1o dia
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
                                    case 1 : novoValorAcaoEmpresaAnterior = empresa1[m]; break;
                                    case 2 : novoValorAcaoEmpresaAnterior = empresa2[m]; break;
                                    case 3 : novoValorAcaoEmpresaAnterior = empresa3[m]; break;
                                    case 4 : novoValorAcaoEmpresaAnterior = empresa4[m]; break;
                                }

                                lucro += novoValorAcaoEmpresaAnterior-valorUltimaCompra;
                                contabilizar = 0;

                                //empresaAnterior = empresaAtual;
                                //valorUltimaCompra = valorCompraAtual;
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
                    }
                }
            }
        }
    }

    //------------------
    //printar os dados
    //------------------
    
}
