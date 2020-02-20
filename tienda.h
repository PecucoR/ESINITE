#ifndef _TIENDA_H_
#define _TIENDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


/* Constantes de OBJETOS.TXT */
#define TAM_VEC 20
#define ID_OBJETO 6
#define NOMBRE_OBJETO 8
#define TIPO_OBJETO 3

/* Estructura de OBJETOS.TXT */

typedef struct{
	char code[6]; /* 6 caracteres */
	char nombre[8]; /* 8 caracteres*/
	char tipo[3]; /* ARM = Arma, ACC = Accesorio, SKI = Skin */
	int coste;
	int alc;
	int porc;
}objeto;

/* Estructura de MOCHILA.TXT */

typedef struct{
	char *nick;
	char *code;
	int cant;
}mochila; //Esta dentro de la estructura jugador

/* FUNCIONES QUE UTILIZAMOS */

void registro_objeto(objeto *objetos, int *numobj);
/*CABECERA: void registro_objeto(objeto*, int*) */
/*PRECONDICION: Que la estructura tenga el numero de objetos a introducir */
/*POSTCONDICION: Almacena los objetos registrados por el administrador en un fichero*/
int almacenob(objeto **ob,int *total);
/*CABECERA: objeto *almacenob(int*) */
/*PRECONDICION: Estructura objetos ya definida.*/
/*POSTCONDICION: Almacena todos los objetos que estan dentro del fichero en el vector de la estructura. */
void tienda(objeto *st, int total,int *dinero);

#endif
