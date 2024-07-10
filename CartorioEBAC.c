#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio de cria��o de variaveis/stings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final de cria��o de variaveis/stings	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexa��o para grava��o
	fprintf(file,", "); //Inclus�o de texto foi colocado " , "
	fclose (file); //fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se as strings
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexa��o para grava��o
	fprintf(file,nome);  //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexa��o para grava��o
	fprintf(file,", "); //Inclus�o de texto foi colocado " , "
	fclose (file); //fecho o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando Informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se as strings
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexa��o para grava��o
	fprintf(file,sobrenome);  //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexa��o para grava��o
	fprintf(file,", "); //Inclus�o de texto foi colocado " , "
	fclose (file); //fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando Informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se as strings
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexa��o para grava��o
	fprintf(file,cargo);  //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	system("pause"); //Pausa arquivo para leitura do usu�rio
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio de cria��o de variaveis/stings
	char cpf[40];
	char conteudo[200];
	//Final de cria��o de variaveis/stings
	
	printf("Digite o CPF a ser consutado: "); //Coletando informa��o do usu�rio para consulta
	scanf("%s",cpf); //%s refere-se as strings
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo leitura e grava��o. O arquivo deve existir.
	
	//Texto para informar ao us�rio que nao existe o arquivo "== NULL" nao existe.
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	//Leitura dos dados da string difente de "NULL" "while" la�o de repetic�o 
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //Leitura da string armazendada em file
		printf("\n\n"); // Espa�amento de linha para melhor est�tica 
	}
	
	system("pause"); //Pausa arquivo para leitura do usu�rio
	
}

int deletar()
{
	//Inicio de cria��o de variaveis/stings
	char cpf[40];
	//Final de cria��o de variaveis/stings
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); //%s refere-se as strings
	
	remove(cpf); //Deleta o arquivo que esta salvo com o nome do numero do CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo leitura e grava��o. O arquivo deve existir.
	
	//Texto para informar ao us�rio que nao existe o arquivo "== NULL" nao existe.
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause"); //Pausa arquivo para leitura do usu�rio
	}
}

int main() // local de in�cio "int" referente a numeros inteiros
{
	int opcao=0; //Definindo as variaveis
	int laco=1; //La�o de repeti��o dado a numeros inteiros
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //Responsavel por limpar a tela
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   	
    	printf("*** Cart�rio da EBAC ***\n\n"); //Inicio do menu
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sitema \n\n"); 
    	printf("Op��o: "); //Fim do menu
     	
        scanf("%d", &opcao); //Armazenando a escolha do usu�rio
 	
    	system("cls"); //Responsavel por limpar a tela
   	   
   	    switch(opcao) //Inicio da sele��o do menu
		{
		   case 1:
		   registro(); //Chamada de fun��es
		   break; //For�ar a sa�da de um la�o de repeti��o "Quebra"
		   
		   case 2:
		   consulta(); //Chamada de fun��es
		   break; //For�ar a sa�da de um la�o de repeti��o "Quebra"
		   
		   case 3:
		   deletar(); //Chamada de fun��es
		   break; //For�ar a sa�da de um la�o de repeti��o "Quebra"
		   
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
		   
		   default:
		   printf("Essa op��o nao est� disponivel!\n");
		   system("pause"); //Pausa arquivo para leitura do usu�rio
		   break;//For�ar a sa�da de um la�o de repeti��o "Quebra"
		   	
		}//Fim da sele��o	   
	} 
}
