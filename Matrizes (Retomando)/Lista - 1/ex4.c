#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char matString[5][50];

	for(int i=0; i<5; i++){
		printf("\nDigite uma palavra: ");
		fgets(matString[i], 50, stdin);
	}

	char caractere;
	printf("\nDigite um caractere: ");
	scanf("%c", &caractere);

	int cont=0;

	puts("------------------------------------------");

	for(int i=0; i<5; i++){
		for(int j=0; matString[i][j]!='\0'; j++){
			if(matString[i][j] == caractere){
				cont++;
			}
		}
		printf("\nNa %i Linha, ( %c ) foi exibido %i vezes", i+1, caractere, cont);
		cont=0;
	}

}//Fim main

