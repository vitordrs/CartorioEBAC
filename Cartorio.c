#include <stdio.h> //Comunica��o com Usuario
#include <stdlib.h>//Aloca��o de espaco na memoria
#include <locale.h>//Aloca��o de texto por regi�o
#include <string.h>//biblioteca das strings

int registro(){ //fun��o do cadastro de usuario

	//iniciando cria��o de variaveis	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser Cadastrado: (Apenas Numeros)");//coletando informa��o de Usuarios0
	scanf("%s", cpf);

	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo na pasta
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	//cadastro do nome
	printf("Digite o Nome  a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	//cadastro sobrenome
	printf("Digite o Sobrenome  a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	//cadastro do cargo
	printf("Digite o Cargo  a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	char cpf [40];
	char conteudo[200];
	//Input do CPf que vai ser pesquisado pelo usuario
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	//procura do cpf no banco de dados
	FILE *file;
	file = fopen(cpf, "r");
	
	//Valida��o para saber se existe o Cpf consultado
	if(file == NULL){
		printf("N�o foi possivel encontrar o Arquivo, N�o foi Localizado...\n");
	}
	//Valida��o 
	printf("\nEssas S�o as informa��es do usuario: \n");
	while(fgets(conteudo, 200, file) !=NULL ){
//		printf("\nEssas S�o as informa��es do usuario: ");
		printf("\t- ");
		printf("%s", conteudo);
		printf("\n");
	}
	system("pause");
}

int deletar(){
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usuario n�o se encontra no sistema.!\n");
		system("pause");
	}
	
	
}


int main (){
	int opcao=0; //Difinindo Variavel
	int laco=1;
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	for (laco=1;laco=1;){
	
		system("cls");
	
	
		
		printf("------- Cart�rio da EBAC -------\n\n"); //Inicio menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes.\n");
		printf("\t2 - Consultar Nomes.\n");
		printf("\t3 - Deletar Nomes.\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: ");// fim menu
		
		scanf("%d", &opcao);//Armazenando escolha do usuario
		
		system("cls");
		
		switch(opcao){
			case 1:
				registro();
				break;
			case 2:
				consulta();
				break;
			case 3:
				deletar();
				break;
			case 4:
				printf("Obrigado por utilizar, At� a Proxima!\n\n");
				return 0;
				break;
			default:
				printf("Essa Op��o n�o existe\n");
				system("pause");
				break;
		}//fim da sele��o
	}
}
