#include <stdio.h>
#include <stdlib.h>
#include "sobreoficina.h"

struct Proprietario{
   char nomeproprietario[50];
   char cnpj[25];
   char enderenco[30];
   char telefone[15];
   char emailatendimento[40];
};

void apresentacaoofcina(proprietario *p){
  printf("==================================================================\n");
  printf("                   DADOS DA EMPRESA                \n");
  printf("==================================================================\n");
  printf("NOME DO PROPRIETARIO:   %s\n",p->nomeproprietario);
  printf("CNPJ:   %s\n",p->cnpj);
  printf("ENDERENÇO:   %s\n",p->enderenco);
  printf("TELEFONE DE ATENDIMENTO:   %s\n",p->telefone);
  printf("EMAIL PARA CONTATO:  %s\n",p->emailatendimento);
  printf("==================================================================\n");
  system("pause");
}

void main_proprietario(){
  proprietario p = {"ALLYSON BRUNO DE FREITAS FERNANDES",
                   "00.776.574/0006-60","RUA JOSE DE FREITAS", "998138643","OFICINAGURGEL@GMAIL.COM"};
 apresentacaoofcina(&p);

}