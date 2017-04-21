#include <stdio.h>
#include <string.h>

char paraMinusculo(char letra)
{
    if(letra >= 97)
        return letra;
    
    return letra + 32;
}

void criaPalavra(char texto[], int inicio, char palavra[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        palavra[i] = paraMinusculo(texto[inicio+i]);

    palavra[i] = '\0';
}

void deletarPalavra(char palavra_deletar[], char texto[])
{
    int tamanhoTexto = strlen(texto); //strlen retorna o tamanho do texto digitado SEM
                                      //contar o '\0'

    int inicioPalavraAtual = 0;

    for(int i=0; i<tamanhoTexto; i++) // ler todos os caracteres do texto lido como entrada
    {
        if(texto[i] == ' ' || texto[i] == '\n') // se for algum separador
        {
            char palavraAtual[50];
            criaPalavra(texto, inicioPalavraAtual, palavraAtual, i-inicioPalavraAtual);

            if(strcmp(palavraAtual, palavra_deletar) == 0)
            {
            }
            
            inicioPalavraAtual = i+1;
        }
    }
}

void inverterPalavra(char palavra_inverter[], char texto[])
{
    int tamanhoTexto = strlen(texto); //strlen retorna o tamanho do texto digitado SEM
                                      //contar o '\0'

    int inicioPalavraAtual = 0;

    for(int i=0; i<tamanhoTexto; i++) // ler todos os caracteres do texto lido como entrada
    {
        if(texto[i] == ' ' || texto[i] == '\n') // se for algum separador
        {
            char palavraAtual[50];
            criaPalavra(texto, inicioPalavraAtual, palavraAtual, i-inicioPalavraAtual);

            printf("%s\n", palavraAtual);

            if(strcmp(palavraAtual, palavra_inverter) == 0)
            {
                int metade = (i-inicioPalavraAtual)/2;
                int p = i-1;
                for(int k=inicioPalavraAtual; k<=metade; k++, p--)
                {
                    char aux = texto[p];
                    texto[p] = texto[k];
                    texto[k] = aux;
                }
            }

            inicioPalavraAtual = i+1;
        }
    }
}

void trocarPalavra(char palavra_velha[], char palavra_nova[], char texto[])
{
    int tamanhoTexto = strlen(texto); //strlen retorna o tamanho do texto digitado SEM
                                      //contar o '\0'

    int inicioPalavraAtual = 0;

    for(int i=0; i<tamanhoTexto; i++) // ler todos os caracteres do texto lido como entrada
    {
        if(texto[i] == ' ' || texto[i] == '\n') // se for algum separador
        {
            char palavraAtual[50];
            criaPalavra(texto, inicioPalavraAtual, palavraAtual, i-inicioPalavraAtual);

            if(strcmp(palavraAtual, palavra_velha) == 0)
            {
            }

            inicioPalavraAtual = i+1;
        }
    }
}

int main()
{
    char texto[1000];

    fgets(texto, 1000, stdin);

    char operacao;
    for(;;)
    {
        scanf("%c", &operacao);

        if(operacao == 'Q')
            break;

        switch(operacao)
        {
            case 'D' : 
            {
                char palavra_deletar[50];
                fgets(palavra_deletar, 50, stdin);

                deletarPalavra(palavra_deletar, texto);
                break;
            }
            
            case 'I' : 
            {
                char palavra_inverter[50];
                fgets(palavra_inverter, 50, stdin);

                inverterPalavra(palavra_inverter, texto); 
                break;
            }

            case 'R' : 
            {
                char palavra_velha[50], palavra_nova[50];
                fgets(palavra_velha, 50, stdin);
                fgets(palavra_nova, 50, stdin);

                trocarPalavra(palavra_velha, palavra_nova, texto); 
                break;
            }
        }
    }

    printf("%s", texto);
}