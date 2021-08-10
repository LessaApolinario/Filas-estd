#include "./src/fila.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Fila *f = criar();

  int op, tempoDeExpediente;

  printf("Qual é o tempo de expediente?\n");
  scanf("%d", &tempoDeExpediente);

  do {
    printf("\n----------Fila do banco----------\n");
    printf("\n[1] - Consultar saldo");
    printf("\n[2] - Sacar");
    printf("\n[3] - Aplicação");
    printf("\n[4] - Extrato");
    printf("\n[5] - Pagamento em dinheiro");
    printf("\n[6] - Pagamento com débito em conta");
    printf("\n[7] - exibir dados diários");
    printf("\n[0] - SAIR");
    printf("\n---------------------------------\n");
    printf("Escolha um serviço:\n");
    scanf("%d", &op);

    switch (op) {
      case 1:
        // consultarSaldo();
        // calcularTempoDeEspera();
        break;
      case 2:
        // sacar();
        // calcularTempoDeEspera();
        break;
      case 3:
        // aplicacao();
        // calcularTempoDeEspera();
        break;
      case 4:
        // extrato();
        // calcularTempoDeEspera();
        break;
      case 5:
        // pagamentoEmDinheiro();
        // calcularTempoDeEspera();
        break;
      case 6:
        // pagamentoComDebito();
        // calcularTempoDeEspera();
        break;
      case 7:
        printf("\nFim do expediente:\n");
        // clientesAtendidos();
        // clientesNaoAtendidos();
        // tempoPrioridade();
        // quantidadePorOperacao();
        // tempoTotalPorOperacao();
        break;
      case 0:
        printf("\nTransações finalizadas\n");
        break;
      default:
        printf("\nOperação inválida\n");
        break;
    }
  } while (op != 0);

  return 0;
}
