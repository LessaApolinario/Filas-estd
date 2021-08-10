#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./src/fila.h"

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  int resposta;
  int controlador[6];

  resposta = menu();

  switch (resposta) {
  case 1:
    // consultarSaldo();
    // calcularTempo();
    break;

  case 2:
    // sacarDinheiro();
    // calcularTempo();
    break;

  case 3:
    // aplicacao();
    // calcularTempo();

    break;

  case 4:
    // extrato();
    // calcularTempo();
    break;

  case 5:
    // pagarEmDinheiro();
    // calcularTempo();
    break;

  case 6:
    // pagarComDebito();
    // calcularTempo();
    break;

  case 7:
    printf("\nDados após o fim do expediente:\n");
    // quantidadeAtendidos();
    // quantidadeNaoAtendidos();
    // tempoPorAcaoPrioridade();
    // quantidadeTransacao();
    // tempoTransacoes();
    break;
  default:
    erro();
    break;
  }

  return 0;
}
