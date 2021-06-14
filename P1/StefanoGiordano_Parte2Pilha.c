/* TAD Pilha = pilha de reais positivos*/
/*
  Arquivo: StefanoGiordano_Parte2Pilha.c
  Autor: Stefano Giordano
  Date: 11/10/09 10:58
  Descri��o: Define e implementa o tipo de dados Pilha
  que pode guardar at� MaxPilha n�meros reais positivos. 
*/
#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define MaxPilha 10
#define Sinal 0
#define fantasma 0

typedef struct {
      int topo;	  // topo indica o local onde deve ser colocado o pr�ximo item
      float tabela[MaxPilha];
} c_Pilha;

typedef c_Pilha *Pilha;

/* construtores */
Pilha newPilha();
/* acesso */
float acessarTopo(Pilha);
bool PilhaVazia(Pilha);
bool PilhaCheia(Pilha);
/* manipula��o */
void pushPilha(Pilha, float);
void popPilha(Pilha);


int main(){
	Pilha A;
	Pilha B;

	
	A = newPilha();
	B = newPilha();
	printf("\n");
	
	printf("Pilha A vazia?: %d",PilhaVazia(A));
	printf("\n");
	pushPilha(A,5.5);
	printf("PILHA A: %.2f",acessarTopo(A));
	printf("\n");
	pushPilha(A,-5.6);
	printf("PILHA A: %.2f",acessarTopo(A));
	printf("\n");
	pushPilha(A,5.7);
	printf("PILHA A: %.2f",acessarTopo(A));
	printf("\n");

	popPilha(A);
	printf("PILHA A: %.2f",acessarTopo(A));
	printf("\n");
	popPilha(A);
	printf("PILHA A: %.2f",acessarTopo(A));
	printf("\n");
	popPilha(A);
	printf("PILHA A: %.2f",acessarTopo(A));
	printf("\n");
	
	
	pushPilha(B,5.8);
	printf("PILHA B: %.2f",acessarTopo(B));
	printf("\n");
	pushPilha(B,5.9);
	printf("PILHA B: %.2f",acessarTopo(B));
	printf("\n");
	pushPilha(B,6.0);
	printf("PILHA B: %.2f",acessarTopo(B));
	printf("\n");

	popPilha(B);
	printf("PILHA B: %.2f",acessarTopo(B));
	printf("\n");
	popPilha(B);
	printf("PILHA B: %.2f",acessarTopo(B));
	printf("\n");
	popPilha(B);
	printf("PILHA B: %.2f",acessarTopo(B));
	printf("\n");

	
	printf(" \n  FIM teste pilha \n");
	return 0;
}
		
Pilha newPilha(){		// 2.0 pontos
	Pilha P;
	P = malloc(sizeof(Pilha));
	P->topo = Sinal+1;
    P->tabela[0] = MaxPilha-1;
    return P;
}

bool PilhaVazia(Pilha P){	// 1.0 ponto 
	bool vazia;
	
	if(P->topo == Sinal + 1) 
		vazia = TRUE;
	else 
		vazia = FALSE;
	
	return vazia;
}

float acessarTopo(Pilha P){	//1.0 ponto
	float y;
	int k;
	if (P->topo == Sinal )
		y = fantasma;
	else {
		k =  P->topo;
		y = P->tabela[k-1];
	}

	return y;

}     

bool PilhaCheia(Pilha P){	// 2.0 pontos
	bool lotada;
	
	if(P->topo == MaxPilha) 
		lotada = TRUE;
	else 
		lotada = FALSE;
	
	return lotada;
}

void pushPilha(Pilha P, float y){	// 2.0 pontos
	int k;
	if(y>= 0){
		if(P->topo != MaxPilha){
		k = P->topo;
		P->tabela[k] = y;
		P->topo = k+1;
		}
	}
	
}


void popPilha(Pilha P){		// 2.0 pontos
	int k;
	if(P->topo != Sinal){
		k = P->topo;
		P->topo = k - 1;
	}
}
