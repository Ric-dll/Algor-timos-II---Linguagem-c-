#include<stdio.h>
#include<stdlib.h>

int contItem(int vet[], int tam, int a){
	int cont = 0;

	for(int i=0; i<tam; i++){
		if(vet[i]==a){
			cont++;
		}
	}
	return cont;
}

int main(void){
	int tam, item;

	printf("\nDigite o tamanho do vetor: ");
	scanf("%i", &tam);

	int vet[tam];

	printf("\nPreencha o vetor: ");
	for(int i=0; i<tam; i++){
		scanf("%i", &vet[i]);
	}

	printf("\nDigite o item a ser verificado: ");
	scanf("%i", &item);

	printf("\nO item %i se repete %i vezes", item, contItem(vet,tam,item));
}//fim main
