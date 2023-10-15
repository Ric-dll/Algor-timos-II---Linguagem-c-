#include<stdio.h>
#include<math.h>

float montante(float capital, float juros, int meses){ 
	return capital*pow((1+juros), meses);
}

main(){
	printf("Montante: %.2f ", montante(2000,0.10,4));
}
