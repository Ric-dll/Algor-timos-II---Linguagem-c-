#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menor(int vet[], int t){
	int i, menor = vet[0];
	
	for(i=0; i<t; i++){
		if(vet[i]<menor){
			menor = vet[i];
		}
	}
	return menor;
}

main(){ 
srand(time(NULL));

	int i, tam;
	
	printf("\nDigite o tamanho: ");
	scanf("%i", &tam);
	
	int vetor[tam];
	
	printf("\nNumeros: ");
	
	for(i=0; i<tam; i++){
		vetor[i] = (rand() % 1000);
		
		printf("%i, ", vetor[i]);
	}
	
	printf("\n\nO menor e: %i", menor(vetor, tam));
}
