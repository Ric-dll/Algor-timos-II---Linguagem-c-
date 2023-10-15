#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 3
#define tAux 3

void trIndiceCol(int mat[TAM][TAM], int coluna1, int coluna2){
	int aux[tAux][tAux];
	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			if(j==coluna1){
				aux[i][j] = mat[i][coluna1];
				mat[i][j] = mat[i][coluna2];
			}
			if(j==coluna2){
				mat[i][j] = aux[i][coluna1];
			}
		}
	}
}

void trSimples(int mat[TAM][TAM], int coluna1, int coluna2){
	for(int i=0, j=0; i<TAM; i++, j++){
		int temp = mat[i][coluna1];
		mat[i][coluna1] = mat[i][coluna2];
		mat[i][coluna2] = temp;
	}
}

int main(void){
	int mat[TAM][TAM];

	printf("\n - Digite os elementos - \n");

	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			printf("\nLinha[%i] X Coluna[%i] : ", i+1, j+1);
			scanf("%i", &mat[i][j]);
		}
	}
	for(int i=0; i<TAM; i++){
		printf("\n");
		for(int j=0; j<TAM; j++){
			printf(" %i", mat[i][j]);
		}
	}
	//Chamando a função
	trSimples(mat, 0, 2);
	puts("");
	for(int i=0; i<TAM; i++){
		printf("\n");
		for(int j=0; j<TAM; j++){
			printf(" %i", mat[i][j]);
		}
	}

}//fim main



