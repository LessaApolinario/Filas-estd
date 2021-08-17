struct lista {
  float saldo;
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

void inserir(Fila *f);

void formarFilas(Fila *f, Fila *prioridade, int i);

void consultar(Fila *f);

int remover(Fila *f);

int contar(Fila *f);

void menu();

void pula_linha();

void erro();

void consultarSaldo(Fila *f);

void sacarDinheiro(Fila *f);

void aplicacao(Fila *f);

void extrato(Fila *f);

void pagarEmDinheiro(Fila *f);

void pagarComDebito(Fila *f);

int temPrioridade();

int verificarInsercao(Fila *f, int resposta);
