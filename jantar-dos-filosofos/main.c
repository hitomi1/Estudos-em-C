/* Jantar dos filósofos
 *
 * SSC0541 - Sistemas Operacionais I
 *
 * Gabriel Silva Fontes - 10856803
 * "Licenciado" sob domínio público (https://unlicense.org).
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "monitor.h"

// Quantos filosofos usaremos
#define N_FILOSOFOS 7

// Estrutura representando um filósofo (argumentos passados pra uma thread)
// Temos que agrupar, pois só é possível passar 1 ponteiro em pthread_create.
struct filosofo_t {
    int numero;
    struct jantar_t *jantar;
};

// Função com o comportamento de um filosofo
// Essa função precisa ter retorno e input void *, pois é a assinatura
// pedida por 'pthread_create'.
//
// Essa função utiliza a API do monitor criada em monitor.c
void *filosofo_thread(void *input) {
    // Castar input
    struct filosofo_t *filosofo = input;

    // Aguardar e pegar os palitos
    jantar_pegar_palitos(filosofo->jantar, filosofo->numero);

    // Comer macarrão
    printf("O filósofo %d começou a comer\n", filosofo->numero);
    sleep(2);
    printf("O filósofo %d terminou de comer\n", filosofo->numero);

    // Devolver os palitos
    jantar_soltar_palitos(filosofo->jantar, filosofo->numero);

    free(filosofo);
    return NULL;
}



int main() {
    // Inicializar monitor
    struct jantar_t *jantar = jantar_inicializar(N_FILOSOFOS);
    if (!jantar) {
        printf("Não foi possível criar o jantar\n");
        return 1;
    }

    // Threads para cada um dos filósofos
    pthread_t threads[N_FILOSOFOS];
    for (int i = 0; i < N_FILOSOFOS; i++) {
        // Criar estrutura representando filósofo
        struct filosofo_t *filosofo = malloc(sizeof(struct filosofo_t));
        // Com seu número
        filosofo->numero = i;
        // E um ponteiro pro jantar
        filosofo->jantar = jantar;

        // Iniciar a thread
        pthread_create(&threads[i], NULL, filosofo_thread, filosofo);
    }

    // Unir e aguardar as threads
    for (int i = 0; i < N_FILOSOFOS; i++) {
        pthread_join(threads[i], NULL);
    }

    jantar_destruir(jantar);

    return 0;
}