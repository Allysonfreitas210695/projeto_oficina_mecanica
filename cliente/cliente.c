#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

struct Cliente
{
	int codigo;
	char nomecliente[45];
	char email[30];
	char telefone[15];
} ;

struct  nocliente
{
	cliente dadocliente;
	struct nocliente* prox;
};

struct  listacliente
{
	Nocliente* inicio;
};

void menualteradados()
{
	printf("=================================================================\n");
	printf("\t    ESCOLHA UMA OPCAO PARA ALTERA DADO DESEJADO        \t\n");
	printf("=================================================================\n");
	printf("\t 1- ALTERA NOME DO CLIENTE \t\n");
	printf("\t 2- ALTERA EMAIL DO CLIENTE \t\n");
	printf("\t 3- ALTERA CONTATO DO CLIENTE \t\n");
	printf("=================================================================\n");
}

void menucliente()
{
	printf("=================================================================\n");
	printf("\t    ESCOLHA A OPÇAO A SEGUIR REFERENTE AO CLIENTE \t\n");
	printf("=================================================================\n");
	printf("\t 1- CADASTRA NO INICIO DA LISTA \t\n");
	printf("\t 2- CADASTRA CLIENTE NO FIM DA LISTA \t\n");
	printf("\t 3- MOSTRA LISTA \t\n");
	printf("\t 4- PESQUISAR CLIENTE \t\n");
	printf("\t 5- SALVA LISTA \t\n");
	printf("\t 6- LER ARQUIVO\t\n");
	printf("\t 7- REMOVE LISTA \t\n");
	printf("\t 8- REMOVE POR CODIGO DO CLIENTE \t\n");
	printf("\t 9- ALTERA DADOS DO CLIENTE \t\n");
	printf("\t 10- TAMANHO DO ARQUIVO CLIENTE \t\n");
	printf("\t 11- CRIAR LISTA CLIENTE \t\n");
	printf("\t 12- ORDENAR LISTA CLIENTE\t\n");
	printf("\t 13- SAIR \t\n");
	printf("=================================================================\n");
}

//LER E ARMAZENA INFORMAÇÕES SOBRE CLIENTE
void lercliente(cliente *c)
{
	printf("================================================================\n");
	printf("        DIGITE A INFORMAÇOES AQUI REFERENTE AO CLIENTE          \n");
	printf("================================================================\n");
	printf("CODIGO DO CLIENTE:\n");
	scanf("%d", &c->codigo);
	printf("DIGITE O NOME DO CLIENTE:\n");
	scanf(" %[^\n]s", c->nomecliente);
	printf("DIGITE O EMAIL DO CLIENTE:\n");
	scanf(" %[^\n]s", c->email);
	printf("DIGITE O TELEFONE DO CLIENTE\n");
	scanf(" %[^\n]s", c->telefone);
	printf("================================================================\n");
}

//MOSTRA OS CLIENTES CADASTRADO NA LISTA;
void mostralista(Listacliente *listacliente)
{
	if(listacliente->inicio == NULL){
		printf("LISTA VAZIA!!\n");
	}
	//PONTEIRO AUXILIAR QUE PERCORRE A LISTA;
	Nocliente* pi = listacliente->inicio;
	while(pi != NULL)
	{
		printf("============================================================\n");
		printf("CODIGO DO CLIENTE: %d\n", pi->dadocliente.codigo);
		printf("NOME DO CLIENTE: %s\n", pi->dadocliente.nomecliente);
		printf("EMAIL DO CLIENTE: %s\n", pi->dadocliente.email);
		printf("TELEFONE DO CLIENTE: %s\n", pi->dadocliente.telefone);
		printf("=============================================================\n");
		//VAI PARA PROXIMA POSIÇÃO DA LISTA;
		pi = pi->prox;
	}

}

//COLOCAR OS CLIENTE NO INICIO DA LISTA
void inseri_cliente_inicio(Listacliente *listacliente, cliente dadocliente)
{
	Nocliente* novo = (Nocliente*) malloc(sizeof(Nocliente));
	novo->dadocliente = dadocliente;
	novo->prox = listacliente->inicio;
	listacliente->inicio = novo;
}

