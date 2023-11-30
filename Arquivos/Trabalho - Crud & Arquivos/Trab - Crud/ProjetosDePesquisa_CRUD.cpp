//Inclusão de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definição de quantidade de avaliadores para contagem no vetor posição
#define MAX_AVALIADORES 100

// Declaração de arquivo. "FILE *"
FILE *arquivoBin;

//Registro de avaliador
struct _Avaliador{
    int ID;
    char Nome[100];
};

//Registro a ser manipulado no Arquivo
struct _ProjetoDePesquisa{
    //Atributos base do projeto
    char Area[50];
    char Titulo[100];
    char PalavrasChave[200];

	//Flag que verifica se o projeto está ou não com avaliador ativo, 0 ou 1
    int status_Avaliador;

    //Status geral do projeto
    int status;

	//Variável para controle de quantidade de avaliadores
    int num_avaliadores;

    //Vetor de Struct de tipo _Avaliador, para corrigir o erro de sobreposição
    struct _Avaliador SAVE_avaliadores[MAX_AVALIADORES];
    //Foi necessário a criação e tal manuseio de vinculação com problemas de valores e substituição em multiplos projetos
};


//Menu de opções
void CRUD(){
    printf("\n ____________________________________\n");
    printf("|                                    |\n");
    printf("|     MENU - Projeto de pesquisa     |\n");
    printf("|____________________________________|\n");
    printf(" |                                  |\n");
    printf(" |      1. Cadastrar Projeto        |\n");
    printf(" |      2. Exibir Projetos          |\n");
    printf(" |      3. Alterar Projeto          |\n");
    printf(" |      4. Excluir Projeto          |\n");
    printf(" |      5. Vincular Avaliador       |\n");
    printf(" |                                  |\n");
    printf(" |            [0] Fechar            |\n");
    printf(" |                                  |\n");
    printf(" |__________________________________|\n");
}


//Função para gravar os dados de um registro (recebido como parâmetro) no arquivo, também cria caso não exista...
void gravar_Dados(struct _ProjetoDePesquisa projPesq){

	//Verificação se o arquivo foi criado sem complicações, "ab" foi preferível ao invés de "a+b" por alguns fatores de sistema
    if((arquivoBin = fopen("Projetos_De_Pesquisa.dat", "ab")) == NULL){
        printf("\nProblemas com a abertura e gravação no arquivo binário...\n");
    }else{
		//Se estiver tudo certo, então, o status do projeto = 1 --> Ativo
        projPesq.status = 1;

        //Melhores considerações das funções no arquivo separado
        fwrite(&projPesq, sizeof(struct _ProjetoDePesquisa), 1, arquivoBin);

        //Fecha o arquivo após o manuseio
        fclose(arquivoBin);
        printf("\nDados gravados com Sucesso!...\n");
    }
}

//Função para ler e exibir os registros do arquivo
void ler_Dados(){
	//condição que verifica abertura de arquivo através da função fopen, o parâmetro "rb" = "r = read, b = binary", para leitura.
    if((arquivoBin = fopen("Projetos_De_Pesquisa.dat", "rb")) == NULL){
        printf("\nProblemas ao abrir o arquivo para leitura...\n");
    }else{
        //Comando para que o código volte ao início do arquivo
        rewind(arquivoBin);

        //Tipo da struct para receber os valores do arquivo.
        struct _ProjetoDePesquisa projPesq;


		//ENQUANTO o fread faz a leitura de um registro e armazena o conteúdo do registro lido do arquivo no Registro projPesq e ainda possui dados a serem lidos (== 1), então continue
        while(fread(&projPesq, sizeof(struct _ProjetoDePesquisa), 1, arquivoBin) == 1) {
			//A função verifica se houve erro durante a operação de arquivo...
            if(ferror(arquivoBin)){
                printf("\nProblemas na leitura do arquivo...\n");
                break;
            }

			//verifica se o status do projeto está ativo para continuar
            if(projPesq.status == 1){
				//Mostra todas as informações necessárias do projeto
                printf("\n------[ Projeto Cadastrado ]------");
                printf("\nArea: %s", projPesq.Area);
                printf("\nTitulo: %s", projPesq.Titulo);
                printf("\nPalavras Chave: %s", projPesq.PalavrasChave);
                printf("\nStatus: %i\n", projPesq.status);

				//Condição para verificar se o status de avaliador está ativo ou não
                if(projPesq.status_Avaliador == 0){
                    printf("\nProjeto sem avaliador\n\n"); //flag = 0
                }else{
                    //Se sim, então o for começa a buscar a posição para mostrar a qual foi atribuido
                    for(int i = 0; i < projPesq.num_avaliadores; i++){
                        printf("ID Avaliador: %i | Nome: %s \n", projPesq.SAVE_avaliadores[i].ID, projPesq.SAVE_avaliadores[i].Nome);
                        //A lógica para como a ordem sempre está correta é que o avaliador na posição [i] estará sempre sendo cadastrado associado a algum projeto.
                        /*
                         * Exemplos:
                         * Avaliador 1 em (projeto 5) ====> avaliador[0] (projeto 5)
                         * avaliador[1] (projeto 2)
                         * avaliador[2] (projeto 4)
                         * avaliador[3] (projeto 1)
                         *
                         * A lógica é que a ordem de cadastro dos avaliadores no array SAVE_avaliadores é preservada, e o loop for percorre esse array,
                         * assim imprimindo as informações de cada avaliador associado ao projeto.
						*/
                    }
                }
            }
        }
        //Fecha o arquivo após o manuseio
        fclose(arquivoBin);
    }
}

