#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char matString[5][50];

	for(int i=0; i<5; i++){
		printf("Digite uma palavra: ");
		fgets(matString[i], 50, stdin);
	}

	char stringCompare[50];

	printf("Digite uma palavra a ser comparada com as anteriores: ");
	fgets(stringCompare, 50, stdin);

	int cont=0;

	for(int i=0; i<5; i++){
		if(strcmp(matString[i], stringCompare) == 0){
			cont++;
		}
	}

	printf("\nA palavra se repete %i vezes", cont);

}//Fim main

