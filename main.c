#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./src/fila.h"

int main() {
  Fila *f = criar();
  Fila *prioridade = criar();

  setlocale(LC_ALL, "Portuguese");

  int resposta, i = 1;
  int controlador[6];
  int numClientes;
  int counter;

  printf("Informe o número de clientes: ");
  scanf("%d", &numClientes);

  printf("\n-----Formação da fila-----\n");
  printf("\n-----prioridade-----\n");
  // preenchendo a fila com prioridade
  for (counter = 1; counter <= numClientes; counter++) {
    pula_linha();
    menu();
    scanf("%d", &resposta);

    verificarInsercao(prioridade, resposta);
  }

  counter = 0; // reinicializando o contador

  printf("\n-----Fila normal-----\n");
  // preenchendo a fila normal
  for (counter = 1; counter <= numClientes; counter++) {
    pula_linha();
    menu();
    scanf("%d", &resposta);

    verificarInsercao(f, resposta);
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

      if (temPrioridade() == 1) {
        consultarSaldo(prioridade);
        remover(prioridade);
      } else {
        consultarSaldo(f);
        remover(f);
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
        remover(prioridade);
      } else {
        sacarDinheiro(f);
        remover(f);
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
       remover(prioridade);
     } else {
       aplicacao(f);
       remover(f);
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
        remover(prioridade);
      } else {
        extrato(f);
        remover(f);
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
        remover(prioridade);
      } else {
        pagarEmDinheiro(f);
        remover(f);
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
        remover(prioridade);
      } else {
        pagarComDebito(f);
        remover(f);
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
