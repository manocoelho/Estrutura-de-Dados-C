typedef struct elemento* Lista;

Lista* cria_lista(Lista* li);
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int insere_inicio(Lista* li, int valor);
int insere_fim(Lista* li, int valor);
int insere_ordenado(Lista* li, int valor);
int remove_inicio(Lista* li);
int remove_fim(Lista* li);
int remove_elemento(Lista* li, int valor);