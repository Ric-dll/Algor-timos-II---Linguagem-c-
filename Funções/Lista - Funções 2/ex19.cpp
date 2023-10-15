#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TAM 5
#define TAM_STRINGS 20

float percentVogais(char *str){
	char vog[] = "aeiou";
	int contV=0;
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
		}
	}

	float percVog= (float)contV/tString*100;

	//Testes de verificação
	//printf("\nVogais: %i", contV);
	//printf("\nPorcentagem de vogais: %.1f%%", percVog);

	return percVog;
}

int strCompareVog(char strings[TAM][TAM_STRINGS]){
	float maior=0;
	int pos = -1; //Caso permaneça -1, logo entrará em um futuro else

	for(int i=0; i<TAM; i++){
		float aux = percentVogais(strings[i]);

		if(aux > maior){
			maior = aux;
			pos = i;
		}

	}
	return pos;
}


int main(void){
	char str[TAM][TAM_STRINGS];

	for(int i=0; i<TAM; i++){
		printf("\n\nDigite a String [%i]: ", i);
		fgets(str[i], sizeof(str[i]), stdin);
	}

	int result = strCompareVog(str);
	printf("\n-------------------------------");

	if(result != -1){
		printf("\nA maior está na posição: %i", result);
	}else{
		printf("\nStrings inválidas");
	}
}//fim main



