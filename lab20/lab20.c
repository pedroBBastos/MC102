#include <stdio.h>

/*
    Este programa tem por objetivo determinar quantas bases do imperio e quantas
  bases rebeldes estão presentes em uma região a partir do mapa de um setor de uma região
  que será dado como entrada.
    A saída informa quantas bases rebeldes e quantas bases do imperio estão na dada região.
    As bases rebeldes sao identificadas pelo caracter '#' e as bases do imperio pelo caracter
  '*'. O caracter '-' identifica espaço vazio.

    Nome : Pedro Barros Bastos    RA : 204481

*/

#define MAX 102

//metodo que recursivamente marca as posicoes da matriz que sao de determinado grupo
void efetuarMarcacao(char map[MAX][MAX], char auxMap[MAX][MAX], char c, int i, int j);

int main()
{
  int rows, cols;
  char map[MAX][MAX], auxMap[MAX][MAX];
  int basesRebeldes = 0, basesImperio = 0;
  
  scanf("%d %d", &rows, &cols);

  //poderemos ter uma matriz auxiliar que marca as posicoes ja verificadas da base atual.
  //assim, na primeira passagem, verificamos se ela ja nao foi verificada, a partir desta matriz auxiliar.
  //se naum, iniciar o processo recursivo para verificação/marcação.

  //para criação de matriz aumentada e facilitar o trabalho
  rows += 2;
  cols += 2;
  
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    {

      if((i == 0 || i == rows-1) || (j == 0 || j == cols-1)) // cantos da matriz aumentada
        map[i][j] = '-';
      else
      {
        char c;

        do
        {
          scanf("%c", &c);
        } while(c == ' ' || c == '\n' || c == '\0'); //dispensando caracteres inuteis vindos da entrada

        map[i][j] = c;
      }

      auxMap[i][j] = 'n';
    }

  for(int i = 1; i < rows-1; i++)
    for(int j = 1; j < cols-1; j++)
    {
      if(auxMap[i][j] == 'n') //posicao ainda nao verificada
      {
        switch(map[i][j])
        {
          // efetuar a chamada recursiva correspondente para marcar na auxMap todas as
          //posicoes da base atual.
          case '*' : basesImperio++; efetuarMarcacao(map, auxMap, '*', i, j); break;
          case '#' : basesRebeldes++; efetuarMarcacao(map, auxMap, '#', i, j); break;
        }
      }
    }
  
  printf("Bases rebeldes: %d\n", basesRebeldes);
  printf("Bases do imperio: %d\n", basesImperio);
}

void efetuarMarcacao(char map[MAX][MAX], char auxMap[MAX][MAX], char c, int i, int j)
{
  if(map[i][j] == c && auxMap[i][j] == 'n')
  {
    auxMap[i][j] = '!';

    //verificacao das posicoes vizinhas
    efetuarMarcacao(map, auxMap, c, i-1, j-1);
    efetuarMarcacao(map, auxMap, c, i-1, j);
    efetuarMarcacao(map, auxMap, c, i-1, j+1);
    efetuarMarcacao(map, auxMap, c, i, j-1);
    efetuarMarcacao(map, auxMap, c, i, j+1);
    efetuarMarcacao(map, auxMap, c, i+1, j-1);
    efetuarMarcacao(map, auxMap, c, i+1, j);
    efetuarMarcacao(map, auxMap, c, i+1, j+1);
  }
}