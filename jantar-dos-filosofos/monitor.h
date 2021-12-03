/* Jantar dos filósofos
 *
 * SSC0541 - Sistemas Operacionais I
 *
 * Gabriel Silva Fontes - 10856803
 * "Licenciado" sob domínio público (https://unlicense.org).
 *
 */

#ifndef JANTAR_DOS_FILOSOFOS_MONITOR_H
#define JANTAR_DOS_FILOSOFOS_MONITOR_H

struct jantar_t;

// Criar e alocar um jantar
struct jantar_t *jantar_inicializar(int n_filosofos);

// Destruir um jantar
void jantar_destruir(struct jantar_t *jantar);

// Pegar palitos, aguardando e lockando os respectivos semáforos
void jantar_pegar_palitos(struct jantar_t *jantar, int filosofo);

// Liberar palitos, deslockando os respectivos semáforos
void jantar_soltar_palitos(struct jantar_t *jantar, int filosofo);

#endif