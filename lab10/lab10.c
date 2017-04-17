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

    float maiorLucro = 0.0;
    int cI, cJ, cK, cL = 0;
    int vI, vJ, vK, vL = 0;

    //os indices dos loops abaixo serao considerados como os indces da compra do
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
                       j == k || j == l || l == k) // igualdade vista
                    {
                        //analisar os outros casos
                    }
                    else
                    {
                        lucro;
                        valorCompraDiaAtual
                        empresaAnterior
                        for(int m=0; m<d+1; m++) // 0 a d+1
                        {

                            if(m == i) //empresa1
                            {
                                if(m != 0) //naum eh o 1o dia
                                {
                                    lucro += valorCompraDiaAnterior-empresaAnterior[m];
                                }

                                valorCompraDiaAtual = empresa1[i]
                            }
                            else
                                if(m == j) //empresa2
                                    valorCompraDiaAtual = empresa2[j];
                                else
                                    if(m == k) //empresa3
                                        valorCompraDiaAtual = empresa3[k];
                                    else
                                        if(m == l) //empresa2
                                            valorCompraDiaAtual = empresa4[l];
                                        else
                                        {
                                            //nenhuma operacao a se realizar neste dia
                                        }

                            

                            valorCompraDiaAnterior = valorCompraDiaAtual;
                        }
                    }
                    




                    // aqui tenho os inidices que resultam no lucro atual
                    //ver como guarda-los para posterior apresentacao
                    //  criar quatro variaveis, mI, mJ, mK e mL, que indicam
                    //os indices do maior lucro até entao
                    //no final dos loops, eles estaram setados bonitinhos para apresentacao

                    if(maiorLucro < lucro) //armazenar o maior lucro ate o momento
                    {
                        maiorLucro = lucro;
                        /*
                        cI = ; // dia compra empresa1
                        cJ = ; // dia compra empresa2
                        cK = ; // dia compra empresa3
                        cL = ; // dia compra empresa4

                        vI = ; // dia venda empresa1
                        vJ = ; // dia venda empresa2
                        vK = ; // dia venda empresa3
                        vL = ; // dia venda empresa4
                        */
                    }
                }
            }
        }
    }

    //------------------
    //printar os dados
    //------------------
    
}