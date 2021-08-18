#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criar() {
  Fila *f = (Fila*)malloc(sizeof (Fila));
  f->inicio = f->fim = NULL;

	return f;
}

void inserir(Fila *f) {
  Lista *aux = (Lista*)malloc(sizeof(Lista));
  aux->saldo = 1500;
  menu();
  scanf("%i", &aux->resposta);
  if(aux->resposta < 0 || aux->resposta > 6) {
    erro();
    printf("Tente novamente!");
    pula_linha();
    inserir(f);
  }
  aux->prox = NULL;

	if (f->inicio == NULL) {
    f->inicio = f->fim = aux;
  } else {
    f->fim->prox = aux;
    f->fim = aux;
  }
}

void formarFilas(Fila *f, Fila *prioridade, int i) {
  pula_linha();
  printf("Pessoa %i a se apresentar: \n", i+1);
  int verifica = temPrioridade();
  if(verifica == 1) {
    inserir(prioridade);
  }
  else if (verifica == 0){
    inserir(f);
  }
  else {
    printf("Tente novamente!");
    formarFilas(f, prioridade, i);
  }
}
void consultar(Fila *f){
  Lista *aux = f->inicio;

  printf("\nFila: ");

	while(aux != NULL){
    printf("%.2f ", aux->saldo);

    aux = aux->prox;
  }

	printf("\n");
}

int remover(Fila *f){
  int valor = 0;
  Lista *aux = f->inicio;

  if (aux == NULL) {
    printf("\nFila vazia!");
  }
	else {
    valor = f->inicio->saldo;
    f->inicio = f->inicio->prox;

		if (f->inicio == NULL) {
			f->fim = NULL;
		}

    free(aux);
  }
  if(f->inicio == f->fim && f->fim == NULL) {
      f = NULL;
  }
  return valor;
}

int contar(Fila *f) {
  int cont = 0;

	Lista *aux = f->inicio;

	while (aux != NULL) {
    cont++;
    aux = aux->prox;
  }

  return cont;
}

void pula_linha() {
  printf("\n\n");
}

void erro() {
    pula_linha();
    printf("Opção inválida ou campo não correspondente!");
    pula_linha();
}

void menu() {
  printf("------OPERAÇÕES DO BANCO------");
  pula_linha();
  printf("Qual serviço será realizado? ");
  pula_linha();
  printf("1 - Consultar saldo.\n2 - Sacar dinheiro.");
  printf("\n3 - Aplicação.\n4 - Extrato.\n5 - Pagamento em dinheiro.");
  printf("\n6 - Pagamento com débito em conta.\n: ");
}

void consultarSaldo(Fila *f) {
  printf("------CONSULTAR SALDO------\n");
  if (f->inicio->saldo == 0) {
    f->inicio->saldo = 1500;
  }

  pula_linha();
  printf("Seu saldo: R$ %.2f", f->inicio->saldo);
  pula_linha();
}

void sacarDinheiro(Fila *f) {
  printf("------SACAR DINHEIRO------");
  pula_linha();
  Fila *aux = f;
  float valorSaque;
  printf("Quanto você deseja sacar? ");
  scanf("%f", &valorSaque);

  aux->inicio->saldo -= valorSaque;

  pula_linha();
  printf("Valor retirado com sucesso!");
  pula_linha();
}

void aplicacao(Fila *f) {
  int meses, i;
  float impostoDeRenda = 0, rendimento = 0, taxa, taxaIR;

  printf("------APLICAÇÃO------");
  pula_linha();
  printf("Quantos meses? ");
  scanf("%d", &meses);

  printf("Qual é a taxa mensal? ");
  scanf("%f", &taxa);

  printf("Qual é a taxa do imposto de renda? ");
  scanf("%f", &taxaIR);

  for (i = 1; i <= meses; i++) {
    rendimento += f->inicio->saldo * (taxa / 100);
    f->inicio->saldo += rendimento;

    printf("Saldo no mês %d = R$ %.2f\n", i, f->inicio->saldo);
  }

  impostoDeRenda = rendimento * (taxaIR / 100);

  pula_linha();
  printf("Valor a receber = R$ %.2f\n", (f->inicio->saldo - impostoDeRenda));
  pula_linha();
}

void extrato(Fila *f) {
  printf("------EXTRATO------");
  pula_linha();
  printf("C: R$%.2f\n", f->inicio->saldo);
  printf("D: ------");
  pula_linha();
}

void pagarEmDinheiro(Fila *f) {
  float divida;

  printf("------PAGAMENTO - DINHEIRO------");
  pula_linha();

  printf("Qual é o valor da divida? ");
  scanf("%f", &divida);

  if (f->inicio->saldo >= divida) {
    pula_linha();
    printf("Pagamento realizado com sucesso!");
    pula_linha();

    f->inicio->saldo -= divida;
  } else {
    pula_linha();
    printf("Saldo insuficiente, falha no pagamento!");
    pula_linha();
  }
}

void pagarComDebito(Fila *f) {
  float debito = 200;
  char data[10] = "20/08/2021";

  f->inicio->saldo -= debito;
  printf("------PAGAMENTO - DÉBITO------");
  pula_linha();
  printf("--------------------");
  pula_linha();
  printf("Data do débito: %s\n", data);
  printf("Valor do débito (D): R$ %.2f\n", debito);
  pula_linha();
  printf("--------------------");
  pula_linha();
}

int temPrioridade() {
  int resposta;

  printf("É idoso (a) ou gestante? (1 - SIM, 0 - NÃO)\n");
  scanf("%d", &resposta);

  if(resposta != 0 && resposta != 1) {
    erro();
    return -1;
  }

  return resposta;
}
