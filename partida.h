#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int tam;
	int dist_maxo;
	int dist_op;
	int mon_def;
	int min_jug;
	int paso_jug;
	int tam_moch;
	int sub_niv;
	int acc_max;
}conf;


void lobby(char*);
void map(char,int*,int*);
void mover(int*,int*);

#endif
