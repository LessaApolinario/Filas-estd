#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./src/fila.h"

int main() {
  Fila *f = criar();

  setlocale(LC_ALL, "Portuguese");

  int resposta;
  int controlador[6];

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
      consultarSaldo(f);
      inserir(f, 10); // 10 segundos
      atendidos++;
      break;

    case 2:
      sacarDinheiro(f);
      inserir(f, 20); // 20 segundos
      atendidos++;
      break;

    case 3:
      /*
        Por favor antes de usar essa função exiba o saldo
        com a função consultarSaldo() para que o saldo da aplicação
        seja diferente de 0, evitando que a saída seja 0 na função aplicacao().
      */
      aplicacao(f);
      inserir(f, 30); // 30 segundos
      atendidos++;
      break;

    case 4:
      // extrato();
      inserir(f, 40); // 40 segundos
      atendidos++;
      break;

    case 5:
      // Por favor exiba o saldo antes de executar essa função
      pagarEmDinheiro(f);
      inserir(f, 50); // 50 segundos
      atendidos++;
      break;

    case 6:
      // Por favor exiba o saldo antes de executar essa função
      pagarComDebito(f);
      inserir(f, 35); // 35 segundos
      atendidos++;
      break;

    case 7:
      printf("\nDados após o fim do expediente:");
      pula_linha();
      printf("----------Índices de atendimento----------");
      pula_linha();
      printf("Atendidos = %d", atendidos);
      pula_linha();
      printf("Não atendidos = %d", (contar(f) - atendidos));
      pula_linha();
      printf("------------------------------------------");
      // quantidade Atendidos com prioridade
      // Precisamos criar uma lógica para fila com prioridade
      pula_linha();
      printf("-----Frequência de cada operação-----");
      pula_linha();
      printf("Consultas de saldo = %d", contarOperacao(f, 10));
      pula_linha();
      printf("Saques = %d", contarOperacao(f, 20));
      pula_linha();
      printf("Aplicações = %d", contarOperacao(f, 30));
      pula_linha();
      printf("Extratos = %d", contarOperacao(f, 40));
      pula_linha();
      printf("Pagamentos em dinheiro = %d", contarOperacao(f, 50));
      pula_linha();
      printf("Pagamentos com débito em conta = %d", contarOperacao(f, 35));
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
      break;
    default:
      erro();
      break;
    }
  } while (resposta != 0);

  return 0;
}
