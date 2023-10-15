#include<stdio.h>
#include<stdlib.h>

//Função pra verificar perfeição
int perfect(int a){
	int soma = 0;

	for(int i=1; i<a; i++){
		if(a%i == 0){
			soma+=i;
		}
	}
	return (a == soma);
}

int isPerfectInVet(int vet[], int t){
	for(int i=0; i<t; i++){
		if(perfect(vet[i])){
			printf("\n%i e perfeito!...", vet[i]);
		}
	}
	return 0;
}

int main(){

	int i, tam;

	printf("\nDigite o tamanho: ");
	scanf("%i", &tam);

	int vetor[tam];

	printf("\nNumeros: ");

	for(i=0; i<tam; i++){
		scanf("%i", &vetor[i]);
	}printf("\nVetor: [ ");
	for(i=0; i<tam; i++){
		printf("%i, ", vetor[i]);
	}printf("]");


	printf("\n\nRetorno: %i", isPerfectInVet(vetor, tam));
}//fim main
