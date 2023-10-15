#include<stdio.h>

int verificacao(int numero){
	if(numero%2!=0){
		return 1;
	}else{
		return 0;
	}
}

main(){
	int x;
	
	printf("Digite um numero: ");
	scanf("%i", &x);
	
	printf("%i", verificacao(x));
}
