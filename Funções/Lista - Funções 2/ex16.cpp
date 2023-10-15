#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 5

int contItensRepetidos(int mat[TAM][TAM]){ //A maneira mais simples, compreende o uso de 4 fors,

	for(int i=0; i<TAM; i++){ //Loop linha
		for(int j=0; j<TAM; j++){ //Loop coluna

			int temp = mat[i][j]; //Armazena cada posição individual do vetor, ou seja, o valor a ser comparado adiante

			for(int k=i; k<TAM; k++){ // Loop para comparar 'temp' com a linha e coluna respectivamente
				for(int l=((k == i)? j + 1 : 0); l<TAM; l++){ //Ternário evita a comparação consigo mesmo
					if(temp == mat[i][l]){ // Compara o valor atual 'temp' com elementos futuros na mesma linha
						return 1;// Se encontrar um item repetido, retorna 1
					}
				}
			}
		}
	}
	return 0;
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

	int verificacao = contItensRepetidos(mat);

	if(verificacao == 1){
		printf("\nHa repetições");
	}else{
		printf("\nNao ha repetições");
	}

}//fim main



