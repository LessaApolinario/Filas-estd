#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "./src/fila.h"

int main() {
  Fila *f = criar();
  Fila *prioridade = criar();
  Fila *aux = criar();

  setlocale(LC_ALL, "Portuguese");

  int i = 0;
  int controlador[6];
  int numClientes;
  int counter = 0;
  int tempoNormal = 0;
  int tempoPrioridade = 0;
  int const terminaExpediente = 9;

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
    if (prioridade != NULL) {
      aux = prioridade;
    }
    else if (f != NULL){
      aux = f;
    }
    else {
      break;
    }

    switch (aux->inicio->resposta) {
    case 0:
      printf("Agradecemos a preferência!\n");
      break;

    case 1:
      printf("Tempo esperado na fila: %is", tempoNormal + tempoPrioridade);
      pula_linha();
      if (prioridade == NULL) {
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
      printf("Tempo esperado na fila: %is", tempoNormal + tempoPrioridade);
      pula_linha();
      if (prioridade == NULL) {
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
     printf("Tempo esperado na fila: %is", tempoNormal + tempoPrioridade);
     pula_linha();
     if (prioridade == NULL) {
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
      printf("Tempo esperado na fila: %is", tempoNormal + tempoPrioridade);
      pula_linha();
      if (prioridade == NULL) {
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
      printf("Tempo esperado na fila: %is", tempoNormal + tempoPrioridade);
      pula_linha();
      if (prioridade == NULL) {
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
      printf("Tempo esperado na fila: %is", tempoNormal + tempoPrioridade);
      pula_linha();
      if (prioridade == NULL) {
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
    if(i < terminaExpediente && f->inicio == NULL) {
      i = terminaExpediente;
    }

    if (prioridade != NULL) {
      if(prioridade->inicio == NULL) {
        prioridade = NULL;
      }
    }

    if(f != NULL) {
      if(f->inicio == NULL) {
        f = NULL;
      }
    }

  } while (i <= terminaExpediente); // 10 clientes no máximo

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
  printf("------Tempo total das operações------");
  pula_linha();
  printf("Consulta - %is\nSacar - %is\nAplicação - %is\n", 
  controlador[0]*10, controlador[1]*20, controlador[2]*30);
  printf("Extrato - %is\nPagamento em dinheiro - %is\nPagamento com débito em conta - %is", 
  controlador[3]*40, controlador[4]*50, controlador[5]*35);
  pula_linha();
  printf("------QUANTIDADE DE EXECUÇÕES------");
  pula_linha();
  printf("Consulta: %i vezes\nSacar: %i vezes\nAplicação: %i vezes\n",
  controlador[0], controlador[1], controlador[2]);
  printf("Extrato: %i vezes\nPagamento em dinheiro: %i vezes\nPagamento com débito em conta: %i vezes",
  controlador[3], controlador[4], controlador[5]);
  pula_linha();
  printf("-----Tempos de operações com prioridade-----");
  pula_linha();
  printf("Tempo Total: %is", tempoPrioridade);
  pula_linha();
  printf("-----Tempo total de operações-----");
  pula_linha();
  printf("Tempo total: %is", tempoPrioridade + tempoNormal);
  pula_linha();
  printf("-----------------------------");
  pula_linha();

  return 0;
}
