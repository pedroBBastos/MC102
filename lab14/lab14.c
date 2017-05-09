#include <stdio.h>

/*
        Este programa tem por objetivo realizar operacoes como impressão, ordenação, inclusao
    remocao e busca de alunos matriculados em uma turma para auxiliar o sistema de gerenciamento
    de turmas da DAC.
        Primeiro, insere-se um determinado numero de RAs para posteriormente apresentar um menu
    para que seja possivel realizar as opcoes acima descritas na lista de RAs passados
        A saida eh apresentada quando, do menu, se escolhe a opcao de imprimir os RAs para ver
    o resultado das operacoes efetuadas. Tambem, para cada caso, sao imprimidos os casos em que determinadas
    operacoes nao podem ser realizadas, como remover alunos de uma lista vazia, etc.

    Nome : Pedro Barros Bastos      RA : 204481

*/

/*
    Metodo que, dada uma entrada lida do teclado, opera sobre
    a string desta e monta o RA como um numero inteiro
*/
int leRA(char entrada[])
{
    int procurado = 0;
    int i = 2, fator = 100000;

    while(entrada[i] != '\n' && entrada[i] != '\0')
    {
        procurado = procurado + (entrada[i]-48)*fator;
        fator = fator/10;
        i++;
    }

    return procurado;
}

/*
    Metodo para pesquisar determinado item linearmente
*/
int pesquisaLinear(int item, int v[], int tam)
{
    for(int i=0; i<tam; i++)
        if(v[i] == item)
            return 1;
    
    return 0;
}

/*
    Metodo que verifica se determinada lista de RAs esta ordenada
    crecentemente.
*/
int estaOrdenadoCrescentemente(int v[], int tam)
{
    for(int i=0; i<tam-1; i++)
        if(v[i] > v[i+1]) // se o da esquerda for maior que o da direita
            return 0;

    return 1;
}

/*
    Metodo que verifica se determinada lista de RAs esta ordenada
    decrecentemente.
*/
int estaOrdenadoDecrescentemente(int v[], int tam)
{
    for(int i=0; i<tam-1; i++)
        if(v[i] < v[i+1]) // se o da esquerda for menor que o da direita
            return 0;

    return 1;
}

/*
    Metodo para remover RA da lista
*/
int removeElemento(char entrada[], int v[], int tam)
{
    /*
        - casos a se considerar na remocao
            - quando a turma nao possui alunos matriculados
            - quando o RA nao esta na lista
    */

    int elemento = leRA(entrada);

    if(tam == 0)
    {
        printf("Nao ha alunos cadastrados na turma!\n");
        return tam;
    }

    if(!pesquisaLinear(elemento, v, tam))
    {
        printf("Aluno nao matriculado na turma!\n");
        return tam;
    }

    int i=0;
    while(v[i] != elemento)
        i++;

    for(int j=i; j<tam-1; j++)
        v[j] = v[j+1];

    return --tam;
}

/*
    Metodo para inserir RA na lista
*/
int insereElemento(char entrada[], int v[], int tam)
{
    /*
        - casos a se considerar na insercao
            - quando a turma atingiu o limite de 150 alunos - ok
            - quando o cara a inserir ja esta na turma - ok
            - quando o vetor estiver ordenado, deve-se colocar o RA de forma correta.
            Se não, colocar na ultima posicao
    */

    int elemento = leRA(entrada);

    if(tam == 150)
    {
        printf("Limite de vagas excedido!\n");
        return tam;
    }

    if(pesquisaLinear(elemento, v, tam))
    {
        printf("Aluno ja matriculado na turma!\n");
        return tam;
    }

    if(estaOrdenadoCrescentemente(v, tam))
    {
        int i=0;

        while(i < tam && v[i] < elemento)
            i++;

        for(int j=tam; j>i; j--)
            v[j] = v[j-1];

        v[i] = elemento;
    }
    else
        if(estaOrdenadoDecrescentemente(v, tam))
        {
            int i=0;

            while(i < tam && v[i] > elemento)
                i++;

            for(int j=tam; j>i; j--)
                v[j] = v[j-1];

            v[i] = elemento;
        }
        else
        {
            v[tam] = elemento;
        }   

    return tam+1;
}

/*
    Metodo que realiza a pesquisa binaria sobre um vetor
    crescentemente ordenado
*/
void pesquisaBinariaCrescente(int procurado, int v[], int tam)
{
    int i = 0, f = tam-1;

    while(i <= f) // enquanto o vetor tiver pelo menos 1 elemento
    {
        int meio = (i+f)/2;
        printf("%d ", meio);

        if(v[meio] == procurado)
        {
            printf("\n%d esta na posicao: %d\n", v[meio], meio);
            return;
        }
        
        if(v[meio] > procurado)
            f = meio-1;
        else
            i = meio+1;
    }

    printf("\n%d nao esta na lista!\n", procurado);
}

/*
    Metodo que realiza a pesquisa binaria sobre um vetor
    decrescentemente ordenado
*/
void pesquisaBinariaDecrescente(int procurado, int v[], int tam)
{
    int i = tam-1, f = 0;

    while(i >= f) // enquanto o vetor tiver pelo menos 1 elemento
    {
        int meio = (i+f)/2;
        printf("%d ", meio);

        if(v[meio] == procurado)
        {
            printf("\n%d esta na posicao: %d\n", v[meio], meio);
            return;
        }
        
        if(v[meio] > procurado)
            f = meio+1;
        else
            i = meio-1;
    }

    printf("\n%d nao esta na lista!\n", procurado);
}

/*
    Metodo para gerenciamento de pesquisa binaria
*/
void pesquisaBinaria(char entrada[], int v[], int tam)
{
    int procurado = leRA(entrada);

    //verificando se a lista esta, de alguma forma, ordenada
    if(estaOrdenadoCrescentemente(v, tam))
        pesquisaBinariaCrescente(procurado, v, tam);
    else
        if(estaOrdenadoDecrescentemente(v, tam))
            pesquisaBinariaDecrescente(procurado, v, tam);
        else
            printf("Vetor nao ordenado!\n");
}

/*
    Metodo para ordenar crescentemente um vetor
*/
void ordenaCrescente(int v[], int tam)
{
    for(int i=0; i<tam; i++)
        for(int j=i; j<tam; j++)
            if(v[j] < v[i])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

/*
    Metodo para ordenar decrescentemente um vetor
*/
void ordenaDecrescente(int v[], int tam)
{
    for(int i=0; i<tam; i++)
        for(int j=i; j<tam; j++)
            if(v[j] > v[i])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void imprimiVetor(int v[], int tam)
{
    for(int i=0; i<tam; i++)
        printf("%d ", v[i]);

    if(tam > 0)
        printf("\n");
}

int main()
{
    int alunos[150];
    int n;

    scanf("%d", &n); // lendo qtd inicial de RAs na lista

    for(int i=0; i<n; i++)
        scanf("%d", &alunos[i]); // lendo cada RA da lista

    char entrada[10];
    for(;;)
    {
        fgets(entrada, 10, stdin);

        if(entrada[0] == 's')
            break;
        
        switch(entrada[0])
        {
            case 'p' : imprimiVetor(alunos, n); break;
            case 'c' : ordenaCrescente(alunos, n); break;
            case 'd' : ordenaDecrescente(alunos, n); break;
            case 'b' : pesquisaBinaria(entrada, alunos, n); break;
            case 'i' : n = insereElemento(entrada, alunos, n); break;
            case 'r' : n = removeElemento(entrada, alunos, n); break;
        }
    }
}