void atualizar_Dados(struct _ProjetoDePesquisa MainProjetoDePesquisa){
	//condição que verifica abertura de arquivo através da função fopen, o parâmetro, "r+b" significa que o arquivo será aberto para leitura e escrita em modo binário
	if((arquivoBin = fopen("Projetos_De_Pesquisa.dat", "r+b")) == NULL){
		printf("\nProblemas para abertura para atualizacao de dados");
	}
	//Comando para que o código volte ao início do arquivo
	rewind(arquivoBin);

	//Tipo da struct para receber os valores do arquivo.
	struct _ProjetoDePesquisa CommitProjetoDePesquisa;

	printf("\n--- Alteracao ---");

	//For de i começando em 0, verifica se a leitura de um registro do arquivo foi lida corretamente, se sim, i++
	for(int i=0; fread(&CommitProjetoDePesquisa, sizeof(struct _ProjetoDePesquisa), 1 , arquivoBin); i++){

		//Compara se o Titulo do registro é igual ao de referência por registro, e se flag está ativo
		if(strcmp(CommitProjetoDePesquisa.Titulo, MainProjetoDePesquisa.Titulo) == 0 && CommitProjetoDePesquisa.status == 1){
			//O comando fseek move o ponteiro do arquivo para a posição correspondente ao registro que está sendo lido
			fseek(arquivoBin, sizeof(struct _ProjetoDePesquisa) * i, SEEK_SET);

			//Flag para definir se o registro está ativo(1) ou inativo(0)
			MainProjetoDePesquisa.status = 1;

			//Atualiza, gravando as novas informações no registro de "MainProjetoDePesquisa", ou seja, no arquivo principal reverenciado
			fwrite(&MainProjetoDePesquisa, sizeof(struct _ProjetoDePesquisa), 1 , arquivoBin);

			break;//Após para o código
		}
	}
	fclose(arquivoBin);
	printf("\nDados Alterados com Sucesso!...\n");
}


