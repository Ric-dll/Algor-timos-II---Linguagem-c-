#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int vrSequencial(char *str){
	const char *seq = "XYZYXZ"; // seq recebe um ponteiro para o endereço do primeiro caractere
	return (strstr(str, seq)!= NULL)? 1 : 0;	//Uso de ternário com função strstr, a mesma que compara a ocorrencia de uma string dentro de outra maior
}

int main(void){
	char string[100];

	printf("\nDigite a sequencia: ");
	fgets(string, sizeof(string), stdin);

	printf("\nResultado: %i", vrSequencial(string));
}//fim main


