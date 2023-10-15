#include<stdio.h>
#include<math.h>

float f(float x){
	if(x!=2) {
		return 8/(2-x);
	}
	else{
		printf("\nDivisao por 0 ...");
		return 0;
	}
}

main(){
	printf("\nF(x): %.2f ", f(2));
}
