#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 128

void leArquivoEntrada(char *arquivoEntrada, int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
                      int *linhas, int *colunas);
void cinza(int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
           int novaR[MAX][MAX], int novaG[MAX][MAX], int novaB[MAX][MAX], int linhas, int colunas);
void esticar(int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
             int novaR[MAX][MAX], int novaG[MAX][MAX], int novaB[MAX][MAX], int linhas, int colunas);
void normalizar(int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
                int novaR[MAX][MAX], int novaG[MAX][MAX], int novaB[MAX][MAX], int linhas, int colunas);
void escreveArquivoSaida(char *arquivoSaida, int novaR[MAX][MAX], int novaG[MAX][MAX], int novaB[MAX][MAX],
                         int linhas, int colunas);

int main(int argc, char **argv) 
{

  if (argc != 3) 
  {
    fprintf(stderr, "Argumentos invalidos. Use:\n");
    fprintf(stderr, "./lab18 <arqEntrada> <arqSaida>\n");
    fprintf(stderr, "Usado:");

    for (int i=0; i<argc; i++) {
	    fprintf(stderr, " %s", argv[i]);
    }

    fprintf(stderr, "\n");
    return 1;
  }

  char efeito[20];
  char *arqEntrada = argv[1];
  //char *arqSaida = argv[2];

  int imagemR[MAX][MAX], imagemG[MAX][MAX], imagemB[MAX][MAX]; // matrizes com os dados RGB dos pixels da imagem de entrada
  int novaR[MAX][MAX], novaG[MAX][MAX], novaB[MAX][MAX];
  int linhas, colunas;

  scanf("%s", efeito);

  leArquivoEntrada(arqEntrada, imagemR, imagemG, imagemB, &linhas, &colunas); // leitura do arquivo de entrada

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

  /*
  for(int i=0; i<linhas; i++)
  {
    for(int j=0; j<colunas; j++)
    {
      printf("%d %d %d - ", novaR[i][j], novaG[i][j], novaB[i][j]);
    }
    printf("\n");
  }

  printf("Terminou de ler\n");
  */

  return 0;
}

void leArquivoEntrada(char *arquivoEntrada, int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
                      int *linhas, int *colunas)
{
  FILE *pArqEntrada = fopen(arquivoEntrada, "r");

  if(pArqEntrada != NULL)
  {
    char c;
    printf("abriu arquivo\n");

    do
    {
      fscanf(pArqEntrada, "%c", &c);
    }
    while(c != '\n'); // P3

    //leitura das linhas e colunas que o arquivo possui
    fscanf(pArqEntrada, "%d", colunas);
    fscanf(pArqEntrada, "%d", linhas);

    fscanf(pArqEntrada, "%c", &c);
    
    do
    {
      fscanf(pArqEntrada, "%c", &c);
    }
    while(c != '\n'); // 255


    for(int i=0; i<*linhas; i++)
    {
      for(int j=0; j<*colunas; j++)
      {
        //int r, g, b;
        fscanf(pArqEntrada, "%d", &imagemR[i][j]);
        fscanf(pArqEntrada, "%d", &imagemG[i][j]);
        fscanf(pArqEntrada, "%d", &imagemB[i][j]);
	
      }
    }

    fclose(pArqEntrada); // fclose ja da o free no ponteiro passado como parametro
  }
  else
    printf("NAO abriu arquivo %d\n", *linhas);
}

void cinza(int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
           int novaR[MAX][MAX], int novaG[MAX][MAX], int novaB[MAX][MAX], int linhas, int colunas)
{
  for(int i=0; i<linhas; i++)
    for(int j=0; j<colunas; j++)
    {
      int value = (int)floor(((double)(imagemR[i][j] + imagemG[i][j] + imagemB[i][j])) / 3);
      novaR[i][j] = value;
      novaG[i][j] = value;
      novaB[i][j] = value;
    }

  printf("Printando conteudo lido\n");
}

void esticar(int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
             int novaR[MAX][MAX], int novaG[MAX][MAX], int novaB[MAX][MAX], int linhas, int colunas)
{
  int Rmax = imagemR[0][0], Gmax = imagemG[0][0], Bmax = imagemB[0][0];
  int Rmin = imagemR[0][0], Gmin = imagemG[0][0], Bmin = imagemB[0][0];

  for(int i=0; i<linhas; i++)
    for(int j=0; j<colunas; j++)
    {
      if(imagemR[i][j] > Rmax)
        Rmax = imagemR[i][j];

      if(imagemR[i][j] < Rmax)
        Rmin = imagemR[i][j];


      if(imagemG[i][j] > Gmax)
        Gmax = imagemG[i][j];

      if(imagemG[i][j] < Gmax)
        Gmin = imagemG[i][j];


      if(imagemB[i][j] > Bmax)
        Bmax = imagemB[i][j];

      if(imagemB[i][j] < Bmax)
        Bmin = imagemB[i][j];
    }

  for(int i=0; i<linhas; i++)
    for(int j=0; j<colunas; j++)
    {
      double sub = Rmax - Rmin;
      if(sub != 0)
        novaR[i][j] = (int)((double)(imagemR[i][j] - Rmin) * 255)/sub;

      sub = Gmax - Gmin;
      if(sub != 0)
        novaG[i][j] = (int)((double)(imagemG[i][j] - Gmin) * 255)/sub;

      sub = Bmax - Bmin;
      if(sub != 0)
        novaB[i][j] = (int)((double)(imagemB[i][j] - Bmin) * 255)/sub;
    }
}

void normalizar(int imagemR[MAX][MAX], int imagemG[MAX][MAX], int imagemB[MAX][MAX],
                int novaR[MAX][MAX], int novaG[MAX][MAX], int novaB[MAX][MAX], int linhas, int colunas)
{
  for(int i=0; i<linhas; i++)
    for(int j=0; j<colunas; j++)
    {
      double soma = (double)(imagemR[i][j] + imagemG[i][j] + imagemB[i][j]);

      if(soma != 0)
      {
        novaR[i][j] = (int)((double)imagemR[i][j] * 255 / soma);
        novaG[i][j] = (int)((double)imagemG[i][j] * 255 / soma);
        novaB[i][j] = (int)((double)imagemB[i][j] * 255 / soma);
      }
      else
      {
        novaR[i][j] = 0;
        novaG[i][j] = 0;
        novaB[i][j] = 0;
      }
    }
}