//COLOCAR NO FINAL DA LISTA SO CLIENTES;
void inseri_cliente_fim(Listacliente *listacliente, cliente dadocliente)
{
	Nocliente* novo = (Nocliente*) malloc(sizeof(Nocliente));
	novo->dadocliente = dadocliente;
	novo->prox = NULL;
	//OLHAR SE A PRIMEIRA POSICAO DA LISTA É NULA, SE FOR COLOCA NO INICIO DA LISTA;
	if(listacliente->inicio == NULL)
	{
		listacliente->inicio = novo;
	}
	else
	{
		//PERCORRER A LISTA ATE ACHA A ULTIMA POSICAO QUE SERA NULL PARA PI COLOCA NOVO DADO;
		Nocliente* pi;
		for(pi = listacliente->inicio ; pi->prox != NULL; pi = pi->prox);
		pi->prox = novo;
	}
}

//PESQUISAR O CODIGO DO CLIENTE E ENVIA INFORMAÇÃO
void pesquisarcliente(Listacliente *listacliente, int codigo)
{
	//PONTEIRO AUXILIAR PEGA O INICIO DA LISTA;
	Nocliente* pi = listacliente->inicio;
	//ENQUANTO O AUXILIAR NAO SEJA NULA E O CODIGO NAO SEJA IGUAL NÃO SAIR DO LAÇO;
	while(pi != NULL && pi->dadocliente.codigo != codigo)
	{
		pi = pi->prox;
	}
	//PI FOR NULO, OU SEJA, OLHOU A LISTA TODA E NAO ENTROU O CODIGO PASSADO;
	if(pi == NULL)
	{
		printf("NAO FOI ENCONTRADO O CLIENTE COM ESSE CODIGO\n");
	}
	//CASO ACHE O CODIGO PASSADO IMPRIMIR AS INFORMAÇOES;
	else
	{
		printf("============================================================\n");
		printf("CODIGO DO CLIENTE: %d\n", pi->dadocliente.codigo);
		printf("NOME DO CLIENTE: %s\n", pi->dadocliente.nomecliente);
		printf("EMAIL DO CLIENTE: %s\n", pi->dadocliente.email);
		printf("TELEFONE DO CLIENTE: %s\n", pi->dadocliente.telefone);
		printf("============================================================\n");
		pi = pi->prox;
	}
}

//APAGA AS INFORMAÇOES DA LISTA;
void removelistacliente(Listacliente *listacliente)
{
	//VERIFICA SE ESTA VAZIA A LISTA;
	if(listacliente->inicio == NULL)
	{
		printf("LISTA VAZIA\n");
	}
	//SE NÃO FAZ UM PONTEIRO PARA LIBERA OS ELEMENTOS;
	Nocliente* pi;
	while(listacliente->inicio != NULL)
	{   
		//PONTEIRO PEGA O PRIMEIRO ELEMENTO DA LISTA;
		pi = listacliente->inicio;
		//O INICIO DA LISTA, APONTA PARA PROXIMO ELEMENTO DA LISTA;
		listacliente->inicio = pi->prox;
		//LIBERA A POSIÇAO;
		free(pi);
	}
}

