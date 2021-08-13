#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criar() {
  Fila *f = (Fila*)malloc(sizeof (Fila));
  f->inicio = f->fim = NULL;

	return f;
}

void inserir(Fila *f, int valor) {
  Lista *aux = (Lista*)malloc(sizeof(Lista));
  aux->info = valor;
  aux->prox = NULL;

	if (f->inicio == NULL) {
    f->inicio = f->fim = aux;
  } else {
    f->fim->prox = aux;
    f->fim = aux;
  }
}

void consultar(Fila *f){
  Lista *aux = f->inicio;

  printf("\nFila: ");

	while(aux != NULL){
    printf("%d ", aux->info);

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
    valor = f->inicio->info;
    f->inicio = f->inicio->prox;

		if (f->inicio == NULL) {
			f->fim = NULL;
		}

    free(aux);
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
    printf("Opção inválida ou campo não correspondente!");
    pula_linha();
}

void menu() {
  printf("------FILA DO BANCO------");
  pula_linha();
  printf("Qual serviço você fará? ");
  pula_linha();
  printf("1 - Consultar saldo.\n2 - Sacar dinheiro.");
  printf("\n3 - Aplicação.\n4 - Extrato.\n5 - Pagamento em dinheiro.");
  printf("\n6 - Pagamento com débito em conta.\n:");
}

void consultarSaldo(Fila *f) {
  if (f->saldo == 0) {
    f->saldo = 1500;
  }

  pula_linha();
  printf("Seu saldo: R$ %.2f", f->saldo);
  pula_linha();
}

void sacarDinheiro(Fila *f) {
  Fila *aux = f;
  float valorSaque;
  printf("Quanto você deseja sacar? ");
  scanf("%f", &valorSaque);

  aux->saldo -= valorSaque;

  pula_linha();
  printf("Valor retirado com sucesso!");
  pula_linha();
}

void aplicacao(Fila *f) {
  int meses, i;
  float impostoDeRenda = 0, rendimento = 0, taxa, taxaIR;

  printf("Quantos meses? ");
  scanf("%d", &meses);

  printf("Qual é a taxa mensal? ");
  scanf("%f", &taxa);

  printf("Qual é a taxa do imposto de renda? ");
  scanf("%f", &taxaIR);

  for (i = 1; i <= meses; i++) {
    rendimento += f->saldo * (taxa / 100);
    f->saldo += rendimento;

    printf("Saldo no mês %d = R$ %.2f\n", i, f->saldo);
  }

  impostoDeRenda = rendimento * (taxaIR / 100);

  pula_linha();
  printf("Valor a receber = R$ %.2f\n", (f->saldo - impostoDeRenda));
  pula_linha();
}

void pagarEmDinheiro(Fila *f) {
  float divida;

  printf("Qual é o valor da divida? ");
  scanf("%f", &divida);

  if (f->saldo >= divida) {
    pula_linha();
    printf("Pagamento realizado com sucesso!");
    pula_linha();

    f->saldo -= divida;
  } else {
    pula_linha();
    printf("Saldo insuficiente, falha no pagamento!");
    pula_linha();
  }
}

void pagarComDebito(Fila *f) {
  float debito = 200;
  char data[10] = "20/08/2021";

  f->saldo -= debito;

  pula_linha();
  printf("--------------------");
  pula_linha();
  printf("Data do débito: %s\n", data);
  printf("Valor do débito (D): R$ %.2f\n", debito);
  pula_linha();
  printf("--------------------");
  pula_linha();
}
