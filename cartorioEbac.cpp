#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria 
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //bibliocteca de alocao de strings

int registro()
{	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Insira o CPF (apenas numeros): ");
	scanf("%s", cpf); //"%s" refere-se a strings
	
	strcpy(arquivo, cpf);	//responsavel por copiar os valores das strings
	
	FILE *file; //funcao ja definida no programa (chamando o arquivo)
	file = fopen(arquivo, "w"); //cria o arquivo/abre o arquivo / "w" write
	fprintf(file,cpf); //valor da variavel é salvo
	fclose(file); //fechamento do arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "/ ");
	fclose(file);
	
	printf("Insira o primeiro nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "/ ");
	fclose(file);
	
	printf("Insira o sobrenome completo: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "/ ");
	fclose(file);
	
	printf("Insira o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); // "a" atualizacao
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	

}

int consulta()
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
	printf("Registro não localizado.\n");	
	}	
	
	while (fgets(conteudo, 200, file) != NULL);
	{
		printf("Dados do registro: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do registro a ser apagado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" read
	
	if(file == NULL)
	{
		printf("Registro não encontrado.\n");
		system("pause");
	}
	
	
}


int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // responsavel por limpar a tele
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("\tCARTORIO DA EBAC \n\n"); //inicio menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar novo cadastro\n");
		printf("\t2 - Consultar registros\n");
		printf("\t3 - Deletar registro\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("opção: ");	//fim menu
	
		scanf("%d", &opcao);
	
		system("cls");
		
		switch(opcao)
		{
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
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não esta disponivel. Por favor, escolha uma opção válida.\n");
			system("pause");
			break;
				
		}
		
		
	}
	

	//printf("Software desenvolvido por Lucas Galdino\n"); 
}
