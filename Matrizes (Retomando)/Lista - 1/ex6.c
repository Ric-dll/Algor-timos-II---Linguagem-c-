#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char matString[5][50];
	const char vogais[10] = "aeiouAEIOU";
	int vog[10] = {0}, tam[5] = {0}, porcent[5] = {0};

	for(int i=0; i<5; i++){
		printf("\nDigite uma palavra: ");
		fgets(matString[i], 50, stdin);
		tam[i] = strlen(matString[i])-1;

		for(int j=0; matString[i][j]!='\0'; j++){
			for(int k=0; k<10; k++){
				if(matString[i][j] == vogais[k]) vog[i]++;
			}
		}
		porcent[i] = (vog[i]*100)/tam[i];
	}
	printf("\n----- Contagem de vogais por String ----- \n");
	for(int i=0; i<5; i++){
		printf("\nString [ %i ] : %i, Porcentagem %i%%", i+1, vog[i], porcent[i]);
	}

}//Fim main
