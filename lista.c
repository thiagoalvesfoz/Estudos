#include <stdio.h>
#include <stdlib.h>//necessário para system("cls");
#include <string.h>//necessário para função strcmp ()
//#include <locale.h>

#define SIZE 100

char nome[SIZE][50];
char email[SIZE][50];
char cpf[SIZE][50];

int opcao; //para guardas as opções
char cpfPesquisa[12];
char emailPesquisa[50]; //Email com 50 colunas
int id;
int apagado = 0;

void cadastro();
void alterar_cadastro();
void pesquisa();
void lista();
void reset();

void header();

int main () {
	//setlocale(LC_ALL,"portuguese");
	
	do{
		
		header(1);

		printf("[1]Novo Cadastro\n");
		printf("[2]Atualizar Cadastro\n");
		printf("[3]Pesquisar\n");
		printf("[4]Listar todos\n");
		printf("[5]Apagar tudo\n");
		printf("[6]sair\n");
		printf("Escolha a opção: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				opcao = 0;
				cadastro();
				break;
			case 2:
				opcao = 0;
				alterar_cadastro();
				break;
			case 3:
				opcao = 0;
				pesquisa();
				break;
			case 4:
				opcao = 0;
				lista();
				break;
			case 5:
				opcao = 0;
				reset();
				break;
			case 6:
				system("cls");
				system("exit");
				break;
			default:
				fflush(stdin);
				printf("Opção inválida, tente novamente...\n");
				system("pause");
				break;
		}

	} while(opcao != 6);
}

void cadastro(){ // início da função cadastro

	static int linha; //importante para navegar nas linhas
	
	if(apagado == 1){
		linha = 0;
		apagado = 0;
	}

	do{
		header(2);

		printf("\nDigite o nome: "); //Cadastra o nome
		gets(nome[linha]); 

		printf("Digite o email: ");
		fflush(stdin);
		scanf("%s", &email[linha]); //Cadastra o email

		printf("Digite o CPF: ");
		fflush(stdin);
		gets(cpf[linha]); //Cadastra o CPF

		printf("\n--------------------------------\n");
		printf(" Cadastro realizado com sucesso!"); //mensagem de confirmação
		printf("\n--------------------------------\n");

		printf("\n[1]Novo Cadastro\n[?]Voltar\n");  //opção para novo cadastro ou voltar a tela inicial
		printf("Escolha a opção: ");
		scanf("%d", &opcao);
		fflush(stdin);

		linha++;
	} while(opcao == 1);

	opcao = 0; //Retorna o vlr = 0 para reutilizar no menu principal.
} // fim da função cadastro

