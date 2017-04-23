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
                int fimPalavraAtual;

                if(texto[i] == '\n') // se o caracter atual for '\n' atualizar o fim da palavra
                                     // para nao acabar apagar o \n
                    fimPalavraAtual = i-1;
                else
                    fimPalavraAtual = i;

                for(int k=fimPalavraAtual; k>=inicioPalavraAtual; k--)
                {
                    int indiceDesloc = k;
                    while(texto[indiceDesloc] != '\0') // ate o fim do texto
                    {
                        texto[indiceDesloc] = texto[indiceDesloc+1];
                        indiceDesloc++;
                    }
                }

                i -= inicioPalavraAtual; //atualizar i pq o vetor inteiro foi deslocado e i deve voltar
                                         //no caracter em que estava
            }
            
            inicioPalavraAtual = i+1;
        }
    }

    printf("%s", texto);
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

            if(strcmp(palavraAtual, palavra_inverter) == 0)
            {
                int p = i-1;
                int metade = (p+inicioPalavraAtual)/2;

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

    printf("%s", texto);
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
                int tamanhoPalavraVelha = strlen(palavra_velha);
                int tamanhoPalavraNova = strlen(palavra_nova);


                if(tamanhoPalavraVelha < tamanhoPalavraNova)
                {
                    //tamanho do vetor aumentara

                    int novoFimVetor = tamanhoTexto+1 + tamanhoPalavraNova - tamanhoPalavraVelha;

                    for(int j=novoFimVetor, k=tamanhoTexto+1; j>i; j--, k--) // deslocando vetor para frente                    
                        texto[j] = texto[k];
                    
                    for(int j=inicioPalavraAtual, k=0; k<tamanhoPalavraNova; j++, k++) // colocando nova palavra no texto
                        texto[j] = palavra_nova[k];
                    
                    // atualizando indice i e tamanhoTexto, devido aos deslocamentos ocorridos
                    //dentro do vetor
                    tamanhoTexto += tamanhoPalavraNova - tamanhoPalavraVelha;
                    i += tamanhoPalavraNova - tamanhoPalavraVelha;
                }
                else
                    if(tamanhoPalavraVelha > tamanhoPalavraNova)
                    {
                        //tamanho do vetor diminuira
                        
                        // atualizando indice i e tamanhoTexto, devido aos deslocamentos ocorridos
                        //dentro do vetor
                        tamanhoTexto += tamanhoPalavraNova - tamanhoPalavraVelha;
                        i += tamanhoPalavraNova - tamanhoPalavraVelha;
                    }
                    else
                    {
                        //basta substituir, pois possuem o mesmo tamanho
                        for(int j=inicioPalavraAtual, k=0; j<i; j++, k++)
                            texto[j] = palavra_nova[k];
                    }
            }

            inicioPalavraAtual = i+1;
        }
    }

    printf("%s", texto);
}

int main()
{
    char texto[1000];

    fgets(texto, 1000, stdin);
    printf("%s", texto);

    char operacao[3]; //caracter de operacao, \n e \0
    for(;;)
    {
        //scanf("%c", &operacao);
        fgets(operacao, 3, stdin);

        //depois de ler um caracter, ja vai cai nos codigos abaixo.
        //Assim, quando der enter (\n) para digitar os parametros
        //o fgets para os parametro so vai pegar o \n, chamando a
        //respectiva funcao sem os devidos paramentros.

        //if(strcmp(operacao, "Q") == 0) -> o certo seria strcmp(operacao, "Q\n")
        if(operacao[0] == 'Q')
            break;

        switch(operacao[0])
        {
            case 'D' : 
            {
                char palavra_deletar[50];
                fgets(palavra_deletar, 50, stdin);

                //removendo '\n' da string lida:
                //a funcao strchr procura pela primeira ocorrencia de determinado caracter
                //em uma dada string, e retorna o ponteiro para a posicao daquele caracter
                //
                //outro jeito de fazer eh remover o /n na mao -> vendo tamanho da string
                //e acessando tam-2 = '\0'
                char* ponteiroBarraN;
                if ((ponteiroBarraN=strchr(palavra_deletar, '\n')) != NULL)
                    *ponteiroBarraN = '\0';

                deletarPalavra(palavra_deletar, texto);
                break;
            }
            
            case 'I' : 
            {
                char palavra_inverter[50];
                fgets(palavra_inverter, 50, stdin);

                //aqui tbem acontece bosta
                //com o fgets, acaba armazenando o \n, o que
                //na hora da comparacao da merda (por conter o \n em uma string e nao na outra).

                //removendo '\n' da string lida:
                //a funcao strchr procura pela primeira ocorrencia de determinado caracter
                //em uma dada string, e retorna o ponteiro para a posicao daquele caracter
                //
                //outro jeito de fazer eh remover o /n na mao -> vendo tamanho da string
                //e acessando tam-2 = '\0'
                char* ponteiroBarraN;
                if ((ponteiroBarraN=strchr(palavra_inverter, '\n')) != NULL)
                    *ponteiroBarraN = '\0';

                inverterPalavra(palavra_inverter, texto); 
                break;
            }

            case 'R' : 
            {
                char palavra_velha[50], palavra_nova[50];
                fgets(palavra_velha, 50, stdin);
                fgets(palavra_nova, 50, stdin);

                char* ponteiroBarraN;
                if ((ponteiroBarraN=strchr(palavra_velha, '\n')) != NULL)
                    *ponteiroBarraN = '\0';

                if ((ponteiroBarraN=strchr(palavra_nova, '\n')) != NULL)
                    *ponteiroBarraN = '\0';

                trocarPalavra(palavra_velha, palavra_nova, texto); 
                break;
            }
        }
    }

    //printf("%s", texto);
}