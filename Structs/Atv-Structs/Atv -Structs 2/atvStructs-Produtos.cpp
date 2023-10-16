#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

//Inicio Structs
struct Produto{
	char marca[100];
	char descricao[50];
	int quantidade;
	float valor;
};
//Fim structs

void convertpMinusculo(char *str){
	for(int i=0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
}

//inicio funções
void menuPrincipal(void){

	//Inicio Designer Menu
        printf("\n ____________________________________\n");
        printf("|                                    |\n");
        printf("|        MENU PRINCIPAL      	     |\n");
        printf("|____________________________________|\n");
        printf("|                                    |\n");
        printf("|      1. Cadatrar Produto           |\n");
        printf("|      2. Exibir Produtos            |\n");
        printf("|      3. Consulta por descricao     |\n");
        printf("|      4. Produto mais caro          |\n");
        printf("|      5. Produto mais barato	     |\n");
        printf("|      6. Editar produto             |\n");
        printf("|      7. Excluir produto            |\n");
        printf("|                                    |\n");
        printf("|      [0] Fechar                    |\n");
        printf("|                                    |\n");
        printf("|____________________________________|\n");
	//Fim Designer Menu
	return;
}

void cadastroProdutos(struct Produto prod[], int ctl){ //recebe o vetor de struct e o controle de iteração

	printf("\n ___________________________________\n");
	printf("|                                   |\n");
	printf("|        CADASTRO DE PRODUTO        |\n");
	printf("|___________________________________|\n");

	printf("\nDigite a marca: ");
	fgets(prod[ctl].marca, sizeof(prod[ctl].marca), stdin);
	convertpMinusculo(prod[ctl].marca);

	printf("\nDigite a descricao: ");
	fgets(prod[ctl].descricao, sizeof(prod[ctl].descricao), stdin);
	convertpMinusculo(prod[ctl].descricao);

	printf("\nQuantidade disponivel: ");
	scanf("%i", &prod[ctl].quantidade);

	printf("\nDigite o preco: ");
	scanf("%f", &prod[ctl].valor);

	printf("\n ______________________________________\n");
	printf("\n --> Produto adicionado com Sucesso!...\n");
	printf("\n ______________________________________\n");
	return;
}

void exibirProdutos(struct Produto prod[], int *qtd){ //recebe o vetor de struct, ponteiro de qtdProdutos e a posição a ser alterada

	system("clear");
	printf("\n ___________________________________\n");
	printf("|                                   |\n");
	printf("|        PRODUTOS CADASTRADOS       |\n");
	printf("|___________________________________|\n");

	for(int i=0; i < *qtd; i++){
		printf("\n___________[ Produto (%i) ]__________\n", i);

		printf("\nMarca: %s", prod[i].marca);
		printf("\nDescricao: %s", prod[i].descricao);
		printf("\nQuantidade: %i", prod[i].quantidade);
		printf("\nPreco: R$ %.2f", prod[i].valor);
		printf("\n______________________________________\n");
	}
	return;
}

void searchDescricao(struct Produto prod[], char *str, int *qtd){ //recebe o vetor de struct, ponteiro de qtdProdutos e a posição a ser alterada

	if(*qtd > 0){
		for(int i=0; i < *qtd; i++){
			if(strcmp(prod[i].descricao, str) == 0){
				printf("\n___________[ Produto (%i) ]__________\n", i);

				printf("\nMarca: %s", prod[i].marca);
				printf("\nDescricao: %s", prod[i].descricao);
				printf("\nQuantidade: %i", prod[i].quantidade);
				printf("\nPreco: R$ %.2f", prod[i].valor);
				printf("\n______________________________________\n");
			}
		}
	}else{
		printf("\nNenhum Produto Cadastrado!...");
	}
	return;
}

void searchMaiorPreco(struct Produto prod[], int *qtd){ //recebe o vetor de struct e qtdProdutos
	int maiorVal=0, posi;

	for(int i=0; i < *qtd; i++){
		if(prod[i].valor > maiorVal){
			maiorVal = prod[i].valor;
			posi = i;
		}
	}

	if(maiorVal > 0){
		printf("\n___________[ Produto (%i) ]__________\n", posi);

		printf("\nMarca: %s", prod[posi].marca);
		printf("\nDescricao: %s", prod[posi].descricao);
		printf("\nQuantidade: %i", prod[posi].quantidade);
		printf("\nPreco: R$ %.2f", prod[posi].valor);
		printf("\n______________________________________\n");
	}else{
		printf("\nNenhum Produto encontrado...\n\n");
	}
	return;
}

void searchMenorPreco(struct Produto prod[], int *qtd){ //recebe o vetor de struct, ponteiro de qtdProdutos e a posição a ser alterada
	int menorVal, posi=-1;

	for(int i=0; i < *qtd; i++){
		if(prod[i].valor < menorVal){
			menorVal = prod[i].valor;
			posi = i;
		}
	}

	if(posi >= 0){
		printf("\n___________[ Produto (%i) ]__________\n", posi);

		printf("\nMarca: %s", prod[posi].marca);
		printf("\nDescricao: %s", prod[posi].descricao);
		printf("\nQuantidade: %i", prod[posi].quantidade);
		printf("\nPreco: R$ %.2f", prod[posi].valor);
		printf("\n______________________________________\n");
	}else{
		printf("\nNenhum Produto encontrado...\n\n");
	}
	return;
}

void setProduto(struct Produto prod[], int posicao){ //recebe o vetor de struct e posicao
	printf("\n ___________________________________\n");
	printf("|                                   |\n");
	printf("|           EDITAR PRODUTO          |\n");
	printf("|___________________________________|\n");

	printf("\nDigite a marca: ");
	fgets(prod[posicao].marca, sizeof(prod[posicao].marca), stdin);
	convertpMinusculo(prod[posicao].marca);

	printf("\nDigite a descricao: ");
	fgets(prod[posicao].descricao, sizeof(prod[posicao].descricao), stdin);
	convertpMinusculo(prod[posicao].descricao);

	printf("\nQuantidade disponivel: ");
	scanf("%i", &prod[posicao].quantidade);

	printf("\nDigite o preco: ");
	scanf("%f", &prod[posicao].valor);

	printf("\nProduto editado com Sucesso!...");

	return;
}

void deleteProduto(struct Produto prod[], int *qtd, int posicao){ //recebe o vetor de struct, ponteiro de qtdProdutos e a posição a ser alterada
	printf("\n _____________________________________\n");
	printf("|                                     |\n");
	printf("|            APAGAR PRODUTO           |\n");
	printf("|_____________________________________|\n");
	printf("\n Digite [0], Para sair...");
	puts("\n _____________________________________");

	if(posicao != 0 && posicao <= *qtd){
		for(int i=posicao; i < *qtd; i++){
			prod[i] = prod[i+1];
		}
		(*qtd)--; //Desincrementa um em qtdProdutos
	}else{
		printf("\nSaindo!...\n\n");
		system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
	}
	return;
}
//Fim funções

int main(void){//Inicio main

	struct Produto produtos[10000]={0};

	//Declaração de variaveis

	char addProdutos;
	int i=0, qtdProdutos=0; //variáveis para controle geral

	//Fim declaração de variaveis

	//chamando o menu
	menuPrincipal();

	//controle de execução do menu
	int menu=1;

	do{
		//inicio escolha de opções
		printf("\nOpção: "); scanf("%i", &menu); getchar(); system("clear");

		switch(menu){
			case 1:{

				do{
					//Chamando a função de Cadastro de produto
					cadastroProdutos(produtos, i);

					printf("\nDeseja adicionar um novo produto: ");
					scanf(" %c", &addProdutos); getchar(); system("clear");

					i++; qtdProdutos++;

				}while(tolower(addProdutos) == 's');

				system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
			break;
			}

			case 2:{
				exibirProdutos(produtos, &qtdProdutos);
				system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
			break;
			}

			case 3:{
				char str[50]="";
				printf("\nBusca por descricao: "); fgets(str, sizeof(str), stdin); convertpMinusculo(str);

				//chamando a função searchDescricao
				searchDescricao(produtos, str, &qtdProdutos);

				system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
			break;
			}

			case 4:{
				//chamando a função searchMaiorValor
				searchMaiorPreco(produtos, &qtdProdutos);

				system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
			break;
			}

			case 5:{
				//chamando a função searchMenorValor
				searchMenorPreco(produtos, &qtdProdutos);

				system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
			break;
			}

			case 6:{
				int posicao;
				printf("\nDigite a posicao a ser alterada: "); scanf("%i", &posicao); getchar();
				//chamando a função setProduto
				setProduto(produtos, posicao);
				system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
			break;
			}

			case 7:{
				int posicao;
				printf("\nDigite a posicao a ser APAGADA: "); scanf("%i", &posicao); getchar();

				//Chamando a função deleteProduto
				deleteProduto(produtos, &qtdProdutos, posicao);

				system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
			break;
			}

			case 0:{
				printf("\nSaindo do programa...\n");
				return 0;
			}

			default:{
				printf("\nOpcao invalida, tente novamente...");
				menuPrincipal();
				break;
			break;
			}
		}

	}while(menu!=0);
	//fim controle de execução menu
}//fim main
