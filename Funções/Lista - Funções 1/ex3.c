#include<stdio.h>

int verVog(char caractere){ 
	char vogais[] = "aeiouAEIOU";
	int i;
	
	for(i=0; i<10; i++){
		if(caractere == vogais[i]){
			return 1;
		}
	}
	return 0;
}

main(){
	char c;
	
	printf("Digite um caractere: ");
	scanf("%c", &c);
	
	printf("%i", verVog(c));
}
