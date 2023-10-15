#include<stdio.h>
#include<math.h>

float imc(float peso, float altura){ 
	return peso/pow(altura,2);
}

main(){
	printf("IMC: %.2f ", imc(82.7, 1.64));
}
