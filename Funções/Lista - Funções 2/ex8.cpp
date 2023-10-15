#include<stdio.h>
#include<stdlib.h>

#define TAM 5

void maiorElementoMxN(int mat[TAM][TAM]){
	int m=0, n=0, maior = mat[0][0], i, j;

	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			if(mat[i][j] > maior){
				maior = mat[i][j];
				m = i;
				n = j;
			}
		}
	}
	printf("\nMaior elemento e: ( %i ) localizado em: Linha[%i] X Coluna[%i]", maior, m+1, n+1);
}

int main(void){
	int vet[TAM][TAM];

	printf("\n - Digite os elementos - \n");

	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			printf("\nLinha[%i] X Coluna[%i] : ", i+1, j+1);
			scanf("%i", &vet[i][j]);
		}
	}
	maiorElementoMxN(vet);
}//fim main
