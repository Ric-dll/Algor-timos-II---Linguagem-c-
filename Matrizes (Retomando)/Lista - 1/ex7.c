#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char matString[5][50];
	const char vogais[10] = "aeiouAEIOU";
	int vog[10] = {0}, x=0, pos=0;


	for(int i=0; i<5; i++){
		printf("\nDigite uma palavra: ");
		fgets(matString[i], 50, stdin);

		for(int j=0; matString[i][j]!='\0'; j++){
			for(int k=0; k<10; k++){
				if(matString[i][j] == vogais[k]) vog[i]++;
			}
		}
	}
	for(int i=0; i<10; i++){
		if(vog[i] > x){
			x = vog[i];
			pos = i;
		}
	}
	for(int i=0; i<5; i++){
		printf("\nString [ %i ] : %i", i+1, vog[i]);
	}
	printf("\n\nA String com mais vogais foi a %i, com %i vogais", pos+1,x);
}//Fim main

