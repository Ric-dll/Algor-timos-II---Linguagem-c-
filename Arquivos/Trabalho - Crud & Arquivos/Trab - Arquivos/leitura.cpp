#include<stdio.h>
#define TAM 1000

FILE *arquivo = fopen("carros.txt", "r");

	struct Carro{
	int ano;
	char descricao[100];
	float preco;
};

int main(void){


	struct Carro vet[TAM]; //Declarando um vetor de structs
	int i=0;

	while((fscanf(arquivo, "%i ; %99[^;] ; %f ;", &vet[i].ano, vet[i].descricao, &vet[i].preco) == 3) && i<TAM){ //Inicia um loop com a função fscanf se true
		i++; //Após ler, incrementa um na posição para ler o próximo
	}

	for(int j=0; j<i; j++){
		printf("\n\n\n[ Carro %i: ] \n", j+1);
		printf("\n- Ano: %i \n- Descricao: %s \n- Preco: %.2f \n", vet[j].ano, vet[j].descricao, vet[j].preco);
	}

	//Fecha a leitura do arquivo;
	fclose(arquivo);
}

//Linha 12: A função 'fopen' abre o arquivo pelo endereço e logo após recebe um parâmetro "r" = ready, ou seja de leia o arquivo...

/* Linha(16)+:
 *
 * A função fscanf é utilizada para ler e armazenar dados de um arquivo em um vetor, fscanf pois f = file junto ao scanf
 * fscanf(arquivoCriado, "Formatação e os tipos referentes aos dados a serem lidos, vetor.variaveis onde serão armazenados os dados");
 * Condição == 3 refere-se a quantidade de tipos de leitura e armazenagem de dados por linha, se lidos 3, e i <quantidade --> então i++;
 *
 * (Formatação do segundo parâmetro da fscanf):  %i ; %99[^;] ; %f ;
 *
 *   ( %i ): Referencia que será lido um tipo inteiro
 * 	 ( ; ): Corresponde literalmente ao caractere ponto e vírgula no arquivo, ou seja, remete que a leitura deve encontrar um ';'
 * 	 ( %99[^;] ):
 * 		- %99: Indica que a função deve ler uma string de ate 99 caracteres(Serve para evitar estouro, pode ser mudado relativo ao tamanho do atributo), o tipo %s fica implícito
 * 		- [^;]: De forma concatenada, instrui a função a ler caracteres até encontrar um ponto e vírgula. Significa que ele lê todos os caracteres até encontrar um ';'
 * 	 ( %f ): Indica que a função deve ler um dado de tipo 'f' e (;) deve encontrar um ; após...
 *
 * OBS: O segundo parâmetro deve ser modificado relativo a estrutura de dados a ser lida, neste caso funcionará somente desta forma...
*/
