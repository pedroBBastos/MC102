#include <stdio.h>
#include <string.h>

/*
        Este programa ter por objetivo transcrever uma mensagem, a partir de palavras-chave
    nela contidas, a fim se verificar a direcao de um ataque iminente bem como o angulo
    de elevacao do canhao para que se possa interceptar este ataque.
        Como entrada o programa recebe a mensagem, uma string de no maximo 1000 caracteres.
        Como saida, o programa exibe as direcoes dos ataques e o ano angulo de elevacao
    do canhao para que se possa interceptar estes ataques.

    Nome : Pedro Barros Bastos      RA : 204481
*/

// verificar se o tamanho do vetor vai importar durante a comparacao - NOPE
//      pois fara as comparacoes ate encontrar o '\0'

// constantes de direcoes
char mercurio[10] = "mercurio"; // ou char mercurio[10] = {'m', 'e', 'r', 'c', 'u', 'r', 'i', 'o', '\0'};
char venus[10] = "venus";
char terra[10] = "terra";
char marte[10] = "marte";
char jupiter[10] = "jupiter";
char saturno[10] = "saturno";
char urano[10] = "urano";
char netuno[10] = "netuno";

// constantes de elevacao de canhao
char verde[10] = "verde";
char amarelo[10] = "amarelo";
char vermelho[10] = "vermelho";

/*
    funcao que retorna o caracter passado no parametro em sua forma minuscula
*/
char paraMinusculo(char letra)
{
    if(letra >= 97)
        return letra;
    
    return letra + 32;
}

/*
    funcao que a partir de uma posicao inicial do texto, monta o vetor
    'palavra' com a palavra contido nesse texto
*/
void criaPalavra(char texto[], int inicio, char palavra[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        palavra[i] = paraMinusculo(texto[inicio+i]);

    palavra[i] = '\0';
}

/*
    Direção:
        mercurio = N
        venus = NE
        terra = L
        marte = SE
        jupiter = S
        saturno = SO
        urano = O
        netuno = NO
*/

/*
        Funcao que verifica se uma dada palavra contida no texto
    corresponde a uma palavra associada a uma direcao
*/
int palavraEhDirecao(char texto[], int inicio, int fim)
{   
    //iniciar um vetor com tamanho da palavra atual
    int tam = fim-inicio+1;
    char palavra[tam];

    criaPalavra(texto, inicio, palavra, tam);

    /*
        Os proximos ifs verificao se a palavra lida
        corresponde a uma palavra associada a uma direcao
    */
    if(strcmp(palavra, mercurio) == 0)
    {
        printf("N - ");
        return 1;
    } 
    else
        if(strcmp(palavra, venus) == 0)
        {
            printf("NE - ");
            return 1;
        }
        else
            if(strcmp(palavra, terra) == 0)
            {
                printf("L - ");
                return 1;
            }
            else
                if(strcmp(palavra, marte) == 0)
                {
                    printf("SE - ");
                    return 1;
                }
                else
                    if(strcmp(palavra, jupiter) == 0)
                    {
                        printf("S - ");
                        return 1;
                    }
                    else
                        if(strcmp(palavra, saturno) == 0)
                        {
                            printf("SO - ");
                            return 1;
                        }
                        else
                            if(strcmp(palavra, urano) == 0)
                            {
                                printf("O - ");
                                return 1;
                            }
                            else
                                if(strcmp(palavra, netuno) == 0)
                                {
                                    printf("NO - ");
                                    return 1;
                                }

    return 0;
}

/*
    Elevação do canhão:
        verde = 30
        amarelo = 45
        vermelho = 60
*/

/*
        Funcao que verifica se uma dada palavra contida no texto
    corresponde a uma palavra associada a uma elevacao
*/
int palavraEhElevacao(char texto[], int inicio, int fim)
{
    //iniciar um vetor com tamanho da palavra atual
    int tam = fim-inicio+1;
    char palavra[tam];

    criaPalavra(texto, inicio, palavra, tam);

    /*
        Os proximos ifs verificao se a palavra lida
        corresponde a uma palavra associada a uma elevacao
    */
    if(strcmp(palavra, verde) == 0)
    {
        printf("30\n");
        return 1;
    } 
    else
        if(strcmp(palavra, amarelo) == 0)
        {
            printf("45\n");
            return 1;
        }
        else
            if(strcmp(palavra, vermelho) == 0)
            {
                printf("60\n");
                return 1;
            }

    return 0;
}

int main()
{
    char texto[1000];

    fgets(texto, 1000, stdin);

    int tamanhoTexto = strlen(texto); //strlen retorna o tamanho do texto digitado SEM
                                      //contar o '\0'

    int inicioPalavraAtual = 0;
    int procurarDirecao = 1; // false -> ler direcao, true -> ler elevacao canhao

    for(int i=0; i<tamanhoTexto; i++) // ler todos os caracteres do texto lido como entrada
    {
        if(texto[i] == ' ' || texto[i] == '\n') // se for algum separador
        {
            if(procurarDirecao)
            {
                if(palavraEhDirecao(texto, inicioPalavraAtual, i-1))
                    procurarDirecao = 0;
            }
            else
                if(palavraEhElevacao(texto, inicioPalavraAtual, i-1))
                    procurarDirecao = 1;
            
            inicioPalavraAtual = i+1;
        }
    }
}
