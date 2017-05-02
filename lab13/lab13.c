/* Laboratorio 15 - Conjuntos
 * Nome: Pedro Barros Bastos
 * RA: 204481
 */

#include <stdio.h>

/* Funcao: pertence
 *
 * Parametros:
 *   conj: vetor contendo o conjunto de entrada
 *    tam: tamanho do conjunto
 *  letra: elemento a ser verificado pertinencia
 *
 * Retorno:
 *   1 se letra pertence a conj e 0 caso contrario
 */
int pertence(char conj[], int tam, char letra){

  /* Implementar a funcao e trocar o valor de retorno */

  for(int i=0; i<tam; i++)
    if(conj[i] == letra)
      return 1;

  return 0;
}

/* Funcao: contido
 *
 * Parametros:
 *   conj1: vetor contendo um conjunto de entrada
 *   conj2: vetor contendo um conjunto de entrada
 *    tam1: tamanho do conjunto conj1
 *    tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   1 se conj1 esta contido em conj2 e 0 caso contrario
 */
int contido(char conj1[], char conj2[], int tam1, int tam2){
  /* Implementar a funcao e trocar o valor de retorno */

  for(int i=0; i<tam1; i++) {
    
    int letraAtualContida = 0;

    for(int j=0; j<tam2; j++) {
      if(conj2[j] == conj1[i]) {
        letraAtualContida = 1;
        break;
      }
    }

    if (!letraAtualContida)
      return 0;
  }

  return 1;
}

/* Funcoes: adicao e subtracao
 *
 * Parametros:
 *   conj: vetor contendo o conjunto que tera incluso ou removido o elemento
 *    tam: tamanho do conjunto
 *  letra: elemento a ser adicionado ou removido
 *
 * Retorno:
 *   tamanho do conjunto apos a operacao.
 */
int adicao(char conj[], int tam, char letra){
  /* Implementar a funcao e trocar o valor de retorno */

  if(!pertence(conj, tam, letra)) {
  
    /*
    char conjNovo[tam+1];
    
    for(int i=0; i<tam; i++)
      conjNovo[i] = conj[i];

    conjNovo[tam] = letra;

    conj = conjNovo; */

    conj[tam] = letra;

    return tam+1;
  }

  return tam;
}

int subtracao(char conj[], int tam, char letra){
  /* Implementar a funcao e trocar o valor de retorno */

  if(pertence(conj, tam, letra)) {
    char conjNovo[tam-1];

    int j = 0;
    for(int i=0; i<tam; i++)
      if(conj[i] != letra) {
        conjNovo[j] = conj[i];
        j++;
      }

    conj = conjNovo;
    return tam-1;
  }

  return tam;
}

/* Funcoes: uniao, intersecao e diferenca
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *     conj1: vetor contendo o conjunto de entrada do primeiro operando
 *     conj2: vetor contendo o conjunto de entrada do segundo operando
 *      tam1: tamanho do conjunto conj1
 *      tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int uniao(char conjRes[], char conj1[], char conj2[], int tam1, int tam2){
  /* Implementar a funcao e trocar o valor de retorno */

  int tamRes = tam1 + tam2;

  for(int i=0; i<tam1; i++)
    if(pertence(conj2, tam2, conj1[i]))
      tamRes--;

  char conjNovo[tamRes];
  int indice1 = 0, indice2 = 0, k = 0;

  while(indice1 < tam1 && indice2 < tam2) {

    if(conj1[indice1] == conj2[indice2]) {

      conjNovo[k] = conj1[indice1]; // ou = conj2[indice2];
      indice1++;
      indice2++;

    } else {

      if(conj1[indice1] < conj2[indice2]) {

        conjNovo[k] = conj1[indice1];
        indice1++;

      } else {

        conjNovo[k] = conj2[indice2];
        indice2++;

      }
    }

    k++;
  }

  while(indice1 < tam1) {
    conjNovo[k] = conj1[indice1];
    indice1++;
    k++;
  }

  while(indice2 < tam2) {
    conjNovo[k] = conj2[indice2];
    indice2++;
    k++;
  }

  conjRes = conjNovo;
  return tamRes;
}

int intersecao(char conjRes[], char conj1[], char conj2[], int tam1, int tam2){
  /* Implementar a funcao e trocar o valor de retorno */

  int tamRes = 0;

  for(int i=0; i<tam1; i++)
    if(pertence(conj2, tam2, conj1[i]))
      tamRes++;

  char conjNovo[tamRes];
  int k = 0;

  for(int i=0; i<tam1; i++)
    if(pertence(conj2, tam2, conj1[i])) {
      conjNovo[k] = conj1[i];
      k++;
    }

  conjRes = conjNovo;
  return tamRes;
}

int diferenca(char conjRes[], char conj1[], char conj2[], int tam1, int tam2){
  /* Implementar a funcao e trocar o valor de retorno */

  int tamRes = 0;

  for(int i=0; i<tam1; i++)
    if(!pertence(conj2, tam2, conj1[i]))
      tamRes++;

  char conjNovo[tamRes];
  int k = 0;

  for(int i=0; i<tam1; i++)
    if(!pertence(conj2, tam2, conj1[i])) {
      conjNovo[k] = conj1[i];
      k++;
    }

  conjRes = conjNovo;
  return tamRes;
}


/* Funcao: complemento
 * Guarda em conjRes o resultado da operação U-conj, onde U é o conjunto 
 * de todas as letras minusculas do alfabeto ingles
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *      conj: vetor contendo o conjunto de entrada do primeiro operando
 *       tam: tamanho do conjunto conj
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int complemento(char conjRes[], char conj[], int tam){
  /* Implementar a funcao e trocar o valor de retorno */

  char U[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                'y', 'z'};

  return diferenca(conjRes, U, conj, 26, tam);
}

