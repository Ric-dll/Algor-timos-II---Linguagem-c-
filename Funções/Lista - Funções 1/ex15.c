#include<stdio.h>

char pontuacao(float a){ 
	if(a >= 0.0 && a <= 4.9){
		return 'D';
	}else if(a >= 5.0 && a <= 6.9){
		return 'C';
	}else if(a >= 7.0 && a <= 8.9){
		return 'B';
	}else if(a >= 9.0 && a <= 10){
		return 'A';
	}else{
		return '?';
	}
}

main(){
	printf("\nPontuacao: %c", pontuacao(8));
}
