struct lista {
  int info;
  struct lista *prox;
	struct lista *ant;
};
typedef struct lista Lista;

struct fila {
  float saldo;
  Lista *inicio;
  Lista *fim;
};
typedef struct fila Fila;

Fila* criar();

void inserir(Fila *f, int valor);

void consultar(Fila *f);

int remover(Fila *f);

int contar(Fila *f);

void menu();

void pula_linha();

void erro();

void consultarSaldo(Fila *f);

void sacarDinheiro(Fila *f);

void aplicacao(Fila *f);

void pagarEmDinheiro(Fila *f);

void pagarComDebito(Fila *f);

int contarOperacao(Fila *f, int tempo);

int acumularTempo(Fila *f, int tempo);

int temPrioridade();
