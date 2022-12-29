#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// definição de constantes
#define tamNome 30 
#define tamMorada 50
#define tamLista 200

//definição de tipos
typedef struct contacto{
		int numero;
		char nome[tamNome];
		char morada[tamMorada];
	} Assinante;
	
//funções
void inserirAssinante(Assinante lista[],int *nrPessoas){
	Assinante aux;
	
	printf("Qual é o seu número?");
	scanf("%d", &aux.numero);
	printf("Qual é o seu nome?");
	fflush(stdin); gets(aux.nome);
	printf("Qual é a sua morada?");
	fflush(stdin); gets(aux.morada);
	lista[*nrPessoas]=aux;
	(*nrPessoas)++;
}
void listar(Assinante lista[],int nrPessoas){
	int i;
	for(i=0; i<nrPessoas; i++){
		printf("\n\nNumero: %d", lista[i].numero);
		printf("\nNome: %s", lista[i].nome);
		printf("\nMorada: %s", lista[i].morada);
	}	
}

void consultar(Assinante lista[], int nrPessoas) {
	int i=0, encontrou=0;
	char nomeAprocurar[tamNome];
	printf("Qual é o nome a procurar?");
	fflush(stdin);
	gets(nomeAprocurar);
	while(i<nrPessoas){
		if (strcmp(nomeAprocurar,lista[i].nome)==0){
			printf("\n\nNumero: %d", lista[i].numero);
			printf("\nNome: %s", lista[i].nome);
			printf("\nMorada: %s", lista[i].morada);
			encontrou=1;
		}
		i++;
	}
	if (encontrou==0){
		printf("O nome não foi encontrado");
	}
}

void gravarDados(Assinante lista[], int nrPessoas) {
	FILE *fich;
	fich=fopen("dados.data","wb");
	fwrite(&nrPessoas, sizeof(int), 1, fich);
	fwrite(lista, sizeof(Assinante), nrPessoas, fich);
	fclose(fich);	
}

void buscarDados(Assinante lista[], int *nrPessoas){
	FILE *fich;
	int t=0;
	if ((fich=fopen("dados.data", "rb"))!=NULL){
		int n;
		n=fread(&t, sizeof(int), 1, fich);
		n=fread(lista, sizeof(Assinante), t, fich);
	}
	*nrPessoas=t;
	fclose(fich);
}

int main () {
	int opcao, nrPessoas=0;
		
	Assinante lista[tamLista];
	 setlocale(LC_ALL,"Portuguese");
	 buscarDados(lista, &nrPessoas);
do{	
	system("cls");
	printf("\n\n**Menu incial**\n\n");
	printf("1- Novo Utilizador\n");
	printf("2- Editar Utilizador\n");
	printf("3- Consultar Utilizador\n");
	printf("4- Remover Utilizador\n");
	printf("5- Listar Utilizadores\n");
	printf("6- Total de assinantes\n");
	printf("0- Terminar\n");
	
	printf("Escolha uma opcao");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1: printf("\nInserir assinante");inserirAssinante(lista, &nrPessoas);break;
		case 2: printf("\nEditar assinante");break;
		case 3: printf("\nConsultar assinante");consultar(lista,nrPessoas);break;
		case 4: printf("\nRemover");break;
		case 5: printf("\nListar");listar(lista, nrPessoas);break;
		case 6: printf("Numero de assinantes: %d", nrPessoas);break;
		case 0: gravarDados(lista,nrPessoas); printf("\nBom viagem, volte sempre");break;
		default: printf("\nOpcao invalida");
	} 
	printf("\n");
	system("pause");
}while(opcao!=0);	

	
	
	

}