#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio de criação de variaveis/stings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final de criação de variaveis/stings	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexação para gravação
	fprintf(file,", "); //Inclusão de texto foi colocado " , "
	fclose (file); //fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",nome); //%s refere-se as strings
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexação para gravação
	fprintf(file,nome);  //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexação para gravação
	fprintf(file,", "); //Inclusão de texto foi colocado " , "
	fclose (file); //fecho o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando Informação do usuário
	scanf("%s",sobrenome); //%s refere-se as strings
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexação para gravação
	fprintf(file,sobrenome);  //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexação para gravação
	fprintf(file,", "); //Inclusão de texto foi colocado " , "
	fclose (file); //fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando Informação do usuário
	scanf("%s",cargo); //%s refere-se as strings
	
	file = fopen(arquivo, "a"); //Abre o arquivo de texto no modo de anexação para gravação
	fprintf(file,cargo);  //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	system("pause"); //Pausa arquivo para leitura do usuário
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio de criação de variaveis/stings
	char cpf[40];
	char conteudo[200];
	//Final de criação de variaveis/stings
	
	printf("Digite o CPF a ser consutado: "); //Coletando informação do usuário para consulta
	scanf("%s",cpf); //%s refere-se as strings
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo leitura e gravação. O arquivo deve existir.
	
	//Texto para informar ao usário que nao existe o arquivo "== NULL" nao existe.
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	//Leitura dos dados da string difente de "NULL" "while" laço de repeticão 
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //Leitura da string armazendada em file
		printf("\n\n"); // Espaçamento de linha para melhor estética 
	}
	
	system("pause"); //Pausa arquivo para leitura do usuário
	
}

int deletar()
{
	//Inicio de criação de variaveis/stings
	char cpf[40];
	//Final de criação de variaveis/stings
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); //%s refere-se as strings
	
	remove(cpf); //Deleta o arquivo que esta salvo com o nome do numero do CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo leitura e gravação. O arquivo deve existir.
	
	//Texto para informar ao usário que nao existe o arquivo "== NULL" nao existe.
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause"); //Pausa arquivo para leitura do usuário
	}
}

int main() // local de início "int" referente a numeros inteiros
{
	int opcao=0; //Definindo as variaveis
	int laco=1; //Laço de repetição dado a numeros inteiros
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //Responsavel por limpar a tela
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   	
    	printf("*** Cartório da EBAC ***\n\n"); //Inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sitema \n\n"); 
    	printf("Opção: "); //Fim do menu
     	
        scanf("%d", &opcao); //Armazenando a escolha do usuário
 	
    	system("cls"); //Responsavel por limpar a tela
   	   
   	    switch(opcao) //Inicio da seleção do menu
		{
		   case 1:
		   registro(); //Chamada de funções
		   break; //Forçar a saída de um laço de repetição "Quebra"
		   
		   case 2:
		   consulta(); //Chamada de funções
		   break; //Forçar a saída de um laço de repetição "Quebra"
		   
		   case 3:
		   deletar(); //Chamada de funções
		   break; //Forçar a saída de um laço de repetição "Quebra"
		   
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
		   
		   default:
		   printf("Essa opção nao está disponivel!\n");
		   system("pause"); //Pausa arquivo para leitura do usuário
		   break;//Forçar a saída de um laço de repetição "Quebra"
		   	
		}//Fim da seleção	   
	} 
}
