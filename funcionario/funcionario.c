#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

struct Funcionario
{
	int cod;
	char nome[50];
	float salario;
	int diastrabalhado[6];
};

struct no
{
	struct no* prox;
	funcionario dado;

};

struct lista
{
	No* inicio;
};

void menufuncionario()
{
	printf("================================================================\n");
	printf("\t   ESCOLHA A OPÇAO REFERENTE AO FUNCIONARIO               \t\n");
	printf("================================================================\n");
	printf("\t1- INSERI NO INICIO\t\n");
	printf("\t2- INSERI NO FINAL\t\n");
	printf("\t3- MOSTRA LISTA FUNCIONARIO\t\n");
	printf("\t4- PESQUISAR FUNCIONARIO\t\n");
	printf("\t5- SALVA LISTA\t\n");
	printf("\t6- LER LISTA DO FUNCIONARIO\t\n");
	printf("\t7- DELETA LISTA\t\n");
	printf("\t8- DELETA POR CODIGO\t\n");
	printf("\t9- ALTERA DADOS DO FUNCIONARIO\t\n");
	printf("\t10- TAMANHO DO ARQUIVO FUNCIONARIO\t\n");
	printf("\t11- CRIAR LISTA\t\n");
	printf("\t12- ORDENAR LISTA\t\n");
	printf("\t13- OPERACAO\t\n");
	printf("\t14- SAIR\t\n");
	printf("================================================================\n");
}

void menualteradadosfuncionario()
{
	printf("================================================================\n");
	printf("\t   ALTERA DADOS FUNCIONARIO                        \t\n");
	printf("================================================================\n");
	printf("\t1- ALTERA NOME FUNCIONARIO\t\n");
	printf("\t2- ALTERA TELEFONE\t\n");
	printf("================================================================\n");
}

void menuoperacao()
{
	printf("================================================================\n");
	printf("\t1- AUMENTA O SALARIO DO FUNCIONARIO\t\n");
	printf("\t2- DIAS TRABALHADO\t\n");
	printf("\t3- PESQUISAR O DIA TRABALHADO\t\n");
	printf("\t4- VALOR POR DIA TRABALHADO\t\n");
	printf("\t5- SAIR\t\n");
	printf("================================================================\n");
}

void mestrabalhado(){
	printf("================================================================\n");
	printf("                       DIAS DO MÊS                              \n");
	printf("================================================================\n");
	printf("1- MÊS DE 31 DIAS\n");
	printf("2- MÊS DE 30 DIAS\n");
	printf("3- MÊS DE 28 DIAS\n");
	printf("================================================================\n");
}

void diasemana(){
	printf("================================================================\n");
	printf("                       DIAS DA SEMANA                           \n");
	printf("================================================================\n");
	printf("0- SEGUNDA\n");
	printf("1- TERÇA\n");
	printf("2- QUARTA\n");
	printf("3- QUINTA\n");
	printf("4- SEXTA\n");
	printf("5- SABADO\n");
	printf("================================================================\n");
}

