/* TAD Fila */
/*
  Arquivo: StefanoGiordano_Parte2Fila
  Autor: Stefano Giordano
  Date: 07/10/09 16:16
  Descri��o: Implementa o tipo Fila como fila circular de inteiros positivos
*/

#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"

#define Geist 0
#define sinal -1
#define MaxFila 15       /* a fila pode guardar ate 15 elementos */

typedef struct {
        int inicio;  	/* inicio indica o local do primeiro da fila */
        int tam;     	/* tam � igual ao tamanho da fila */
        int item [MaxFila]; 
}Fila;                 	

Fila criarFila( );    		/* o construtor cria a fila vazia */
bool FilaVazia(Fila);  		/* devolve TRUE se a fila estiver vazia */
Fila pushFila(Fila, int);  	/* coloca o valor dado no fim da fila */
Fila popFila(Fila);       	/* retira o primeiro da fila */
Fila esvaziarFila(Fila);	/* esvazia a fila */
int acessarFila(Fila);  /* acessar fila */

int main( ){
	Fila A;

  A = criarFila();
  printf("TA VAZIA OU NAO: %d\n", FilaVazia(A));

  A = pushFila(A, 11);
  A = pushFila(A, 666);
  A = pushFila(A, 24);
  A = pushFila(A, 69);

  printf("%d", acessarFila(A));
  printf("\n");
  A = popFila(A);
  printf("%d", acessarFila(A));
  printf("\n");
  A = popFila(A);
  printf("%d", acessarFila(A));
  printf("\n");
  A = popFila(A);
  printf("%d", acessarFila(A));
  printf("\n");
  A = popFila(A);
  printf("%d", acessarFila(A));
  printf("\n");
  A = popFila(A);
  

	
	printf(" \n  FIM teste Fila \n");
	return 0;
}

Fila criarFila( ){
  Fila f1;
  f1.inicio = sinal;
  f1.tam = sinal;
  
  return f1;
}

bool FilaVazia(Fila q){
  bool vazia;
  int k = q.inicio;
  if(q.inicio == sinal)
    vazia = TRUE;
  else 
    vazia = FALSE;

  return vazia;
}

Fila pushFila(Fila q, int novo){
  int s;
  if(novo >= 0){
  s = (q.tam + 1)% MaxFila;
  if (q.inicio != s){
      q.item[s] = novo;
      if (q.inicio == sinal) q.inicio = (q.inicio + 1) % MaxFila;
      q.tam = s;
    }
  }
  return q;
}

Fila popFila(Fila q){
  if (q.inicio != sinal){
        if (q.inicio == q.tam){ q.inicio = sinal; q.tam = sinal; }
        else q.inicio = q.inicio + 1;
    }

  return q;
}

Fila esvaziarFila(Fila q){
  q.inicio = sinal;
  q.tam = sinal;

  return q;
}

int acessarFila(Fila q){
    int k, v;
    k = q.inicio;
    if (k == sinal) v = Geist;
    else v = q.item[k];
    return v;
}

