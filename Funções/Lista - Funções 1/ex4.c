#include<stdio.h>

int maior(int a, int b, int c){ 
	if(a<b && a<c){
		return a;
	}else if(b<a && b<c){
		return b;
	}else{
		return c;
	}
}

main(){
	int x, y, z;
	
	printf("Digite um numero: ");
	 scanf("%i", &x);
	printf("Digite um numero: ");
	 scanf("%i", &y);
	printf("Digite um numero: ");
	 scanf("%i", &z);
	 
	printf("%i", maior(x, y, z));
}