//LER E ARMAZENA INFORMACOES;
void lerfuncionario(funcionario *f)
{

	printf("DIGITE O CODIGO DO FUNCIONARIO\n");
	scanf("%d", &f->cod);
	printf("DIGITE O NOME DO FUNCIONARIO\n");
	scanf(" %[^\n]s", f->nome);
	printf("DIGITE O SALARIO DO FUNCIONARIO\n");
	scanf(" %f", &f->salario);

	printf("================================================================\n");
	printf("DIGITE 1 PARA DIAS TRABALHADO E 0 PARA DIAS NAO TRABALADO\n");
	printf("================================================================\n");
	printf("SEGUNDA-FEIRA: \n");
	scanf("%d", &f->diastrabalhado[0]);
	printf("TERÇA-FEIRA: \n");
	scanf("%d", &f->diastrabalhado[1]);
	printf("QUARTA-FEIRA: \n");
	scanf("%d", &f->diastrabalhado[2]);
	printf("QUINTA-FEIRA: \n");
	scanf("%d", &f->diastrabalhado[3]);
	printf("SEXTA-FEIRA: \n");
	scanf("%d", &f->diastrabalhado[4]);
	printf("SABADO: \n");
	scanf("%d", &f->diastrabalhado[5]);

}
//COLOCAR AS INFORMAÇOES NO INICIO DA LISTA;
void inseri_inicio(Lista *lista, funcionario dado)
{
	No* novo = (No *) malloc(sizeof(No));
	//NOVO NO RECEBE O DADO DO FUNCIONARIO PASSADO POR PARAMETRO;
	novo->dado = dado;
	//O PROXIMO ELEMETO TA LISTA RECEBE O PRIMEIRO DADO DA LISTA;
	novo->prox = lista->inicio;
	//E O INICIO DA LISTA, AGORA RECEBE O NOVO DADO;
	lista->inicio = novo;
}
//COLOCAR AS INFORMAÇOES NO FIM DA LISTA;
void inseri_fim(Lista *lista, funcionario dado)
{
	No* novo = (No *) malloc(sizeof(No));
	novo->dado = dado;
	novo->prox = NULL;
    //OLHAR SE A PRIMEIRA POSICAO DA LISTA É NULA, SE FOR COLOCA NO INICIO DA LISTA;
	if(lista->inicio == NULL)
	{
		lista->inicio = novo;
	}
	else
	{
		
		No* pi;
		//PERCORRER A LISTA ATE ACHA A ULTIMA POSICAO QUE SERA NULL PARA PI COLOCA NOVO DADO;
		for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox);
		pi->prox = novo;
	}

}
//MOSTRA A INFORMAÇOES DA LISTA;
void mostra(Lista *lista)
{
	//PONTEIRO AUXILIAR;
	No* pi;
	//CORRE ATE QUANDO LISTA  FOR IGUAL A NULL E IMPRIMI AS INFORMAÇOES NELA;
	for(pi = lista->inicio; pi != NULL; pi = pi->prox)
	{
    printf("================================================================\n");
    printf("              DADOS DO FUNCIONARIO PESQUISADO                   \n");
    printf("================================================================\n");
    printf("CODIGO DO FUNCIONARIO: %d\n",pi->dado.cod);
	printf("NOME DO FUNCIONARIO: %s\n",pi->dado.nome);
	printf("SALARIO DO FUNCIONARIO: %.2f\n",pi->dado.salario);
	printf("SEGUNDA: %d\n",pi->dado.diastrabalhado[0]);
	printf("TERÇA: %d\n",pi->dado.diastrabalhado[1]);
	printf("QUARTA: %d\n",pi->dado.diastrabalhado[2]);
	printf("QUINTA: %d\n",pi->dado.diastrabalhado[3]);
	printf("SEXTA: %d\n",pi->dado.diastrabalhado[4]);
	printf("SABADO: %d\n",pi->dado.diastrabalhado[5]);
	printf("================================================================\n");
	}
	
}