//Função para alterar os dados de um registro com a placa passada por parâmetro
void delete_Dados(char Titulo[100]){
	//condição que verifica abertura de arquivo através da função fopen, o parâmetro, "r+b" significa que o arquivo será aberto para leitura e escrita em modo binário
    if((arquivoBin = fopen("Projetos_De_Pesquisa.dat", "r+b")) == NULL){
        printf("\nErro na abertura de arquivo para exclusao...");
    }
    //Comando para que o código volte ao início do arquivo
    rewind(arquivoBin);

    //Variável de acesso local tipo struct
    struct _ProjetoDePesquisa CommitProjetoDePesquisa;

    printf("\n--- Exclusao ---\n");

	//Contador utilizado para acessar o registro que será alterado
	//é inicializado como -1 dentro do loop, pois, antes de cada leitura de registro, i é incrementado, e geralmente começa em 0...Max
    int i = -1;

	//Enquanto o arquivo não chegar ao fim...
    while(!feof(arquivoBin)){
		//fread faz a leitura de um registro e armazena o conteúdo do registro lido do arquivo no Registro CommitProjetoDePesquisa
        fread(&CommitProjetoDePesquisa, sizeof(struct _ProjetoDePesquisa), 1, arquivoBin);

        //incrementa para continuação
        i++;

		//Verificação de possíveis erros
        if(ferror(arquivoBin)){
            printf("\nErro na leitura para exclusao...\n");
            break;
        }

		//Verifica se o arquivo ainda não chegou ao fim, e se o titulo recebido como parâmetro é o mesmo do registro da struct, e se a mesma está com status ativo
        if((!feof(arquivoBin)) && (strcmp(CommitProjetoDePesquisa.Titulo, Titulo) == 0) && CommitProjetoDePesquisa.status == 1){ //Se sim...

			//Status passa a receber flag de inativo
            CommitProjetoDePesquisa.status = 0;

            //O comando fseek move o ponteiro do arquivo para a posição correspondente ao registro que está sendo lido
            fseek(arquivoBin, sizeof(struct _ProjetoDePesquisa) * i, SEEK_SET);

            //Atualiza, gravando as novas informações no registro de "CommitProjetoDePesquisa", ou seja, no arquivo reverenciado
            fwrite(&CommitProjetoDePesquisa, sizeof(struct _ProjetoDePesquisa), 1, arquivoBin);

            //Está sendo usado para posicionar o indicador 'i' de posição no final do arquivo.
            fseek(arquivoBin, 0, SEEK_END);
        }
    }
    //Fecha o arquivo após manuseio
    fclose(arquivoBin);

    printf("\nDados Excluidos com Sucesso!...\n"); //Validação :)
}

//Função pra vincular_Avaliador, recebe título como parâmetro de busca
void vincular_Avaliador(char titulo[100]) {

	//condição que verifica abertura de arquivo através da função fopen, o parâmetro, "+" Indica que o arquivo deve ser aberto tanto para leitura quanto para escrita.
    if ((arquivoBin = fopen("Projetos_De_Pesquisa.dat", "r+b")) == NULL) {
        printf("\nErro na abertura de arquivo para exclusao...");
    }

    //Comando para que o código volte ao início do arquivo
    rewind(arquivoBin);

    //Variável de acesso local tipo struct
    struct _ProjetoDePesquisa projPesq;

	//Variável local para controle de encontro de projeto
    int projetoEncontrado = 0;

	//ENQUANTO o fread faz a leitura de um registro e armazena o conteúdo do registro lido do arquivo no Registro projPesq e ainda possui dados a serem lidos (== 1), então continue
    while (fread(&projPesq, sizeof(struct _ProjetoDePesquisa), 1, arquivoBin) == 1) {

		//Verificação de caso de erro no arquivo
        if (ferror(arquivoBin)) {
            printf("\nErro na leitura para Vinculacao...\n");
            break;
        }

		//Verificação de igualdade entre o título do projeto e o parâmetro passado, além de verificar os status de projeto se ativo, e avaliador se ainda não
        if ((strcmp(projPesq.Titulo, titulo) == 0) && projPesq.status == 1 && projPesq.status_Avaliador == 0) {

			//Se projeto não tiver avaliador, passará a ter e ficará com flag 1
            projPesq.status_Avaliador = 1;

            printf("\n--- Cadastro de Avaliador ---\n");

			//Verifica se o número de avaliadores dentro do projeto de pesuqisa localmente criado pra manuseio é menor do que o maximo definido
            if (projPesq.num_avaliadores < MAX_AVALIADORES) { //Se sim...

				/* GAMBIARRA:
				 * Recebe as informações do avaliador e armazena no projeto de pesquisa, no campo de struct avaliador "SAVE_avaliadores"
				 * Como foi Criado um vetor para SAVE_avaliadores, que armazena os mesmos, tudo que será obtido, será salvo no vetor do
				 * projeto de pesquisa na posição referente ao contador "num_avalidores"...
				*/

                printf("\nNome do Avaliador: ");
                scanf("%s", projPesq.SAVE_avaliadores[projPesq.num_avaliadores].Nome);

                printf("\nID: ");
                scanf("%i", &projPesq.SAVE_avaliadores[projPesq.num_avaliadores].ID);

				//Incrementa o vetor para salvar a posição
                projPesq.num_avaliadores++;

				//Move o ponteiro para a posição que antecede o início do registro que está sendo lido,
				//SEEK_CUR desloca o ponteiro baseado na posição atual do arquivo, motivo pelo qual do (-) em sizeof
                fseek(arquivoBin, -sizeof(struct _ProjetoDePesquisa), SEEK_CUR);

                //Atualiza, gravando as novas informações no registro "projPesq", que é o arquivo reverenciado
                fwrite(&projPesq, sizeof(struct _ProjetoDePesquisa), 1, arquivoBin);

				//Atualiza a variável local para condição posterior
                projetoEncontrado = 1;
            } else {
                printf("\nLimite de avaliadores atingido para este projeto.\n");
            }
            //Caso de certo antes de ler todo o arquivo, pode finalizar o processo
            break;
        }
    }

	//Verifica se o projeto foi encontrado(1) ou não(0)
    if (!projetoEncontrado) {
		//Sesim significa que já foi vinculado, impossibilitanto assim a vinculação novamente
        printf("\nProjeto nao encontrado ou ja possui avaliador.\n");
    }

	//Fecha a leitura do arquivo
    fclose(arquivoBin);
}


