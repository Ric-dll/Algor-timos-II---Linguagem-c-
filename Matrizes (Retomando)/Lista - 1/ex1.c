#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

	char matString[5][50];

	for(int i=0; i<5; i++){
		fgets(matString[i], 50, stdin);
	}
	for(int i=0; i<5; i++){
		printf("\n%i : %s", i+1,matString[i]);
	}

}//Fim main

