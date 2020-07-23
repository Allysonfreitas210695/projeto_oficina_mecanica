#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto
{
	int codigoproduto;
	char nomeproduto[50];
	char marca[10];
	float valor;
	int qtd;
};

struct noproduto
{
	struct noproduto* prox;
	produto dado;
};



struct listaproduto
{
	Noproduto* inicio;
};

void menu()
{
	printf("==================================================================\n");
	printf("          ESCOLHA A OPCAO DE OPERACAÇAO\n");
	printf("==================================================================\n");
	printf("1- INSERI CADASTRO NO INICIO DA LISTA\n");
	printf("2- INSERI CADASTRO NO FINAL DA LISTA\n");
	printf("3- MOSTRA LISTA DE PRODUTOS\n");
	printf("4- PESQUISAR POR PRODUTO\n");
	printf("5- SALVA CADASTRO\n");
	printf("6- LER INFORMAÇOES SOBRE PRODUTO SALVO\n");
	printf("7- DELETA LISTA DE PRODUTO\n");
	printf("8- DELETA PRODUTO POR CODIGO\n");
	printf("9- ALTERA DADOS DO PRODUTO\n");
	printf("10- VER TAMANHO DA LISTA DE PRODUTO\n");
	printf("11- CRIAR LISTA DE PRODUTO\n");
	printf("12- ORDENAR LISTA DE PRODUTO\n");
	printf("13- OPERAÇAO COM PRODUTO\n");
	printf("14- SAIR\n");
	printf("================================================================\n");
}

void compra(){
	printf("================================================================\n");
	printf("1- PESQUISAR E CONTINUAR COMPRADO\n");
	printf("2- FINALIZAR E MOSTRA TOTAL\n");
	printf("================================================================\n");
}

void lerproduto(produto *p)
{
	printf("==================================================================\n");
	printf("       INFORME OS DADOS SOBRE O PRODUTO        \n ");
	printf("==================================================================\n");
	printf("DIGITE O CODIGO DO PRODUTO\n");
	scanf("%d",&p->codigoproduto);
	printf("DIGITE O NOME DO PRODUTO\n");
	scanf(" %[^\n]s",p->nomeproduto);
	printf("DIGITE A MARCA DO PRODUTO\n");
	scanf(" %[^\n]s",p->marca);
	printf("DIGITE O VALOR DE PRODUTO\n");
	scanf(" %f", &p->valor);
	printf("DIGITE A QUANTIDADE DE PRODUTOS DISPONIVEIS\n");
	scanf(" %d", &p->qtd);
}

//CADASTRA O PRODUTO NO COMEÇO DA LISTA 
void inseri_produto_inicio(Listaproduto *listaproduto, produto dado)
{
	Noproduto* novo = (Noproduto *) malloc(sizeof(Noproduto));
	novo->dado = dado;
	novo->prox = listaproduto->inicio;
	listaproduto->inicio = novo;
}

//CADASTRA O PRODUTO NO FINAL DA LISTA
void inseri_produto_fim(Listaproduto *listaproduto, produto dado)
{
	Noproduto* novo = (Noproduto *) malloc(sizeof(Noproduto));
	novo->dado = dado;
	novo->prox = NULL;

	if(listaproduto->inicio == NULL)
	{
		listaproduto->inicio = novo;
	}
	else
	{
		Noproduto* pi;
		for(pi = listaproduto->inicio; pi->prox != NULL; pi = pi->prox);
		pi->prox = novo;
	}

}

