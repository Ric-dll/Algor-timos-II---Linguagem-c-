#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 5

int contColNull(int mat[TAM][TAM]){
	int cont=0;

	for(int i=0; i<TAM; i++){
		int contColunaNula = 1;

		for(int j=0; j<TAM; j++){
			if(mat[j][i] != 0){
				contColunaNula = 0;
				break; //se algum elemento for diferente de 0, logo já não é nula
			}
		}
		if(contColunaNula == 1){
			cont++;
		}
	}
	return cont;
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
	printf("\n\nQuantidade de colunas nulas: %i", contColNull(mat));

}//fim main



