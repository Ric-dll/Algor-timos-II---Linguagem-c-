#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contCaractere(char str[], char c){
	int cont=0;
	for(int i =0; str[i]!='\0'; i++){
		if(str[i] == c){
			cont++;
		}
	}
	return cont;
}

int main(void){
	char str[120] = "", c;

	printf("\nDigite uma palavra: "); fgets(str, sizeof(str), stdin);
	printf("\nDigite o caractere a ser verificado: "); scanf(" %c", &c);

	printf("\nO caractere ( %c ) aparece [%i] vezes", c, contCaractere(str, c));
}//fim main