//MOSTRA A LISTA DO PRODUTOS CADASTRADO
void mostraproduto(Listaproduto *listaproduto)
{
	Noproduto* pi;
	int i = 1;
	for(pi = listaproduto->inicio; pi != NULL; pi = pi->prox)
	{
		printf("============================================================\n");
		printf("DADOS DO PRODUTO %d\n", i);
		printf("============================================================\n");
		printf("CODIGO DO PRODUTO: %d\n", pi->dado.codigoproduto);
		printf("NOME DO PRODUTO: %s\n", pi->dado.nomeproduto);
		printf("VALOR DO PRODUTO: %f\n", pi->dado.valor);
		printf("MARCA DO PRODUTO: %s\n", pi->dado.marca);
		printf("QUANTIDADE CADASTRADA: %d\n", pi->dado.qtd);
		printf("============================================================\n");
	}
}

//REMOVE O FINAL DA LISTA;
void deleta_produto_final(Listaproduto *listaproduto)
{
	if(listaproduto->inicio == NULL)
	{
		printf("PRODUTO NAO ENCONTRADO\n");
	}
	else if(listaproduto->inicio->prox == NULL)
	{
		Noproduto* pi = listaproduto->inicio;
		listaproduto->inicio = NULL;
		free(pi);
	}
	else
	{
		Noproduto* pi;
		Noproduto* pa;
		for(pi = listaproduto->inicio ; pi->prox != NULL ; pi = pi->prox)
		{
			pa = pi;
		}
		pa->prox = NULL;
		free(pi);
	}
}

//REMOVE POR CODIGO DO PRODUTO
void deletaprodutocodigo(Listaproduto *listaproduto, int cod)
{
	if(listaproduto->inicio == NULL)
	{
		printf("LISTA VAZIA\n");
	}
	else if(listaproduto->inicio->dado.codigoproduto == cod)
	{
		Noproduto* pi = listaproduto->inicio;
		listaproduto->inicio = pi->prox;
		free(pi);
	}
	else if(listaproduto->inicio->prox == NULL)
	{
		if(listaproduto->inicio->dado.codigoproduto != cod)
		{
			printf("PRODUTO NAO ENCONTRADO\n");
		}
	}
	else
	{
		Noproduto* pi;
		Noproduto* pa;
		for(pi = listaproduto->inicio; pi->prox != NULL && pi->dado.codigoproduto != cod; pi = pi->prox)
		{
			pa = pi;
		}
		if(pi == NULL)
		{
			printf("NAO FOI ENCONTRADO O PRODUTO\n");
		}
		else
		{
			pa->prox = pi->prox;
		}
		free(pi);
	}
}

//REMOVE A LISTA TODA;
void deletalistaproduto(Listaproduto *listaproduto)
{
	Noproduto* pi;
	while(listaproduto->inicio != NULL)
	{
		pi = listaproduto->inicio;
		listaproduto->inicio = pi->prox;
		free(pi);
	}
}
//PESQUISA PELO PRODUTO USADO O CODIGO;
void pesquisarproduto(Listaproduto *listaproduto, int cod)
{
	Noproduto* pi;
	for(pi = listaproduto->inicio; pi != NULL && pi->dado.codigoproduto != cod; pi = pi->prox);
	if(pi == NULL)
	{
		printf("NENHUM PRODUTO ENCONTRADO\n");
	}
	else
	{
		printf("%s: %.2f\n", pi->dado.nomeproduto, pi->dado.valor);
	}
}

//METADO PARA PEGAR O CODIGO E RETORNA UM VALOR;
Noproduto* alteradadosproduto(Listaproduto *listaproduto, int codigo)
{
	Noproduto* pi;
	for(pi = listaproduto->inicio; pi != NULL && pi->dado.codigoproduto != codigo; pi = pi->prox);
	if(pi == NULL)
	{
		return 0;
	}
	else
	{
		return pi;
	}
}

//MOSTRA O TAMANHO DO ARQUIVO;
void tamanhoarquivoproduto(Listaproduto *listaproduto)
{
	Noproduto* pi = listaproduto->inicio;
	int cont = 0;
	while(pi != NULL)
	{
		cont++;
		pi = pi->prox;
	}
	printf("TOTAL DE PRODUTOS SALVO %d\n", cont);
}

