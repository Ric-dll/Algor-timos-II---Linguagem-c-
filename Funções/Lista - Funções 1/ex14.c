#include<stdio.h>

void perfeito(int a){ 
	int i, soma=0;
	for(i=1; i<a; i++){
		if(a%i==0){
			soma+=i;
		}
	}
	soma==a? printf("\nE um Numero e perfeito") : printf("\nNAO e um Numero perfeito");
}

main(){
	perfeito(9);
}
