#include <stdio.h>

/*
        Este programa tem por objetivo realizar as operacoes de soma e subtracao
    entre dois inteiros positivos grandes de ate 30 digitos.
        Como entrada recebe um operando, um operador e outro operando, respectivamente,
        Como saida, apresenta os dois operandos na forma de 30 digitos e o resultado
    da operacao desejada entre eles.

    Nome : Pedro Barros Bastos      RA : 204481

*/


/*
    Metodo para calculo da soma entre dois operandos.
    Implementa o algoritmo de soma entre dois numeros

    Ex : 17 + 15 = 32
    1
    17
   +15
   ----
    32
*/
void soma(char operando1[30], char operando2[30])
{
    int vetorResultado[30];
    int excedente = 0;
    int i;

    for(i=29; i>=0; i--)
    {
        int intValueD1 = operando1[i] - 48; // - '0' ou % '0'
        int intValueD2 = operando2[i] - 48; // - '0' ou % '0'
        int partialResult = intValueD1 + intValueD2 + excedente;

        if(partialResult >= 10)
        {
            if(i != 0)
            {
                int digitoCasaAtual = partialResult % 10;
                vetorResultado[i] = digitoCasaAtual;
                excedente = 1;
            }
            else
            {
                printf("overflow");
                return;
            }
        }
        else
        {
            vetorResultado[i] = partialResult;
            excedente = 0;
        }
    }

    i = 0;
    while(vetorResultado[i] == 0)
        i++;

    while(i < 30)
    {
        printf("%d", vetorResultado[i]);
        i++;
    }
}

/*
    Metodo para calculo da subtracao entre dois operandos.
    Implementa o algoritmo de subtracao entre dois numeros

    Ex: 38 - 29 = 09
 (2)3(18)8
       -29
       ----
        09   
*/
void subtracao(char maiorOperando[30], char menorOperando[30], char sinal)
{
    int vetorResultado[30];
    int digito1, digito2;
    int i;

    for(i=29; i>=0; i--)
    {
        digito1 = maiorOperando[i] - 48;
        digito2 = menorOperando[i] - 48;

        if(digito1 < digito2)
        {
            maiorOperando[i-1] = maiorOperando[i-1] - 1;
            digito1 = digito1 + 10;
        }

        vetorResultado[i] = digito1 - digito2;
    }

    if(sinal == '-')
        printf("%c", sinal);

    i = 0;
    while(vetorResultado[i] == 0)
        i++;

    while(i < 30)
    {
        printf("%d", vetorResultado[i]);
        i++;
    }
}

int main()
{
    char operando1[30];
    char operando2[30];
    char operacao;

    /*
            Inicio do processo de leitura do 1o operando, operador e segundo
        operando, respectivamente.
    */

    char digito; // caracter digitado
    int finishedCurrentOperand = 0; // variavel de controle para verificacao do fim dos 30 caracteres
    int i, indiceParada; // indices

    for(i=29; i>=0; i--) // laco de leitura dos caracteres de um operando
    {
        if(!finishedCurrentOperand)
        {
            scanf("%c", &digito);

            if(digito != '\n')
                operando1[i] = digito;
            else
            {
                operando1[i] = '0';
                finishedCurrentOperand = 1;
                indiceParada = i+1; // ultimo digito 'normal' foi o anterior
            }
        }
        else
            operando1[i] = '0';
    }

    if(!finishedCurrentOperand)
    {
        indiceParada = 0;
        scanf("%c", &digito); //lendo /n, que nao tera utilidade alguma

        /*
            o scanf("%c") le estritamente cada caracter que eh digitado. Sem esperar o /n
            vai atribuindo o que foi digitado no momento em que eh digitado
        */
    }

    //processo de inversao do numero lido, que foi colocado ao avesso no vetor
    int k;
    int limite = (29+indiceParada)/2;
    for(k=29; indiceParada<=limite; k--, indiceParada++)
    {
        char aux = operando1[indiceParada];
        operando1[indiceParada] = operando1[k];
        operando1[k] = aux;
    }

    /*
        Leitura do operador
    */
    finishedCurrentOperand = 0;
    scanf("%c", &operacao);
    scanf("%c", &digito); //lendo /n, que nao tera utilidade alguma

    /*
        Reiniciando processo de leitura de operando, para ler o segundo operando
    */

    for(i=29; i>=0; i--)
    {
        if(!finishedCurrentOperand)
        {
            scanf("%c", &digito);

            if(digito != '\n')
                operando2[i] = digito;
            else
            {
                operando2[i] = '0';
                finishedCurrentOperand = 1;
                indiceParada = i+1; // ultimo digito 'normal' foi o anterior
            }
        }
        else
            operando2[i] = '0';
    }

    if(!finishedCurrentOperand) // aqui nao precisa ler o \n pois nao havera mais nada para ler depois
        indiceParada = 0;

    //processo de inversao do numero lido, que foi colocado ao avesso no vetor
    limite = (29+indiceParada)/2;
    for(k=29; indiceParada<=limite; k--, indiceParada++)
    {
        char aux = operando2[indiceParada];
        operando2[indiceParada] = operando2[k];
        operando2[k] = aux;
    }

    /*
        Termino da leitura de operandos e operador
    */

    /*
        ----------------------------------------------------------
    */

    /*
        Printando os operandos
    */
    for(i=0; i<30; i++)
        printf("%c", operando1[i]);

    printf("\n");

    for(i=0; i<30; i++)
        printf("%c", operando2[i]);

    printf("\n");


    /*
        Iniciando processo para calculo do resultado
    */
    switch(operacao)
    {
        case '+' :
            {
                soma(operando1, operando2);
                break;
            }
            
        case '-' :
            {
                //verificando maior operando
                int maiorOperando = 0;
                for(i=0; i<30; i++)
                    if(operando1[i] > operando2[i])
                    {
                        maiorOperando = 1;
                        break;
                    }
                    else
                        if(operando1[i] < operando2[i])
                        {
                            maiorOperando = 2;
                            break;
                        }

                if(maiorOperando == 0) // se forem iguais
                    printf("0");
                else
                {
                    if(maiorOperando == 1)
                        subtracao(operando1, operando2, '+'); // resultado sera > que 0
                    else
                        subtracao(operando2, operando1, '-'); // resultado sera < que 0
                }

                break;
            }
    }

    printf("\n");
}
