#include<stdio.h>
#include<math.h>

void aOUp(float a, float b, float c, char w){ 

	switch(w){
		case 'A':{
			printf("\nA media aritmetica e: %.2f", (a+b+c)/3);
				break;
		}
		case 'P': { // pesos: 5,3,2
			printf("\nA media Ponderada e: %.2f", ((a*5 + b*3 + c*2)/3));
				break;
		}
		default:{
			printf("\nOpcao invalida");	
				break;
		}
	}
	
}

main(){
	aOUp(5, 5, 5, 'A');
}
