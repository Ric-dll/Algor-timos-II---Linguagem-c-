#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TAM 5
#define TAM_STRINGS 20

int buscarString(char strings[TAM][TAM_STRINGS], char *str){
	for(int i=0; i<TAM; i++){
		if(strcmp(strings[i], str) == 0){
			return 1;
		}
	}
	return 0;
}

int main(void){
	char matStrings[TAM][TAM_STRINGS];
	char str[TAM_STRINGS];

	for(int i=0; i<TAM; i++){
		printf("\nDigite uma String: ");
		fgets(matStrings[i], sizeof(matStrings[i]), stdin);
	}

	printf("\nPesquisar: ");
	fgets(str, sizeof(str), stdin);

	if(buscarString(matStrings, str) == 1){
		printf("\nString: %s encontrada", str);
	}else{
		printf("\nString: %s NAO encontrada", str);
	}
}//fim main



