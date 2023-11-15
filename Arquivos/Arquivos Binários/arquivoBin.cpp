#include<stdio.h>
#include<string.h>

FILE *arquivoBin;

struct Funcionario{
	char nome[100];
	float salario;
	int flag;
};

void gravar(Funcionario f){
	//fopen abre o arquivo, pora trabalhar com struct usa-se a extensão .dat
	arquivoBin = fopen("Funcionario.dat", "a+b");
	//Recebe o endereço de memória de funcionario 'f', verifica o tamanho, referencia a qtd de arquivos, e o arquivo
	f.flag=1;
	fwrite(&f, sizeof(struct Funcionario), 1, arquivoBin);
	//fclone fecha o arquivo
	fclose(arquivoBin);
}

void cadastrar(struct Funcionario funcionario){
	int cont=1;
	
	printf("\n - Cadastrar Funcionario - \n");
	
	do{
		printf("\nNome: "); getchar(); //Getchar limpa buffer de entrada
		fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
		printf("\nSalario: ");
		scanf("%f", &funcionario.salario);
		
		gravar(funcionario); //Grava as informações 
		printf("_____________________________________________________");
		printf("\n\nAdicionar outro funcionario: (1)Sim : (0)Nao \n\n");
		scanf("%i", &cont);

		
	}while(cont==1);
	
return;
}

void consultar(){
	//abre o arquivo para a leitura
	arquivoBin=fopen("funcionario.dat", "r");
	//retorna no inicio do arquivo para leitura
	rewind(arquivoBin);
	
	Funcionario f;
	
	// "Enquanto não chegar ao fim do arquivo..."
	while(!feof(arquivoBin)){
		//fread lê um bloco de dados e já passa para o proximo
		fread(&f, sizeof(struct Funcionario), 1, arquivoBin);
		
		if(f.flag==1){
			//printa Nome e salário
		printf("Nome: %s", f.nome);
		printf("salário: %.2f", f.salario);
		}
	}
	fclose(arquivoBin);
}

void excluir(char nome[100]){
	
	arquivoBin = fopen("funcionarios.dat", "r+b");
	rewind(arquivoBin);
	Funcionario f;

	int cont =-1; //Verificador de posição
	
	while(!feof(arquivoBin)){
		fread(&f, sizeof(struct Funcionario), 1, arquivoBin); //Lê a primeira struct
		cont ++; 
		
		if((f.flag==1) && (strcmp(nome, f.nome)) == 0){ //Se  (flag == 1) e (entrada de função == nome)
			//Flag, que é o verificador da struct recebe 0, referente a um sinal de 1 ou 0 para continuação
			f.flag=0; 
			//fseek posiciona um ponteiro que fica na posição *cont
			fseek(arquivoBin, sizeof(Funcionario)*cont, SEEK_SET);
			
			fwrite(&f, sizeof(Funcionario), 1, arquivoBin); 
			
			fseek(arquivoBin, 0, SEEK_END);
		}
	}
	
}

int main(void){
	Funcionario f; //Criando uma variável Struct funcionário
	cadastrar(f); //Cadastrando funcionário baseado na struct
	gravar(f); //Gravando no arquivo
	consultar();
}
