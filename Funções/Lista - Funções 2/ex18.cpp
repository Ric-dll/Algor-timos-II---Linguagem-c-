#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void percentCharacter(char *str){
	char vog[] = "aeiou";
	int contV=0, contC=0;
	int tString = strlen(str)-1; //-1 p/ desconsiderar o '\n' incrementado

	for(int i=0; i<tString; i++){
		char c = tolower(str[i]); //Para converter p/ minusculo cada caractere
		int vogal=0;

		for(int j=0; vog[j]!='\0'; j++){
			if(c == vog[j]){
				vogal=1;
				break;
			}
		}
		if(vogal == 1){
			contV++;
		}else{
			contC++;
		}
	}

	float percVog= (float)contV/tString*100;
	float percCons = (float)contC/tString*100;

	printf("\nVogais: %i", contV);
	printf("\nConsoantes: %i", contC);

	printf("\nPorcentagem de vogais: %.1f%% \nPorcentagem de Consoantes: %.1f%%", percVog, percCons);
}

int main(void){
	char str[20];

	printf("\nDigite a String: ");
	fgets(str, sizeof(str), stdin);

	percentCharacter(str);
}//fim main



