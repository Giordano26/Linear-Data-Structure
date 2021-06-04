/*
  Arquivo: Stefano_Giordano_ListaLigada.c
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 16/05/2021
  Descrição: Funções com lista ligada
*/

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define fantasma 49
typedef struct Celula {
    char item;
    struct Celula * next;
} Celula;
typedef Celula * Lista;

Lista newLista( ); // cria uma lista vazia	
bool ListaVazia(Lista); // devolve TRUE se a lista é vazia	
int obterTamanho(Lista); // retorna o tamanho da lista
char obterElemento(Lista, int); // devolve o registro de ordem k na lista 
Celula * buscarItem(Lista, int); //  devolve o endereço do registro que contém y ou NULL
void mostrarLista(Lista); // mostra na tela os elementos da lista
Lista inserirLista(Lista, char); // acrescenta um novo elemento ao inicio da lista
Lista removerPrimeiro(Lista); // remove o primeiro registro
Lista esvaziarLista(Lista); // torna a lista vazia	
Lista removerUltimo(Lista); // remove o último registro

int main(){
    Lista lolo;
    lolo = newLista();
    printf("Lista vazia?: %d\n", ListaVazia(lolo));
    printf("Inserção na lista começa...\n");
    lolo = inserirLista(lolo,'A');
    lolo = inserirLista(lolo,'B');
    lolo = inserirLista(lolo,'C');


    printf("Tamanho da lista: %d\n", obterTamanho(lolo));
    mostrarLista(lolo); 
    printf("Lista vazia?: %d\n", ListaVazia(lolo));
    int pos =  1;
    printf("Elemento na posição %d: %c\n",pos, obterElemento(lolo,pos));
    printf("Endereço do item na posição %d: %p\n",pos,buscarItem(lolo,pos));

    printf("Após remoção\n");
    lolo = removerUltimo(lolo);
    //lolo = removerPrimeiro(lolo);
    //lolo = esvaziarLista(lolo);
    printf("Tamanho da lista: %d\n", obterTamanho(lolo));
    mostrarLista(lolo);
    //printf("Lista vazia?: %d", ListaVazia(lolo));

    printf("Elemento na posição %d: %c\n",pos, obterElemento(lolo,pos));
    printf("Endereço do item na posição %d: %p\n",pos,buscarItem(lolo,pos));

    printf("\n\nFIM\n\n");
    return 0;
}

Lista newLista(){
  return NULL; //Cria um null pointer já que iniciamos uma lista vazia
}

Lista inserirLista(Lista list, char c){
    Lista novo = (Lista) malloc(sizeof(Lista)); //atualiza o valor do ponteiro
    if(novo != NULL){
    novo->item = c; 
    novo->next = list;
    } 
    return novo;
}

void mostrarLista(Lista list){
    Lista aux;
    if( list == NULL){
        printf("lista vazia!\n");
    }else{
        for(aux = list; aux != NULL; aux = aux->next){
            printf("Item = %c\n", aux->item);
        }
    }
    
}

bool ListaVazia(Lista list){
    bool vazia = TRUE; 
    if(list != NULL) //baseada em como iniciliazamos a lista
        vazia = FALSE;
    return vazia;
}

int obterTamanho(Lista list){
    int tamanho = 0;
    Lista aux = list;
    while(aux != NULL){
        tamanho++; //variavel que atualiza conforme cada loop ocorre, parando quando for nulo
        aux = aux->next;
    }
    return tamanho; 
}

char obterElemento(Lista list, int i){
    char elemento = fantasma; //se não existir o item, retorna o fantasma
    Lista aux = list;
    int count = 1;
    while(aux != NULL){ //roda a lista até o ponto que queremos obter o item de ordem k
        if(count == i){
            elemento = aux->item; //quando encontrar o item requerido, retorna o mesmo
            break;
        }
        count++; //varíavel para girar a lista
        aux = aux->next; //aponta para o próximo item

    }

    return elemento;
}

Celula * buscarItem(Lista list, int i){
    Celula * end = NULL; //se não houver o que buscar retorna nulo
    Lista aux = list;
    int count = 1;
    while(aux != NULL){ //roda a lista até encontrar nulo
        if(count == i){ 
            end = aux; //se for o item que buscamos retorna o endereço, já que tipo Lista é Celula *
            break;
        }
        count++; //continua o contador para rodar o loop
        aux = aux->next; // aponta para o próximo

    }

    return end;
}

Lista removerPrimeiro(Lista list){
    Lista temp = list;
    if(temp != NULL){
        list = list->next; //deixa o primeiro item como o próximo
        free(temp);
    }

    return list;
}

Lista esvaziarLista(Lista list){
    Lista no = list;
    Lista no_auxiliar = no;
    while(no != NULL){
        no_auxiliar = no;
        no = no->next;
        free(no_auxiliar);
    }
    list = NULL; //esvaziar a lista é apenas deixa-lá nula
    return list; 
}

Lista removerUltimo(Lista list){
    if(list != NULL){
        Lista temp;
        if(list->next == NULL){ //se a lista tiver apenas um item
            temp = list;
            free(temp);
            list = NULL;
        }else{
            Lista aux = list;
            while(aux->next->next != NULL){
                aux = aux->next;
            }
            free(aux->next);

            aux->next = NULL;
        }

        
    }
    return list;
}
