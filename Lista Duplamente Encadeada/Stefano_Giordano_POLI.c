/*
  Arquivo: Stefano_Giordano_POLI.c
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 02/05/2021
  Descrição: Funções de polinomios utilizando lista duplamente encadeada
*/

#include <stdio.h>
#include <stdlib.h>
#define geist -1

typedef struct Monomio{
    float coef;
    int expo;
    struct Monomio *suc;
    struct Monomio *pre;
}Monomio;

typedef struct{
    int grau;
    Monomio *inicio;
    Monomio *fim;

}POLI;

void newPoli( POLI *); // cria o polinômio identicamente nulo
int obterGrau( POLI *); // devolve o grau do polinômio
void mostrarPoli( POLI *); // mostra na tela o polinômio ou mensagem
void copiarPoli( POLI *, POLI *); // faz uma cópia do primeiro polinômio
void somarPoli( POLI *, POLI *, POLI *);// devolve a soma dos dois primeiros polinômios.
void inserirNoFinal( POLI *, float, int); // insere um monômio no final do polinômio
void inserirNoInicio( POLI *, float, int); // insere um monômio no início do polinômio 

int main(){
    POLI px; newPoli(&px);
    inserirNoFinal(&px, 3, 4);
    inserirNoFinal(&px, 0, 2);
    inserirNoFinal(&px, 1, 1);
    inserirNoFinal(&px, 7, 2);
    inserirNoFinal(&px, 9, 0);
    mostrarPoli(&px);
    printf("Grau: %d\n", obterGrau(&px));
    POLI fx; newPoli(&fx);
    copiarPoli(&px, &fx);
    printf("Copia: ");
    mostrarPoli(&fx);
    
    POLI tx; newPoli(&tx);
    inserirNoInicio(&tx, 7, 0);
    inserirNoInicio(&tx, -1, 1);
    inserirNoInicio(&tx, 0, 2);
    inserirNoInicio(&tx, 2, 2);
    inserirNoInicio(&tx, 5, 2);
    inserirNoInicio(&tx, 4, 3);
    inserirNoInicio(&tx, 10, 3);
    inserirNoInicio(&tx, -3, 4);
    mostrarPoli(&tx);
    printf("Grau: %d\n", obterGrau(&tx));

    POLI babo; newPoli(&babo);
    copiarPoli(&tx, &babo);
    inserirNoInicio(&babo,10,10);
    printf("Alterado: ");
    mostrarPoli(&babo);
    printf("Original: ");
    mostrarPoli(&tx);
 
    POLI sum; newPoli(&sum);
    somarPoli(&px, &tx, &sum);
    mostrarPoli(&sum);
    printf("Grau: %d\n", obterGrau(&sum));


    POLI sx; newPoli(&sx);
    inserirNoFinal(&sx,-1,1);
    inserirNoInicio(&sx,2,2);
    inserirNoInicio(&sx,1,4);
    inserirNoFinal(&sx,7,0);
    mostrarPoli(&sx);
    printf("Grau: %d\n",obterGrau(&sx));
    

    printf("\n\nFIM\n\n");
    return 0;
}

void newPoli(POLI *polinom){
    polinom->inicio = NULL;
    polinom->fim = NULL;
}

int obterGrau(POLI * polinom){
    int grau = geist;
    if (polinom->inicio != NULL) {
        grau = polinom->grau;
    }
    return grau;
}

void mostrarPoli( POLI * polinom){
    if(polinom->inicio == NULL){
        printf("Polinomio não contém nada!\n");
    }else{
    printf("P(x) = ");
    Monomio *atual = polinom->inicio;
    while(atual != NULL){
        if(atual->coef > 0){
            printf("+ %.1fx^%d ", atual->coef, atual->expo);
        }else{
            printf(" %.1fx^%d ", atual->coef, atual->expo);
        }
        atual = atual->suc;
        }
    }
    printf("\n");
    
}

void copiarPoli(POLI *poli1, POLI *poli2){
    Monomio *atual = poli1->inicio;
        
        while(atual != NULL){

            if(poli2->inicio != NULL){
                Monomio *copiar = (Monomio*) malloc(sizeof(Monomio));
                copiar->coef = atual->coef;
                copiar->expo = atual->expo;
                poli2->fim->suc = copiar;
                copiar->pre =poli2->fim;
                copiar->suc = NULL;
                poli2->fim = copiar;
                atual = atual->suc;
                
            }else{
                Monomio *copiar = (Monomio*) malloc(sizeof(Monomio));
                copiar->coef = atual->coef;
                copiar->expo = atual->expo;
                poli2->inicio = copiar;
                poli2->grau = copiar->expo;
                copiar->pre = poli2->fim;
                copiar->suc = NULL;
                poli2->fim = copiar;  
                atual = atual->suc;                             
            }

        }
    }


