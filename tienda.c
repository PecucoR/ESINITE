#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tienda.h"

void menu_tienda(){
	objeto *ob;
	int tot,moneda,opc;
	ob = cargar_objeto(&tot);
	
	printf("Le regalamos 200 monedas!\n");
	moneda  = 200;
	
	printf("Que deseas realizar? \n");
	printf("1. Registrar objeto\n");
	printf("2. Acceder a la tienda.\n");
	scanf("%i",&opc);
	switch(opc){
		case 1:
			registro_objeto(ob,&tot);
		break;
		
		case 2:
			tienda(st,tot,&moneda);
		break;
	}
}



objeto cargar_objeto(int total){
	objeto st[TAM_VEC];
	int cont=0;
	char cad[255],*tok,aux;
	FILE *f;
	
	f = fopen("objetos.txt","r");
	if (f==NULL){
		printf("No se han podido cargar los objetos.\n");
	}

	while(!feof(f)){
		fgets(cad,255,f);
		printf("%s",cad);
		tok = strtok(cad,"/"); /* Asi dividimos la cadena por trozos */
		strcpy(st[cont].code,tok);
		printf("%s\n",st[cont].code);
		tok = strtok(NULL,"/");
		strcpy(st[cont].nombre,tok);
		tok = strtok(NULL,"/");
		strcpy(st[cont].tipo,tok);
		printf("Funciono %s\n",st[cont].tipo);
		tok = strtok(NULL,"/");
		st[cont].coste = atoi(tok);
		tok = strtok(NULL,"/");
		st[cont].alc = atoi(tok);
		tok = strtok(NULL,"/");
		cont++;
		memset(cad,'\0',255);
	}
	
	fclose(f);
	printf("Se han cargado %i objetos.\n",cont+1);
	return st;
}




void registro_objeto(objeto *objetos, int *numobj){
	char *cad1,*cad2,*cad3,ans;
	int cad4,cad5,cad6;
	FILE *fich;
	
	fich = fopen("objetos.txt","a"); /* Abrimos el fichero de modo que añada al final los datos */
	if (fich == NULL){
		printf("Error al intentar abrir el fichero.\n");
		exit(1);
	}
	do{
		objetos = (objeto*)realloc(objetos, *(numobj+1)*sizeof(objeto));
		if (objetos == NULL){
			printf("Error\n");
			 exit(1);	
		}
		printf("Introduce el codigo (6 caracteres): ");
		cad1 = (char*)malloc(ID_OBJETO+1*sizeof(char));
		fflush(stdin);
		fgets(cad1,ID_OBJETO+1,stdin);
		printf("Introduce el nombre (8 caracteres): ");
		fflush(stdin);
		cad2 = (char*)malloc(NOMBRE_OBJETO+1*sizeof(char));
		fgets(cad2,NOMBRE_OBJETO+1,stdin);
		printf("Introduce el tipo de objeto (ARM,ACC,SKI): ");
		cad3 = (char*)malloc(TIPO_OBJETO+1*sizeof(char));
		fflush(stdin);
		fgets(cad3,TIPO_OBJETO+1,stdin);
		printf("Introduzca el coste del objeto: ");
		scanf("%i",&cad4);
		if(strcmp(cad3,"ARM") == 0){ /* Si cad3 == ARM*/
			printf("Introduzca el alcance del arma: ");
			scanf("%i",&cad5);
			printf("Introduzca el porcentaje de dano: ");
			scanf("%i",&cad6);
		}
		else if (strcmp(cad3,"ACC") == 0){ /* Si cad3 == ACC */
			cad5 = 0;
			printf("Introduzca el porcentaje de cura/escudo: ");
			scanf("%i",&cad6);
		}
		else if (strcmp(cad3,"SKI") == 0){ /* Si cad3 == SKI*/
			cad5 = 0;
			cad6 = 0;
		}
		
		/* Pasamos lo que hemos introducido por teclado a la estructura */
		
		objetos[*numobj].code = cad1;
		objetos[*numobj].nombre = cad2;
		objetos[*numobj].tipo = cad3;
		objetos[*numobj].coste = cad4;
		objetos[*numobj].alc = cad5;
		objetos[*numobj].porc = cad6;
		
		
		fprintf(fich,"%*s/%*s/%*s/%i/%i/%i/\n",ID_OBJETO,cad1,NOMBRE_OBJETO,cad2,TIPO_OBJETO,cad3,cad4,cad5,cad6); /*Escribimos lo que hemos registrado dentro del fichero*/
		
		system("pause");
		
		/* Liberamos cad1,cad2 y cad3 para evitar que se colapse la memoria*/
		free(cad1);
		free(cad2);
		free(cad3);
		*numobj = *numobj + 1; /*Sumamos un objeto mas por si queremos añadir más*/
		
		printf("Deseas introducir otro objeto mas? (S/N)\n");
		fflush(stdin);
		ans = getchar();
		
	}while(ans == 's' || ans == 'S');
	
	fclose(fich);
}




void tienda(objeto *st, int total,int *dinero){
	int i=0,opc;
	char ch;
	
	printf("<< Bienvenido a la tienda de Esinait >>\n");
	printf("<<Estos son los objetos disponibles en nuestra tienda: >>\n");
	while (i<numobj){
		printf("%i) NOMBRE:%-*s        PRECIO: %i.\n",i,st[i].nombre,st[i].coste);
		i++;
	}
	printf("<< Deseas comprar algun objeto disponible? >>\n");
	fflush(stdin);
	ch = getchar();
	if (ch == 's' || ch == 'S'){
		printf("<< Que objeto es el que deseas compar? (S/N)>>\n");
		scanf("%i",&opc);
		for(i=0;i<total;i++){
			if (opc == i){
				if (strcmp(st[i].tipo,"ARM") == 0 || strcmp(st[i].tipo,"ACC") == 0){
					printf("<< Que cantidad va a comprar? >>\n");
					scanf("%i",&cant);
				}
				else cant = 1;
				if ((*dinero = *dinero - cant * st[i].coste) < 0) printf("<< No tienes suficiente dinero para comprar este objeto >>\n");
				else{
					printf("<< Deseas confirmar la compra del objeto %s ? (S/N)>>",st[i].nombre);
					fflush(stdin);
					ch = getchar();
					if (ch == 's' || ch == 'S'){
						*dinero = *dinero - cant * st[i].coste;
						meter_mochila(st[i].codigo,cant);
						printf("<< COMPRA REALIZADA CON EXITO, CREDITOS RESTANTES : %i >>\n",*dinero);
					}
				}
			}
		}
	}
	
}

void meter_mochila(objeto o, int cant){
	mochila mo;
	FILE *f;
	f = fopen("mochila.txt","a");
	if (f==NULL){
		printf("Error desconocido del sistema.\n");
	}
	else{
		fprintf(f,"%-*s/%-*s/%i/\n",nick,o.code,cant);
		fclose(f);
	}
}


