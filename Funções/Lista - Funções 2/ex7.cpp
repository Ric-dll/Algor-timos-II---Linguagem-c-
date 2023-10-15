#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inverte(char str[]){
	size_t t = strlen(str); //size_t é um tipo que referencia a tamanho, da mesma forma que int, porém específico para tamanhos, convém a utilização

	for(int i=t+1; i>=0; i--){
		printf("%c", str[i]);
	}
}

int main(void){
	char vet[] = "valar morghulis";
	inverte(vet);
}//fim main
