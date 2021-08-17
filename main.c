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

  printf("Informe o número de clientes: ");
  scanf("%d", &numClientes);

  for (int i = 0; i < 6; i++) {
      controlador[i] = 0;
  }

  // contador de clientes
  int atendidos = 0;

  do {
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

      if (temPrioridade() == 1) {
        consultarSaldo(prioridade);
        inserir(prioridade, 10);
      } else {
        consultarSaldo(f);
        inserir(f, 10); // 10 segundos
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

      if (temPrioridade() == 1) {
        sacarDinheiro(prioridade);
        inserir(prioridade, 20);
      } else {
        sacarDinheiro(f);
        inserir(f, 20); // 20 segundos
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

     if (temPrioridade() == 1) {
       aplicacao(prioridade);
       inserir(prioridade, 30);
     } else {
       aplicacao(f);
       inserir(f, 30); // 30 segundos
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

      if (temPrioridade() == 1) {
        extrato(prioridade);
        inserir(prioridade, 40);
      } else {
        extrato(f);
        inserir(f, 40); // 40 segundos
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

      if (temPrioridade() == 1) {
        pagarEmDinheiro(prioridade);
        inserir(prioridade, 50);
      } else {
        pagarEmDinheiro(f);
        inserir(f, 50); // 50 segundos
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

      if (temPrioridade() == 1) {
        pagarComDebito(prioridade);
        inserir(prioridade, 35);
      } else {
        pagarComDebito(f);
        inserir(f, 35); // 35 segundos
      }

      controlador[5]++;
      atendidos++;
      break;

    default:
      erro();
      break;
    }

    i++;
  } while (i != numClientes); // 10 clientes no máximo

  printf("\nDados após o fim do expediente:");
  pula_linha();
  printf("----------Índices de atendimento----------");
  pula_linha();
  printf("Fila prioridade: ");
  consultar(prioridade);
  pula_linha();
  printf("Fila normal: ");
  consultar(f);
  pula_linha();
  printf("Atendidos = %d", atendidos);
  pula_linha();
  printf("Não atendidos = %d", ((contar(f) + contar(prioridade)) - atendidos));
  pula_linha();
  printf("------------------------------------------");
  pula_linha();
  printf("-----Tempos por operação (prioridade)-----");
  pula_linha();
  printf("Tempo total das consultas de saldo = %ds", acumularTempo(prioridade, 10));
  pula_linha();
  printf("Tempo total dos saques = %ds", acumularTempo(prioridade, 20));
  pula_linha();
  printf("Tempo total das aplicações = %ds", acumularTempo(prioridade, 30));
  pula_linha();
  printf("Tempo total dos extratos = %ds", acumularTempo(prioridade, 40));
  pula_linha();
  printf("Tempo total dos pagamentos em dinheiro = %ds", acumularTempo(prioridade, 50));
  pula_linha();
  printf("Tempo total dos pagamentos com débito em conta = %ds", acumularTempo(prioridade, 35));
  pula_linha();
  printf("-----------------------------------------");
  pula_linha();
  printf("-----Frequência de cada operação-----");
  pula_linha();
  printf("Consultas de saldo = %d", contarOperacao(f, 10) + contarOperacao(prioridade, 10));
  pula_linha();
  printf("Saques = %d", contarOperacao(f, 20) + contarOperacao(prioridade, 20));
  pula_linha();
  printf("Aplicações = %d", contarOperacao(f, 30) + contarOperacao(prioridade, 30));
  pula_linha();
  printf("Extratos = %d", contarOperacao(f, 40) + contarOperacao(prioridade, 40));
  pula_linha();
  printf("Pagamentos em dinheiro = %d", contarOperacao(f, 50) + contarOperacao(prioridade, 50));
  pula_linha();
  printf("Pagamentos com débito em conta = %d", contarOperacao(f, 35) + contarOperacao(prioridade, 35));
  pula_linha();
  printf("-------------------------------------");
  pula_linha();
  printf("-----Tempos por operação-----");
  pula_linha();
  printf("Tempo total das consultas de saldo = %ds", acumularTempo(f, 10));
  pula_linha();
  printf("Tempo total dos saques = %ds", acumularTempo(f, 20));
  pula_linha();
  printf("Tempo total das aplicações = %ds", acumularTempo(f, 30));
  pula_linha();
  printf("Tempo total dos extratos = %ds", acumularTempo(f, 40));
  pula_linha();
  printf("Tempo total dos pagamentos em dinheiro = %ds", acumularTempo(f, 50));
  pula_linha();
  printf("Tempo total dos pagamentos com débito em conta = %ds", acumularTempo(f, 35));
  pula_linha();
  printf("-----------------------------");
  pula_linha();

  return 0;
}
