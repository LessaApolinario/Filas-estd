#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./src/fila.h"

int main() {
  Fila *f = criar();
  Fila *prioridade = criar();

  setlocale(LC_ALL, "Portuguese");

  int resposta, i = 0;
  int controlador[6];
  int numClientes;
  int counter = 0;
  int tempoNormal = 0;
  int tempoPrioridade = 0;

  printf("Informe o número de clientes: ");
  scanf("%d", &numClientes);

  printf("\n-----Formação da fila-----\n");

  for (counter = 0; counter < numClientes; counter++) {
    formarFilas(f, prioridade, counter);
  }

  for (int i = 0; i < 6; i++) {
    controlador[i] = 0;
  }

  // contador de clientes
  int atendidos = 0;

  do {
    printf("-----Atendimento-----");
    pula_linha();
    menu();
    scanf("%i", &resposta);

    switch (resposta) {
    case 0:
      printf("Agradecemos a preferência!\n");
      break;

    case 1:

      if (controlador[0] != 0) {
        erro();
        printf("\nOperação já efetuada!");
        pula_linha();
        break;
      }
      if (prioridade->inicio == NULL) {
        tempoNormal +=  10;
        consultarSaldo(f);
        remover(f);
      }
      else {
        tempoPrioridade +=  10;
        consultarSaldo(prioridade);
        remover(prioridade);
      }

      controlador[0]++;
      atendidos++;
      break;

    case 2:

      if (controlador[1] != 0) {
        erro();
        printf("\nOperação já efetuada!");
        pula_linha();
        break;
      }

      if (prioridade->inicio == NULL) {
        tempoNormal +=  20;
        sacarDinheiro(f);
        remover(f);
      } else {
        tempoPrioridade +=  20;
        sacarDinheiro(prioridade);
        remover(prioridade);
      }

      controlador[1]++;
      atendidos++;
      break;

    case 3:
      /*
        Por favor antes de usar essa função exiba o saldo
        com a função consultarSaldo() para que o saldo da aplicação
        seja diferente de 0, evitando que a saída seja 0 na função aplicacao().
      */

     if (controlador[2] != 0) {
        erro();
        printf("\nOperação já efetuada!");
        pula_linha();
        break;
      }

     if (prioridade->inicio == NULL) {
       tempoNormal += 30;
       aplicacao(f);
       remover(f);
     } else {
       tempoPrioridade += 30;
       aplicacao(prioridade);
       remover(prioridade);
     }

      controlador[2]++;
      atendidos++;
      break;

    case 4:

      if (controlador[3] != 0) {
        erro();
        printf("\nOperação já efetuada!");
        pula_linha();
        break;
      }

      if (prioridade->inicio == NULL) {
        tempoNormal += 40;
        extrato(f);
        remover(f);
      } else {
        tempoPrioridade += 40;
        extrato(prioridade);
        remover(prioridade);
      }

      controlador[3]++;
      atendidos++;
      break;

    case 5:
      // Por favor exiba o saldo antes de executar essa função

      if (controlador[4] != 0) {
        erro();
        printf("\nOperação já efetuada!");
        pula_linha();
        break;
      }

      if (prioridade->inicio == NULL) {
        tempoNormal += 50;
        pagarEmDinheiro(f);
        remover(f);
      } else {
        tempoPrioridade += 50;
        pagarEmDinheiro(prioridade);
        remover(prioridade);
      }

      controlador[4]++;
      atendidos++;
      break;

    case 6:
      // Por favor exiba o saldo antes de executar essa função

      if (controlador[5] != 0) {
        erro();
        printf("\nOperação já efetuada!");
        pula_linha();
        break;
      }

      if (prioridade->inicio == NULL) {
        tempoNormal += 35;
        pagarComDebito(f);
        remover(f);
      } else {
        tempoPrioridade += 35;
        pagarComDebito(prioridade);
        remover(prioridade);
      }

      controlador[5]++;
      atendidos++;
      break;

    default:
      erro();
      break;
    }

    i++;
  } while (i <= numClientes); // 10 clientes no máximo

  printf("\nDados após o fim do expediente:");
  pula_linha();
  printf("----------Índices de atendimento----------");
  pula_linha();
  printf("Atendidos = %d", atendidos);
  pula_linha();
  printf("Não atendidos = %d", (numClientes - atendidos));
  pula_linha();
  printf("------------------------------------------");
  pula_linha();
  printf("------Tempos das operações------");
  pula_linha();
  printf("Consulta - 10s\nSacar - 20s\nAplicação - 30s\n");
  printf("Pagamento em dinheiro - 50s\nPagamento com débito em conta - 35s");
  pula_linha();
  printf("-----Tempos de operações com prioridade-----");
  pula_linha();
  printf("Tempo Total: %is", tempoPrioridade);
  pula_linha();
  printf("-----Tempos total de operações-----");
  pula_linha();
  printf("Tempo total: %is", tempoPrioridade + tempoNormal);
  pula_linha();
  printf("-----------------------------");
  pula_linha();

  return 0;
}
