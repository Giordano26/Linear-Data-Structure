/*
  Arquivo: Stefano_Giordano_TarefaPilha.c
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 18/04/2021
  Descrição: Funções de inverter e copiar pilha
*/

#include <stdio.h>
#include "Pilha.h"
#include "booleano.h"

void inverterPilha(Pilha *);
void copiarPilha(Pilha *, Pilha *);

int main()
{	
	/*int teste;
    Pilha testePilha;
    Pilha turaco1;

    criarPilha(&turaco1);
    criarPilha(&testePilha);

    for (teste = 65; teste < 91; teste++)
    {
        pushPilha(&testePilha, teste);
        char zape = acessarPilha(&testePilha);
        printf("%c", zape);
    }
    copiarPilha(&testePilha, &turaco1);

    inverterPilha(&testePilha);

    printf("\n\n");

    for (teste = 1; teste <= 26; teste++)
    {
        char zape = testePilha.vetor[teste];
        printf("%c", zape);
    }

    copiarPilha(&testePilha, &turaco1);

    printf("\n\n");
    printf("Turaco1: ");
    for (teste = 1; teste <= 52; teste++)
    {
        char zape = turaco1.vetor[teste];
        printf("%c", zape);
    }

    printf("\n\n");
    printf("Turaco-INTEGRO: ");

    for (teste = 1; teste <= 26; teste++)
    {
        char zape = testePilha.vetor[teste];
        printf("%c", zape);
    }*/
    printf("\n\nFIM\n\n");
    return 0;
}

void inverterPilha(Pilha *ap)
{
    Pilha aux1;
    Pilha aux2;

    criarPilha(&aux1);
    criarPilha(&aux2);

    if(!PilhaVazia(ap)){
        do{
            pushPilha(&aux1, acessarPilha(ap));
            popPilha(ap);

        }while(!(PilhaVazia(ap)));

        do{
            pushPilha(&aux2, acessarPilha(&aux1));
            popPilha(&aux1);

        }while(!PilhaVazia(&aux1));

        do{
            pushPilha(ap,acessarPilha(&aux2));
            popPilha(&aux2);

        }while(!PilhaVazia(&aux2));
    }
}

void copiarPilha(Pilha *ap1, Pilha *ap2)
{
    Pilha aux1;
    criarPilha(&aux1);

    if(!PilhaVazia(ap1)){
        do{
            pushPilha(&aux1, acessarPilha(ap1));
            popPilha(ap1);

        }while(!(PilhaVazia(ap1)));

        do{
            pushPilha(ap2, acessarPilha(&aux1));
            pushPilha(ap1, acessarPilha(&aux1));
            popPilha(&aux1);
        }while(!(PilhaVazia(&aux1)));
    }
}
