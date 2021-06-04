/* Template - cabeçalho da atividade */
/*
  Arquivo: Stefano_Giordano.c
  Autor: Matheus Madureira Fortunato | Humberto Chiesi Neto | Antonio Mello Babo | Stefano Martins Ferreira Giordano
  Date: 08/03/21 14:46
  Descrição: Um programa que mostra todas as escolhas possiveis no caso em que a capacidade da mochila eh igual a  N = 12, considerando que ha somente 9 produtos com pesos de 1 a 9.
*/

#include <stdio.h>

int main(){

	int N = 12;
	int nprodutos = 9;
	int x, y, z;
	int valor;

	printf("N = %d\n",N);
	for(x =1; x <=nprodutos - 2; ++x){
		for(y= x+1; y<=nprodutos -1; ++y){
			for(z= y+1; z<=nprodutos; ++z){
				if(x+y+z == N){
					valor = x*3 + 2*y + z;
					printf("\nx = %d y = %d z = %d valor= %d \n", x, y, z, valor);
				}

			}
		}

	}

	printf("\n FIM \n");
	return 0;
}
