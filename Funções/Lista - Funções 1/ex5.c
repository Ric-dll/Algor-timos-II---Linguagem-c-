#include<stdio.h>

int verificacao(int numero){
	int i;
	
	for(i=2; i<numero; i++){ //printf("batatinha %d\n", i);
		if(numero%i == 0){ //printf("Nugets %d\n", i);
			return 0;
		}
	}
	return 1;
}


main(){
	int x;
	
	printf("Digite um numero: ");
	scanf("%i", &x);
	
	printf("%i", verificacao(x));
}
