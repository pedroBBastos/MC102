#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void leArquivoEntrada(char *arquivoEntrada, int **imagemR, int **imagemG, int **imagemB,
                      int *linhas, int *colunas);
void inicializaMatriz(int **matriz, int linhas, int colunas);
void cinza(int **imagemR, int **imagemG, int **imagemB,
           int **novaR, int **novaG, int **novaB, int linhas, int colunas);
void esticar(int **imagemR, int **imagemG, int **imagemB,
             int **novaR, int **novaG, int **novaB, int linhas, int colunas);
void normalizar(int **imagemR, int **imagemG, int **imagemB,
                int **novaR, int **novaG, int **novaB, int linhas, int colunas);
void escreveArquivoSaida(char *arquivoSaida, int **novaR, int **novaG, int **novaB,
                         int linhas, int colunas);
void liberaMatriz(int **matriz, int linhas, int colunas);

int main(int argc, char **argv) 
{
  if (argc != 3) 
  {

    fprintf(stderr, "Argumentos invalidos. Use:\n");
    fprintf(stderr, "./lab18 <arqEntrada> <arqSaida>\n");
    fprintf(stderr, "Usado:");

    for (int i=0; i<argc; i++) 
	    fprintf(stderr, " %s", argv[i]);

    fprintf(stderr, "\n");
    return 1;
  }

  char efeito[20];
  char *arqEntrada = argv[1];
  char *arqSaida = argv[2];

  scanf("%s", efeito);

  
  FILE *pArqEntrada = fopen(arqEntrada, "r");

  //leitura do arquivo de entrada
  if(pArqEntrada != NULL)
  {
    int colunas, linhas;
    char c;

    do
    {
      fscanf(pArqEntrada, "%c", &c);
    }
    while(c != '\n'); // P3


    fscanf(pArqEntrada, "%d", &colunas);
    fscanf(pArqEntrada, "%d", &linhas);

    //printf("colunas -> %d\n", colunas);
    //printf("linhas -> %d\n", linhas);

    fscanf(pArqEntrada, "%c", &c);

    
    do
    {
      fscanf(pArqEntrada, "%c", &c);
    }
    while(c != '\n'); // 255


    int **imagemR, **imagemG, **imagemB;
    int **novaR, **novaG, **novaB;

    //alocação dinamica dos vetores que serao necessarios
    imagemR = malloc(linhas*sizeof(int *));
    imagemG = malloc(linhas*sizeof(int *));
    imagemB = malloc(linhas*sizeof(int *));

    for(int i=0; i<linhas; i++)
    {
      imagemR[i] = malloc(colunas*sizeof(int));
      imagemG[i] = malloc(colunas*sizeof(int));
      imagemB[i] = malloc(colunas*sizeof(int));
    }

    

    for(int i=0; i<linhas; i++)
    {
      for(int j=0; j<colunas; j++)
      {
        fscanf(pArqEntrada, "%d", &imagemR[i][j]);
        fscanf(pArqEntrada, "%d", &imagemG[i][j]);
        fscanf(pArqEntrada, "%d", &imagemB[i][j]);
      }
    }

    fclose(pArqEntrada); // fclose ja da o free no ponteiro passado como parametro
    
    /*
    printf("Printando conteudo lido\n");

    for(int i=0; i<linhas; i++)
    {
      for(int j=0; j<colunas; j++)
      {
        printf("%d %d %d - ", imagemR[i][j], imagemG[i][j], imagemB[i][j]);
      }
      printf("\n");
    }

    printf("Terminou de ler\n");
    */

    if(strcmp(efeito, "cinza") == 0)
      cinza(imagemR, imagemG, imagemB,
            novaR, novaG, novaB, linhas, colunas);
    else
      if(strcmp(efeito, "esticar") == 0)
        esticar(imagemR, imagemG, imagemB,
                novaR, novaG, novaB, linhas, colunas);
      else
        normalizar(imagemR, imagemG, imagemB,
            novaR, novaG, novaB, linhas, colunas);

    //escrever no arquivo de saida
    
    //liberando memoria alocada  para as matrizes de pixels
    for(int i=0; i<linhas; i++)
    {
      free(imagemR[i]);
      free(imagemG[i]);
      free(imagemB[i]);
      free(novaR[i]);
      free(novaG[i]);
      free(novaB[i]);
    }
    free(imagemR);
    free(imagemG);
    free(imagemB);
    free(novaR);
    free(novaG);
    free(novaB);
    

  }

  return 0;
}

void leArquivoEntrada(char *arquivoEntrada, int **imagemR, int **imagemG, int **imagemB,
                      int *linhas, int *colunas)  
{
}

void cinza(int **imagemR, int **imagemG, int **imagemB,
           int **novaR, int **novaG, int **novaB, int linhas, int colunas)
{
}

void esticar(int **imagemR, int **imagemG, int **imagemB,
             int **novaR, int **novaG, int **novaB, int linhas, int colunas)
{
}

void normalizar(int **imagemR, int **imagemG, int **imagemB,
                int **novaR, int **novaG, int **novaB, int linhas, int colunas)
{ 
}
