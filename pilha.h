#define TAM 10

struct elemento{

    int num;
};

typedef struct pilha Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
int tamanho_pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int pilha_cheia(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct elemento *valor);
int insere_pilha(Pilha* pi, struct elemento valor);
int remove_pilha(Pilha* pi);