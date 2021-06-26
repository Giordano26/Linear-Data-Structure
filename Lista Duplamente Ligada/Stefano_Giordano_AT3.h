/*
  Arquivo: Stefano_Giordano_AT3.h
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 23/06/2021
  Descrição: Funções com lista duplamente ligada 
*/
#define fantasma 0

typedef struct Celula{
    int valor;
    struct Celula *suc;
    struct Celula *pre;
} Celula;

typedef struct {
    int tamanho;
    Celula *inicio;
    Celula *fim;
} Lista;

Lista newLista();               // cria a lista vazia
void mostrarLista(Lista);       // mostra a lista a partir do primeiro
int obterMaximo(Lista);        // devolve o maior item da lista
Lista inserir(Lista, int);      // insere umnovo item na lista


Lista newLista(){
    Lista S;
    S.tamanho = 0;
    S.inicio = NULL;
    S.fim = NULL;
    return S;
}

void mostrarLista(Lista ap){
    Celula * aux = ap.inicio;
    if (ap.inicio == NULL) printf("Lista Vazia\n");
    else{
        while (aux != NULL){
            printf(" %d |", aux->valor);
            aux = aux->suc;
        }
    }
}

int obterMaximo(Lista ap){
    int maior = fantasma;
    if(ap.inicio != NULL) maior = ap.fim->valor;
    return maior;
}

Lista inserir(Lista ap, int i){
    Celula * inserir, * iteracao;
    inserir = malloc(sizeof(Celula));
    inserir->valor = i;
    inserir->pre = NULL;
    inserir->suc = NULL;

    if (ap.inicio == NULL){
        ap.inicio = inserir;
        ap.fim = inserir;
    } else{
        iteracao = ap.inicio;
        if (iteracao->valor > i) {
            inserir->suc = ap.inicio;
            ap.inicio->pre = inserir;
            ap.inicio = inserir;
        } else{
            while (iteracao != NULL && iteracao->valor < i)  iteracao = iteracao->suc;
            if (iteracao == NULL){
                inserir->pre = ap.fim;
                ap.fim->suc = inserir;
                ap.fim = inserir;
            } else{
                inserir->suc = iteracao;
                inserir->pre = iteracao->pre;
                iteracao->pre->suc = inserir;
                iteracao->pre = inserir;
            }
        }

    }
    ap.tamanho = ap.tamanho + 1;
    return ap;
}