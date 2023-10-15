#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

void menuPrincipal(void){

	//Inicio Designer Menu
        printf("\n __________________________________\n");
        printf("|                                  |\n");
        printf("|        MENU PRINCIPAL      	   |\n");
        printf("|__________________________________|\n");
        printf("|                                  |\n");
        printf("|      1. Cadatrar imovel          |\n");
        printf("|      2. Exibir imoveis           |\n");
        printf("|      3. Consulta por tipo        |\n");
        printf("|      4. Consulta por comercio    |\n");
        printf("|      5. Capital de venda         |\n");
        printf("|      6. Imoveis em aluguel	   |\n");
        printf("|      7. Mais caro a venda        |\n");
        printf("|      8. Excluir imovel           |\n");
        printf("|                                  |\n");
        printf("|      [0] Fechar                  |\n");
        printf("|                                  |\n");
        printf("|__________________________________|\n");
	//Fim Designer Menu

	return;
}

struct Imovel{
	int cod;
	char tipo[20];
	char endereco[50];
	float valor;
	char situacao[20];
};

//Fun豫o para converter para minusculo qualquer string
void convertpMinusculo(char *str) {
    int i;
	for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


int main(void){

	int menu=1;
	//Chamando Menu
	menuPrincipal();

	//Variaveis
	struct Imovel imoveis[999] = {0}; //Struturando

	int qtdImoveis=0, i=0, x, pos, j=0, codSearch;
	float maiorValor, totVenda, totAluguel;
	char addImoveis, pesquisaComercial[10];// check[10] = "venda";

	do{
		//Escolhe a op챌ao, limpa resto de teclado e o hist처rico
		printf("\n\nOpcao: ");
		scanf("%i", &menu); fflush(stdin);
		system("clear");

		//Op챌천es
		switch(menu){
			case 1: { //Faz o Cadastro das Structs no Vetor

				//Tutorial de Entrada
					printf("\n ______________________________________________________\n");
					printf("|                                                      |\n");
					printf("|             TUTORIAL EXEMPLO DE CADASTRO             |\n");
					printf("|______________________________________________________|\n");
					printf("\n Digite o Codigo: (1) (2) (3) (n) ...\n");
					printf("\n Digite o Tipo: [Casa] [Apartamento] [Kitnet]\n");
					printf("\n Digite o Endereco: [Av. Paulista]\n");
					printf("\n Digite o Valor: (1200.00)\n");
					printf("\n Digite a Situacao comercial: [Aluguel] [Venda]\n");
					printf("\n_______________________________________________________\n");
				//Fim Tutorial

				do{
					printf("\n __________________________________\n");
					printf("|                                  |\n");
					printf("|        CADASTRO DE IMOVEL    	   |\n");
					printf("|__________________________________|\n");

					printf("\n Digite o Codigo: ");
					 scanf("%i", &imoveis[i].cod);
					  getchar(); //Limpa o buffer de entrada dps de um valor tipo numerico, ja o stdin limpa o de saída

					printf("\n Digite o Tipo: ");
					fgets(imoveis[i].tipo, sizeof(imoveis[i].tipo), stdin);
					convertpMinusculo(imoveis[i].tipo);

					printf("\n Digite o Endereco: ");
					fgets(imoveis[i].endereco, sizeof(imoveis[i].endereco), stdin);

					printf("\n Digite o Valor: ");
					 scanf("%f", &imoveis[i].valor);
					  getchar();

					printf("\n Digite a Situacao: ");
					fgets(imoveis[i].situacao, sizeof(imoveis[i].situacao), stdin);
					convertpMinusculo(imoveis[i].situacao);

					printf("\n _____________________________________\n");
					printf("\n --> Imovel adicionado com Sucesso!...\n\n");

					qtdImoveis++; //
					i++; //Incrementa a posicao no vetor de imoveis

					//Condi챌찾o de continuidade
					printf("\nDeseja adicionar um novo imovel? (S/N): ");
					scanf(" %c", &addImoveis); getchar();
					system("clear");

				}while(addImoveis=='s' || addImoveis == 'S');
					system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
				break;
			}
			case 2: { //Exibe Todos os Imoveis
				system("clear");
					printf("\n ___________________________________\n");
					printf("|                                   |\n");
					printf("|        IMOVEIS CADASTRADOS        |\n");
					printf("|___________________________________|\n");

					for(x=0; x<qtdImoveis; x++){

						printf("\n___________[ Imovel (%i) ]__________\n", x+1);

						printf("\n Cod: %i", imoveis[x].cod);
						printf("\n Tipo: %s", imoveis[x].tipo);
						printf("\n Valor: %.2f", imoveis[x].valor);
						printf("\n Endereco: %s", imoveis[x].endereco);
						printf("\n Situacao: %s", imoveis[x].situacao);
						puts("\n-----------------------------------\n");
					}
						system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();

				break;
			}
			case 3: { //Pesquisa por tipo, (casa, apartamento, kitnet)

					printf("\n _____________________________________\n");
					printf("|                                     |\n");
					printf("|          CONSULTA POR TIPO          |\n");
					printf("|_____________________________________|\n");
					printf("\n Digite [0], Para sair...");
					puts("\n _____________________________________");

					printf("\n Pesquise por (Casa)/(Apartamento)/(Kitnet): ");
					 fgets(pesquisaComercial, sizeof(pesquisaComercial), stdin);
					  convertpMinusculo(pesquisaComercial);

						if(qtdImoveis > 0){

							for(j=0; j<qtdImoveis; j++){

								if(strcmp(imoveis[j].tipo, pesquisaComercial) == 0){ //Compara豫o de escolha

									printf("\n\n___________[ Imovel (%i) ]__________\n", j+1);
									printf("\n Cod: %i", imoveis[j].cod);
									printf("\n Tipo: %s", imoveis[j].tipo);
									printf("\n Valor: %.2f", imoveis[j].valor);
									printf("\n Endereco: %s", imoveis[j].endereco);
									printf("\n Situacao: %s", imoveis[j].situacao);
									puts("\n-----------------------------------\n");
								}else{
									printf("\n Nenhum Imovel com do tipo %s encontrado", pesquisaComercial);
								}
							}

						}else{
							printf("\n\n Nenhum Imovel cadastrado...\n\n");
						}

				break;
			}
			case 4: { //Pesquisa por venda ou aluguel, (situa豫o comercial)

					printf("\n _____________________________________\n");
					printf("|                                     |\n");
					printf("|        CONSULTA POR SITUACAO        |\n");
					printf("|_____________________________________|\n");
					printf("\n Digite [0], Para sair...");
					puts("\n _____________________________________");

					printf("\n Pesquise por (Venda)/(Aluguel): ");
					 fgets(pesquisaComercial, sizeof(pesquisaComercial), stdin);
					  convertpMinusculo(pesquisaComercial);

						if(qtdImoveis>0){

							for(j=0; j<qtdImoveis; j++){

								if(strcmp(imoveis[j].situacao, pesquisaComercial) == 0){ //Compara豫o de escolha

									printf("\n___________[ Imovel (%i) ]__________\n", j+1);
									printf("\n Cod: %i", imoveis[j].cod);
									printf("\n Tipo: %s", imoveis[j].tipo);
									printf("\n Valor: %.2f", imoveis[j].valor);
									printf("\n Endereco: %s", imoveis[j].endereco);
									printf("\n Situacao: %s", imoveis[j].situacao);
									puts("\n-----------------------------------\n");
								}else{
									printf("\n Nenhum Imovel com a situação %s encontrado...\n", pesquisaComercial);
								}
							}

						}else{
							printf("\n\n Nenhum Imovel cadastrado...\n\n");
						}
					system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
				break;
			}
			case 5: { //exibir o valor total da soma de todos os imóveis com situação “venda”;
				totVenda=0;
				for(i=0; i<qtdImoveis; i++){
					if(strcmp(imoveis[i].situacao, "venda\n")==0){ //Compara a situação na posição com a string
						totVenda += imoveis[i].valor;
					}
				}

				if(totVenda>0){
					printf("\nOs imoveis com a disposicao (venda) possuem juntos um capital liquido de: \n\n | R$ %.2f |\n\n", totVenda);
				}else{
					printf("\nNenhum capital de imoveis a venda disponivel...\n\n");
				}

					system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
				break;
			}
			case 6: { //exibir o valor total da soma de todos os imóveis com situação “aluguel”;
				totAluguel=0;

				for(i=0; i<qtdImoveis; i++){
					if(strcmp(imoveis[i].situacao, "aluguel\n")==0){ //Compara a situação na posição com a string
						totAluguel += imoveis[i].valor;
					}
				}

				if(totAluguel>0){
					printf("\nOs imoveis com a disposicao (aluguel) possuem juntos um capital mensal de: \n\n | R$ %.2f |\n\n", totAluguel);
				}else{
					printf("\nNenhum capital de imoveis em aluguel disponivel...\n\n");
				}

					system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();

				break;
			}
			case 7: { //Imovel mais caro a venda
				maiorValor=0;

					for(i=0; i<qtdImoveis; i++){
						if(imoveis[i].valor > maiorValor && (strcmp(imoveis[i].situacao, "venda\n")==0)){ //Compara o valor atual com maior valor
							maiorValor = imoveis[i].valor;
							pos = i;
						}
					}

					if(maiorValor > 0){

						printf("\nO imovel com maior preco a venda custa: R$ %.2f \n\n", maiorValor);

							printf("\n___________[ Imovel (%i) ]__________\n", pos+1);
							printf("\n Cod: %i", imoveis[pos].cod);
							printf("\n Tipo: %s", imoveis[pos].tipo);
							printf("\n Valor: %.2f", imoveis[pos].valor);
							printf("\n Endereco: %s", imoveis[pos].endereco);
							printf("\n Situacao: %s", imoveis[pos].situacao);
							puts("\n-----------------------------------\n");

					}else{
						printf("\nNenhum imovel a venda encontrado...\n\n");
					}

					system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
				break;
			}
			case 8: { //Apagar algum imovel

				printf("\n _____________________________________\n");
				printf("|                                     |\n");
				printf("|            APAGAR IMOVEL            |\n");
				printf("|_____________________________________|\n");
				printf("\n Digite [0], Para sair...");
				puts("\n _____________________________________");

				printf("\n Digite o Codigo do imovel a ser apagado: ");
				 scanf("%i", &codSearch);
				  getchar();

				if(codSearch!=0 && codSearch>0){ //Se o código for valido

					for(i=0; i<qtdImoveis; i++){ // Inicia o primeiro loop
						if(imoveis[i].cod == codSearch){ //Se achar um código compatível, "=="
							for(j=i; j<qtdImoveis; j++){ // inicia um loop com o valor anterior
								imoveis[i] = imoveis[i+1]; //O imovel passa pra próxima posição
							}
						}
					}
					qtdImoveis--; //Diminui a qtde de imoveis
					printf("\nImovel Excluido com Sucesso!...\n\n");
					system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
				}else{ //F
					printf("\nSaindo!...\n\n");
					system("read -p 'Pressione Enter para continuar...'"); system("clear"); menuPrincipal();
				}

				break;
			}

			case 0: {
				printf("\nSaindo do programa...\n");
				return 0;
			}
			default:
				printf("\nOpcao invalida, tente novamente...");
				menuPrincipal();
				break;
		}

	}while(menu!=0);

	printf("\nSaindo do programa...\n");

}
//Fim main