//DELETA O FUNCIONRIO PELO CODIGO ;
void deletacodigo(Lista *lista, int cod)
{
	//OLHA SE A LISTA TA VAZIA;
	if(lista->inicio == NULL)
	{
		printf("lista vazia\n");
	}
	//OLHA SE A PRIMEIRA POSIÇAO DO ALUNO É IGUAL AO CODIGO PASSADO;
	else if(lista->inicio->dado.cod == cod)
	{
		No* pi = lista->inicio;
		lista->inicio = pi->prox;
		free(pi);
	}
     //OLHAR SE TEM SÓ UMA POSIÇAO E SE PROXIMO É NULL, SE FOR ENTRA NA PROXIMA CODIÇAO;
	else if(lista->inicio->prox == NULL)
	{
		//SE A PRIMEIRA POSIÇAO FOR DIFERENTE DO CODIGO PASSADO ELE IMPRIMI EMBAIXO
		if(lista->inicio->dado.cod != cod)
		{
			printf("FUNCIONARIO NÃO ENCONTRADO\n");
		}
	}
	else
	{
		//AUXILIAR PARA PERCORRE A LISTA;
		No* pi;
		//AUXILIAR PARA PEGAR O ANTERIOR DO PI;
		No* pa;
		for(pi = lista->inicio; pi->prox != NULL && pi->dado.cod != cod; pi = pi->prox)
		{
			pa = pi;
		}
		//SE O PI CHEGAR AO FINAL DA ISTA E NAO ENCONTRA NADA;
		if(pi == NULL)
		{
			printf("NÃO FOI ENCONTRADO O CODIGO DO FUNCIONARIO\n");
		}
        //SENÃO PA QUE É O ANTEIRO, PEGA O PI QUE APONTA PARA PROXIMO ELEMENTO DE PI;
		else
		{
			pa->prox = pi->prox;
		}
		free(pi);
	}
}
//DELETA A LISTA DO FUNCIONARIO;
void deletalista(Lista *lista)
{
	//VERIFICA SE ESTA VAZIA A LISTA;
	if(lista->inicio == NULL){
		printf("LISTA VAZIA!!");
	}
	//SE NÃO FAZ UM PONTEIRO PARA LIBERA OS ELEMENTOS;
	No* pi;
	while(lista->inicio != NULL)
	{
		//PONTEIRO PEGA O PRIMEIRO ELEMENTO DA LISTA;
		pi = lista->inicio;
		//O INICIO DA LISTA, APONTA PARA PROXIMO ELEMENTO DA LISTA;
		lista->inicio = pi->prox;
		//LIBERA A POSIÇAO;
		free(pi);
	}
}
//BUSCA O FUNCIONARIO PELO CODIGO;
void pesquisar(Lista lista, int cod)
{
	//PONTEIRO AUXILIAR PARA PERCORRER A LISTA;
	No* pi;
	for(pi = lista.inicio; pi != NULL && pi->dado.cod != cod; pi = pi->prox);
	//SE CHEGAR AO FINAL DA LISTA NAO ENCONTRA O CODIGO;
	if(pi == NULL)
	{
		printf("NENHUM FUNCIONARIO FOI ENCONTRADO\n");
	}
	//SENAO É PORQUE ACHOU O CODIGO
	else
	{
		printf("CODIGO: %d\n", pi->dado.cod);
		printf("NOME DO FNCIONÁRIO: %s\n", pi->dado.nome);
		printf("SALARIO: %.0f\n", pi->dado.salario);
		printf("DIAS TRABALHADO\n");
		printf("SEGUNDA: %d\n", pi->dado.diastrabalhado[0]);
		printf("TERÇA: %d\n", pi->dado.diastrabalhado[1]);
		printf("QUARTA: %d\n", pi->dado.diastrabalhado[2]);
		printf("QUINTA: %d\n", pi->dado.diastrabalhado[3]);
		printf("SEXTA: %d\n", pi->dado.diastrabalhado[4]);
		printf("SABADO: %d\n", pi->dado.diastrabalhado[5]);
	}
}

//RETORNA O CODIGO DO FUNCIONARIO;
No* alteradados(Lista *lista, int codigo)
{
	No* pi;
	for(pi = lista->inicio; pi != NULL && pi->dado.cod != codigo; pi = pi->prox);
	if(pi == NULL)
	{
		return 0;
	}
	else
	{
		return pi;
	}
}

//VER TAMANHO DOS DADOS CADASTRADO FUNCIONARIO;
void tamanhoarquivo(Lista *lista)
{
	No* pi = lista->inicio;
	int cont = 0;
	while(pi != NULL)
	{
		cont++;
		pi = pi->prox;
	}
	printf("TAMANHO DO ARQUIVO: %d\n", cont);
}

//CRIAR LISTA SEM SER DE UM E UM;
Lista criarlista(int n)
{
	Lista lista;
	lista.inicio = NULL;
	int i;
	for(i = 0; i < n; i++)
	{
		printf("=====================================\n");
		printf("DADOS SOBRE O FUNCIONARIO %d:\n", i + 1);
		printf("=====================================\n");
		funcionario f;
		lerfuncionario(&f);
		inseri_fim(&lista, f);
		printf("======================================\n");
	}
	return lista;
}



