#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Este programa tem por objetivo gerar todos os anagramas de uma string dada recursivamente.

  Nome : Pedro Barros Bastos   RA : 204481
 */

/*
 * Entrada: 
 *          string_ordenada: a string original, que devemos processar 
 *                           para encontrarmos todos os anagramas
 *          letra_usada: um vetor de booleanos (implementado da forma 
 *                       de um vetor de inteiros) para marcarmos quais 
 *                       posições da string original já foram usadas
 *          word: o anagrama que estamos formando
 *          n: o numero de letras do anagrama
 *          k: a posição onde incluiremos a proxima letra em word
 * 
 * A ideia para gerar sem repeticoes eh que setada a letra da posicao k,
 * e retornado da chamada recursiva, temos
 * que colocar uma letra diferente na posição k, pois senão geraríamos
 * as repetições. Quando n==k incluimos a letra faltante e imprimimos o
 * anagrama.
 */
void generate(char *string_ordenada, int *letra_usada, char *word, int n, int k){

  //condicao de parada -> se nao ha mais letras para colocar no anagrama atual, printa-lo
  if(n == 0)
  {
    word[k] = '\0';
    printf("%s\n", word); // printando o anagrama

    return;
  }

  //se nao, percorrer todas as letras que ainda nao foram usadas e fazer a recursao
  for(int i=0; i<(n+k); i++)
  {
    
    if(!letra_usada[i] && word[k] != string_ordenada[i]) // assim ja verifica se ainda nao foi usada e se um caracter igual ja foi
                                                         // usado na mesma chamada, sem precisar percorrer toda a string de novo
                                                         // -> letra_usada serve mais para as chamadas subsequentes
    {
      word[k] = string_ordenada[i];
      letra_usada[i] = 1;
      generate(string_ordenada, letra_usada, word, n-1, k+1);
      letra_usada[i] = 0;
    }
  }

  word[k] = '\0';

  return;
}
