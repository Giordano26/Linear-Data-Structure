/*
  Arquivo: Stefano_Giordano_TarefaBuffer.c
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 18/04/2021
  Descrição: Funções de buffer de editor de texto: delete,insert,back e start
*/


#include <stdio.h>
#include "Pilha.h"
#include "booleano.h"

void editar(int, Pilha *, Pilha *, char);

int main()
{
    printf("\n\nFIM\n\n");
    return 0;
}

void editar(int op, Pilha *PilhaA, Pilha *PilhaB, char c)
{
    switch (op)
    {
    case 1: //funcao Delete
        popPilha(PilhaB);
        break;
    case 2: // funcao insert
        pushPilha(PilhaA, c);
        break;
    case 3:// funcao back
        popPilha(PilhaA);
        break;
    case 4:// funcao start
        while(!(PilhaVazia(PilhaA))){
            pushPilha(PilhaB, acessarPilha(PilhaA));
            popPilha(PilhaA);
        }
        break;
    case 5:// funcao end
       while(!(PilhaVazia(PilhaB))){
            pushPilha(PilhaA, acessarPilha(PilhaB));
            popPilha(PilhaB);
        }
    }
}