//CERIAR UMA LISTA DE VARIOS ELEMENTOS DE UMA VEZ;
Listaproduto criarlistaproduto(int n)
{
	Listaproduto listaproduto;
	listaproduto.inicio = NULL;
	int i;
	for(i = 0; i < n; i++)
	{
		printf("============================================================\n");
		printf("DADOS SOBRE O PRODUTO %d:\n", i + 1);
		printf("============================================================\n");
		produto f;
		lerproduto(&f);
		inseri_produto_inicio(&listaproduto, f);
		printf("============================================================\n");
	}
	return listaproduto;
}

//ORDENA PARA O MENOR CODIGO DA LISTA;
void ordenarproduto(Listaproduto *listaproduto)
{
	Noproduto* pi;
	Noproduto* pj;
	Noproduto* pfim = NULL;
	if(listaproduto->inicio == NULL)
	{
		return;
	}
	for(pi = listaproduto->inicio; pi->prox != NULL; pi = pi->prox)
	{
		for(pj = listaproduto->inicio; pj->prox != pfim; pj = pj->prox)
		{
			if(pj->dado.codigoproduto > pj->prox->dado.codigoproduto)
			{
				produto temp = pj->dado;
				pj->dado = pj->prox->dado;
				pj->prox->dado = temp;
			}
		}
		pfim = pj;
	}

}

//SALVA AS INFORMAÇOES DO PROGRAMA
void salvalistaproduto(Listaproduto *listaproduto)
{
	FILE *f = fopen("./cadastroproduto.b", "wb");
	Noproduto* pi;
	for(pi = listaproduto->inicio; pi != NULL; pi = pi->prox)
	{
		fwrite(&pi->dado, sizeof(produto), 1, f);
	}
	fclose(f);
}

//LER O ARQUIVO DO MEU DIRETORIO;
Listaproduto lerarquivoproduto()
{

	Listaproduto listaproduto;
	listaproduto.inicio = NULL;
	FILE *f = fopen("./cadastroproduto.b", "rb");
	produto ff;
	while(fread(&ff, sizeof(produto), 1, f))
	{
		inseri_produto_fim(&listaproduto, ff);
	}
	fclose(f);
	return listaproduto;
}

//PESQUISA PELO CODIGO E RETORNA;
Noproduto* produtocompra(Listaproduto *listaproduto, int cod){
	Noproduto* pi = listaproduto->inicio;
	while(pi != NULL && pi->dado.codigoproduto != cod )
	{
		pi = pi->prox;
	}
	if(pi == NULL){
		return NULL;
	}
	else{
		return pi;
	}
}

