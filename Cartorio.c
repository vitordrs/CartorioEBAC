#include <stdio.h> //Comunicação com Usuario
#include <stdlib.h>//Alocação de espaco na memoria
#include <locale.h>//Alocação de texto por região
#include <string.h>//biblioteca das strings

int registro(){ //função do cadastro de usuario

	//iniciando criação de variaveis	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser Cadastrado: (Apenas Numeros)");//coletando informação de Usuarios0
	scanf("%s", cpf); //%s refere-se a strings

	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo na pasta
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");// faz espacamento entre as informaçoes
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

int consulta(){//função de consultar usuarios
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//Recebe dado do CPf que vai ser pesquisado pelo usuario
	scanf("%s", cpf);
	//procura do cpf no banco de dados
	FILE *file;
	file = fopen(cpf, "r");// Aabre o arquivo para ser vizualizado o "r" siginifica "read = leitura"
	
	//Validação para saber se existe o Cpf consultado
	if(file == NULL){
		printf("Não foi possivel encontrar o Arquivo, Não foi Localizado...\n");//mensagem caso o cpf nao seja encontrado no sistema
	}
	//Validação 
	printf("\nEssas São as informações do usuario: \n");
	while(fgets(conteudo, 200, file) !=NULL ){
		printf("\t- ");
		printf("%s", conteudo);
		printf("\n");
	}
	system("pause");
}

int deletar(){ //função de deletar usuarios
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); // recebendo o CPF que sera deletado
	scanf("%s", cpf);
	
	remove(cpf);// funçao utilizada para remover o CPF
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usuario não se encontra no sistema.!\n");//validação para descibrir se o CPF se encontra no sistema
		system("pause");
	}
	
	
}


int main (){
	int opcao=0; //Difinindo Variavel
	int laco=1;
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	char senhadigitada[]= "a";
	int comparacao1;
	
	printf("------- Cartório da EBAC -------\n\n");
	printf("Login de Adiministrador\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	comparacao1 = strcmp(senhadigitada, "admin");
	
	if(comparacao1 == 0){
			
		for (laco=1;laco=1;){
		
			system("cls");
		
		
			
			printf("------- Cartório da EBAC -------\n\n"); //Inicio menu
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar Nomes.\n");
			printf("\t2 - Consultar Nomes.\n");
			printf("\t3 - Deletar Nomes.\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Opção: ");// fim menu
			
			scanf("%d", &opcao);//Armazenando escolha do usuario
			
			system("cls"); //responsavel por limpar a tela
			
			switch(opcao){ //inicio da seleção de menu
				case 1:
					registro(); //chamda de função
					break;
				case 2:
					consulta();
					break;
				case 3:
					deletar();
					break;
				case 4:
					printf("Obrigado por utilizar, Até a Proxima!\n\n");
					return 0;
					break;
				default:
					printf("Essa Opção não existe\n");
					system("pause");
					break;
			}//fim da seleção
		}
	}
	else
		printf("Senha Incorreta");
}
