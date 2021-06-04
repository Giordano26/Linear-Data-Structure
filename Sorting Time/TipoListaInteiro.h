/*
  Arquivo: TipoListaInteiro.h
  Autor: LISBETE MADSEN BARBOSA
  Date: 10/02/09 09:01
  Descri��o: Este programa define o tipo ListaInt com as fun��es
  necess�rias para a atividade Sorting.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

# define Max 150001

typedef struct {
	int tamanho;
	int vetor[Max];
}ListaInt;

//interface

void construirListaAleatoria(ListaInt *,int, int);
void criarLista(ListaInt *);
void copiarLista(ListaInt *, ListaInt *);

void mostrarLista(ListaInt *);

void inserirNoFim(int, ListaInt *);
void ordenarListaCrescenteS(ListaInt *);
void ordenarListaCrescenteB(ListaInt *);
void ordenarListaCrescenteI(ListaInt *);

// implementa��o

void construirListaAleatoria(ListaInt *ap, int Limite, int n){
    int i,k,g,a,b;
    double d;
    if (n > Max-1) n = Max-1;
    ap->tamanho = n;
    ap->vetor[0] = Max-1;
    a = 1;	b = Limite;
    srand((int) time(NULL));
    for(i=1; i < n+1; i++){
        d = (double)rand()/((double)RAND_MAX +1);
        k = (int)(d*(b-a));
        g = a+k;
        ap->vetor[i] = g;
    };
}

void criarLista(ListaInt *ap){         /* cria uma lista vazia */
    ap->tamanho = 0;                   /* tamanho da lista igual a zero */
    ap->vetor[0] = Max-1;              /* a posi��o zero no vetor quarda a capacidade do espa�o reservado */
}

void copiarLista(ListaInt *ap, ListaInt *bp){
    int i,n;
    n = ap->tamanho;
    bp->tamanho = n;
    bp->vetor[0] = ap->vetor[0];
    if (n!=0) for(i=1;i<=n;i++) bp->vetor[i] = ap->vetor[i];
}

void mostrarLista(ListaInt *ap){
    int n,i;
    n = ap->tamanho;
    if(n==0)printf("\n lista vazia\n");
    else{
        for(i=1;i<=n;i++){ printf(" %d ",ap->vetor[i]);}
        printf("\n");
    }
}


void inserirNoFim(int novo, ListaInt *ap){
    int m,n,p;
    m = ap->vetor[0]; n = ap->tamanho;
    if (n != m) {
        p = n+1;
        ap->vetor[p] = novo;
        ap->tamanho = p;
    }
}

void ordenarListaCrescenteS(ListaInt *ap){      /* SelectionSort: localizar o menor e colocar no seu lugar */
    int i,j,min,n,aux;
    n = ap->tamanho;                           /* n = quantidade de elementos da lista */
    for(i=1;i<n;i++){                          /* n-1 etapas  */
        min = i;                                                                  /* min = local onde se encontra o menor */
        for(j=i+1;j<=n; j++) if (ap->vetor[j] < ap->vetor[min]) min = j;          /* atualiza��o de min */
        aux = ap->vetor[i]; ap->vetor[i] = ap->vetor[min]; ap->vetor[min] = aux;   /* troca com o menor */
    }
}

void ordenarListaCrescenteB(ListaInt *ap){      /* BubbleSort: trocar pares consecutivos fora da ordem */
    int i,j,fim,n,aux;
    n = ap->tamanho;                           /* n = quantidade de elementos da lista */
    fim = n-1;
    for(i=1;i<n;i++){                          /* n-1 etapas  */
        for(j=1;j<=fim; j++){                   /* comparar/trocar do primeiro ao penultimo */
            if (ap->vetor[j] > ap->vetor[j+1]){
                 aux = ap->vetor[j]; ap->vetor[j] = ap->vetor[j+1]; ap->vetor[j+1] = aux;
            };
        }
        fim = fim -1;
    }
}

void ordenarListaCrescenteI(ListaInt *ap){      /* InsertionSort - ordena��o por inser��o */
    int i,k,n,aux;
    n = ap->tamanho;                           /* n = quantidade de elementos da lista */
    for(i=2;i<=n;i++){                         /* n-1 etapas  */
        aux = ap->vetor[i];
        k = i-1;
        while ((k>0) && (ap->vetor[k] > aux)) {ap->vetor[k+1] = ap->vetor[k]; k = k - 1;}  /* desloca */
        ap->vetor[k+1] = aux;                                                              /* insere  */
	}
}
