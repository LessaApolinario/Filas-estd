#include <stdio.h>
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
  }
	else {
    f->fim->prox = aux;
    f->fim = aux;
  }
}

void consultar(Fila *f){
  Lista *aux = f->inicio;

  printf("\nFila: ");

	while(aux!=NULL){
    printf("%d ", aux->info);
    aux=aux->prox;
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

int menu() {
  int resposta;

  printf("------FILA DO BANCO------");
  pula_linha();
  printf("Qual serviço você fará? ");
  pula_linha();
  printf("1 - Consultar saldo.\n 2 - Sacar dinheiro.");
  printf("\n3 - Aplicação.\n4 - Extrato.\n5 - Pagamento em dinheiro.");
  printf("\n6 - Pagamento com débito em conta.\n:");
  scanf("%i", &resposta);

  return resposta;
}
