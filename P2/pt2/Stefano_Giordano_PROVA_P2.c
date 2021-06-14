#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor; 
    struct Celula *next;
    
} Celula ;

typedef Celula *Pilha;

//interface 
Pilha push(Pilha, int); //inserir novo inteiro na pilha circular
Pilha pop(Pilha); //remover o primeiro item da pilha circular


int main(){

    return 0;
}



Pilha push(Pilha stack, int n){
    Celula *aux;
    aux = malloc(sizeof(Celula));

    aux->valor = n;
    aux->next = stack;
    
    stack = aux;

    return stack;
}

Pilha pop(Pilha stack){
    Celula *aux;

    if(stack != NULL){
        aux = stack;
        stack = stack->next;
        free(aux);
    }
    
    return stack;
}