void pesquisa(){ // início da função pesquisa
	
	int i;
	do{
		header(3);
		printf("\n[1] Pesquisar por CPF");
		printf("\n[2] Pesquisar por Email");
		printf("\n[?] Voltar\n");
		printf("\nEscolha a opção: ");
		scanf("%d", &opcao);
		fflush(stdin);
		
		switch(opcao){
			case 1:
				header(31);				
				printf("\nDigite o CPF: ");
				gets(cpfPesquisa);

				for(i = 0; i < SIZE; i++){
					if(strcmp(cpf[i], cpfPesquisa) == 0){
						printf("\n-------------------------------\n");
						printf(" CPF ENCONTRADO!");
						printf("\n-------------------------------\n\n");
						printf("nome: %s\nEmail: %s\nCPF: %s\n\n", nome[i], email[i], cpf[i]);
						system("pause");
						break;
					}else if(strcmp(cpf[i], cpfPesquisa) == 1){
						printf("\n-------------------------------\n");
						printf(" CPF não encontrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}else{
						printf("\n-------------------------------\n");
						printf(" Nenhum dado cadastrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}
				}
				break;

			case 2:
				header(32);
				printf("\nDigite o Email: ");
				scanf("%s", &emailPesquisa);

				for(i = 0; i < SIZE; i++){
					if(strcmp(email[i], emailPesquisa) == 0){
						printf("\n-------------------------------\n");
						printf(" Email encontrado!");
						printf("\n-------------------------------\n\n");
						printf("nome: %s\nEmail: %s\nCPF: %s\n\n", nome[i], email[i], cpf[i]);
						system("pause");
						break;
					}
					else if(strcmp(email[i], emailPesquisa) == 1){
						printf("\n-------------------------------\n");
						printf(" Email não encontrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}
					else{
						printf("\n-------------------------------\n");
						printf(" Nenhum dado cadastrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}
				}
				break;

			default:
				opcao=0;
				header(3);
				break;
		}

		if(opcao != 0){
			opcao=0;
			header(3);
			printf("\n[1]Nova pesquisa\n[?]Menu\n");
			printf("Escolha a opção: ");
			scanf("%d", &opcao);
			fflush(stdin);
		}

	} while(opcao == 1);
	opcao = 0;
} // fim da função pesquisa

void alterar_cadastro(){

	do{
		int i;
		int achou = 0;

		header(4);

		printf("[1] Pesquisar por CPF\n");
		printf("[2] Pesquisar por email\n");
		printf("[3] Pesquisar por ID\n");
		printf("[?] Voltar\n");
		printf("\nEscolha a opção: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				header(31);
				printf("\nDigite o CPF: ");
				gets(cpfPesquisa);
				
				for (i = 0; i < SIZE; i++){
					if(strcmp(cpf[i], cpfPesquisa) == 0){
						printf("\n-------------------------------\n");
						printf(" CPF ENCONTRADO!");
						printf("\n-------------------------------\n\n");
						printf("nome: %s\nEmail: %s\nCPF: %s\n\n", nome[i], email[i], cpf[i]);
						system("pause");
						achou = 1;
						break;
					}

					else if (strcmp(cpf[i], cpfPesquisa) == 1){
						printf("\n-------------------------------\n");
						printf(" CPF não encontrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}

					else {
						printf("\n-------------------------------\n");
						printf(" Nenhum dado cadastrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}
				}
				break;

			case 2:
				header(32);
				printf("\nDigite o email: ");
				scanf("%s", &emailPesquisa);

				for(i = 0; i < SIZE; i++){
					if(strcmp(email[i], emailPesquisa) == 0){
						printf("\n-------------------------------\n");
						printf(" Email encontrado!");
						printf("\n-------------------------------\n\n");
						printf("nome: %s\nEmail: %s\nCPF: %s\n\n", nome[i], email[i], cpf[i]);
						system("pause");
						achou = 1;
						break;
					}

					else if(strcmp(email[i], emailPesquisa) == 1){
						printf("\n-------------------------------\n");
						printf(" Email não encontrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}

					else{
						printf("\n-------------------------------\n");
						printf(" Nenhum dado cadastrado!");
						printf("\n-------------------------------\n\n");
						system("pause");
						break;
					}
				}
				break;

			case 3:
				header(33);
				printf("\nDigite sua ID: ");
				scanf("%d", &i);
			
				if(strlen(cpf[i]) > 0){
					printf("\nnome: %s\nEmail: %s\nCPF: %s\n\n", nome[i], email[i], cpf[i]);
					system("pause");			
					achou = 1;
					break;
				}
				
				
				else if (achou != 1){
				printf("\n-------------------------------\n");
				printf(" Nenhum dado cadastrado!");
				printf("\n-------------------------------\n\n");
				system("pause");
				break;
				}

			default:
				opcao = 0;
				header(4);
				break;
		}

		if(achou){
			char novo[50];
			printf("\n--QUAL OPÇÃO DESEJA ATUALIZAR---\n\n");
			printf("[1]Nome\n[2]Email\n[3]CPF\n[?]Voltar\n\n");
			printf("Escolha a opção: ");
			scanf("%d", &opcao);
			
			switch(opcao){
				case 1:
					fflush(stdin);
					printf("\nDigite o novo nome: ");
					gets(novo);
					strcpy(nome[i], novo);
					system("cls");
					printf("-------------------------------\n");
					printf(" Nome alterado para %s.\n", nome[i]);
					printf("-------------------------------\n\n");
					printf("\nnome: %s\nEmail: %s\nCPF: %lld\n\n", nome[i], email[i], cpf[i]);
					system("pause");
					break;

				case 2:
					fflush(stdin);
					printf("\nDigite o novo email: ");
					scanf("%s", &novo);
					strcpy(email[i], novo);
					system("cls");
					printf("-------------------------------\n");
					printf(" Email alterado para %s.\n", email[i]);
					printf("-------------------------------\n\n");
					printf("\nnome: %s\nEmail: %s\nCPF: %lld\n", nome[i], email[i], cpf[i]);
					system("pause");
					break;

				case 3:
					fflush(stdin);
					printf("\nDigite o novo CPF: ");
					gets(novo);
					strcpy(cpf[i], novo);
					system("cls");
					printf("-------------------------------\n");
					printf(" CPF alterado para %s.\n", cpf[i]);
					printf("-------------------------------\n\n");
					printf("\nnome: %s\nEmail: %s\nCPF: %lld\n", nome[i], email[i], cpf[i]);
					system("pause");
					break;

				/*case 4:
					for(int n = 0; n < 50; n++){ 	
						nome[i][n] = 0;				|Os dados são gravados em sequencia, linha por linha.
						email[i][n] = 0;			|Se apagar uma informação de uma posição de memoria.
						cpf[i][n] = 0;				|Essa posição será inutilizada...
					}
					break;*/
				default:
					header(4);
					break;
			}
		}

		if(opcao != 0){			
			printf("\n[1] Nova atualização\n[?] Menu\n");
			printf("\nEscolha a opção: ");
			scanf("%d", &opcao);
			fflush(stdin);
		}

	} while (opcao == 1);
	opcao = 0;
}

void lista(){ // início da função lista
	int i;
	system("cls");
	printf("--- LISTAR TODOS ---\n");
	int achou = 0;
	for (i = 0; i<SIZE; i++){
		if(strlen(cpf[i]) > 0){//soluciona o problema de listagem nula.
			printf("\n-------------------------------");
			printf("\nID: %d", i);
			printf("\nnome: %s\nEmail: %s\nCPF: %s", nome[i], email[i], cpf[i]);
			printf("\n-------------------------------\n");
			achou = 1;
		}
	}
	if (achou != 1){
		printf("\n-------------------------------\n");
		printf(" Nenhum dado cadastrado!");
		printf("\n-------------------------------\n\n");
	}

	if(achou == 1){
		opcao = 0;
		printf("\nDeseja exportar para um arquivo?\n");
		printf("\t[1]sim [?]não\n");
		printf("\nEscolha a opção: ");
		scanf("%d", &opcao);
		fflush(stdin);

		if(opcao == 1){
			FILE *gravar = fopen("cadastro.txt", "w");

			for(int l = 0; l < SIZE; l++){
					
				if (strlen(cpf[l]) > 0){  
					fprintf(gravar, "\t----------\n");
				  	fprintf(gravar, "Nome: %s\n", nome[l]);
				  	fprintf(gravar, "Email: %s\n", email[l]);
				  	fprintf(gravar, "CPF: %s\n", cpf[l]);
		  		}

		  		else {
		  			break;
		  		}
		  	}

		  	fclose(gravar);
		  	system("cls");
		  	printf("\n-------------------------------\n");
		 	printf(" Exportação feita com sucesso!");
		 	printf("\n-------------------------------\n");
		 	printf("\nPara acessar o arquivo, vá ao diretório do programa instalado.\n");
		}

		else {
			system("cls");
			printf("\n-------------------------------\n");
			printf(" Lista não exportada!");
			printf("\n-------------------------------\n");
			printf("Os dados cadastrados poderão ser perdidos!!!\n");
		}
	}

	opcao = 0; //se por acaso o usuário pressionar 6, isso evita fechar o programa ao voltar ao menu,
	printf("\n");
	system("pause");
}
// fim da função lista

void reset(){
	for(int m = 0; m < SIZE; m++){
		for(int n = 0; n < 50; n++){
			if(SIZE != 0){
				nome [m][n] = 0;
				email [m][n] = 0;
				cpf[m][n] = 0;
			}
			break;
		}
	}
	apagado = 1;
	printf("\n-------------------------------\n");
	printf(" Todos os dados foram apagados!");
	printf("\n-------------------------------\n");
	system("pause");
}

void header(int x){

	opcao = 0;
	system("cls");
	fflush(stdin);

	switch(x){
		case 1:	
			printf("\n-------- Menu --------\n");
			break;
		case 2:
			printf("\n\t--- NOVO CADASTRO ---\n");
			break;
		case 3:
			printf("\n\t--- PESQUISAR ---\n");
			break;
		case 31:
			printf("\n\t--- PESQUISAR POR CPF ---\n");
			break;
		case 32:
			printf("\n\t--- PESQUISAR POR EMAIL---\n");	
			break;
		case 33:
			printf("\n\t--- PESQUISAR POR ID ---\n");
			break;
		case 4:
			printf("\n\t--- ATUALIZAR DADOS CADASTRAIS ---\n\n");
		default:
			break;
	}
}