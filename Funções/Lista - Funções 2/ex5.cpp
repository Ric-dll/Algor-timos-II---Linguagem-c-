#include<stdio.h>
#include<stdlib.h>

#define TAM 5

int somaDiagP(int mat[TAM][TAM]){
	int soma = 0;

	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			if(i == j){
				soma += mat[i][j];
			}
		}
	}
	return soma;
}

int somaDiagSe(int mat[TAM][TAM]){
	int soma = 0;

	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			if(i+j == TAM-1){ //Regra matemática de diagonal sec. de matriz
				soma += mat[i][j];
			}
		}
	}
	return soma;
}

int main(void){
	int mat[TAM][TAM];

	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			printf("Matriz [%i][%i] : ", i+1, j+1);
			scanf("%i", &mat[i][j]);
		}
	}

	puts("");

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			printf("%i ", mat[i][j]);
		}
		puts("");
	}

	printf("\nA soma da diagonal principal e: %i", somaDiagP(mat));
	printf("\nA soma da diagonal secundaria e: %i", somaDiagSe(mat));
}//fim main
