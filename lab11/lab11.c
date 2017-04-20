#include <stdio.h>
#include <string.h>

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
int palavraEhDirecao(char texto[1000], int inicio, int fim)
{   
    //iniciar um vetor com tamanho da palavra atual
    int tam = fim-inicio+1;
    char palavra[tam];

    int i;
    for(i=0; i<tam; i++)
        palavra[i] = paraMinusculo(texto[inicio+i]);
    palavra[i] = '\0';

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
int palavraEhElevacao(char texto[1000], int inicio, int fim)
{
    //iniciar um vetor com tamanho da palavra atual
    int tam = fim-inicio+1;
    char palavra[tam];

    int i;
    for(i=0; i<tam; i++)
        palavra[i] = paraMinusculo(texto[inicio+i]);
    palavra[i] = '\0';

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
    char texto[1000]; //1000 caracteres, incluindo \ns e \0 ou 1001 com o \0 ??

    fgets(texto, 1000, stdin);

    int tamanhoTexto = strlen(texto); //strlen retorna o tamanho do texto digitado SEM
                                      //contar o '\0'

    int inicioPalavraAtual = 0;
    int procurarDirecao = 1; // false -> ler direcao, true -> ler elevacao canhao

    for(int i=0; i<tamanhoTexto; i++)
    {
        if(texto[i] == ' ' || texto[i] == '\n')
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
