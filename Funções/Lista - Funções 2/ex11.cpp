#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void trDeOcorrencias(char *str, char c1, char c2){
	int i , j;

	for(i = j = 0; str[i]!='\0'; i++){
		if(str[i] == c1){
			str[j] = c2;
			j++;
		}
	}
	str[j] = '\0';
}

int main(void){
	char str[120], c1, c2;

	printf("\nDigite a palavra: "); fgets(str, sizeof(str), stdin);
	printf("\nTermo c1: "); scanf(" %c", &c1);
	printf("\nTermo c2: "); scanf(" %c", &c2);

	trDeOcorrencias(str, c1, c2);
	printf("\nFinal: %s", str);

}//fim main

