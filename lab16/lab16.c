#include <stdio.h>
#include <stdlib.h>

/*
------------------------------------------------------------------------------------------------------------
Aluno(a): Pedro Barros Bastos
RA: 204481
------------------------------------------------------------------------------------------------------------
*/


/*
------------------------------------------------------------------------------------------------------------
void ordena(int *conj, int tam);


Esta funcao deve ordenar um conjunto dado como parametro.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;

------------------------------------------------------------------------------------------------------------
*/

void ordena(int *conj, int tam) {
  int i, j;
  int aux;

  for (i = tam - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (conj[j] > conj[j + 1]) {
        aux = conj[j];
        conj[j] = conj[j + 1];
        conj[j + 1] = aux;
      }
    }
  }
}

/*
------------------------------------------------------------------------------------------------------------
int pertence(int *conj, int tam, int elemento);


Esta funcao deve verificar se um elemento esta presente no conjunto.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;
- elemento -> Elemento no qual deve ser ser verificado se esta presente no conjunto;

Retorno

- 1 Caso o elemento PERTENCA conjunto;
- 0 Caso o elemento NAO PERTENCA ao conjunto;

------------------------------------------------------------------------------------------------------------
*/

int pertence(int *conj, int tam, int elemento) {

  for(int i=0; i < tam; i++)
    if(conj[i] == elemento)
      return 1;

  return 0;
}

/*
------------------------------------------------------------------------------------------------------------
int contido(int *conj_A, int *conj_B, int tam_A, int tam_B);


Esta funcao deve verificar se o conjunto A esta contido no conjunto B.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_B -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;

Retorno

- 1 Caso o conjunto A ESTEJA CONTIDO no conjunto B;
- 0 Caso o conjunto A NAO ESTEJA CONTIDO no conjunto B;

------------------------------------------------------------------------------------------------------------
*/

int contido(int *conj_A, int *conj_B, int tam_A, int tam_B) {

  for(int i=0; i<tam_A; i++) {
    
    int elementoAtualContido = 0;

    for(int j=0; j<tam_B; j++) {
      if(conj_B[j] == conj_A[i]) { // verifica se cada elemento do conjuntoA (primeiro for)
                                 // tambem esta no conjuntoB (segundo for)
        elementoAtualContido = 1;
        break;
      }
    }

    if (!elementoAtualContido) // quando chegar aqui e letraAtualContida for falso, algum elemento
                            // do conjunto1 nao esta no conjunto2, podendo se retornar falso
      return 0;
  }

  return 1; // se chegou ate aqui, todos os elementos de conjA estao contidos em conjB -> verdadeiro
}

/*
------------------------------------------------------------------------------------------------------------
int* init(int *tam, int *cap);


Esta funcao deve inicializar um vetor(conjunto).

Parametros:
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;

OBS:
- A capacidade inicial do vetor(conjunto) deve ser 2.
- O quantidade inicial de elementos no vetor(conjunto) deve ser zero.
- Nao confundir capacidade com quantidade de elementos.

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* init(int *tam, int *cap) {
  int *conj;

  *tam = 0;
  *cap = 2;

  conj = malloc(2*sizeof(int));
  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* adicao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve adicionar um novo elemento no conjunto, ou seja, se o elemento ja pertence ao 
conjunto o mesmo NAO deve ser adicionado.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser adicionado;

OBS:
- Ao adicionar um novo elemento o tamanho atual do conjunto devera ser atualizado;
- Caso o ponteiro para o conjunto seja NULL, o conjunto devera ser alocado com uma capacidade de dois (02) 
e a atualizacao da capacidade deverar ser feita;
- Caso a quantidade de elementos do conjunto seja igual a capacidade do conjunto e um novo elemento tenha que 
ser inserido, então o conjunto tera de ser realocado com o dobro da capacidade e a capcidade do conjunto 
devera ser atualizada;

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------

*/