void somarPoli( POLI *p1, POLI *p2, POLI *p_soma){
    Monomio *atual_p1 = p1->inicio;
    Monomio  *atual_p2 = p2->inicio;
    while(atual_p1 != NULL && atual_p2 != NULL){
        if(atual_p1->expo == atual_p2->expo){
            float coeficiente = atual_p1->coef + atual_p2->coef;
            if(coeficiente != 0){
                Monomio *inserir = (Monomio*) malloc(sizeof(Monomio));
                inserir->coef = coeficiente;
                inserir->expo = atual_p1->expo;
                if(p_soma->inicio == NULL){
                    p_soma->inicio = inserir;
                    p_soma->grau = inserir->expo;
                }else{
                    p_soma->fim->suc = inserir;
                }
                inserir->pre = p_soma->fim;
                inserir->suc = NULL;
                p_soma->fim = inserir;
            }
            atual_p1 = atual_p1->suc;
            atual_p2 = atual_p2->suc;
        }else{
            Monomio *inserir = (Monomio*) malloc(sizeof(Monomio));
            if(atual_p1->expo > atual_p2->expo){

                inserir->coef = atual_p1->coef;
                inserir->expo = atual_p1->expo;
                if(p_soma->inicio == NULL){
                    p_soma->inicio = inserir;
                    p_soma->grau = inserir->expo;
                }else{
                    p_soma->fim->suc = inserir;
                }
                inserir->pre = p_soma->fim;
                inserir->suc = NULL;
                p_soma->fim = inserir;
                atual_p1 = atual_p1->suc;
            }else{
                inserir->coef = atual_p2->coef;
                inserir->expo = atual_p2->expo;
                if(p_soma->inicio == NULL){
                    p_soma->inicio = inserir;
                    p_soma->grau = inserir->expo;
                }else{
                    p_soma->fim->suc = inserir;
                }
                inserir->pre = p_soma->fim;
                inserir->suc = NULL;
                p_soma->fim = inserir;
                atual_p2 = atual_p2->suc;
            }
        }
    }
    if(atual_p1 != NULL){
        do{
            Monomio *inserir = (Monomio*) malloc(sizeof(Monomio));
            inserir->coef = atual_p1->coef;
            inserir->expo = atual_p1->expo;
            if(p_soma->inicio == NULL){
                p_soma->inicio = inserir;
                p_soma->grau = inserir->expo;
            }else{
                p_soma->fim->suc = inserir;
            }
            inserir->pre = p_soma->fim;
            inserir->suc = NULL;
            p_soma->fim = inserir;
            atual_p1 = atual_p1->suc;
        }while(atual_p1 != NULL);
    }else if (atual_p2 != NULL){
        do{
            Monomio *inserir = (Monomio*) malloc(sizeof(Monomio));
            inserir->coef = atual_p2->coef;
            inserir->expo = atual_p2->expo;
            if(p_soma->inicio == NULL){
                p_soma->inicio = inserir;
                p_soma->grau = inserir->expo;
            }else{
                p_soma->fim->suc = inserir;
            }
            inserir->pre = p_soma->fim;
            inserir->suc = NULL;
            p_soma->fim = inserir;
            atual_p2 = atual_p2->suc;
        }while(atual_p2 != NULL);
    }
}

void inserirNoInicio( POLI *polinom, float coef, int exp) {
    Monomio *mono = (Monomio*) malloc(sizeof(Monomio));
    if(coef != 0 && exp >= 0 && polinom->fim != NULL){
        int aux = polinom->inicio->expo;
        if(exp > aux){
        mono->coef = coef;
        mono->expo = exp;
        mono->suc = polinom->inicio;
        polinom->inicio = mono;
        polinom->grau = exp;
        }
    }else if(coef != 0 && exp >= 0){
        mono->coef = coef;
        mono->expo = exp;
        mono->suc = polinom->inicio;
        polinom->inicio = mono;
        polinom->grau = exp;
        polinom->fim = mono;
    }
}


void inserirNoFinal( POLI *polinom, float coef, int exp){  
    Monomio *mono = (Monomio*) malloc(sizeof(Monomio));
    if(coef != 0 && exp >= 0 && polinom->inicio != NULL){
        int aux = polinom->fim->expo;
        if(exp < aux){
        mono->coef = coef;
        mono->expo = exp;
        polinom->fim->suc = mono;
        mono->pre =polinom->fim;
        mono->suc = NULL;
        polinom->fim = mono;
        }
    }else if(coef != 0 && exp >= 0){
        mono->coef = coef;
        mono->expo = exp;
        polinom->inicio = mono;
        polinom->grau = mono->expo;
        mono->pre = polinom->fim;
        mono->suc = NULL;
        polinom->fim = mono;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}

