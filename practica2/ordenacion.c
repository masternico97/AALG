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
/* Funcion: maximo    Fecha:28/09/2018             */
/* Vuestro comentario: esta función busca el       */
/*elemento más grande y devuelve la posición de    */
/*la tabla en la que se sitúa                      */
/***************************************************/

int maximo(int *tabla, int ip, int iu){
  int i;
  int val = ip;

  if((!tabla)||(ip<0)||(iu<ip)){
    return ERR;
  }

  for(i = ip;i < iu;i++){
    if(tabla[i+1]>tabla[val]){/*operación básica*/
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

/***************************************************/
/* Funcion: SelectSortInv    Fecha:28/09/2018      */
/* Vuestro comentario: esta función busca el       */
/*elemento más grande y lo coloca en la primera    */
/*posición, acortando la tabla en cada ejecución   */
/*para colocar el elemento mas grande exclullendo  */
/*las casillas ya ordenadas de la tabla            */
/***************************************************/

int SelectSortInv(int* tabla, int ip, int iu)
{
  int i,max,sum = 0;
  if((!tabla)||(ip<0)||(iu<ip)){
    return ERR;
  }

  for(i = ip;i < iu;i++){
    max = maximo(tabla, i, iu);
    if(max == ERR){
    return ERR;
    }
    sum += iu-i;
    swap(&tabla[i], &tabla[max]);
  }
  return sum;
}

int merge(int* tabla, int ip, int iu, int imedio){
  int i = ip;
  int j = imedio+1;
  int k = 0;
  int op = 0;
  int* taux = NULL;
  if((!tabla)||(ip<0)||(iu<ip)||(imedio>iu)||(imedio<ip)){
    return ERR;
  }
  if(ip==iu){
    return 0;
  }
  taux = (int*)malloc((iu-ip+1)*sizeof(int));
  if(!taux){
    return ERR;
  }
  while(i<=imedio && j<=iu){
    op++;
    if(tabla[i]<tabla[j]){
      taux[k]=tabla[i];
      i++;
    }else{
      taux[k]=tabla[j];
      j++;
    }
    k++;
  }
  if(i>imedio){
    while(j<=iu){
      taux[k]=tabla[j];
      j++;
      k++;
    }
  }else if(j>iu){
    while(i<=imedio){
      taux[k]=tabla[i];
      i++;
      k++;
    }
  }
  for(i=ip,k=0;i<=iu;i++,k++){
    tabla[i]=taux[k];
  }
  free(taux);
  return op;
}


int MergeSort(int* tabla, int ip, int iu){
  int M;
  if((!tabla)||(ip<0)||(iu<ip)){
    return ERR;
  }
  if(ip==iu){
    return 0;
  }
  else{
  M=(ip+iu)/2;
  return MergeSort(tabla,ip,M)+MergeSort(tabla,M+1,iu)+merge(tabla,ip,iu,M);
  }
}


/***************************************************/
/* Funcion: medio    Fecha:26/10/2018   	         */
/* Vuestro comentario: 			                       */
/***************************************************/


int medio(int *tabla, int ip, int iu, int *pos){

	if(!tabla || ip < 0 || iu < ip || !pos){
		return ERR;
	}

	*pos = ip;
	return OK;
}


/***************************************************/
/* Funcion: partir    Fecha:26/10/2018   	         */
/* Vuestro comentario: 			                       */
/***************************************************/


int partir(int* tabla, int ip, int iu,int *pos){

	int OB, pivote, i;

	if(!tabla || ip < 0 || iu < ip || !pos){
		return ERR;
	}

	OB=medio(tabla, ip, iu, pos);
	if(OB==ERR){
		return ERR;	
	}

	pivote=tabla[*pos];

	swap(&tabla[ip], &tabla[*pos]);
	*pos=ip;

	for(i=ip+1; i<=iu; i++){
		OB++;
		if(tabla[i]<pivote){
			(*pos)++;	
			swap(&tabla[i], &tabla[*pos]);	
		}
	}
	swap(&tabla[ip], &tabla[*pos]);
	return OB;
}

/***************************************************/
/* Funcion: QuickSort    Fecha:26/10/2018          */
/* Vuestro comentario: esta función busca el       */
/*elemento más grande y lo coloca en la primera    */
/*posición, acortando la tabla en cada ejecución   */
/*para colocar el elemento mas grande exclullendo  */
/*las casillas ya ordenadas de la tabla            */
/***************************************************/

int QuickSort(int* tabla, int ip, int iu){
	int OB, pos, comprobacion;	

	if(!tabla || ip < 0 || iu < ip){
		return ERR;
	}
	
	if(ip==iu){
		return 0;
	}

	OB=partir(tabla ,ip ,iu ,&pos);
	if(OB==ERR){
		return ERR;
	}

	if(ip<pos-1){
		comprobacion=QuickSort(tabla, ip, pos-1);
		if(comprobacion==ERR){
			return ERR;
		}
		OB+=comprobacion;
	}

	if(pos+1<iu){
		comprobacion=QuickSort(tabla, pos+1, iu);
		if(comprobacion==ERR){
			return ERR;
		}
		OB+=comprobacion;
	}
	return OB;
}
/***************************************************/
/* Funcion: QuickSort_src    Fecha:02/11/2018          */
/* Vuestro comentario: esta función busca el       */
/*elemento más grande y lo coloca en la primera    */
/*posición, acortando la tabla en cada ejecución   */
/*para colocar el elemento mas grande exclullendo  */
/*las casillas ya ordenadas de la tabla            */
/***************************************************/
int QuickSort_src(int* tabla, int ip, int iu){
	int OB, i, pos, comprobacion;
	int* array = NULL;
	OB = 0;	
	i = 0;

	if(!tabla || ip < 0 || iu < ip){
		return ERR;
	}
	
	if(ip==iu){
		return 0;
	}


	array =(int*)malloc((iu-ip+1)*sizeof(int));
	if(!array)return ERR;

	OB=partir(tabla ,ip ,iu ,&pos);
	if(OB==ERR){
		return ERR;
	}

	array[i] = iu;
	i++;
	while(ip<(pos-1)){
		if(!tabla || ip < 0 || iu < ip){
			return ERR;
		}
	
		if(ip==iu){
			OB += 0;
		}
		iu = pos-1;
		OB+=partir(tabla ,ip ,iu ,&pos);
		array[i] = iu;
		i++;
	}
	while((pos+1)<iu){
		if(!tabla || ip < 0 || iu < ip){
			return ERR;
		}
	
		if(ip==iu){
			OB += 0;
		}
		ip = pos+1;
		OB+=partir(tabla ,ip ,iu ,&pos);
		iu = array[i-1];
		i--;
		pos = iu+1;
	}
	free(array);
	if(OB < 0)return ERR;
	return OB;
}