//RECEBE UM  CODIGO DO CLIENTE PARA APAGAR A INFORMAÇAO REFERENTE AO CLIENTE INFORMADO;
void removeporcodigo(Listacliente *listacliente, int codigo)
{
	//OLHA SE A LISTA TA VAZIA;
	if(listacliente->inicio == NULL)
	{
		printf("LISTA VAZIA\n");
	}
	//OLHA SE A PRIMEIRA POSIÇAO DO ALUNO É IGUAL AO CODIGO PASSADO;
	else if(listacliente->inicio->dadocliente.codigo == codigo)
	{
		Nocliente* pi = listacliente->inicio;
		listacliente->inicio = pi->prox;
		free(pi);
	}
	//OLHAR SE TEM SÓ UMA POSIÇAO E SE PROXIMO É NULL, SE FOR ENTRA NA PROXIMA CODIÇAO;
	else if(listacliente->inicio->prox == NULL){
		//SE A PRIMEIRA POSIÇAO FOR DIFERENTE DO CODIGO PASSADO ELE IMPRIMI EMBAIXO
		  if(listacliente->inicio->dadocliente.codigo != codigo){
			  printf("CLIENTE NAO PODE SER REMOVIDO CODIGO DIFERENTE\n");
		  }
	}
	else
	{
		//AUXILIAR PARA PERCORRE A LISTA;
		Nocliente* pi;
		//AUXILIAR PARA PEGAR O ANTERIOR DO PI;
		Nocliente* pa = NULL;
		for(pi = listacliente->inicio; pi->prox != NULL && pi->dadocliente.codigo != codigo; pi = pi->prox)
		{
			pa = pi;
		}
		//SE O PI CHEGAR AO FINAL DA ISTA E NAO ENCONTRA NADA;
		if(pi == NULL)
		{
			printf("O CODIGO DO CLIENTE NAO FOI ENCONTRADO\n");
		}
		//SENÃO PA QUE É O ANTEIRO, PEGA O PI QUE APONTA PARA PROXIMO ELEMENTO DE PI;
		else
		{
			pa->prox = pi->prox;
		}
	}
}

//METADO QUE PEGA O CODIGO DO CLIENTE;
Nocliente* alteracliente(Listacliente *listacliente, int codigo)
{
	Nocliente* pi ;
	for(pi = listacliente->inicio; pi != NULL && pi->dadocliente.codigo != codigo; pi = pi->prox);
	if(pi == NULL)
		return NULL;
	else
		return pi;
}

//VER O TAMANHO DO ARQUIVO AQUI;
void tamanhoarquivocliente(Listacliente *listacliente)
{
	Nocliente* pi = listacliente->inicio;
	int cont = 0;
	while(pi != NULL)
	{
		cont++;
		pi = pi->prox;
	}
	printf("TAMANHO DO ARQUIVO %d\n", cont);
}

//CRIAR A LISTA DE CLIENTE COM MUITOS ELEMENTOS;
Listacliente criarlistacliente(int n){
	Listacliente listacliente;
	listacliente.inicio = NULL;
	int i;
	for(i = 0; i < n; i++){
		cliente c;
		lercliente(&c);
		inseri_cliente_fim(&listacliente,c);
	}
	return listacliente;
}

//ORDENA A LISTA PELO CODIGO DO CLIENTE
void ordenarlistacliente(Listacliente *listacliente){
	Nocliente* pi;
	Nocliente* pj;
	Nocliente* pfim = NULL;
	//SE A LISTA NAO TIVE NADA ELE RETORNA PARA TELA
	if(listacliente->inicio == NULL){
		return;
	}
	else{
	for(pi = listacliente->inicio; pi->prox != NULL; pi = pi->prox){
		for(pj = listacliente->inicio; pj->prox != pfim; pj = pj->prox){
			//SE O DADO PRIMEIRO FOR MAIOR QUE O PROXIMO DADO ENTRA NA CONDIÇAO;
			if(pj->dadocliente.codigo > pj->prox->dadocliente.codigo){
				
				//AQUI FAZ A TROCA
				cliente temp = pj->dadocliente;
				pj->dadocliente = pj->prox->dadocliente;
				pj->prox->dadocliente = temp;
				
			}
		}
		pfim = pj;
	}
	
	}
}

//SALVA EM UM ARQUIVO;
void salvacliente(Listacliente *listacliente)
{
	//ABRINDO O ARQUIVO;
	FILE *fcliente = fopen("./cadastrocliente.b", "ab");
	if(listacliente->inicio == NULL)
	{
		printf("LISTA VAZIA\n");
	}
	else
	{
		Nocliente* pi = listacliente->inicio;
		while(pi != NULL)
		{
			//GUARDA AS INFORMAÇOES DO CLIENTE  NO ARQUIVO CRIADO EM CIMA;
			fwrite(&pi->dadocliente, sizeof(cliente), 1, fcliente);
			
			pi = pi->prox;

		}
	}
	//FECHAR O ARQUIVO;
	fclose(fcliente);
}

