#include<stdio.h>
#include<math.h>

int ver(int a){ 
	if(a>0){
		return 1;
	}else if(a<0){
		return -1;
	}else{
		return 0;
	}
}

main(){
	printf("\nValor: %i", ver(0));
}
