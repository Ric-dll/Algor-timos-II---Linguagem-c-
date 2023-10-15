#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rmCaractere(char *str, char c){
	int i, j, ;
	for(i=j=0; str[i]!='\0'; i++){ // i = j = 0, é o mesmo que 2 for's, um para str[i] e outro para a mesma variável str porém em [j];
		if(str[i] != c){
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0'; // [j] se encontra uma posição a frente do término da string, logo faz sentido que de forma simples, ela receba sem grandes problemas '\o'
}

int main(void){
	char str[120] = "", c;

	printf("\nDigite uma palavra: ");
	 fgets(str, sizeof(str), stdin);
	printf("\nDigite o caractere a ser verificado: ");
	 scanf(" %c", &c);

	//chamando a função
	rmCaractere(str, c);
	printf("\nPalavra final: %s", str);

}//fim main
