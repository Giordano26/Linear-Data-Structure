/*
  Arquivo: Stefano_Giordano_OpListas.c
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 22/03/2021
  Descrição: Programa com funções de busca, criação, adição, remoção e verficação de listas
*/


#include <stdio.h>

#define Fantasma -1
#define Maximo 100
#include "booleano.h"

typedef struct
{
    int tamanho;
    int vetor[Maximo];
} Lista;

Lista criarLista(); // Cria a lista vazia

int obterTamanho(Lista); // Obtem tamanho da lista

bool verificarListaVazia(Lista); // devolve TRUE se a lista é vazia

int obterElemento(Lista, int); // devolve o item que está na posição p;

int buscarElemento(Lista, int); // devolve a posição do elemento

void mostrarLista(Lista); // mostra os elementos da lista

Lista inserirLista(Lista, int); // insere um novo item na lista ordenada

Lista removerElemento(Lista, int); // remove o item que está na posição p

void concatenar(Lista *, Lista *);

void removerPrimeiro( Lista * );

void main()
{
    return 0;
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
    int inicio = 1, fim = L.tamanho, p = Fantasma, meio = Fantasma;

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


void concatenar(Lista *ap1, Lista*ap2){

   int tam1 = obterTamanho(ap2);

   for(int k = 0 ; k < tam1; k++){
       inserirLista(ap1, obterElemento(ap2,k));
   }

   while(obterTamanho(ap2)!=0){
       removerPrimeiro(ap2);
   }

}
