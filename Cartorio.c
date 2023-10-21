#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
//inicio da cria��o de vari�veis/string
char arquivo[40];
char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //refere-se a salvar dentro do string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores dos string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); // cria o arquivo e o "W" significa escrever
    fprintf(file,cpf); // salvo o valor da vari�vel no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // abrindo o arquivo salvo na m�quina e atualiza
    fprintf(file,","); //salva uma informa��o dentro do arquivo
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //solicita ao usu�rio
    scanf("%s", nome); //salva na vari�vel nome
    
    file = fopen(arquivo, "a");  // abrindo o arquivo salvo na m�quina e atualiza
    fprintf(file,nome); //salva uma informa��o dentro do arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //separa por v�rgula
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //solicita ao usu�rio
    scanf("%s", sobrenome); //salva na vari�vel sobrenome
    
    file = fopen(arquivo, "a"); //abrindo o arquivo salvo na m�quina e atualiza
    fprintf(file,sobrenome); //salva uma informa��o dentro do arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //separa por v�rgula
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: "); //solicita ao usu�rio
    scanf("%s", cargo); //salva na vari�vel cargo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo salvo na m�quina e atualiza
    fprintf(file,cargo); //salva uma informa��o dentro do arquivo
    fclose(file); // fecha o arquivo
    
    system("pause");
    
}
  

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //criar arquivo para consultar
	char conteudo[200]; //conte�do do arquivo
	
	printf("Digite o CPF a ser consultado: "); //solicita ao usu�rio
	scanf("%s",cpf); //salva na vari�vel string CPF
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); // abre o arquivo CPF e l�
	
	if(file == NULL) //valida��o compara��o
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //resposta ao usu�rio
	}
     
    while(fgets(conteudo, 200, file) != NULL) // la�o de repeti��o at� trazer as informa��ese se n�o achar � nulo
    {
    	  printf("\n Essas s�o as informa��es do usu�rio: "); //salva o conte�do da vari�vel
    	  printf("%s",conteudo); //salva o conte�do da string
    	  printf("\n\n");
    	  
	}
	
	system("pause");
		
}

int deletar()
{
	char cpf[40]; //criar a variavel string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //solicita informa��o ao usu�rio
	scanf("%s", cpf); // varrer e salvar dentro da string
	
	remove(cpf); //acessa a pasta e deleto o arquivo solicitado
	{
		printf("O usu�rio foi deletado com sucesso!.\n\n"); //resposta ao deletar
	}
	
	
	FILE *file; //consultar, acessar, ler o arquivo
	file = fopen(cpf , "r"); //abre a pasta, procura o arquivo e l�
	
	if(file == NULL) //valida��o da fun��o
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //resposta ao usu�rio
		system("pause");
		
	}
}

int main() //fun��o principal
    {
    int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)	//Entrar no la�o
    {
		
		system("cls"); //limpar a tela
	
     	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem local
    
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu e as ### s�o meramente visual
		printf("Escolha a op��o desejada do menu:\n\n"); //\n\n espa�amento de duas linhas
		printf("\t1 - Registrar nomes\n"); //\t cria o espa�o
		printf("\t2 - Consultar nomes\n"); //\n espa�amento de uma linha
		printf("\t3 - Deletar nomes\n\n"); //\n\n espa�amento de duas linhas
		printf("\t4 - Sair do sitema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio e pausa o programa
	
		system("cls"); //fun�a� limpar a tela
	
	
	switch(opcao) //inicio da sele��o do menu
	{
		case 1:
		registro(); //chamada de fun��es
		break; // encerra a op��o
		
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
		printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
	} //fim da sele��o
	
		
      
    }
}


