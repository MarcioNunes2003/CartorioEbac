#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo, "w" significa escrever
	fprintf(file, cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");// "a" significa adicionar
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Comando para pausar uma tela
}

int consulta() //Comando responsável pela consulta de usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	//Início da criação de Variáveis/Strings
	char cpf[40];
	char conteudo[200];
	//Final da criação de Variáveis/Strings 
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s", cpf); //%s refere-se a string
	
	system("cls"); //Limpar a tela do console
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" significa ler
	
	if(file == NULL ) // "Se o arquivo for igual a nada" printf = mostrar
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
		
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //Comando para percorrer um arquivo de texto linha por linha, lendo e processando o conteúdo de cada linha até o final do arquivo ser alcançado
	{
		printf("Essas são as informações do CPF informado:\n\n  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Comando para pausar uma tela
}

int deletar() //Comando responsável por deletar usuários no sistema
{
	//Início da criação de Variáveis/Strings
	char cpf[40];
	//Final da criação de Variáveis/Strings 
	
	printf("Digite o CPF do usuário a ser deletado:  ");
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" significa ler
	
	remove(cpf); //Comando para remover um arquivo específico
	
	if(file == NULL); // "Se o arquivo for igual a nada" printf = mostrar
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}

int main() //Menu do sistema
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	
		printf("\t### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//Fim do Menu
	
	
		scanf("%d", &opcao); //Armazenando a Escolha do Usuário
	
		system("cls");
		
		
		switch(opcao) //Início da Seleção
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Opção Inválida!\n");
			system("pause");
			break;
		 //Fim da Seleção
		}
}
}

