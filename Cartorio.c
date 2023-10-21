#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int registro() //Função responsável por cadastrar os usuários no sistema
{
//inicio da criação de variáveis/string
char arquivo[40];
char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //refere-se a salvar dentro do string
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores dos string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); // cria o arquivo e o "W" significa escrever
    fprintf(file,cpf); // salvo o valor da variável no arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // abrindo o arquivo salvo na máquina e atualiza
    fprintf(file,","); //salva uma informação dentro do arquivo
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //solicita ao usuário
    scanf("%s", nome); //salva na variável nome
    
    file = fopen(arquivo, "a");  // abrindo o arquivo salvo na máquina e atualiza
    fprintf(file,nome); //salva uma informação dentro do arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //separa por vírgula
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //solicita ao usuário
    scanf("%s", sobrenome); //salva na variável sobrenome
    
    file = fopen(arquivo, "a"); //abrindo o arquivo salvo na máquina e atualiza
    fprintf(file,sobrenome); //salva uma informação dentro do arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //separa por vírgula
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: "); //solicita ao usuário
    scanf("%s", cargo); //salva na variável cargo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo salvo na máquina e atualiza
    fprintf(file,cargo); //salva uma informação dentro do arquivo
    fclose(file); // fecha o arquivo
    
    system("pause");
    
}
  

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //criar arquivo para consultar
	char conteudo[200]; //conteúdo do arquivo
	
	printf("Digite o CPF a ser consultado: "); //solicita ao usuário
	scanf("%s",cpf); //salva na variável string CPF
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); // abre o arquivo CPF e lê
	
	if(file == NULL) //validação comparação
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //resposta ao usuário
	}
     
    while(fgets(conteudo, 200, file) != NULL) // laço de repetição até trazer as informaçõese se não achar é nulo
    {
    	  printf("\n Essas são as informações do usuário: "); //salva o conteúdo da variável
    	  printf("%s",conteudo); //salva o conteúdo da string
    	  printf("\n\n");
    	  
	}
	
	system("pause");
		
}

int deletar()
{
	char cpf[40]; //criar a variavel string
	
	printf("Digite o CPF do usuário a ser deletado: "); //solicita informação ao usuário
	scanf("%s", cpf); // varrer e salvar dentro da string
	
	remove(cpf); //acessa a pasta e deleto o arquivo solicitado
	{
		printf("O usuário foi deletado com sucesso!.\n\n"); //resposta ao deletar
	}
	
	
	FILE *file; //consultar, acessar, ler o arquivo
	file = fopen(cpf , "r"); //abre a pasta, procura o arquivo e lê
	
	if(file == NULL) //validação da função
	{
		printf("O usuário não se encontra no sistema!.\n"); //resposta ao usuário
		system("pause");
		
	}
}

int main() //função principal
    {
    int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)	//Entrar no laço
    {
		
		system("cls"); //limpar a tela
	
     	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem local
    
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu e as ### são meramente visual
		printf("Escolha a opção desejada do menu:\n\n"); //\n\n espaçamento de duas linhas
		printf("\t1 - Registrar nomes\n"); //\t cria o espaço
		printf("\t2 - Consultar nomes\n"); //\n espaçamento de uma linha
		printf("\t3 - Deletar nomes\n\n"); //\n\n espaçamento de duas linhas
		printf("\t4 - Sair do sitema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário e pausa o programa
	
		system("cls"); //funçaõ limpar a tela
	
	
	switch(opcao) //inicio da seleção do menu
	{
		case 1:
		registro(); //chamada de funções
		break; // encerra a opção
		
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
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
	} //fim da seleção
	
		
      
    }
}


