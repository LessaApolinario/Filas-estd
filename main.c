#include "./src/fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Fila *f = criar();
  Fila *f2 = criar();

  inserir(f, 10);
  inserir(f, 11);
  inserir(f, 13);

	consultar(f);

  // printf("\n Quantidade de elementos: %d", contar(f));

  // consultar(f);

  // remover(f);
  // remover(f);

	// removeNoFinal(f, 13);

	//inseriNoInicio(f, 14);

  // consultar(f);

  return 0;
}
