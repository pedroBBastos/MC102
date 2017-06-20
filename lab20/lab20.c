#include <stdio.h>

#define MAX 100

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
  //Pensar em um modo para que, no retorno de todo o processo de recursao que verificou uma base, a contagem se
  //efetue -> soh contar mais um depois da chamada da funcao
  
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    {
      /*
      if((i == 0 || i == MAX-1) || (j == 0 || j == MAX-1)) // preenchimento das bordas
          map[i][j] = '-';
      else
      */
      scanf("%c ", &map[i][j]);
      auxMap[i][j] = 'n';
    }


  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    {
      if(auxMap[i][j] == 'n') //posicao ainda nao verificada
      {
        switch(map[i][j])
        {
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

    if(i-1 >= 0 && i-1 < rows && j-1 >= 0 && j-1 < rows)
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