#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int ra, telefone;
  char nome[100];
} Aluno;

typedef struct {
  int armazenado;
  int capacidade;
  Aluno *alunos;
} Base;

/* Funcao: criar_base
 *
 * Inicializa a base ja com a capacidade.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   n: quantidade maxima de alunos
 */
void criar_base(Base *base, int n) {

  (*base).armazenado = 0;
  (*base).capacidade = n;
  (*base).alunos = malloc(n*sizeof(Aluno));

  printf("Base criada. \n");
}

/* Funcao: buscar
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *
 * Retorno:
 *   Indice do registro com RA no vetor de alunos
 *   -1 caso contrario.
 */
int buscar(Base *base, int ra) {

  for(int i=0; i<(*base).armazenado; i++)
    if((*base).alunos[i].ra == ra)
      return i;
  
  return -1;
}

/* Funcao: imprimir
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void imprimir(Base *base, int ra) {

  int indice = buscar(base, ra);
  
  if(indice != -1)
  {
    Aluno aluno = (*base).alunos[indice];
    printf("%d - %d - %s\n", aluno.ra, aluno.telefone, aluno.nome);
  }
  else
    printf("Aluno %d nao encontrado.\n");
  
}

/* Funcoes: adicionar
 *
 * Inclui um registro sem permitir RAs duplicados.
 * O quantidade de alunos deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *   telefone: numero do telefone
 *   nome: string com o nome
 */
void adicionar(Base *base, int ra, int telefone, char *nome) {

  int indice = buscar(base, ra);

  if(indice != -1) // tem, portanto, alterar
  {
    /*
    (*base).alunos[indice].telefone = telefone;

    //(*base).alunos[indice].nome = nome; // errado -> atribuicao de um ponteiro a um tipo vetor(ja alocado de 100)
    int k=0;
    while(nome[k] != '\0')
    {
      (*base).alunos[indice].nome[k] = nome[k];
      k++;
    }
    (*base).alunos[indice].nome[k] = '\0';

    printf("Alterado: %d - %d - %s\n", ra, telefone, nome);
    return;
    */
  }

  // se chegar ate aqui eh pq nao encontrou o aluno na base. Portanto, inseri-lo

  if((*base).armazenado < (*base).capacidade)
  {
    /*
    char novoNome[100];
    int k=0;
    while(nome[k] != '\0')
    {
      novoNome[k] = nome[k];
      k++;
    }
    novoNome[k] = '\0';
    
    Aluno novoAluno = {ra, telefone, novoNome};
    (*base).alunos[(*base).armazenado] = novoAluno;
    (*base).armazenado++;
    
    printf("Adicionado: %d - %d - %s\n", ra, telefone, nome);
    return;
    */
  }

  printf("Erro: base cheia.\n");
}

/* Funcoes: remover
 *
 * Remove um registro se o ra estiver presente.
 * O quantidade de registro deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void remover(Base *base, int ra) {
  
  int indice = buscar(base, ra);

  if(indice != -1) // tem, portanto, remover
  {
    for(int i=indice; i<(*base).armazenado-1; i++)
      (*base).alunos[i] = (*base).alunos[i+1];

    (*base).armazenado--;
    printf("Aluno %d removido.", ra);
    
    return;
  }

  printf("Aluno %d nao encontrado.\n", ra);
}

/* Funcao: liberar_base
 *
 * Libera a memoria de todos alunos da base.
 * Deve deixar a base com capacidade e quantidade armazenada igual a zero
 * e o ponteiro para alunos igual a NULL.
 *
 * Parametros:
 *   base: ponteiro para a base
 */
void liberar_base(Base *base) {
  
  (*base).armazenado = 0;
  (*base).capacidade = 0;
  (*base).alunos = NULL;
}
