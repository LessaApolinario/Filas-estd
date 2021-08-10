#include <stdio.h>
#include "fila.h"

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