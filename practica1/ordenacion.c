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

#include "permutaciones.h"
#include "ordenacion.h"
/***************************************************/
/* Funcion: minimo    Fecha:28/09/2018             */
/* Vuestro comentario: esta función busca el       */
/*elemento más pequeño y devuelve la posición de   */
/*la tabla en la que se sitúa                      */
/***************************************************/
int minimo(int *tabla, int ip, int iu){
  int i;
  int val = ip;

  if((!tabla)||(ip<0)||(iu<ip)){
    return ERR;
  }

  for(i = ip;i < iu;i++){
    if(tabla[i+1]<tabla[val]){/*operación básica*/
      val = i+1;
    }

  }
return(val);
}
/***************************************************/
/* Funcion: SelectSort    Fecha:28/09/2018         */
/* Vuestro comentario: esta función busca el       */
/*elemento más pequeño y lo coloca en la primera   */
/*posición, acortando la tabla en cada ejecución   */
/*para colocar el elemento mas pequeño exclullendo */
/*las casillas ya ordenadas de la tabla            */
/***************************************************/
int SelectSort(int *tabla, int ip, int iu){
  int i,min,sum = 0;
  if((!tabla)||(ip<0)||(iu<ip)){
    return ERR;
  }

  for(i = ip;i < iu;i++){
    min = minimo(tabla, i, iu);
    if(min == ERR){
    return ERR;
    }
    sum += iu-i;
    swap(&tabla[i], &tabla[min]);
  }
  return sum;
}

int SelectSortInv(int* tabla, int ip, int iu)
{
  /* vuestro codigo */
}


