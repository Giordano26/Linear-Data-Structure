/*
  Arquivo: Stefano_Giordano_Sorting.c
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 11/04/2021
  Descrição: Teste de tempo para algoritmos de ordenção
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "TipoListaInteiro.h"


int main(){
    //definicao da lista
    ListaInt l_insertion, l_bubble, l_selection;
    //Variaveis do tipo time_t que serao responsaveis por armazenar o tempo inicial e o tempo final da execucao de uma operacao de ordenacao
    time_t inicio, fim;
    //Maior valor da faixa de inteiros da lista
    int maior_valor = 5000;
    int teste = 20; //primeiro teste solicitado com 20 itens
    //Definindo variaveis responsaveis por armazenar o tempo decorrido de cada uma das ordenacoes.
    double diferenca_selection, diferenca_insertion, diferenca_bubble;

    printf("\nTamanho da lista = %d itens\n", teste);

    construirListaAleatoria(&l_insertion, maior_valor, teste); //criação de lista aleatória com 20 itens
    copiarLista(&l_insertion,&l_bubble); //copia para as outras listas para que o teste seja o mais preciso possivel
    copiarLista(&l_insertion,&l_selection);

    printf("LISTA 1: \n");
    mostrarLista(&l_insertion);
    printf("LISTA 2: \n");
    mostrarLista(&l_bubble);
    printf("LISTA 3: \n");
    mostrarLista(&l_selection);
    printf("\n\n");

  //começo da ordenação selection
    printf("SelectionSort - ");
    ordenarListaCrescenteS(&l_selection);
    mostrarLista(&l_selection);
    printf("\n\n");

  //começo da ordenação bubble
    printf("BubbleSort - ");
    ordenarListaCrescenteS(&l_bubble);
    mostrarLista(&l_bubble);
    printf("\n\n");

  
  //começo da ordenação Insertion
    printf("InsertionSort - ");
    ordenarListaCrescenteS(&l_insertion);
    mostrarLista(&l_insertion);
    printf("\n\n");


  // ================================================================================================================
    //Teste com N numeros da Tabela, mudam de acordo com o Max no arquivo TipoListaInteiro.h (10000...20000...50000...)
    //Numero de elementos
    printf("\nTamanho da lista = %d itens", Max-1); //max é alterado para cada teste ma TipoListaInteiro.h


    //construindo a lista, que tem valores de 0 ate maior_valor, com Max-1 elementos
    construirListaAleatoria(&l_insertion, maior_valor, Max-1);
    copiarLista(&l_insertion, &l_bubble);
    copiarLista(&l_insertion, &l_selection);

    //Tempo SelectionSort
    inicio = time(NULL);
    ordenarListaCrescenteS(&l_selection);
    fim = time(NULL);


    diferenca_selection = difftime(fim,inicio);

    printf(" \n\n");
    printf("    SelectionSort - ");
    printf("  Tempo de execucao = %6.4f segundos \n",diferenca_selection);


    //Tempo InsertionSort
    inicio = time(NULL);
    ordenarListaCrescenteI(&l_insertion);
    fim = time(NULL);

    diferenca_insertion = difftime(fim,inicio);;

    printf(" \n\n");
    printf("    InsertionSort - ");
    printf("  Tempo de execucao = %6.4f segundos \n",diferenca_insertion);


    //Tempo BubbleSort
    inicio = time(NULL);
    ordenarListaCrescenteB(&l_bubble);
    fim = time(NULL);

    diferenca_bubble = difftime(fim, inicio);

    printf(" \n\n");
    printf("    BubbleSort - ");
    printf("  Tempo de execucao = %6.4f segundos \n",diferenca_bubble);

    printf("\n\nFim\n\n");
}
