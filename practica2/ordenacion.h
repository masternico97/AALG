/**
 *
 * Descripcion: Funciones de cabecera para ordenacion 
 *
 * Fichero: ordenacion.h
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */

#ifndef ORDENACION_H
#define ORDENACION_H

/* constantes */

#define ERR -1
#define OK (!(ERR))

/* definiciones de tipos */
typedef int (* pfunc_ordena)(int*, int, int);

/* Funciones */

int SelectSort(int* tabla, int ip, int iu);
int SelectSortInv(int* tabla, int ip, int iu);
int MergeSort(int* tabla, int ip, int iu);
int QuickSort(int* tabla, int ip, int iu);
int QuickSort_src(int* tabla, int ip, int iu);


#endif
