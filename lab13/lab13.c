/* Laboratorio 15 - Conjuntos
 * Nome: Pedro Barros Bastos
 * RA: 204481

    Este arquivo contém funções que serão usadas para operações
  sobre conjuntos, realizadas pelo main() contida no arquivo lab13_main.c
  Os metodos que neste arquivo constam sao:

    int pertence(char conj[], int tam, char letra);
    int contido(char conj1[], char conj2[], int tam1, int tam2);
    int adicao(char conj[], int tam, char letra);
    int subtracao(char conj[], int tam, char letra);
    int uniao(char destRes[], char conj1[], char conj2[], int tam1, int tam2);
    int intersecao(char destRes[], char conj1[], char conj2[], int tam1, int tam2);
    int diferenca(char destRes[], char conj1[], char conj2[], int tam1, int tam2);
    int complemento(char conjRes[], char conj[], int tam);

    As descricoes de cada metodo os precedem. Tambem foi colocada neste arquivo
  uma funcao para ordenacao de um conjunto, apos verificacao de sua necessidade
  para o metodo de computo da uniao entre dois conjuntos (os conjuntos passados 
  como parametro nao estao ordenados)

 */

#include <stdio.h>

void ordena_certo(char vet[], int tam) {
  int i, j;
  char aux;

  for (i = tam - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (vet[j] > vet[j + 1]) {
        aux = vet[j];
        vet[j] = vet[j + 1];
        vet[j + 1] = aux;
      }
    }
  }
}

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

  for(int i=0; i<tam; i++)
    if(conj[i] == letra) // se encontrar a letra que esta procurando retorna verdadeiro
      return 1;

  return 0; // se chegar aqui, nao encontrou letra procurada
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

  for(int i=0; i<tam1; i++) {
    
    int letraAtualContida = 0;

    for(int j=0; j<tam2; j++) {
      if(conj2[j] == conj1[i]) { // verifica se cada elemento do conjunto1 (primeiro for)
                                 // tambem esta no conjunto2 (segundo for)
        letraAtualContida = 1;
        break;
      }
    }

    if (!letraAtualContida) // quando chegar aqui e letraAtualContida for falso, algum elemento
                            // do conjunto1 nao esta no conjunto2, podendo se retornar falso
      return 0;
  }

  return 1; // se chegou ate aqui, todos os elementos de conj1 estao contidos em conj2 -> verdadeiro
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

  if(!pertence(conj, tam, letra)) {
  
    /*
    Isso nao da certo pq se cria um ponteiro local a esta funcao,
    que quando sair, deixara de existir. Se este ponteiro for atribuido
    ao vetor passado como parametro, o vetor tbem acabara ao final
    ficando com lixo por conta da anulacao da variavel local usada
    para a operacao

    char conjNovo[tam+1];
    
    for(int i=0; i<tam; i++)
      conjNovo[i] = conj[i];

    conjNovo[tam] = letra;

    conj = conjNovo;
    */

    //verificando que a letra passada nao esta no conjunto passado, a adiciona
    //na ultima posicao e retorna o tamanho + 1

    conj[tam] = letra;
    return tam+1;
  }

  return tam; // se ja esta no conjunto, so retorna o tamanho atual passado
}

int subtracao(char conj[], int tam, char letra){

  if(pertence(conj, tam, letra)) {

    /*
    Isso nao da certo pq se cria um ponteiro local a esta funcao,
    que quando sair, deixara de existir. Se este ponteiro for atribuido
    ao vetor passado como parametro, o vetor tbem acabara ao final
    ficando com lixo por conta da anulacao da variavel local usada
    para a operacao

    char conjNovo[tam-1];

    int j = 0;
    for(int i=0; i<tam; i++)
      if(conj[i] != letra) {
        conjNovo[j] = conj[i];
        j++;
      }

    conj = conjNovo;
    */

    //se a letra passada esta contida no conjunto a retira deste e retorna o tamanho - 1

    for(int i=0; i<tam; i++) // for ate achar o indice da letra procurada
      if(conj[i] == letra) {
        
        for(int j=i; j<tam-1; j++) // dai em diante, deslocar o vetor para apagar a letra do vetor
          conj[j] = conj[j+1];

        break;
      }


    return tam-1;
  }

  return tam; // se nao esta no vetor, devolve-se o tamanho atual passado
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

  /*
  Aqui imprimi os dois conjuntos para verificar se estavam entrando na funcao ja ordenados.
  Assim, vendo que nao estavam, chama-se o metodo deste .c para realizar a ordenacao

  for(int i=0; i<tam1; i++)
    printf("%c", conj1[i]);

  printf("--------------------");

  for(int i=0; i<tam2; i++)
    printf("%c", conj2[i]);

  return 0; 
  */

  //aqui usa-se a ideia de intercalacao de vetores para realizar a uniao
  //para tanto, os dois conjuntos ja devem estar  ordenados

  ordena_certo(conj1, tam1);
  ordena_certo(conj2, tam2);

  int tamRes = tam1 + tam2;

  for(int i=0; i<tam1; i++)
    if(pertence(conj2, tam2, conj1[i]))
      tamRes--; // decresce da soma dos tamanhos as ocorrencias de elementos iguais

  int indice1 = 0, indice2 = 0, k = 0;

  while(indice1 < tam1 && indice2 < tam2) {

    if(conj1[indice1] == conj2[indice2]) {

      conjRes[k] = conj1[indice1]; // ou = conj2[indice2];
      indice1++;
      indice2++;

    } else {

      if(conj1[indice1] < conj2[indice2]) {

        conjRes[k] = conj1[indice1];
        indice1++;

      } else {

        conjRes[k] = conj2[indice2];
        indice2++;

      }
    }

    k++;
  }

  while(indice1 < tam1) {
    conjRes[k] = conj1[indice1];
    indice1++;
    k++;
  }

  while(indice2 < tam2) {
    conjRes[k] = conj2[indice2];
    indice2++;
    k++;
  }

  return tamRes;
}

int intersecao(char conjRes[], char conj1[], char conj2[], int tam1, int tam2){

  int tamRes = 0;

  for(int i=0; i<tam1; i++)
    if(pertence(conj2, tam2, conj1[i]))
      tamRes++; // acresce-se a ocorrencia de elementos iguais

  int k = 0;

  for(int i=0; i<tam1; i++)
    if(pertence(conj2, tam2, conj1[i])) {
      conjRes[k] = conj1[i]; // quando um elemento pertencente aos dois conjuntos, passa-o para conjRes
      k++;
    }

  return tamRes;
}

int diferenca(char conjRes[], char conj1[], char conj2[], int tam1, int tam2){

  int tamRes = 0;

  for(int i=0; i<tam1; i++)
    if(!pertence(conj2, tam2, conj1[i]))
      tamRes++; // acresce-se a ocorrencia de elemetos de conj1 que nao pertencem a conj2

  int k = 0;

  for(int i=0; i<tam1; i++)
    if(!pertence(conj2, tam2, conj1[i])) {
      conjRes[k] = conj1[i]; // copia os elementos de conj1 que nao pertencem a conj2 para conjRes
      k++;
    }

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

  return diferenca(conjRes, U, conj, 26, tam); // diferenca com todo o alfabeto ingles
}

