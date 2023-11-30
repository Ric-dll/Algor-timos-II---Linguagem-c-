#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define TAM 1000

//Função para gerar um ano aleatório
int gerarAno(){ //Retorna um ano aleatório entre: [1940 - 2023]
	return rand() % (2023 - 1940 + 1)+1940;
}

//Função pra gerar uma descrição aleatória
void gerarDescricao(char *descricao){
	char des[][40] = {"Toyota Camry", "Toyota Corolla", "Toyota RAV4", "Toyota Highlander", "Toyota Tacoma", "Ford Mustang", "Ford F-150", "Ford Explorer", "Ford Escape", "Ford Edge", "Chevrolet Silverado", "Chevrolet Equinox", "Chevrolet Malibu", "Chevrolet Traverse", "Chevrolet Camaro", "Honda Accord", "Honda Civic", "Honda CR-V", "Honda Pilot", "Honda Odyssey", "Nissan Altima", "Nissan Rogue", "Nissan Titan", "Nissan Armada", "Nissan Pathfinder", "Volkswagen Jetta", "Volkswagen Passat", "Volkswagen Tiguan", "Volkswagen Atlas", "Volkswagen Golf", "BMW 3 Series", "BMW 5 Series", "BMW X3", "BMW X5", "BMW 7 Series", "Mercedes-Benz C-Class", "Mercedes-Benz E-Class", "Mercedes-Benz GLC", "Mercedes-Benz GLE", "Mercedes-Benz S-Class", "Audi A4", "Audi Q5", "Audi A6", "Audi Q7", "Audi R8", "Tesla Model 3", "Tesla Model S", "Tesla Model X", "Tesla Model Y", "Hyundai Sonata", "Hyundai Tucson", "Hyundai Santa Fe", "Hyundai Palisade", "Hyundai Kona", "Kia Optima", "Kia Sportage", "Kia Sorento", "Kia Telluride", "Kia Soul", "Subaru Legacy", "Subaru Outback", "Subaru Forester", "Subaru Ascent", "Subaru WRX", "Mazda3", "Mazda6", "Mazda CX-5", "Mazda CX-9", "Mazda MX-5 Miata", "Fiat 500", "Fiat 500X", "Fiat 500L", "Fiat 124 Spider", "Jeep Wrangler", "Jeep Grand Cherokee", "Jeep Cherokee", "Jeep Compass", "Jeep Renegade", "Volvo S60", "Volvo XC40", "Volvo XC60", "Volvo XC90", "Volvo V90", "Lexus ES", "Lexus RX", "Lexus NX", "Lexus GX", "Lexus LX", "Porsche 911", "Porsche Cayenne", "Porsche Panamera", "Porsche Macan", "Porsche 718 Boxster", "Jaguar XE", "Jaguar XF", "Jaguar F-PACE", "Jaguar E-PACE", "Jaguar I-PACE"};
	sprintf(descricao, "%s", des[rand()%40]); //Gera um valor aleatório e combina com a posição do vetor para armazenar
}

//Função pra gerar um preço aleatório
float gerarPreco(){
	return ((float)rand() / RAND_MAX) * (120000 - 20000) + 20000;
}

