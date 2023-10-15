#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char matString[5][50];
	const char vogais[10] = "aeiouAEIOU";
	int cont=0;

	for(int i=0; i<5; i++){
		printf("\nDigite uma palavra: ");
		fgets(matString[i], 50, stdin);
	}

	for(int i=0; i<5; i++){ //Percorredor de Linhas
		for(int j=0; matString[i][j]!='\0'; j++){ // Percorredor de Strings
			for(int k=0; k<10; k++){ //Percorredor de vogais a,e,i,o,u,A,E,I,O,U = 5
				if(matString[i][j] == vogais[k]){ //Vogais na posição K, pois é o responsável por percorrer a sí
					cont++;
				}
			}
		}
	}
	printf("\nPossui %i vogais no geral!", cont);
}//Fim main

