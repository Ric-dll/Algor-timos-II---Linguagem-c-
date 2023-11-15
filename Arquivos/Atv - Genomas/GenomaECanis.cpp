#include<stdio.h>
#include<stdlib.h>

#define z 0

int main(void){
	FILE *genoma;
	char c;
	float cont=z, A=z, T=z, C=z, G=z, N=z, Bz, soma=z;
	
	//a função 'fopen' abre o arquivo pelo endereço e logo após recebe um parâmetro "r" = ready, ou seja de leia
	genoma = fopen("genCompEhrlichiaCanis.fasta", "r");
	
	while(!feof(genoma)){ // enquanto o não fim do arquivo, representado pela função '!feof'
		c = fgetc(genoma); // 'fgetc' usa simultaneamente já retornando
		cont ++;
		//printf("%c", c);
		(c=='A')? A++: NULL;
		(c=='T')? T++: NULL;
		(c=='C')? C++: NULL;
		(c=='G')? G++: NULL;
		(c=='\n')? N++: NULL;
	}
	
	printf("\n\nQuantidade de caracteres: %.0f\n", cont);
	printf("\nQuantidade de A: %.0f , porcentagem: %.2f %%", A, ((A/cont)*100));
	printf("\nQuantidade de T: %.0f , porcentagem: %.2f %%", T, ((T/cont)*100));
	printf("\nQuantidade de C: %.0f , porcentagem: %.2f %%", C, ((C/cont)*100));
	printf("\nQuantidade de G: %.0f , porcentagem: %.2f %%", G, ((G/cont)*100));
	//printf("\n\nQuantidade de \\n: %.0f, porcentagem: %.2f %%", N, ((N/cont)*100));
	printf("\n\nA soma das porcentagens e de: %.3f %%\n\n", ((A+T+C+G+N)/cont)*100);
	
	fclose(genoma);
}
