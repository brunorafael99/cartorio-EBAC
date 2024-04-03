#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() // Função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuario
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo e o "a" siginifica atualizar
	fprintf(file, ",");//Adicionando uma "," entre as variaveis
	fclose(file);//Fechando arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coletando informação do usuario
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Abrindo arquivo e o "a" significa atualizar
	fprintf(file,nome);//Salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abrindo arquivo e o "a" significa atualizar
	fprintf(file, ",");//adicionando uma "," entre as variaveis
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo variavei
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		
	setlocale(LC_ALL,"portuguese");//Definindo linguagem
	
		printf("###Cartório da EBAC###\n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Delatar nomes\n");//Fim do menu
		printf("\t4 - Sair do sistema!\n\n");
		printf("Opção: ");
	
		scanf("%d",&opcao); //Armszenando a escolha do usuário
	
		system("cls");//responsavel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();	
			break;
			
			case 3:
			deletar();
			break;

			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return o;
			break;
			
			default:
			printf("Essa opção não esta disponivel\n");
			system("pause");
			break;
		} //fim da seleção
		
		
	
}
}



