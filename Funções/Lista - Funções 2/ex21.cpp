#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TAM_F 20

void intercalarVetores(int vet1[], int vet2[]){
	int vetF[TAM_F]={0};

	for(int i=0; i<TAM_F; i++){
		if(i%2 == 0){ //Primeira ocorrência verdadeira, logo vetF[0] = vet1[0]
			vetF[i] = vet1[i/2]; //pos[0/2] = [0]; pos[2/2] = [1]; pos[4/2] = [2]
		}else{
			vetF[i] = vet2[i/2]; //pos[1/2] = (arredondado)[0]; pos[2/2] = [1]
		}
		//printf(" %i %i ",vet1[i], vet2[i]);
	}
	for(int i=0; i<TAM_F; i++){
		printf(" %i ",vetF[i]);
	}

}

int main(void){
	int vet1[] = {1,3,5,7,9,11,13,15,17,19};
	int vet2[] = {2,4,6,8,10,12,14,16,18,20};

	intercalarVetores(vet1, vet2);
}//fim main




