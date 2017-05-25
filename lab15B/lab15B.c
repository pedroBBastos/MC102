/* Laboratorio 15B - Brincando com cordas
 * Nome: Pedro Barros Bastos
 * RA: 204481
 */

 /*
    Para testar um metodo, apagar o uso dos outros dois?
    So eh printada uma operacao na tela se ela foi realizada, mostrando depois dos dois pontos
    o resultado obtido
 */

#include <stdio.h>
#include <string.h>

void pegaMovimentos(char vetor[], int inicio, int tam, char movimentos[])
{
    //ps: tam eh o tamanho da seq. de movimentos a ser copiada para movimentos[]
    //ou seja, '\0' nao conta

    for(int i=0; i<tam; i++)
        movimentos[i] = vetor[inicio+i];

    movimentos[tam] = '\0';
} 

/* Funcao: removePadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo as ocorrencias de um dado padrao.
 * 
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *       padrao: subsequencia de movimentos, cujas ocorrencias devem ser removidas
 *    targetStr: sequencia obtida apos a remocao de str de todas as ocorrencias do dado padrao.
 *               
 *  
 * Retorno:
 *
 *    1, se as occorrencias do dado padrao foram removidas
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15];
 *
 *     char padrao1[3] = "+-"
 *     char padrao2[3] = "**"
 * 
 *     removePadrao(seq1, padrao1, seq2); // seq2 sera "**-*+++"
 *     removePadrao(seq1, padrao2, seq2); // seq2 sera "+-*+-*-*+++" 
 * 
 */
int removePadrao(char str[], char padrao[], char targetStr[]) //aparentemente, ok
{
    int removeu = 0;
    int tamStr = strlen(str), tamPadrao = strlen(padrao);

    if(tamPadrao > tamStr)
    {
        targetStr = str;
        return removeu;
    }

    int i=0, j=0;
    while(i+tamPadrao <= tamStr)
    {
        char seqMovimentos[tamPadrao+1]; //lembrar que strlen nao conta o '\0'
        pegaMovimentos(str, i, tamPadrao, seqMovimentos);

        if(strcmp(seqMovimentos, padrao) == 0) //atualizar indice de copia
        {
            i += tamPadrao;
            removeu = 1;

            /*
            if(i < tamStr)
            {
                targetStr[j] = str[i];
                j++;
            }
            */
        }
        else
            if(i+tamPadrao <= tamStr)
            {
                targetStr[j] = str[i];
                j++;
                i++;
            }
    }

    for(; i<tamStr; j++, i++)
        targetStr[j] = str[i];

    targetStr[j] = '\0';

    return removeu;
}

/* Funcao: removeBloco
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo o bloco inicial delimitado pelo dado caractere.
 * 
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *            c: caractere delimitador do bloco a ser removido
 *    targetStr: se str comeca com o caractere do parametro c, targetStr contera a sequencia obtida
 *               apos a remocao (de str) do bloco de movimentos da primeira posicao de str ate a 
 *               segunda ocorrencia (inclusive) do caractere do parametro c. Se nao exsitir uma segunda 
 *               ocorrencia do caracter do parametro c, targetStr deve conter a sequencia vazia.
 *
 * Retorno:
 *
 *    1, se o bloco foi removido
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15] = "*+-*+-*-*+++";
 *     char seq3[15] = "*+-+--+++";
 *     char seq4[15];
 * 
 *     removeBloco(seq1, '*', seq4); // seq4 sera "+-*+-*-*+++"
 *     removeBloco(seq2, '*', seq4); // seq4 sera "+-*-*+++"
 *     removeBloco(seq3, '*', seq4); // seq4 sera "" (sequencia vazia)
 * 
 */
int removeBloco(char str[], char c, char targetStr[]) 
{    
    int tam = strlen(str);

    if(tam == 0)
    {
        targetStr = "";
        return 0;
    }

    if(str[0] == c)
    {
        int i = 0;
        while(str[i] != c && str[i] != '\0')
            i++;

        if(i == tam) // acabou a string e nao encontrou a segunda ocorrencia
            targetStr = "";
        else
            pegaMovimentos(str, i+1, tam-i-1, targetStr); //tam-i-1 -> tamanho da seq. de movimentos

        return 1;
    }

    targetStr = str;
    return 0;
}

/* Funcao: substituiPadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    substituindo as ocorrencias de um dado padrao por um novo padrao.
 *
 * Parametros:
 *           str: sequencia de movimentos '+', '-', '*'
 *        padrao: subsequencia de movimentos, cujas ocorrencias devem ser substituidas pelo novoPadrao
 *    novoPadrao: subsequencia de movimentos que deve substituir cada ocorrencia do dado padrao
 *     targetStr: sequencia obtida apos a substituicao em str de todas as ocorrencias do dado padrao 
 *                pelo novoPadrao
 *
 *     Voce pode assumir que as subsequencias padrao e novoPadrao tem o mesmo tamanho.
 *
 * Retorno:
 *
 *    1, se as ocorrencias do dado padrao foram substituidas pelo novoPadrao
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+*+-+*+-*++";
 *     char seq2[15];
 *     char seq3[15];
 *
 *     char padrao[5] = "+*+"
 *     char novoPadrao[5] = "*-*"
 * 
 *     substituiPadrao(seq1, padrao, novoPadrao, seq2); // seq2 sera "*-*-*-*-*++"
 *     substituiPadrao(seq2, padrao, novoPadrao, seq3);  // seq3 sera "*-*-*-*-*++" 
 * 
 */
int substituiPadrao(char str[], char padrao[], char novoPadrao[], char targetStr[]) 
{
    int substituiu = 0;
    int tamStr = strlen(str), tamPadrao = strlen(padrao);

    if(tamPadrao > tamStr)
        return substituiu;

    int i=0;
    while(i+tamPadrao <= tamStr)
    {
        char seqMovimentos[tamPadrao+1]; //lembrar que strlen nao conta o '\0'
        pegaMovimentos(str, i, tamPadrao, seqMovimentos);

        if(strcmp(seqMovimentos, padrao) == 0) //colocar no espaco do padrao o novoPadrao
        {
            /*
            printf("seqMovimentos -> %s\n", seqMovimentos);
            printf("padrao -> %s\n", padrao);
            printf("novoPadrao -> %s\n", novoPadrao);
            */

            for(int k=0; k<tamPadrao; k++)
            {
                targetStr[i] = novoPadrao[k];
                i++;
            }

            substituiu = 1;
        }
        
        targetStr[i] = str[i];
        i++;
    }

    while(str[i] != '\0')
    {
        targetStr[i] = str[i];
        i++;
    }

    targetStr[i] = '\0';

    //printf("targetStr -> %s\n", targetStr);

    return substituiu;
}