//ORDENAR LISTA FUNCIONARIO;
void ordenar(Lista *lista)
{
	No* pi;
	No* pj;
	No* pfim = NULL;
	if(lista->inicio == NULL)
	{
		return;
	}
	for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox)
	{
		for(pj = lista->inicio; pj->prox != pfim; pj = pj->prox)
		{
			//SE O DADO PRIMEIRO FOR MAIOR QUE O PROXIMO DADO ENTRA NA CONDIÇAO;
			if(pj->dado.cod > pj->prox->dado.cod)
			{
				//AQUI FAZ A TROCA;
				funcionario temp = pj->dado;
				pj->dado = pj->prox->dado;
				pj->prox->dado = temp;
			}
		}
		pfim = pj;
	}

}
//SALVA LISTA DE FUNCIONARIO;
void salvalista(Lista lista)
{
	//ABRE ARQUIVO NO DIRETORIO;
	FILE *f = fopen("./cadastrofuncionario.b", "wb");
	No* pi;
	for(pi = lista.inicio; pi != NULL; pi = pi->prox)
	{
		//GUARDA AS INFORMAÇOES DO FUNCIONARIO  NO ARQUIVO CRIADO EM CIMA;
		fwrite(&pi->dado, sizeof(funcionario), 1, f);
	}
	//FECHA ARQUIVO;
	fclose(f);
}
//LER ARQUIVO DE FUNCIONARIO
Lista lerarquivo()
{
	//TERMOS QUE DA UM NOME A LISTA;
	Lista lista;
	//INICIA ELA COM NULL;
	lista.inicio = NULL;
	FILE *f = fopen("./cadastrofuncionario.b", "rb");
	funcionario ff;
	while(fread(&ff, sizeof(funcionario), 1, f))
	{
		inseri_fim(&lista, ff);
	}
	//FECHA ARQUIVO;
	fclose(f);
	//RETORNA LISTA COM ELEMENTO PEGO DO ARQUIVO;
	return lista;
}

//DIARIA DO FUNCIONARIO;
void valorpordiaria(funcionario *f){
	int i, cont = 0;
	for(i = 0; i < 6; i++)
	{
		if(f->diastrabalhado[i] > 0)
		{
			cont++;
		}
	}
	if(cont == 0){
		printf("FUNCIONARIO NAO TRABALHOU EM NUNHUM DIA\n");
	}
	else{
		int mes;
		mestrabalhado();
		scanf("%d",&mes);
		if(mes == 1){
			int n;
			printf("DIGITE QUANTOS DOMINGOS NAO FORAM TRABALHADO\n");
			scanf("%d",&n);
			float valordiaria = f->salario/(31 - n);
			float semanal = valordiaria * cont;
			printf("DIAS TRABALHADO: %d\n",cont);
			printf("VALOR DA DIARIA %.2f\n",valordiaria);
			printf("VALOR SEMANAL: %.2f\n",semanal);
		}
		if(mes == 2){
			int n;
			printf("DIGITE QUANTOS DOMINGOS NAO FORAM TRABALHADO\n");
			scanf("%d",&n);
			float valordiaria = f->salario/(30 - n);
			float semanal = valordiaria * cont;
			printf("DIAS TRABALHADO: %d\n",cont);
			printf("VALOR DA DIARIA %.2f\n",valordiaria);
			printf("VALOR SEMANAL: %.2f\n",semanal);
		}
		if(mes == 3){
			int n;
			printf("DIGITE QUANTOS DOMINGOS NAO FORAM TRABALHADO COMO MES É DE 28 DIAS INFORME O TOTAL DE DOMINGOS\n");
			scanf("%d",&n);
			float valordiaria = f->salario/(28 - n);
			float semanal = valordiaria * cont;
			printf("DIAS TRABALHADO: %d\n",cont);
			printf("VALOR DA DIARIA %.2f\n",valordiaria);
			printf("VALOR SEMANAL: %.2f\n",semanal);
		}
	}
	
}

//OPERACAO PARA VER SE O FUNCIONARIO TRABALHOU!!
void diatrabalhado(funcionario *f,int dia){
	
	int i;
	int cont = 0;
	
	for(i = 0; i < 6; i++)
	{
		if(f->diastrabalhado[dia] > 0)
		{
		    cont++;
		}
		else{
			cont = 0;
		}
	}
	
	if(cont != 0){
		printf("DIA TRABALHANDO\n");
	}
	else{
		printf("DIA NAO TRABALHADO\n");
	}

}

//OLHA QUANTOS DIAS FORAM TRABALHANDO PELO FUNCIONARIO;
void totaldiastrabalhado(funcionario *f)
{
	int i, cont = 0;
	for(i = 0; i < 6; i++)
	{
		if(f->diastrabalhado[i] > 0)
		{
			cont++;
		}
	}
    printf("TOTAL DE DIAS TRABALHADO %d\n",cont);
	
}

//AQUI RECEBE O DADO DO FUNCIONARIO ENVIADO POR PARAMETRO;
void aumento_salario(funcionario *f)
{

	int porcetagem;

	if(f->salario >= 0 && f->salario <= 400)
	{
		porcetagem = 15;
	}
	else if(f->salario > 400 && f->salario <= 500)
	{
		porcetagem = 13;
	}
	else if(f->salario > 600 && f->salario <= 700)
	{
		porcetagem = 10;
	}
	else if(f->salario > 700 && f->salario <= 800)
	{
		porcetagem = 7;
	}
	else
	{
		porcetagem = 5;
	}
	
	//OPERACAO DE AUMENTO DO SALARIO AQUI
	f->salario = f->salario + (f->salario * porcetagem)/100;
	printf("SALARIO NOVO %.2f\n",f->salario );
}


