#include<stdio.h>
#include<stdlib.h>

void altDiag(int mat[5][5]){

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(i == j){
				mat[i][j] = 1;
			}
		}
	}
}

int main(void){
	int mat[5][5];

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			printf("Matriz [%i][%i] : ", i+1, j+1);
			scanf("%i", &mat[i][j]);
		}
	}

	altDiag(mat); puts("");

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			printf("%i ", mat[i][j]);
		}
		puts("");
	}

}//fim main
