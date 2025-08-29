#define TAM 100

struct aluno{

    int matricula;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);