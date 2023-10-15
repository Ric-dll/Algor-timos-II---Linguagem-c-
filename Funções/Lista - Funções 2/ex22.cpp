#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TAM 10

void ordenacaoBolha(int vet[TAM], char c){
	if(tolower(c) == 'c'){ int aux=0;
		printf("\nOrdem Crescente...\n");

		for(int i=0; i<TAM; i++){
			for(int j=i+1; j<TAM; j++){
				if(vet[i]>vet[j]){ //Sinal > indica crescente para o método bolha
					aux = vet[i];
					vet[i] = vet[j];
					vet[j] = aux;
				}
			}
		}
		printf("\n Vetor [ ");
		for(int i=0; i<TAM; i++){
			printf(" %i ", vet[i]);
		}printf(" ]");

	}else
		if(tolower(c) == 'd'){ int aux=0;
		printf("\nOrdem decrescente...\n");

		for(int i=0; i<TAM; i++){
			for(int j=i+1; j<TAM; j++){
				if(vet[i]<vet[j]){ //Sinal < indica crescente para o método bolha
					aux = vet[i];
					vet[i] = vet[j];
					vet[j] = aux;
				}
			}
		}
		printf("\n Vetor [ ");
		for(int i=0; i<TAM; i++){
			printf(" %i ", vet[i]);
		}printf(" ]");

	}else{
		printf("\nCaractere invalido!...");
	}
}

int main(void){
	int vet[TAM]={0};
	char c;

	printf("\n-- Digite os Numeros no vetor --\n\n");
	for(int i=0; i<TAM; i++){
		printf("Numero: ");
		scanf("%i", &vet[i]);
	}
	printf("Escolha (C) ou (D): ");
	scanf(" %c", &c); puts("");

	ordenacaoBolha(vet,c);

}//fim main




