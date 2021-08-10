#include "./src/fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  int resposta;
  int controlador[6];

  resposta = menu();

  switch (resposta) {
    case 1:
    
      break;
    
    case 2:

      break;

    case 3:

      break;
    
    case 4:

      break;

    case 5:

      break;
    
    case 6: 

      break;

    default:
      erro();
      break;
  }

  return 0;
}
