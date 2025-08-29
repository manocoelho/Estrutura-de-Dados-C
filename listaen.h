struct aluno{

    int matricula;
};

typedef struct elemento *Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int remove_inicio(Lista *li, struct aluno valor);
int insere_fim(Lista *li, struct aluno valor);
int insere_lista_ordenada(Lista* li, struct aluno valor);
int remove_inicio(Lista* li);
int remove_fim(Lista* li);
int remove_lista(Lista* li, int valor);