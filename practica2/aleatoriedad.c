#include <stdio.h>
#include <stdlib.h>
#include "permutaciones.h"

#define TAM 10
	int main(){

	FILE *file;
	int i, valores[TAM];

	file=fopen("aleatoriedad.txt","w");
	if(!file){
		return -1;	
	}
	
	for(i=0;i<10; i++){
		valores[i]=0;
	}

	for(i=0; i<1000000; i++){
		valores[aleat_num(1, 10)-1]++;	
	}

	for(i=0; i<10; i++){
		fprintf(file,"%d\t%d\n",(i+1), valores[i]);
	}
	
	fclose(file);
	
	return 0;	
}