int* adicao(int *conj, int *tam, int *cap, int elemento) {

  if(conj == NULL){
    int *novo_conj = init(tam, cap);
    return novo_conj;
  }

  if(!pertence(conj, *tam, elemento)) {

    if(*tam == *cap) { // o conjunto tera de ser realocado com o dobro da capacidade

      *cap = 2*(*cap);
      int *novo_conj = malloc((*cap)*sizeof(int));

      for (int i=0; i < *tam; i++)
        novo_conj[i] = conj[i];
      
      novo_conj[*tam] = elemento;
      *tam = *tam + 1;

      //conj = novo_conj;
      //return conj; --> isso aqui nao pode -> quando sair do metodo, novo_conj deixara de existir, o que
      //tbem acabara ocorrendo com conj
      return novo_conj;
    }

    conj[*tam] = elemento;
    *tam = *tam + 1;
    return conj;
  }
  
  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* subtracao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve remover um elemento no conjunto caso ele exista.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser removido;

OBS:
- Ao remover um elemento o tamanho atual do conjunto devera ser atualizado;
- Caso a capacidade seja maior que dois (02) e a quantidade de elementos do conjunto seja menor ou igual que 1/4 da capacidade do conjunto, então 
o conjunto tera de ser realocado com a metade da capacidade e a capacidade do conjunto devera ser atualizada.

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* subtracao(int *conj, int *tam, int *cap, int elemento) {

  if(pertence(conj, *tam, elemento)) {

    for(int i=0; i < *tam; i++) // for ate achar o indice da letra procurada
      if(conj[i] == elemento) {
        
        for(int j=i; j < *tam-1; j++) // dai em diante, deslocar o vetor para apagar a letra do vetor
          conj[j] = conj[j+1];

        break;
      }

    *tam = *tam - 1;

    if (*cap > 2 && *tam <= (*cap/4)) {

      *cap = (*cap)/2;
      int *novo_conj = malloc((*cap)*sizeof(int));

      for (int i=0; i < *tam; i++)
        novo_conj[i] = conj[i];
      
      return novo_conj;
    }

    return conj;
  }

  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a uniao entre os conjuntos A e B. O resultado dessa uniao deve ser armazenado em 
um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {

  int *conj_C = init(tam_C, cap_C);

  for(int i=0; i<tam_A; i++)
    conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);

  for(int j=0; j<tam_B; j++)
    conj_C = adicao(conj_C, tam_C, cap_C, conj_B[j]);

  return conj_C;
}

/*
------------------------------------------------------------------------------------------------------------
int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a intersecao entre os conjuntos A e B. O resultado dessa intersecao deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
  
  //int pertence(int *conj, int tam, int elemento)
  //int* init(int *tam, int *cap)
  //int* adicao(int *conj, int *tam, int *cap, int elemento)

  //bug aqui -> quando eh necessario aumentar a capacidade do vetor de interseccao,
  //buga, colocando lixo na ultima posicao do vetor de interseccao -> mesmo bug na diferença

  // -->> ERRO IDENTIFICADO -> eh corrigido fazendo o abaixo -> conj_C recebe o retorno da
  //funçao chamada ->>> MAS o correto eh sempre devolver o proprio conjunto passado como parametro,
  //sendo que este fora alterado pela funçao => CORRIGIR CODIGO DA SOMA E SUBTRACAO, no momento em
  //que a realocação eh feita

  int *conj_C = init(tam_C, cap_C);

  for(int i=0; i<tam_A; i++)
    if(pertence(conj_B, tam_B, conj_A[i]))
      conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);

  return conj_C;
}

/*
------------------------------------------------------------------------------------------------------------
int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a diferenca entre os conjuntos A e B. O resultado dessa diferenca deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {

  int *conj_C = init(tam_C, cap_C);

  for(int i=0; i<tam_A; i++)
    if(!pertence(conj_B, tam_B, conj_A[i]))
      conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);

  return conj_C;
}
