#include <stdio.h>
#include <stdlib.h>
#include "Stefano_Giordano_AT3.h"


int main() {
	int i;
    Lista H = newLista();
    for (i = 10; i <= 50; i++) {
        H = inserir(H, i);
    }
    H = inserir(H, 5);
    H = inserir(H, 55);
    H = inserir(H, 1);
    H = inserir(H,100);
    mostrarLista(H);
    printf("\n maior numero: %d", obterMaximo(H));

    return 0;
}