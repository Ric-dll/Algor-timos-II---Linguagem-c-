#include<stdio.h>

void c(int a){ 
	int i;
	
	for(i=1; i<a; i++){
		if(a%i==0){
			printf("%i, ", i);
		}
	}
}

main(){
	printf("\nDivisores inteiros: "); c(12);
}
