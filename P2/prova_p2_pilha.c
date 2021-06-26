/* Corrigir prova p2 - pilha */
/*
  Arquivo: prova p2 pilha.c
  Autor: Lisbete Madsen Barbosa
  Date: 04/10/10 06:45
  Descrição: testes prova P2 - Pilha em lista circular
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct Celula{
    int valor;
    struct Celula *next;
}Celula;

typedef Celula * Pilha;

Pilha criarPilhaVazia();
void mostrarPilha(Pilha);

Pilha push(Pilha, int);
Pilha pop(Pilha);

int main (){
    int k;
    Pilha c;
    c = criarPilhaVazia();
//	mostrarPilha(c);
    for(k=1;k<=5;k++){
     	c = push(c,k);
	}
	
	printf("\n"); mostrarPilha(c);
	
	c = pop(c); 	mostrarPilha(c);
	c = pop(c); 	mostrarPilha(c);
	c = pop(c); 	mostrarPilha(c);
	c = pop(c); 	mostrarPilha(c);
	c = pop(c); 	mostrarPilha(c);

    printf("\n");
    return 0;
}


Pilha criarPilhaVazia(){
    Pilha A;
    A = NULL;
    return A;
}


     
void mostrarPilha(Pilha L){		// a partir do primeiro
    Celula *p,*pri;
    int k;
    if (L == NULL) printf("pilha vazia \n");
    else { 
     	printf("\n pilha \n");
        p = L->next; // primeiro
        pri = p;
        do {
            k = p->valor;  printf(" %d \n", k);
            p = p->next; 
		} while (p != pri);
    }
 //   printf("\n");
}






/*
Pilha push(Pilha L, int y){
	Celula *novo, *pri;
	novo = (Celula*)malloc(sizeof(Celula));
    novo->valor = y;
    printf(" inserindo %d   ",y);
    if(L == NULL){
    	novo->next = novo;
    	L = novo;
	} else { 
		pri = L->next;  // topo da pilha
		novo->next = pri; 
		L->next = novo; 
	}	
	return L;
}


Pilha pop(Pilha L){
	Celula *pri;
	if (L != NULL){
		pri = L->next; 
		if (pri == L) L = NULL; 
		else{ L->next = pri->next; }
		free(pri);		
	}
	return L;	
}

*/
