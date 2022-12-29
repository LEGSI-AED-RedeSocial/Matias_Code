#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Usei o typedef para dar um nome á struct e sempre que precisar dela só preciso usar o nome, esta struct foi usada para determinar que tipo de informação cada user vai ter*/
typedef struct user_structure{
	char name[50];
	char address[200];
	int phone_number;
	int pin;
} User;

/* em vez de "int" ou "long" o tipo de dados do array vai ser do tipo da struct, ou seja, cada célula do array vai ser, outro array com todas as informações do user*/
void novo_utilizador(User lista_utilizadores[], int *numero_utilizadores){
	User aux;

	
	printf("\nInsira o seu nome:\n");
	fgets(aux.name, 50, stdin);
	printf("\nInsira a sua morada:\n");
	fgets(aux.address, 200, stdin);
	printf("\nInsira o seu numero telefonico:\n");
	scanf("%d%*c", &aux.phone_number);
	do
	{
		printf("\nIntroduza o seu PIN (4 Digitos):\n");
		scanf("%d%*c",&aux.pin);
		if (aux.pin<1000 || aux.pin>9999)
		{
			printf("Introduza um numero valido");
		}		

	} while(aux.pin<1000 || aux.pin>9999);
	
	
	(*numero_utilizadores)++;	
	lista_utilizadores[*numero_utilizadores]=aux;
}

void listar(User lista_utilizadores[],int numero_utilizadores){
	int i;
	for(i=0; i<numero_utilizadores; i++){
		printf("\n\nNumero: %d", lista_utilizadores[i].phone_number);
		printf("\nNome: %s", lista_utilizadores[i].name);
		printf("\nMorada: %s", lista_utilizadores[i].address);
	}	
}

int consultar(User lista_utilizadores[], int numero_utilizadores) {
	int i=0, encontrou=0;
	char nomeAprocurar[50];
	printf("Qual é o nome a procurar?");
	fflush(stdin);
	gets(nomeAprocurar);
	while(i<numero_utilizadores){
		if (strcmp(nomeAprocurar,lista_utilizadores[i].name)==0){
			printf("\n\nNumero: %d", lista_utilizadores[i].phone_number);
			printf("\nNome: %s", lista_utilizadores[i].name);
			printf("\nMorada: %s", lista_utilizadores[i].address);
			encontrou=1;
		}
		i++;
	}
	if (encontrou==0){
		printf("O nome não foi encontrado");
	}
}

int main(){

	int opcao, numero_utilizadores=0;	
	User lista_utilizadores[200];
	setlocale(LC_ALL,"Portuguese");

	do{	
	
	printf("\n\n*** Menu ***\n\n");
	printf("\n1- Novo Utilizador");
	printf("\n2- Utilizador recorrente");
	printf("\n3- Editar Utilizador");
	printf("\n4- Remover Utilizador");
	printf("\n5- Listar Utilizadores");
	printf("\n6-Consultar Utilizador");
	printf("\n0- Sair");

	printf("\n\nEscolha uma opcao\n");
	scanf("%d%*c", &opcao);
	
	switch(opcao){
	case 1:
		printf("\n Novo Utilizador");
		novo_utilizador(lista_utilizadores, &numero_utilizadores);
		break;
	case 2:
		printf("\n Utilizador recorrente");
		break;
	case 3:
		printf("\n Editar Utilizador");
		break;
	case 4:
		printf("\n Remover Utilizador");
		break;
	case 5:
		printf("\n Listar Utilizadores");
		listar(lista_utilizadores, numero_utilizadores);
		break;
	case 6:
		printf("\n Consultar Utilizador");
		consultar(lista_utilizadores,numero_utilizadores);
		break;
	case 0:
		printf("\n Volte sempre!");
		exit;
		break;
	default:
		printf("\n Insira uma opcao valida");
		break;
	}
	
	printf("\n");
	system("pause");
	
	} while (opcao!=0);
	
	
}