#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel pelo gerenciamento das strings

int main()
{
	int opcao=0; //definindo as variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
			
		printf("--- Cartório da EBAC ---\n\n"); //inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n"); // o comando \t = espaçamento
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do programa\n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d" , &opcao); //armazenando a escolha do usuario
		
		system("cls"); //limpar a tela
		
		switch(opcao) //tela de seleção do menu
		{
			case 1:
				registrar();
				break;
			case 2:
				consultar();
				break;
			case 3:
				deletar();
				break;
			case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
			default:
				printf("Essa opção não existe.\n");
				system("pause");
				break;
		}	
	}
	
}

int registrar() //inicio do registro
{
	char arquivo[40]; //criação das string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	strcpy (arquivo, cpf); // Responsavel por copiar os valores das strings, x = y
	
	FILE *file; // Cria um arquivo
	file = fopen(arquivo, "w"); //abre um arquivo
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file - fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file - fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
		
	file - fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf (file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar() //inicio da consulta de usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //inicio da exclusão de usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}
	
	remove(cpf); //excluir
	
	if(file != NULL)
	{
		printf("Usuário deletado com sucesso.\n");
		system("pause");
	}
}

