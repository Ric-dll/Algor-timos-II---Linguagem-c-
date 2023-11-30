//Incluindo a biblioteca criada, a mesma possui as outras bibliotecas presentes, logo ao cham-la, também possui a inclusão das outras fundamentais
#include "bibliotecaFuncoes.h"

FILE  *arquivo; //O comando é ponteiro que aponta para uma estrutura FILE

struct Carro{
	int ano;
	char descricao[100];
	float preco;
};

int main(void){
srand(time(NULL)); //Sempre que iniciar será uma semente aleatória

	struct Carro carro; //criando uma variavel tipo struct de nome carro
	char descricao[100]; //Auxiliar para receber uma geração de descrição e adicionar ao arquivo

	//Abre ou Cria o arquivo para escrita utilizando parâmetro 'w'
	arquivo = fopen("carros.txt", "w");

	//Gerando 1000 itens de uma struct completa
	for(int i=0; i<TAM; i++){
		carro.ano = gerarAno();

		gerarDescricao(descricao); //Gerando a descrição
		strcpy(carro.descricao, descricao); //Copiando a descrição para a struct

		carro.preco = gerarPreco();//Gerando preço

		//Escrevendo no arquivo, com a seginte estrutura, relativo as variaveis carro...
		fprintf(arquivo, "%i;%s;%.2f;\n", carro.ano, carro.descricao, carro.preco);
	}

	fclose(arquivo); //Terminando o arquivo

}
