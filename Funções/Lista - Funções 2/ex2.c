#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int primos(int vet[], int t){
	int i, qtdePrimos = 0, primo, j;
	
	for(i=0; i<t; i++){
		primo = 1;
		
		for(j=2; j<vet[i]; j++){
			if(vet[i]%j == 0){
				primo = 0;
					break;
			}
		}
		
		if(primo == 1 && vet[i] > 1){
			qtdePrimos++;
			printf("\n\n%i E primo...", vet[i]);
		}
		
	}
	return qtdePrimos;
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
	
	printf("\n\nPossui %i N's primos...", primos(vetor, tam));
}