Listacliente lerarquivocliente()
{
	//ABRE PARA LEITURA O ARQUIVO;
	FILE *fcliente = fopen("./cadastrocliente.b", "rb");
	Listacliente listacliente;
	listacliente.inicio = NULL;
	cliente c;
	//ENQUANTO NAO CHEGAR NO FIM NAO SAI;
	while(fread(&c, sizeof(cliente), 1, fcliente))
	{
		inseri_cliente_fim(&listacliente, c);
	}
	//FECHAR O ARQUIVO;
	fclose(fcliente);
	//RETORNA LISTA COM AS INFORMAÇOES;
	return listacliente;
}

void maincliente()
{
	Listacliente listacliente;
	listacliente.inicio = NULL;
	int opcliente;
	menucliente();
	scanf("%d", &opcliente);
	while(opcliente != 13)
	{
		switch(opcliente){
		
		case 1:
		{
			cliente c;
			lercliente(&c);
			inseri_cliente_inicio(&listacliente, c);
			break;
		}
		case 2:
		{
			cliente c;
			lercliente(&c);
			inseri_cliente_fim(&listacliente, c);
			break;
		}
		case 3:
		{
			mostralista(&listacliente);
			break;
		}
		case 4:
		{
			int codigocliente;
			printf("INFORME O CODIGO DO CLIENTE\n");
			scanf("%d", &codigocliente);
			pesquisarcliente(&listacliente, codigocliente);
			break;
		}
		case 5:
		{
			salvacliente(&listacliente);
			break;
		}
		case 6:
		{
			listacliente = lerarquivocliente();
			break;
		}
		case 7:
		{
			removelistacliente(&listacliente);
			break;
		}
		case 8:
		{
			int codigocliente;
			printf("DIGITE O CODIGO DO CLIENTE\n");
			scanf("%d", &codigocliente);
			removeporcodigo(&listacliente, codigocliente);
			break;
		}
		case 9:
		{
			int codigocliente;
			printf("INFORME O CODIGO DO CLIENTE\n");
			scanf("%d", &codigocliente);
			Nocliente* pi = alteracliente(&listacliente, codigocliente);
			if(pi == NULL)
			{
				printf("CODIGO NAO ENCONTRADO DO CLIENTE\n");
			}
			else
			{
				int op;
				menualteradados();
				scanf("%d", &op);
				if(op == 1)
				{
					char nomenovo[39];
					printf("DIGITE O NOME QUE VOCE DESEJA ALTERA\n");
					scanf(" %[^\n]s", nomenovo);
					strcpy(pi->dadocliente.nomecliente, nomenovo);
				}
				if(op == 2)
				{
					printf("DIGITE O NOVO EMAIL QUE VOCE DESEJA ALTERA");
					char novoemail[39];
					printf("DIGITE O NOME QUE VOCE DESEJA ALTERA\n");
					scanf(" %[^\n]s", novoemail);
					strcpy(pi->dadocliente.email, novoemail);
				}
				if(op == 3)
				{
					printf("DIGITE O NOVO CONTATO DO TELEFONE\n");
					char novotelefone[15];
					scanf(" %[^\n]s", novotelefone);
					strcpy(pi->dadocliente.telefone, novotelefone);
				}
			}
            break;
		}
		case 10:
		{
			tamanhoarquivocliente(&listacliente);
			break;
		}
		case 11:
		{   
			int n;
			printf("INFORME A QUANTIDADE DE ELEMENTOS QUE DESEJA CADASTRA NA LISTA\n");
			scanf("%d",&n);
			listacliente = criarlistacliente(n);
			break;
		}
		case 12:
		{
			 ordenarlistacliente(&listacliente);
			break;
		}
		}
		system("pause");
		system("cls");
		menucliente();
		scanf("%d", &opcliente);
	}

}