//Função principal
int main(void){

	//Definição de loop para opção no menu
    int menu = 1;

    //Variável struct local do projeto para manuseio principal
    struct _ProjetoDePesquisa projeto;

	//repita o Loop enquanto o menu opção for diferente de 0
    while(menu != 0){

        system("clear"); //Limpa o terminal
        CRUD(); //Chama o menu

		//Escolha de opção
        printf("\nEscolha uma opcao: ");
        scanf("%i", &menu);

		//Atribuição de opção
        switch(menu){
            case 1: {

				//Faz o cadastro pegando todas as informações importantes
                printf("\n--- Cadastro ---\n");

                printf("\nArea: ");
                scanf("%s", projeto.Area);

                printf("\nTitulo: ");
                scanf("%s", projeto.Titulo);

                printf("\nPalavras Chave: ");
                scanf("%s", projeto.PalavrasChave);

				//Define os status de avaliador e número dos mesmos como 0, pois inicialmente não possui
                projeto.status_Avaliador = 0;
                projeto.num_avaliadores = 0;

				//Função gravar dados, para criar o arquivo
                gravar_Dados(projeto);
                break;
			}

            case 2: {
				//Chama a função para ler os dados armazenados no arquivo
                printf("\n--- Exibicao ---\n");
                ler_Dados();
                break;
			}

            case 3: {
                //Recebendo o título do registro para alteração
				printf("\n------[ Alteracao ]------\n"); getchar();
				printf("\nTitulo do projeto a ser alterado: "); scanf("%s", projeto.Titulo);

				//Novos dados
				printf("\nArea: "); scanf("%s", projeto.Area);
				printf("\nPalavras-Chave: "); scanf("%s", projeto.PalavrasChave);

				//Chamando a função para alterar os dados no registro que foi entrado
				atualizar_Dados(projeto);

				system("read -p 'Pressione Enter para continuar...'"); system("clear"); CRUD();
				break;
			}

            case 4: {
                printf("\n--- Exclusao ---\n");

                printf("\nInforme o titulo do projeto a ser excluido: ");
                scanf("%s", projeto.Titulo);

                delete_Dados(projeto.Titulo);
                break;
			}

            case 5: {
                printf("\n--- Vinculacao ---\n");
                printf("\nInforme o titulo do projeto para vincular um avaliador: ");

				//Recebe de forma direta o título no atributo local presente na varivel local
                scanf("%s", projeto.Titulo);

				//Chama a função com o título obtido por referência direta a struct
                vincular_Avaliador(projeto.Titulo);
                break;
			}

            case 0: {
				//Somente para aparecer a mensagem, não é necessário pois como condição do loop, quando 0, automaticamente fecha
                printf("\nSistema Encerrado...\n");
                break;
			}

            default: {
				//Se for digitado alguma opção que não está listada
                printf("\nOpcao invalida! Tente novamente...\n");
                break;
			}
		}

        printf("\nPressione ENTER para continuar...\n");
        getchar(); // Limpar o buffer do teclado
        getchar(); // Esperar ENTER
    }

    return 0;
}
