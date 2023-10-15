#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int palindromo(char *str){
	int t = strlen(str)-2; //-2 pois o fgets armazena além da string, o '\0' e '\n', ou seja, deixando somente a string, assim sem necessidade de utilizar -1 no for

	//Modo simplificado e direto de usar for em comparação de string
	for(int i=0, j=t; i<j; i++, j--){ // p1: (i=0, j=t-1) ; p2(i<j) ; p3(i++, j--)
		if(str[i] != str[j]){
			return 0;
		}
	}
	return 1;
}

int main(void){
	char str[20];
	printf("\nDigite um possivel palindromo: ");
	fgets(str, sizeof(str), stdin);

	if(palindromo2(str) == 1){
		printf("\nE um palindromo");
	}else{
		printf("\nNao e um palindromo");
	}
}//fim main



