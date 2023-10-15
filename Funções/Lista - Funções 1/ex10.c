#include<stdio.h>
#include<math.h>

int somaentreij(int a, int b){ 
	int i, soma=0;
	
	for(i=a+1; i<b; i++){
		soma+=i;
	}
	return soma;
}

main(){
	printf("A soma do conjunto interno entre i e j e: %i ", somaentreij(1,10));
}
