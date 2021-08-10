struct lista {
  int info;
  struct lista *prox;
	struct lista *ant;
};
typedef struct lista Lista;

struct fila {
  Lista *inicio;
  Lista *fim;
};
typedef struct fila Fila;

Fila* criar();

void inserir(Fila *f, int valor);

void consultar(Fila *f);

int remover(Fila *f);

int contar(Fila *f);
