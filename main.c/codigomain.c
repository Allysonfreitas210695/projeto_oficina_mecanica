#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcionario/funcionario.h"
#include "cliente/cliente.h"
#include "produto/produto.h"
#include "sobreoficina/sobreoficina.h"

/*

   DISCIPLINA - ALGORITMO E ESTRUTURA DE DADOS 1;
   PROFESSOR - REUDISMAM ROLIN;
   UFERSA - CAMPUS PAU DOS FERROS;
   DISCENTE - ALLYSON BRUNO DE FREITAS FERNANDES;
   PERIODO 2020.3;

*/
/*============PROJETO OFICINA MECANICA=============*/

void bemvindo()
{
	printf("=================================================================\n");
	printf("\t                   SEJA BEM-VINDO                           \t\n");
	printf("\n");
	printf("=================================================================\n");
	printf("\t                   A OFICINA GURGEL                          \t\n");
	printf("\t      SUA PRESENÇA É ESSENCIAL PARA NOSSO CRESCIMENTO      \t\n");
	printf("=================================================================\n");
	printf("\n");
}

void cadastrosenha()
{
	printf("=================================================================\n");
	printf("                     CADASTRO DE SENHA                            \n");
	printf("=================================================================\n");
}

void loginparateracesso()
{
	printf("=================================================================\n");
	printf("                    LOGIN DE SENHA                            \n");
	printf("=================================================================\n");
}

void login()
{

	cadastrosenha();
	int criasenha, loginsenha;
	printf("CADASTRE SEU SENHA NUMERICA!!\n");
	scanf("%d", &criasenha);

	loginparateracesso();
	printf("DIGITE A SENHA QUE VOCÊ CADASTRO!!\n");
	scanf("%d", &loginsenha);

	while(loginsenha != criasenha)
	{
		printf("============================================================\n");
		printf("ACESSO NEGADO, DIGITE A SENHA DE NOVO!!\n");
		scanf("%d", &loginsenha);
		system("cls");
	}

	printf("================================================================\n");
	printf("                  ACESSO PERMITIDO                              \n");
	printf("================================================================\n");
	system("pause");
	system("cls");

}

void menuoficina()
{
	printf("=================================================================\n");
	printf("\t               ESCOLHA A OPCAO DESEJA   \t\n");
	printf("=================================================================\n");
	printf("\t 1- CADASTRA FUNCIONARIO\t\n");
	printf("\t 2- CADASTRA CLIENTE\t\n");
	printf("\t 3- CADASTRA PRODUTOS\t\n");
	printf("\t 4- INFORMAÇOES SOBRE A OFICINA\t\n");
	printf("\t 5- SAIR\t\n");
	printf("===============================================================\n");
}

int main(void)
{
	setlocale(LC_ALL, "portuguese");;
	login();
	bemvindo();

	int op;
	menuoficina();
	scanf("%d", &op);

	while(op != 5)
	{
		switch (op)
		{
		case 1:
		{
			main_funcionario();
			break;
		}

		case 2:
		{
			maincliente();
			break;
		}

		case 3:
		{
			main_produto();
			break;
		}
		case 4:
		{
			main_proprietario();
			break;
		}
		default:
		{
			printf("NO MOMENTO NÃO TRABALHAMOS COM ESSA OPÇÃO\n");
			break;
		}

		}

		system("pause");
		system("cls");
		menuoficina();
		scanf("%d", &op);
	}

	return 0;
}




