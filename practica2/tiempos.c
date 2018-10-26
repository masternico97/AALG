/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */

#include "tiempos.h"
#include "permutaciones.h"
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, int n_perms, int N, PTIEMPO ptiempo)
{
	int** matriz = NULL;
	int i, comprobacion, max, min;
	double counter, start_t, end_t, total_t = 0;	
	
	if(!metodo || n_perms < 1 || N < 1 || !ptiempo){
		return ERR;
	}
	
	matriz = genera_permutaciones(n_perms, N);
	if(!matriz){
		return ERR;
	}

	counter = 0;
	min=INT_MAX;
	max=INT_MIN;

	for(i=0; i<n_perms; i++){
		
		start_t = clock();
		comprobacion = metodo(matriz[i], 0, N-1);
		end_t = clock();

		if(comprobacion == ERR){
			for(i=n_perms; i>=0; i--){
				free(matriz[i]);
			}
			free(matriz);
			return ERR;
		}
		
		if(comprobacion<min){
			min=comprobacion;
		}

		if(comprobacion>max){
			max=comprobacion;
		}
		total_t += (end_t-start_t);
		counter+=comprobacion;
	}

	/*Completamos la estructura tiempo*/
	
	ptiempo->N=N;
	ptiempo->n_elems=n_perms;
	ptiempo->tiempo=(total_t/n_perms)/CLOCKS_PER_SEC;
	ptiempo-> medio_ob=counter/n_perms;
	ptiempo->min_ob=min;
	ptiempo->max_ob=max;

	/*Borramos la matriz depues de usarla*/

	for(i=0; i<n_perms; i++){
		free(matriz[i]);
	}
	free(matriz);
	
	return OK;
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*                                                 */
/* Vuestra documentacion                           */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, int num_min, int num_max, int incr, int n_perms)
{
	int i, retorno, tam;
	PTIEMPO tiempo = NULL;
	
	if(!metodo || !fichero || num_min<0 || num_max<num_min|| incr<0 || n_perms<1){
		return ERR;
	}

	/*Numero de veces que se repite tiempo_medio_ordenacion*/
	tam=((num_max-num_min)/incr)+1;

	tiempo=(PTIEMPO)malloc(tam*sizeof(TIEMPO));
	if(!tiempo){
		return ERR;
	}

	for(i=0; i<tam; i++){
		if(tiempo_medio_ordenacion(metodo, n_perms, num_min+(incr*i), &tiempo[i]) == ERR){
			free(tiempo);			
			return ERR;
		}
	}
	
	retorno=guarda_tabla_tiempos(fichero, tiempo, tam);
	free(tiempo);
	return retorno;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos)
{
	int i;
	FILE *guardado;

	if(!fichero || !tiempo || n_tiempos<1){
		return ERR;	
	}
	
	guardado=fopen(fichero, "w");

	for(i=0; i<n_tiempos; i++){
		fprintf(guardado, "%d\t%f\t%.2f\t%d\t%d\n", tiempo[i].N, tiempo[i].tiempo, tiempo[i].medio_ob, tiempo[i].min_ob, tiempo[i].max_ob);
	}
	
	fclose(guardado);

	return OK;
}


