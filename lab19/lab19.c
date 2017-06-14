#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  printf("----------\n");
  printf("n -> %d\n", n);
  printf("k -> %d\n", k);
  printf("----------\n");

  for(int i=0; i<k; i++)
    printf("%c", word[i]);
  printf("\n----------\n");

  for(int i=0; i<(n+k); i++)
    printf("%d, ", letra_usada[i]);
  printf("\n----------\n");
  
  if(n == 0)
  {
    word[k] = '\0';
    printf("Anagrama ->> %s\n", word); // printando o anagrama

    return;
  }
  
  for(int i=0; i<(n+k); i++) // aqui deve-se percorrer para as n letras disponíveis para tanto
  {
    // verificar se a mesma letra ja foi usada para chamadas recursivas
    //percorrer o vetor e ver se a letra atual eh igual a alguma letra ja usada
    
    if(!letra_usada[i])
    {
      int repetida = 0;
      for(int j=0; j<(n+k); j++)
	if(letra_usada[j] == 1 && letra_usada[i] == letra_usada[j])
	{
	  repetida = 1;
	  break;
	}

      if(!repetida)
      {
	word[k] = string_ordenada[i];
	letra_usada[i] = 1;
	generate(string_ordenada, letra_usada, word, n-1, k+1);
	//letra_usada[i]
      }    
    }
  }

  //zerar os usados menos o atual aqui?? - parece que sim - acaba uma chamada recursiva
  for(int i=k; i<(n+k); i++)
  {
    printf("Limpando posicao %d\n", i);
    letra_usada[i] = 0;
  }

  for(int i=0; i<(n+k); i++)
    printf("%d, ", letra_usada[i]);
  printf("\n");

  return;
}
