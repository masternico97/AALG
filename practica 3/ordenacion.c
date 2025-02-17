/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Miguel Luque
 * Version: 1.1
 * Fecha: 28-09-2018
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "permutaciones.h"
#include "ordenacion.h"
/****************************************************/
/* Funcion: minimo    Fecha:28/09/2018              */
/* Vuestro comentario: esta función busca el       */
/*elemento más pequeño y devuelve la posición de */
/*la tabla en la que se sitúa                      */
/****************************************************/

int minimo(int *tabla, int ip, int iu) {
    int i;
    int val = ip;

    if ((!tabla) || (ip < 0) || (iu < ip)) {
        return ERR;
    }

    for (i = ip; i < iu; i++) {
        if (tabla[i + 1] < tabla[val]) {/*operación básica*/
            val = i + 1;
        }

    }
    return (val);
}

/****************************************************/
/* Funcion: maximo    Fecha:28/09/2018              */
/* Vuestro comentario: esta función busca el       */
/*elemento más grande y devuelve la posición de   */
/*la tabla en la que se sitúa                      */
/****************************************************/

int maximo(int *tabla, int ip, int iu) {
    int i;
    int val = ip;

    if ((!tabla) || (ip < 0) || (iu < ip)) {
        return ERR;
    }

    for (i = ip; i < iu; i++) {
        if (tabla[i + 1] > tabla[val]) {
            val = i + 1;
        }

    }
    return (val);
}
/****************************************************/
/* Funcion: SelectSort    Fecha:28/09/2018          */
/* Vuestro comentario: esta función busca el       */
/*elemento más pequeño y lo coloca en la primera  */
/*posición, acortando la tabla en cada ejecución  */
/*para colocar el elemento mas pequeño exclullendo */
/*las casillas ya ordenadas de la tabla             */
/****************************************************/

int SelectSort(int *tabla, int ip, int iu) {
    int i, min, sum = 0;
    if ((!tabla) || (ip < 0) || (iu < ip)) {
        return ERR;
    }

    for (i = ip; i < iu; i++) {
        min = minimo(tabla, i, iu);
        if (min == ERR) {
            return ERR;
        }
        sum += iu - i;
        swap(&tabla[i], &tabla[min]);
    }
    return sum;
}

/***************************************************/
/* Funcion: SelectSortInv    Fecha:28/09/2018      */
/* Vuestro comentario: esta función busca el      */
/*elemento más grande y lo coloca en la primera   */
/*posición, acortando la tabla en cada ejecución */
/*para colocar el elemento mas grande exclullendo  */
/*las casillas ya ordenadas de la tabla            */
/***************************************************/

int SelectSortInv(int* tabla, int ip, int iu) {
    int i, max, sum = 0;
    if ((!tabla) || (ip < 0) || (iu < ip)) {
        return ERR;
    }

    for (i = ip; i < iu; i++) {
        max = maximo(tabla, i, iu);
        if (max == ERR) {
            return ERR;
        }
        sum += iu - i;
        swap(&tabla[i], &tabla[max]);
    }
    return sum;
}


/***************************************************/
/* Funcion: merge    Fecha:26/10/2018              */
/* Vuestro comentario: 			           */
/***************************************************/

int merge(int* tabla, int ip, int iu, int imedio) {
    int i = ip;
    int j = imedio + 1;
    int k = 0;
    int op = 0;
    int* taux = NULL;
    if ((!tabla) || (ip < 0) || (iu < ip) || (imedio > iu) || (imedio < ip)) {
        return ERR;
    }
    if (ip == iu) {
        return 0;
    }
    taux = (int*) malloc((iu - ip + 1) * sizeof (int));
    if (!taux) {
        return ERR;
    }
    while (i <= imedio && j <= iu) {
        op++;
        if (tabla[i] < tabla[j]) {
            taux[k] = tabla[i];
            i++;
        } else {
            taux[k] = tabla[j];
            j++;
        }
        k++;
    }
    if (i > imedio) {
        while (j <= iu) {
            taux[k] = tabla[j];
            j++;
            k++;
        }
    } else if (j > iu) {
        while (i <= imedio) {
            taux[k] = tabla[i];
            i++;
            k++;
        }
    }
    for (i = ip, k = 0; i <= iu; i++, k++) {
        tabla[i] = taux[k];
    }
    free(taux);
    return op;
}


