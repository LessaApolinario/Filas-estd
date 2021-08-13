#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./src/fila.h"

int main() {
  Fila *f = criar();

  setlocale(LC_ALL, "Portuguese");

  int resposta;
  int controlador[6];

  // contadores de clientes
  int atendidos = 0, naoAtendidos = 0;

  // Tempos a serem acumulados
  int tempoSaldo = 0, tempoSacar = 0;
  int tempoAplicacao = 0, tempoExtrato = 0;
  int tempoDinheiro = 0, tempoDebito = 0;

  // Frequência das operações
  int qtdSaldo = 0, qtdSacar = 0;
  int qtdAplicacao = 0, qtdExtrato = 0;
  int qtdPagamentoDinheiro = 0, qtdPagamentoDebito = 0;

  do {
    menu();
    scanf("%i", &resposta);

    switch (resposta) {
    case 0:
      printf("Agradecemos a preferência!\n");
      break;

    case 1:
      consultarSaldo(f);
      tempoSaldo += 10;
      inserir(f, tempoSaldo);
      qtdSaldo++;
      atendidos++;
      break;

    case 2:
      sacarDinheiro(f);
      tempoSacar += 20;
      inserir(f, tempoSacar);
      qtdSacar++;
      atendidos++;
      break;

    case 3:
      /*
        Por favor antes de usar essa função exiba o saldo
        com a função consultarSaldo() para que o saldo da aplicação
        seja diferente de 0, evitando que a saída seja 0 na função aplicacao().
      */
      aplicacao(f);
      tempoAplicacao += 30;
      inserir(f, tempoAplicacao);
      qtdAplicacao++;
      atendidos++;
      break;

    case 4:
      // extrato();
      tempoExtrato += 40;
      qtdExtrato++;
      atendidos++;
      break;

    case 5:
      // Por favor exiba o saldo antes de executar essa função
      pagarEmDinheiro(f);
      tempoDinheiro += 50;
      inserir(f, tempoDinheiro);
      qtdPagamentoDinheiro++;
      atendidos++;
      break;

    case 6:
      // Por favor exiba o saldo antes de executar essa função
      pagarComDebito(f);
      tempoDebito += 35;
      inserir(f, tempoDebito);
      qtdPagamentoDebito++;
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
      printf("Consultas de saldo = %d", qtdSaldo);
      pula_linha();
      printf("Saques = %d", qtdSacar);
      pula_linha();
      printf("Aplicações = %d", qtdAplicacao);
      pula_linha();
      printf("Extratos = %d", qtdExtrato);
      pula_linha();
      printf("Pagamentos em dinheiro = %d", qtdPagamentoDinheiro);
      pula_linha();
      printf("Pagamentos com débito em conta = %d", qtdPagamentoDebito);
      pula_linha();
      printf("-------------------------------------");
      pula_linha();
      printf("-----Tempos por operação-----");
      pula_linha();
      printf("Tempo total das consultas de saldo = %ds", tempoSaldo);
      pula_linha();
      printf("Tempo total dos saques = %ds", tempoSacar);
      pula_linha();
      printf("Tempo total das aplicações = %ds", tempoAplicacao);
      pula_linha();
      printf("Tempo total dos extratos = %ds", tempoExtrato);
      pula_linha();
      printf("Tempo total dos pagamentos em dinheiro = %ds", tempoDinheiro);
      pula_linha();
      printf("Tempo total dos pagamentos com débito em conta = %ds", tempoDebito);
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
