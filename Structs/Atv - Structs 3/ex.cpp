#include<stdio.h>
#include<string.h>

int tamanho=0;

struct Ficha{
	char nome[200];
	int idade;
	float salario;	
};

void insere(Ficha fichario[], Ficha f){
	fichario[tamanho] = f;
	tamanho++;
}

void exibe(Ficha fichario[]){
	int i;
	for(i=0; i<tamanho; i++){
		printf("\nNome: %s", fichario[i].nome);
		printf("\nIdade: %i", fichario[i].idade);
		printf("\nSalario: %.2f\n", fichario[i].salario);
	}	
}

float somaSalario(Ficha fichario[]){
	int i;
	float soma=0;
	
	for(i=0; i<tamanho; i++){
		soma+=fichario[i].salario;
	}
	return soma;
}

Ficha maiorSalario(Ficha fichario[]){
	int i;
	Ficha f = fichario[0];
	
	for(i=0; i<tamanho; i++){
		if(fichario[i].salario > f.salario){
			f = fichario[i];
		}
	}
	return f;
}


main(){
	struct Ficha fichario[100];
	Ficha f;
	
	strcpy(f.nome, "Ana");
	f.idade = 20;
	f.salario = 2500;
	insere(fichario, f);

	strcpy(f.nome, "Joao");
	f.idade = 30;
	f.salario = 3000;
	insere(fichario, f);
	exibe(fichario);
	
	puts("");
	
	f = maiorSalario(fichario);
	
	printf("Soma dos Salarios: %.2f\n", somaSalario(fichario));
	printf("Maior salario: %s = %.2f", f.nome, f.salario);
}
