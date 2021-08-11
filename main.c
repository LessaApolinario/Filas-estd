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
    case 1:
      consultarSaldo(f);
      tempoSaldo += 10; // + 10 segundos
      inserir(f, tempoSaldo);
      qtdSaldo++;
      atendidos++;
      break;

    case 2:
      // sacarDinheiro();
      tempoSacar += 20;
      qtdSacar++;
      atendidos++;
      break;

    case 3:
      // aplicacao();
      tempoAplicacao += 30;
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
      // pagarEmDinheiro();
      tempoDinheiro += 50;
      qtdPagamentoDinheiro++;
      atendidos++;
      break;

    case 6:
      // pagarComDebito();
      tempoDebito += 35;
      qtdPagamentoDebito++;
      atendidos++;
      break;

    case 7:
      printf("\nDados após o fim do expediente:\n");
      printf("\n----------Índices de atendimento----------\n");
      printf("\nAtendidos = %d\n", atendidos);
      printf("\nNão atendidos = %d", (contar(f) - atendidos));
      printf("\n------------------------------------------\n");
      // quantidade Atendidos com prioridade
      // Precisamos criar uma lógica para fila com prioridade
      printf("\n-----Frequência de cada operação-----\n");
      printf("\nConsultas de saldo = %d\n", qtdSaldo);
      printf("\nSaques = %d\n", qtdSacar);
      printf("\nAplicações = %d\n", qtdAplicacao);
      printf("\nExtratos = %d\n", qtdExtrato);
      printf("\nPagamentos em dinheiro = %d\n", qtdPagamentoDinheiro);
      printf("\nPagamentos com débito em conta = %d\n", qtdPagamentoDebito);
      printf("\n-------------------------------------\n");
      printf("\n-----Tempos por operação-----\n");
      printf("\nTempo total das consultas de saldo = %ds\n", tempoSaldo);
      printf("\nTempo total dos saques = %ds\n", tempoSacar);
      printf("\nTempo total das aplicações = %ds\n", tempoAplicacao);
      printf("\nTempo total dos extratos = %ds\n", tempoExtrato);
      printf("\nTempo total dos pagamentos em dinheiro = %ds\n", tempoDinheiro);
      printf("\nTempo total dos pagamentos com débito em conta = %ds\n", tempoDebito);
      printf("\n-----------------------------\n");
      break;
    default:
      erro();
      break;
    }
  } while (resposta != 0);

  return 0;
}
