#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char matString[5][50];

	for(int i=0; i<5; i++){
		printf("\nDigite uma palavra: ");
		fgets(matString[i], 50, stdin);
	}

	printf("\nDigite um caractere a ser procurado: ");
	char caractere;
	scanf("%c", &caractere);

	int cont=0; puts("------------------------------------------");

	for(int i=0; i<5; i++){
		for(int j=0; matString[i][j]!='\0'; j++){
			if(matString[i][j] == caractere){
				cont++;
			}
		}
	}

	printf("\nO caractere [ %c ] se repete ( %i ) vezes", caractere, cont);

}//Fim main

