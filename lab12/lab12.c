#include <stdio.h>
#include <string.h>

void deletarPalavra(char texto[])
{
    char[50] palavra_deletar;
    fgets(palavra_deletar, 50, stdin);

    
}

void inverterPalavra(char texto[])
{
    char[50] palavra_inverter;
    fgets(palavra_inverter, 50, stdin);
}

void trocarPalavra(char texto[])
{
    char[50] palavra_velha, palavra_nova;
    fgets(palavra_velha, 50, stdin);
    fgets(palavra_nova, 50, stdin);
}

int main()
{
    char[1000] texto;

    fgets(texto, 1000, stdin);

    char operacao;
    for(;;)
    {
        scanf("%c", &operacao);

        if(operacao == 'Q')
            break;

        switch(operacao)
        {
            case 'D' : deletarPalavra(); break;
            case 'I' : inverterPalavra(); break;
            case 'R' : trocarPalavra(); break;
        }
    }

    printf("%s", texto);
}