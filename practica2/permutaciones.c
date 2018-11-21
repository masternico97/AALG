/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "permutaciones.h"
#include <stdlib.h>

/***************************************************/
/* Funcion: aleat_num Fecha: 21-9-2018             */
/* Autores: Miguel Luque y Nicolás Serrano        */
/*                                                 */
/* Rutina que intercambia dos números             */
/*                                                 */
/* Entrada:                                        */
/* int* a: primer número                          */
/* int* b: segundo número                         */
/***************************************************/
void swap(int* a, int* b) {
    int tmp;

    if (a && b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

/***************************************************/
/* Funcion: aleat_num Fecha: 21-9-2018             */
/* Autores: Miguel Luque y Nicolás Serrano        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup) {
    if (sup < inf) {
        return ERR;
    }

    return (int) (inf + (double) rand() / (RAND_MAX + 1.0)*(sup - inf + 1));

}

/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int N) {
    int* perm = NULL;
    int i;

    if (N < 1) {
        return NULL;
    }

    perm = (int*) malloc(N * sizeof (int));
    if (perm == NULL) {
        return NULL;
    }

    for (i = 1; i <= N; i++) {
        perm[i - 1] = i;
    }

    for (i = 1; i <= N; i++) {
        swap(&perm[i - 1], &perm[aleat_num(i - 1, N - 1)]);
    }

    return (perm);
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N) {
    int** matriz = NULL;
    int i;

    if (n_perms < 1 || N < 1) {
        return NULL;
    }

    matriz = (int**) malloc(n_perms * sizeof (int*));
    if (!matriz) {
        return NULL;
    }

    for (i = 0; i < n_perms; i++) {
        matriz[i] = genera_perm(N);
        if (!matriz[i]) {
            for (i = i - 1; i >= 0; i--) {
                free(matriz[i]);
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}
