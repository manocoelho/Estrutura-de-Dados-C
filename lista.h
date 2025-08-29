#include <stdio.h>
#include<stdlib.h>

#define TAM 10

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
int insere_inicio(Lista* li, int valor);
int insere_fim(Lista* li, int valor);
int remove_inicio(Lista* li);
int remove_fim(Lista* li);
int mostrar_lista(Lista *li);