void main_produto()
{
	Listaproduto listaproduto;
	listaproduto.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 14)
	{
		switch (op)
		{

		case 1:
		{
			produto f;
			lerproduto(&f);
			inseri_produto_inicio(&listaproduto, f);
			break;
		}
		case 2:
		{
			produto f;
			lerproduto(&f);
			inseri_produto_fim(&listaproduto, f);
			break;
		}
		case 3:
		{
			mostraproduto(&listaproduto);
			break;
		}
		case 4:
		{
			int cod;
			printf("INFORME O CODIGO DO FUNCIONARIO\n");
			scanf("%d", &cod);
			pesquisarproduto(&listaproduto, cod);
			break;
		}
		case 5:
		{
			salvalistaproduto(&listaproduto);
			break;
		}
		case 6:
		{
			listaproduto = lerarquivoproduto();
			break;
		}
		case 7:
		{
			deletalistaproduto(&listaproduto);
			break;
		}
		case 8:
		{
			int cod;
			printf("INFORME O CODIGO DO FUNCIONARIO\n");
			scanf("%d", &cod);
			deletaprodutocodigo(&listaproduto, cod);
			break;
		}
		case 9:
		{
			int codfuncionario;
			printf("INFORME O CODIGO DO FUNCIONARIO\n");
			scanf("%d", &codfuncionario);

			Noproduto* pi = alteradadosproduto(&listaproduto, codfuncionario);
			if(pi == 0)
			{
				printf("NAO EXISTE ESSE produto COM ESSE CODIGO\n");
			}
			else
			{
				int op;
				printf("DIGITE 1 PARA NOME , 2 PARA PREÇO E 3 PARA ALTERA PREÇO DO PRODUTO\n");
				scanf("%d", &op);
				if(op == 1)
				{
					char nomeproduto[45];
					printf("DIGITE O NOME QUE QUER FAZER A MUDANÇA: \n");
					scanf(" %[^\n]s", nomeproduto);
					strcpy(pi->dado.nomeproduto, nomeproduto);
					printf("O NOME DO PRODUTO FOI ALTERADO PARA %s\n", pi->dado.nomeproduto);
				}
				else if(op == 2)
				{
					char marcacorrigir[45];
					printf("DIGITE O NOME CERTO DA MARCA\n");
					scanf(" %[^\n]s", marcacorrigir);
					strcpy(pi->dado.marca, marcacorrigir);
					printf("O NOME DA MARCA CORRIGIDA É %s\n", pi->dado.marca);
				}
				else
				{
					float novopreco;
					printf("DIGITE O NOVO PREÇO DO PRODUTO\n");
					scanf("%f", &novopreco);
					pi->dado.valor = novopreco;
					printf(" NOVO VALOR %.0f", pi->dado.valor);
				}

			}
			break;
		}
		case 10:
		{
			tamanhoarquivoproduto(&listaproduto);
			break;
		}
		case 11:
		{
			int n;
			printf("DIGITE O NUMERO DO TAMANHO DA LISTA QUE VOCE DESEJA CRIAR\n");
			scanf("%d", &n);
			listaproduto = criarlistaproduto(n);
			break;
		}
		case 12:
		{
			ordenarproduto(&listaproduto);
			break;
		}
        case 13:
		{
			int op;
			float soma = 0;
			compra();
			scanf("%d",&op);
			while(op != 2)
			{
				
				if(op == 1){
					int codigop;
					printf("DIGITE O CODIGO DO PRODUTO\n");
					scanf("%d",&codigop);
					Noproduto* pi = produtocompra(&listaproduto,codigop);
					if(pi == NULL){
						printf("PRODUTO NAO ESTA NA LISTA\n");
					}
					else{
						int qtd;
						printf("DIGITE A QUANTIDADE DE PEDIDOS\n");
						scanf("%d",&qtd);
						
						//INFORMA A CLIENTE QUAL VALOR DO PRODUTO;
						printf("%s: %.2f\n",pi->dado.nomeproduto,pi->dado.valor);
						
						//OPERACAO;
						soma += pi->dado.valor * qtd;
						
						//IMPRIMIR A QUANTIDADE PEDIDA E VALOR DESSE PEDIDO;
						printf("%s: QUANTIDADE %d TOTAL DE R$ %.2f\n",
						pi->dado.nomeproduto,qtd,soma);
						
						//DIMINUIR A QUANTIDADE DE ITENS;
						pi->dado.qtd = pi->dado.qtd - qtd;
					
						if(pi->dado.qtd == 0)
							printf("ACABOU O ESTOQUE\n");
						else
							printf("A QUANTIDADE AGORA DISPONIVEL É %d\n",pi->dado.qtd);	
						
					}
				}
				
				compra();
				scanf("%d",&op);
			}
			printf("========================================================\n");
			printf("                  COMPRA FINALIZADA                     \n");
			printf("========================================================\n");
			printf("VALOR DA COMPRA: %.2f\n",soma);
			printf("========================================================\n");
			break;
		}
		default:

			printf("NO MOMENTO NÃO TRABALHAMOS COM ESSA OPÇÃO\n");
			break;
		}

		system("pause");
		system("cls");
		menu();
		scanf("%d", &op);
	}

}


