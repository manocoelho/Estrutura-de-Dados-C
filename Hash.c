#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PRIMEIRO_NIVEL 10
#define TAMANHO_SEGUNDO_NIVEL 10

// Estrutura para armazenar o objeto na tabela hash
typedef struct {
    int chave;
    // Adicione os campos do seu objeto aqui
    // Por exemplo: char nome[50];
} Objeto;

// Estrutura para a tabela hash com encadeamento separado duplo
typedef struct {
    Objeto** tabela[TAMANHO_PRIMEIRO_NIVEL][TAMANHO_SEGUNDO_NIVEL];
} TabelaHash;

// Função para calcular o hash no primeiro nível
int hash_primeiro_nivel(int chave) {
    return chave % TAMANHO_PRIMEIRO_NIVEL;
}

// Função para calcular o hash no segundo nível
int hash_segundo_nivel(int chave) {
    return (chave / TAMANHO_PRIMEIRO_NIVEL) % TAMANHO_SEGUNDO_NIVEL;
}

// Função para inicializar a tabela hash
void inicializar_tabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_PRIMEIRO_NIVEL; i++) {
        for (int j = 0; j < TAMANHO_SEGUNDO_NIVEL; j++) {
            tabela->tabela[i][j] = NULL;
        }
    }
}

// Função para inserir um objeto na tabela hash
void inserir(TabelaHash* tabela, Objeto* objeto) {
    int indice_primeiro_nivel = hash_primeiro_nivel(objeto->chave);

    // Verifica se a tabela do segundo nível no primeiro nível está vazia
    if (tabela->tabela[indice_primeiro_nivel][0] == NULL) {
        // Aloca memória para a tabela do segundo nível
        tabela->tabela[indice_primeiro_nivel][0] = (Objeto**)malloc(TAMANHO_SEGUNDO_NIVEL * sizeof(Objeto*));
        for (int i = 0; i < TAMANHO_SEGUNDO_NIVEL; i++) {
            tabela->tabela[indice_primeiro_nivel][i] = NULL;
        }
    }

    // Calcula o hash no segundo nível
    int indice_segundo_nivel = hash_segundo_nivel(objeto->chave);

    // Verifica se a lista no segundo nível está vazia
    if (tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel] == NULL) {
        // Aloca memória para a lista no segundo nível
        tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel] = (Objeto**)malloc(sizeof(Objeto*));
        tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel][0] = objeto;
    } else {
        // Se a lista não estiver vazia, realoca memória para adicionar o objeto à lista
        int tamanho_lista = sizeof(tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel]) / sizeof(Objeto*);
        tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel] = (Objeto**)realloc(
            tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel],
            (tamanho_lista + 1) * sizeof(Objeto*)
        );
        tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel][tamanho_lista] = objeto;
    }
}

// Função para recuperar um objeto na tabela hash a partir da chave
Objeto* recuperar(TabelaHash* tabela, int chave) {
    int indice_primeiro_nivel = hash_primeiro_nivel(chave);
    int indice_segundo_nivel = hash_segundo_nivel(chave);

    // Verifica se a tabela do segundo nível no primeiro nível não está vazia
    if (tabela->tabela[indice_primeiro_nivel][0] != NULL &&
        tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel] != NULL) {
        // Percorre a lista para procurar o objeto com a chave correspondente
        for (int i = 0; tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel][i] != NULL; i++) {
            if (tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel][i]->chave == chave) {
                return tabela->tabela[indice_primeiro_nivel][indice_segundo_nivel][i];
            }
        }
    }

    // Retorna NULL se o objeto não for encontrado
    return NULL;
}

// Função para liberar a memória utilizada pela tabela hash
void liberar_tabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_PRIMEIRO_NIVEL; i++) {
        for (int j = 0; j < TAMANHO_SEGUNDO_NIVEL; j++) {
            // Libera a memória utilizada pela lista no segundo nível
            if (tabela->tabela[i][j] != NULL) {
                free(tabela->tabela[i][j]);
            }
        }
    }
}

int main() {
    TabelaHash tabela;
    // Inicializa a tabela hash
    inicializar_tabela(&tabela);

    // Exemplo de uso
    Objeto obj1 = {1 /* chave */, /* outros campos do objeto */};
    Objeto obj2 = {11 /* chave */, /* outros campos do objeto */};
    
    // Insere os objetos na tabela hash
    inserir(&tabela, &obj1);
    inserir(&tabela, &obj2);

    // Recupera um objeto a partir da chave
    Objeto* resultado = recuperar(&tabela, 1);

    // Verifica se o objeto foi encontrado e exibe a mensagem correspondente
    if (resultado != NULL) {
        printf("Objeto encontrado! Chave: %d\n", resultado->chave);
    } else {
        printf("Objeto nao encontrado.\n");
    }

    // Libera a memória utilizada pela tabela hash
    liberar_tabela(&tabela);

    return 0;
}
