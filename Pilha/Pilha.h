#include "booleano.h"

#define Max 100
#define ghost 36
#define sinal 0

typedef struct
{
    int topo;
    char vetor[Max];
} Pilha;

void criarPilha(Pilha *ap)
{
    ap->topo = sinal;
    ap->vetor[0] = Max - 1;
}

void pushPilha(Pilha *ap, char ch)
{
    int k;
    if (ap->topo != Max - 1)
    {
        k = ap->topo + 1;
        ap->vetor[k] = ch;
        ap->topo = k;
    }
}

void popPilha(Pilha *ap)
{
    int k;
    if (ap->topo != sinal)
    {
        k = ap->topo;
        ap->topo = k - 1;
    }
}

char acessarPilha(Pilha *ap)
{
    int k;
    char y;
    if (ap->topo == sinal)
        y = ghost;
    else
    {
        k = ap->topo;
        y = ap->vetor[k];
    }
    return y;
}

bool PilhaVazia(Pilha *ap)
{
    bool vazia;
    if (ap->topo == sinal)
        vazia = TRUE;
    else
        vazia = FALSE;
    return vazia;
}
