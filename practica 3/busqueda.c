/**
 *
 * Descripcion: Implementacion funciones para busqueda
 *
 * Fichero: busqueda.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 11-11-2016
 *
 */

#include "busqueda.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 *  Funciones de geracion de claves
 *
 *  Descripcion: Recibe el numero de claves que hay que generar
 *               en el parametro n_claves. Las claves generadas
 *               iran de 1 a max. Las claves se devuelven en
 *               el parametro claves que se debe reservar externamente
 *               a la funcion.
 */

/**
 *  Funcion: generador_claves_uniforme
 *               Esta fucnion genera todas las claves de 1 a max de forma
 *               secuencial. Si n_claves==max entonces se generan cada clave
 *               una unica vez.
 */
void generador_claves_uniforme(int *claves, int n_claves, int max)
{
  int i;

  for(i = 0; i < n_claves; i++) claves[i] = 1 + (i % max);

  return;
}


PDICC ini_diccionario (int tamanio, char orden)
{
  PDICC dic = NULL;

  if(tamanio < 1 || (orden != NO_ORDENADO && orden != ORDENADO)) return NULL;

  dic=(PDICC)malloc(sizeof(DICC));
  if(!dic) return NULL;

  dic->tamanio=tamanio;
  dic->orden=orden;
  dic->n_datos=0;
  dic->tabla=(int*)malloc(sizeof(int)*tamanio);

  return dic;
}

void libera_diccionario(PDICC pdicc)
{
	if(!pdicc) return;
  free(pdicc->tabla);
  free(pdicc);
}

int inserta_diccionario(PDICC pdicc, int clave)
{
  int i;
  int OB = 0 ;

  if(!pdicc || pdicc->n_datos == pdicc->tamanio) return ERR;

  pdicc->tabla[pdicc->n_datos]=clave;

  if(pdicc->orden==ORDENADO){
    i=pdicc->n_datos-1;
    while (i >= 0 && pdicc->tabla[i]>clave){
      pdicc->tabla[i+1]=pdicc->tabla[i];
      i--;
      OB++;
    }
    pdicc->tabla[i+1]=clave;
  }
  pdicc->n_datos++;
  return OB;
}

int insercion_masiva_diccionario (PDICC pdicc,int *claves, int n_claves)
{
  int i, comprobacion;
  int OB = 0;

	if(!pdicc || !claves || n_claves==0) return ERR;

  for(i=0; i<n_claves; i++){
    comprobacion=inserta_diccionario(pdicc, claves[i]);
    if(comprobacion == ERR) return ERR;
    OB+=comprobacion;
  }
  return OB;
}

int busca_diccionario(PDICC pdicc, int clave, int *ppos, pfunc_busqueda metodo)
{
  int OB;
  if(!pdicc || !ppos || !metodo) return ERR;
  OB = metodo(pdicc->tabla,0,(pdicc->n_datos)-1,clave,ppos);
  return OB;
}


/* Funciones de busqueda del TAD Diccionario */
int bbin(int *tabla,int P,int U,int clave,int *ppos)
{
  int OB = 0;

  if(!tabla || P>U || !ppos) return ERR;

  while(P<=U){
    *ppos = (U+P)/2;
    OB++;

    if(clave == tabla[*ppos]){
      (*ppos)++;
      return OB;
    }

    else if(clave < tabla[*ppos]){
      U = (*ppos)-1;
    }
    else{
      P = (*ppos)+1;
    }
  }
  return ERR;
}

int blin(int *tabla,int P,int U,int clave,int *ppos)
{
  int OB = 1;

  if(!tabla || P>U || !ppos) return ERR;

  *ppos = 0;
  while(clave != tabla[(*ppos)] && (*ppos)<=U){
    OB++;
    (*ppos)++;
  }

  if((*ppos)>U) return ERR;
  (*ppos)++;
  return OB;
}
