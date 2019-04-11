#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <locale.h>

//	Aluno: Thiago Alves | Engenharia de Software
//	Faculdade uniamérica - Turma 2019/2023
// 	Versão Windows

////// CONFIGURAÇÕES DA LISTA //////////
#define SIZE 100 //determina quantas linhas terá nossa lista.

char nome[SIZE][50];
char email[SIZE][50];
char cpf[SIZE][50];
//////////////////////////////////////

int opcao; //guardas as decisões do usuário durante a execução do programa
char cpfPesquisa[12]; //auxilia na validaçao de CPF;
char emailPesquisa[50]; //auxilia na validação de E-mail;
int id;	// busca dados por linha exata.
int apagado = 0; //reseta a variável "linha" na função cadastro caso a função reset for chamada.

void cadastro();
void alterar_cadastro();
void pesquisa();
void lista();
void reset();

void header();//guarda todos os cabeçalhos

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
	
	if(apagado == 1){ //reseta a linha caso o reset aconteça.
		linha = 0;
		apagado = 0;
	}

	do{
		header(2); //chama a id do cabeçalho

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

		printf("\n[1]Novo Cadastro\n[?]Voltar\n");  //opções para sair do loop
		printf("Escolha a opção: ");
		scanf("%d", &opcao);
		fflush(stdin);

		linha++;
	} while(opcao == 1);

	opcao = 0; //importante resetar antes de retornar ao menú.
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
			case 1: //caso a opção 1 for selecionada executa esse bloco.
				header(31);	//chama um cabeçalho na função header.			
				printf("\nDigite o CPF: ");
				gets(cpfPesquisa);

				for(i = 0; i < SIZE; i++){
					if(strcmp(cpf[i], cpfPesquisa) == 0){
						printf("\n-------------------------------\n"); //Aparece caso o cpf consultado.
						printf(" CPF ENCONTRADO!");						//estiver cadastrado na lista.
						printf("\n-------------------------------\n\n");
						printf("nome: %s\nEmail: %s\nCPF: %s\n\n", nome[i], email[i], cpf[i]);
						system("pause");
						break;
					}else if(strcmp(cpf[i], cpfPesquisa) == 1){ //mensagem de tentantiva sem sucesso 1.
						printf("\n-------------------------------\n"); //teoricamente essa mensagem deverá
						printf(" CPF não encontrado!");					//aparecer quando o cpf consultado.
						printf("\n-------------------------------\n\n");//não estiver na lista de cadastrados.
						system("pause");
						break;
					}else{ 
						printf("\n-------------------------------\n"); //mensagem de tentantiva sem sucesso 1.
						printf(" Nenhum dado cadastrado!");				//teoricamente essa mensagem deverá
						printf("\n-------------------------------\n\n");//aparecer quando a nossa lista
						system("pause");								//estiver vazia.
						break;
					}
				}
				break;

			case 2:
				header(32);
				printf("\nDigite o Email: ");	//realiza o mesmo que o case 1 porém com E-mail.
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

			default: //termina o loop e retorna ao menu do programa
				opcao=0; 
				header(3);
				break;
		}

		if(opcao != 0){ //teoricamente essa opção deverá aparecer
			opcao=0;	//apenas quando houver pelo menos 1 pesquisa.
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
		//junção da função pesquisa e cadastro com adicional de busca por ID.
		int i;				//essa função deveria ser mais curta e limpa.
		int achou = 0; //irá nos ajudar a modificar uma linha já preenchida.

		header(4);

		printf("[1] Pesquisar por CPF\n");	//detalhes do funcionamento na função pesquisa.
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
						achou = 1; //muda o status de achou para verdadeiro.
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
						achou = 1; //muda o status de achou para verdadeiro.
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
					achou = 1; //muda o status de achou para verdadeiro.
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
		//se achou é verdadeiro então executa o bloco abaixo.
		if(achou){
			char novo[50];
			printf("\n--QUAL OPÇÃO DESEJA ATUALIZAR---\n\n");
			printf("[1]Nome\n[2]Email\n[3]CPF\n[?]Voltar\n\n");
			printf("Escolha a opção: ");
			scanf("%d", &opcao);
			
			switch(opcao){ 
				case 1: //altera o nome
					fflush(stdin);
					printf("\nDigite o novo nome: ");
					gets(novo);
					strcpy(nome[i], novo);//copia o nome da var "novo" para o "nome" da linha "[i]".
					system("cls");
					printf("-------------------------------\n");
					printf(" Nome alterado para %s.\n", nome[i]);
					printf("-------------------------------\n\n");
					printf("\nnome: %s\nEmail: %s\nCPF: %lld\n\n", nome[i], email[i], cpf[i]);
					system("pause");
					break;

				case 2: //altera o email
					fflush(stdin);  
					printf("\nDigite o novo email: ");
					scanf("%s", &novo);
					strcpy(email[i], novo); //copia o email da var "novo" para o "email" da linha "[i]".
					system("cls");
					printf("-------------------------------\n");
					printf(" Email alterado para %s.\n", email[i]);
					printf("-------------------------------\n\n");
					printf("\nnome: %s\nEmail: %s\nCPF: %lld\n", nome[i], email[i], cpf[i]);
					system("pause");
					break;

				case 3:  //altera o CPF
					fflush(stdin);
					printf("\nDigite o novo CPF: ");
					gets(novo);
					strcpy(cpf[i], novo); //copia o cpf da var "novo" para o "cpf" da linha "[i]".
					system("cls");
					printf("-------------------------------\n");
					printf(" CPF alterado para %s.\n", cpf[i]);
					printf("-------------------------------\n\n");
					printf("\nnome: %s\nEmail: %s\nCPF: %lld\n", nome[i], email[i], cpf[i]);
					system("pause");
					break;

				/*case 4: //Quando utilizada exclui um cadastro inteiro guardado em uma ID pesquisada.
					for(int n = 0; n < 50; n++){ 
						nome[i][n] = 0;			  |Porém os dados foram programados para gravar
						email[i][n] = 0;		  |em sequencia, linha por linha. Se apagar uma 
						cpf[i][n] = 0;			  |informação de uma posição de linha, essa
					}							  |posição de linha será inutilizada...
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
		if(strlen(cpf[i]) > 0){//soluciona o problema de aparecer listagem nula na tela.
			printf("\n-------------------------------");
			printf("\nID: %d", i);
			printf("\nnome: %s\nEmail: %s\nCPF: %s", nome[i], email[i], cpf[i]);
			printf("\n-------------------------------\n");
			achou = 1; //auxilia na tomada de decisão das próximas condições
		}
	}
	if (achou != 1){//se for diferente de 1 ou seja, (achou = 0), então executa esse bloco.
		printf("\n-------------------------------\n");
		printf(" Nenhum dado cadastrado!");
		printf("\n-------------------------------\n\n");
	}

	else if(achou == 1){ //mas se achou for igual à 1, então esse bloco é executado
		opcao = 0;
		printf("\nDeseja exportar para um arquivo?\n"); //pergunta padrão para exportar aquivo.
		printf("\t[1]sim [?]não\n");
		printf("\nEscolha a opção: ");
		scanf("%d", &opcao);
		fflush(stdin);

		if(opcao == 1){ //se a resposta foi sim (1), será executado esse bloco
			FILE *gravar = fopen("cadastro.txt", "w"); //cria um arquivo com nome cadastro

			for(int l = 0; l < SIZE; l++){  //realiza o loop para preencher automaticamente
											//a lista de pessoas cadastradas
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

		  	fclose(gravar); //fecha o arquivo em segurança.
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
	//zera todos valores em cada linha e em cada coluna.
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
	apagado = 1; //informa que aconteceu um reset para a função "cadastro()" resetar a "linha".
	printf("\n-------------------------------\n");
	printf(" Todos os dados foram apagados!");
	printf("\n-------------------------------\n");
	system("pause");
}

void header(int id){
	//função em desenvolvimento, substitui todos os cabeçalhos para acabar com linhas.
	//de códigos repetidas.
	opcao = 0;
	system("cls");//limpa a tela.
	fflush(stdin);//limpa o buffer do teclado.

	switch(id){//id dos cabeçalhos
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