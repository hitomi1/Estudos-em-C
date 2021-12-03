/* Jantar dos filósofos
 *
 * SSC0541 - Sistemas Operacionais I
 *
 * Gabriel Silva Fontes - 10856803
 * "Licenciado" sob domínio público (https://unlicense.org).
 *
 */

#include <stdlib.h>
#include <semaphore.h>

// Nosso monitor, representando o jantar como um todo
struct jantar_t {
    // Quantos filósofos participam
    int n_filosofos;
    // Semáforos dos palitos
    sem_t *palitos;
};

// Criar e alocar um jantar
struct jantar_t *jantar_inicializar(int n_filosofos) {
    struct jantar_t *jantar = malloc(sizeof(struct jantar_t));
    if (!jantar) return NULL;

    // Alocar vetor de semáforos
    jantar->palitos = malloc(sizeof(sem_t)*n_filosofos);
    if (!jantar->palitos) return NULL;
    // Incializar semáforos dos palitos
    for (int i = 0; i < n_filosofos; i++) {
        sem_init(&jantar->palitos[i], 0, 1);
    }

    jantar->n_filosofos = n_filosofos;
    return jantar;
}

// Destruir um jantar
void jantar_destruir(struct jantar_t *jantar) {
    if (jantar) {
        if (jantar->palitos) free(jantar->palitos);
        free(jantar);
    }
}

// Pegar palitos, aguardando e lockando os respectivos semáforos
void jantar_pegar_palitos(struct jantar_t *jantar, int filosofo) {
    int palito_esquerdo = filosofo;
    int palito_direito = (filosofo+1) % jantar->n_filosofos;

    // A ordem varia se o filósofo for par ou ímpar
    int primeiro_palito;
    int segundo_palito;
    // Caso seja um filosofo impar
    if (filosofo % 2) {
        // Primeiro o da esquerda, depois o da direita
        primeiro_palito = palito_esquerdo;
        segundo_palito = palito_direito;
    } else {
        // Primeiro o da direita, depois o da esquerda
        primeiro_palito = palito_direito;
        segundo_palito = palito_esquerdo;
    }

    // Pegar o primeiro palito
    sem_wait(&jantar->palitos[primeiro_palito]);
    // Pegar o segundo palito
    sem_wait(&jantar->palitos[segundo_palito]);
}

// Liberar palitos, deslockando os respectivos semáforos
void jantar_soltar_palitos(struct jantar_t *jantar, int filosofo) {
    int palito_esquerdo = filosofo;
    int palito_direito = (filosofo+1) % jantar->n_filosofos;

    // Liberar os dois palitos
    sem_post(&jantar->palitos[palito_esquerdo]);
    sem_post(&jantar->palitos[palito_direito]);
}