void main_funcionario()
{
	Lista lista;
	lista.inicio = NULL;
	int op;
	menufuncionario();
	scanf("%d", &op);
	while(op != 14)
	{
		switch(op)
		{

		case 1:
		{
			funcionario f;
			lerfuncionario(&f);
			inseri_inicio(&lista, f);
			break;
		}
		case 2:
		{
			funcionario f;
			lerfuncionario(&f);
			inseri_fim(&lista, f);
			break;
		}
		case 3:
		{
			mostra(&lista);
			break;
		}
		case 4:
		{
			int cod;
			printf("INFORME O CODIGO DO FUNCIONARIO\n");
			scanf("%d", &cod);
			pesquisar(lista, cod);
			break;
		}
		case 5:
		{
			salvalista(lista);
			break;
		}
		case 6:
		{
			lista = lerarquivo();
			break;
		}
		case 7:
		{
			deletalista(&lista);
			break;
		}
		case 8:
		{
			int cod;
			printf("INFORME O CODIGO DO FUNCIONARIO\n");
			scanf("%d", &cod);
			deletacodigo(&lista, cod);
			break;
		}
		case 9:
		{
			int codfuncionario;
			printf("INFORME O CODIGO DO FUNCIONARIO\n");
			scanf("%d", &codfuncionario);

			No* pi = alteradados(&lista, codfuncionario);
			if(pi == 0)
			{
				printf("NAO EXISTE ESSE FUNCIONARIO COM ESSE CODIGO\n");
			}
			else
			{
				int opaltera;
				menualteradadosfuncionario();
				scanf("%d", &opaltera);

				if(opaltera == 1)
				{
					char nomefuncionario[45];
					printf("DIGITE O NOME QUE FAZER A MUDANÇA: \n");
					scanf(" %[^\n]s", nomefuncionario);
					strcpy(pi->dado.nome, nomefuncionario);
					printf("O NOME DO FUNCIONARIO FOI ALTERADO PARA %s\n", pi->dado.nome);
				}
				if(opaltera == 2)
				{
					float novosalario;
					printf("DIGITE A ALTERAÇAO DO SALARIO\n");
					scanf("%f", &novosalario);
					pi->dado.salario = novosalario;
				}
			}
			break;
		}
		case 10:
		{
			tamanhoarquivo(&lista);
			break;
		}
		case 11:
		{
			int n;
			printf("DIGITE O NUMERO DO TAMANHO DA LISTA QUE VOCE DESEJA CRIAR\n");
			scanf("%d", &n);
			lista = criarlista(n);
			break;
		}
		case 12:
		{
			ordenar(&lista);
			break;
		}
		case 13:
		{
			int codigofuncionario;
			printf("DIGITE O CODIGO DO FUNCIONARIO AQUI\n");
			scanf("%d", &codigofuncionario);
			No* pi = alteradados(&lista, codigofuncionario);
			if(pi == NULL)
			{
				printf("NAO EXISTE ESSE CODIGO!!\n");
			}
			else
			{
				int op;
				menuoperacao();
				scanf("%d", &op);
				while(op != 5)
				{
					switch(op)
					{
					case 1:
					{
						aumento_salario(&pi->dado);
						break;
					}
					case 2:
					{
						totaldiastrabalhado(&pi->dado);
						break;
					}
					case 3:{
						int dia;
						diasemana();
						scanf("%d",&dia);
						diatrabalhado(&pi->dado,dia);
						break;
					}
					case 4:{
						valorpordiaria(&pi->dado);
						break;
					}
					default:
						printf("NAO TRABALHAMOS COM ESSE TIPO DE OPERAÇAO\n");
						break;
					}

					menuoperacao();
					scanf("%d", &op);
				}

			}
			break;
		}

		default:
			printf("NO MOMENTO NAO ESTAMS TABALHANDO COM ESSE TIPO DE SERVIÇO\n");
			break;

		}
		system("pause");
		system("cls");

		menufuncionario();
		scanf("%d", &op);
	}
}
