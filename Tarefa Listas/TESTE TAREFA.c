/*
  Arquivo: TESTE TAREFA.c
  Autor: 
  Date: 
  Descrição: Teste da tarefa - lista ordenada sem duplicatas
*/

#include <stdio.h>
#include "Booleano.h"

#define Fantasma 0
#define Maximo 51

typedef struct {
    int tamanho;
    int vetor[Maximo];
} Lista;


// construtor

Lista criarLista();
Lista construirLista(int);

// acesso

int obterTamanho(Lista);
bool verificarListaVazia(Lista);
int obterElemento(Lista, int);
int buscarElemento(Lista, int);
void mostrarLista(Lista);

// manipulação

Lista inserirLista(Lista, int);
Lista removerElemento(Lista, int);

Lista inserirLista2(Lista, int);
int buscarElemento2(Lista,int);

int main( ){
	Lista A,B;
	int local, item, tam;
	bool vazia;
	
	printf("\n lista A ");
	A = criarLista();
	mostrarLista(A);
	tam = obterTamanho(A); printf(" tamanho = %d ",tam);
	vazia = verificarListaVazia(A); printf("\n lista vazia = %d ", vazia);
	local = 1; item = obterElemento(A,local); printf("\n elemento local %d = %d ",local, item);
	item = 8; local = buscarElemento2(A,item); printf("\n busca elemento %d local = %d ",item, local);

	printf("\n inserir na lista A \n");
	A = inserirLista2(A,10);
	mostrarLista(A);
	tam = obterTamanho(A); printf(" tamanho = %d \n",tam);
	
	printf("\n inserir na lista A \n");
	A = inserirLista2(A,8);
	mostrarLista(A);
	tam = obterTamanho(A); printf(" tamanho = %d \n",tam);
	
	printf("\n inserir na lista A \n");
	A = inserirLista2(A,18);
	mostrarLista(A);
	tam = obterTamanho(A); printf(" tamanho = %d \n",tam);

    printf("\n inserir na lista A duplicata \n");
	A = inserirLista2(A,8);
	mostrarLista(A);
	tam = obterTamanho(A); printf(" tamanho = %d \n",tam);
	
	item = 8; local = buscarElemento2(A,item); printf("\n busca elemento %d local = %d ",item, local);
			
	printf("\n\n lista B \n");
	B = construirLista(10);
	mostrarLista(B);
	tam = obterTamanho(B); printf(" tamanho = %d \n",tam);
	vazia = verificarListaVazia(B); printf("\n lista vazia = %d ", vazia);
	local = 1; item = obterElemento(B,local);printf("\n elemento local %d = %d ",local, item);
	local = 5; item = obterElemento(B,local);printf("\n elemento local %d = %d ",local, item);
	local = 12; item = obterElemento(B,local);printf("\n elemento local %d = %d ",local, item);
	item = 8; local = buscarElemento(B,item); printf("\n busca elemento %d local = %d ",item, local);
	item = 21; local = buscarElemento(B,item); printf("\n busca elemento %d local = %d ",item, local);	
	
	printf("\n\n lista B inserir o item 10\n");
	B = inserirLista(B,10);
	mostrarLista(B);
	tam = obterTamanho(B); printf(" tamanho = %d \n",tam);
	
	printf("\n\n lista B remover o quinto elemento\n");
	B = removerElemento(B,5);
	mostrarLista(B);
	tam = obterTamanho(B); printf(" tamanho = %d \n",tam);
	
	printf("\n\n lista B remover o decimo elemento\n");
	B = removerElemento(B,10);
	mostrarLista(B);
	tam = obterTamanho(B); printf(" tamanho = %d \n",tam);
	
	printf("\n\n   FIM   \n");
	return 0;
}


Lista construirLista(int M){
	Lista L;
	int k;
	L.tamanho = M;
	for(k=1; k<=M;k++){
		L.vetor[k] = 2*k+1;
	}
	return L;
}
Lista criarLista()
{
    Lista newList;
    newList.tamanho = 0;

    return newList;
}

int obterTamanho(Lista list)
{
    return list.tamanho;
}

bool verificarListaVazia(Lista L)
{
    bool vazio = FALSE;

    if (L.tamanho == 0)
    {
        vazio = TRUE;
    }

    return vazio;
}

int obterElemento(Lista list, int p)
{

    if (list.tamanho > 0 && list.tamanho >= p)
    {
        return list.vetor[p];
    }

    return Fantasma;
}

int buscarElemento(Lista L, int x)
{
    int inicio = 1, fim = L.tamanho, p = Fantasma, meio;

    if (L.tamanho > 0)
    {
        do
        {
            meio = (fim + inicio) / 2;

            if (x < L.vetor[meio])
            {
                fim = meio - 1;
            }
            else
                inicio = meio + 1;

        } while (x != L.vetor[meio] && inicio <= fim);
    }

    if (x == L.vetor[meio])
    {
        p = meio;
    }

    return p;
}

void mostrarLista(Lista list)
{
	int num;
    for (num = 1; num <= list.tamanho; num++)
    {
        printf("Elemento %d : %d\n", num, list.vetor[num]);
    }
}

Lista inserirLista(Lista l, int elemento)
{
    int tamanho = l.tamanho;
    if (tamanho == 0)
    {
        l.tamanho++;
        l.vetor[1] = elemento;
    }
    else
    {
        int primeiro = 1, ultimo = tamanho;
        int meio;

        do
        {
            meio = (ultimo + primeiro) / 2;
            if (l.vetor[meio] < elemento)
            {
                primeiro = meio + 1;
            }
            else if (l.vetor[meio] > elemento)
            {
                ultimo = meio - 1;
            }

        } while (primeiro <= ultimo && l.vetor[meio] != elemento);

        if (l.vetor[meio] != elemento)
        {
            if (primeiro > tamanho)
            {
                l.vetor[primeiro] = elemento;
            }
            else
            {
                int cursor = tamanho + 1;
                while (cursor > primeiro)
                {
                    l.vetor[cursor] = l.vetor[cursor - 1];
                    cursor--;
                }
                l.vetor[primeiro] = elemento;
            }

            l.tamanho++;
        }
    }

    return l;
}

Lista removerElemento(Lista list, int p)
{
	int n;
    if (list.tamanho > 0 && list.tamanho >= p)
    {
        for (n = p; n < list.tamanho; n++)
        {
            list.vetor[n] = list.vetor[n + 1];
        }

        list.tamanho -= 1;
    }

    return list;
}
Lista inserirLista2(Lista L, int y){		// inserir lista ordenada sequencial
	int p,n,j,k;
	p = 0; n = L.tamanho;
	if (n!=0) {
		k = 1;
		while ((y > L.vetor[k]) && (k < n)) k++;
		if (y != L.vetor[k]) {
			if (y > L.vetor[k]) {  L.vetor[n+1] = y; } 
			else {  for(j=n; j>=k; j--) L.vetor[j+1] = L.vetor[j]; 
					L.vetor[k]=y;
			}
			L.tamanho ++;
		}
	} else { L.vetor[1] = y; L.tamanho = 1; }
	return L;
}



int buscarElemento2(Lista L, int y) {	// busca lista ordenada sequencial
	int p,n,k;
	p = 0; n = L.tamanho;
	if (n!=0) {
		k = 1;
		while ((y > L.vetor[k]) && (k < n)) k++;
		if (y == L.vetor[k]) p = k;
	}
	return p;
}