/***************************************************/
/* Funcion: MergeSort    Fecha:26/10/2018          */
/* Vuestro comentario: 			           */

/***************************************************/


int MergeSort(int* tabla, int ip, int iu) {
    int M;
    int comprobacion1, comprobacion2, comprobacion3;
    if ((!tabla) || (ip < 0) || (iu < ip)) {
        return ERR;
    }
    if (ip == iu) {
        return 0;
    } else {
        M = (ip + iu) / 2;
	comprobacion1 = MergeSort(tabla, ip, M);
	comprobacion2 = MergeSort(tabla, M + 1, iu);
	comprobacion3 = merge(tabla, ip, iu, M);
	if(comprobacion1 == ERR || comprobacion2 == ERR || comprobacion3 == ERR) return ERR;
        return comprobacion1 + comprobacion2 + comprobacion3;
    }
}


/***************************************************/
/* Funcion: medio    Fecha:26/10/2018   	   */
/* Vuestro comentario:		                   */
/***************************************************/


int medio(int *tabla, int ip, int iu, int *pos) {

    if (!tabla || ip < 0 || iu < ip || !pos) {
        return ERR;
    }

    *pos = ip;
    return OK;
}


/***************************************************/
/* Funcion: partir    Fecha:26/10/2018   	   */
/* Vuestro comentario: 			           */
/***************************************************/


int partir(int* tabla, int ip, int iu, int *pos) {

    int OB, pivote, i;

    if (!tabla || ip < 0 || iu < ip || !pos) {
        return ERR;
    }

    OB = medio(tabla, ip, iu, pos);
    if (OB == ERR) {
        return ERR;
    }

    pivote = tabla[*pos];

    swap(&tabla[ip], &tabla[*pos]);
    *pos = ip;

    for (i = ip + 1; i <= iu; i++) {
        OB++;
        if (tabla[i] < pivote) {
            (*pos)++;
            swap(&tabla[i], &tabla[*pos]);
        }
    }
    swap(&tabla[ip], &tabla[*pos]);
    return OB;
}

/***************************************************/
/* Funcion: QuickSort    Fecha:26/10/2018          */
/* Vuestro comentario: 			           */

/***************************************************/

int QuickSort(int* tabla, int ip, int iu) {
    int OB, pos, comprobacion;

    if (!tabla || ip < 0 || iu < ip) {
        return ERR;
    }

    if (ip == iu) {
        return 0;
    }

    OB = partir(tabla, ip, iu, &pos);
    if (OB == ERR) {
        return ERR;
    }

    if (ip < pos - 1) {
        comprobacion = QuickSort(tabla, ip, pos - 1);
        if (comprobacion == ERR) {
            return ERR;
        }
        OB += comprobacion;
    }

    if (pos + 1 < iu) {
        comprobacion = QuickSort(tabla, pos + 1, iu);
        if (comprobacion == ERR) {
            return ERR;
        }
        OB += comprobacion;
    }
    return OB;
}

/***************************************************/
/* Funcion: QuickSort_src    Fecha:02/11/2018      */
/* Vuestro comentario: 			           */
/***************************************************/
int QuickSort_src(int* tabla, int ip, int iu) {
    int OB, pos, comprobacion;

    if (!tabla || ip < 0 || iu < ip) {
        return ERR;
    }

    if (ip == iu) {
        return 0;
    }

    OB = partir(tabla, ip, iu, &pos);
    if (OB == ERR) {
        return ERR;
    }

    if (ip < pos - 1) {
        comprobacion = QuickSort_src(tabla, ip, pos - 1);
        if (comprobacion == ERR) {
            return ERR;
        }
        OB += comprobacion;
    }

    while (pos + 1 < iu) {
        ip = pos + 1;
        if (!tabla || ip < 0 || iu < ip) {
            return ERR;
        }
        if (ip == iu) {
            return OB;
        }
        comprobacion = partir(tabla, ip, iu, &pos);
        if (ip < pos - 1) {
            comprobacion += QuickSort_src(tabla, ip, pos - 1);
        }
        if (comprobacion == ERR) {
            return ERR;
        }
        OB += comprobacion;
    }
    return OB;
}
