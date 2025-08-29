#define TAM 10

struct pessoa{
    
    int senha;
};

typedef struct fila Fila;

Fila* cria_fila();
void libera_fila(Fila* fi);
int tamanho_fila(Fila* fi);
int fila_vazia(Fila* fi);
int fila_cheia(Fila* fi);
int insere_fila(Fila* fi, struct pessoa valor);
int remove_fila(Fila* fi);
int consulta_Fila(Fila* fi, struct pessoa *valor);