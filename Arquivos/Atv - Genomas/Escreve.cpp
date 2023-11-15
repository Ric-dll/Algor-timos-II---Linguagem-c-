#include<stdio.h>
#include<string.h>

int main(void){
	FILE *nomes;
	char nome[50]; int i, tam;
	nomes = fopen("nomes.txt", "w"); // 'w' = White (reescreve); 'a' = salva e incrementa +5
	for(i=0; i<5; i++){
		printf("Informe um nome: ");
		gets(nome);
		fprintf(nomes, "Nome: %i: %s\n", i+1, nome);
	}
	nomes = fopen("nomes.txt", "r"); //'r' = rewind = releitura do vetor
	while(fgets(nome, 50, nomes) != NULL){
		tam = strlen(nome);
		nome[tam-1] = '\0';
		puts(nome);
	}
	
	fclose(nomes);
}
