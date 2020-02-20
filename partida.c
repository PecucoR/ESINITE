#include "partida.h"
#define ANCH 450
#define ALT 550

/* EL TAMAÑO DEL MAPA VIENE DADO EN LA CONFIGURACION QUE LE DE EL ADMINISTRADOR DE LA PARTIDA, LOS VALORES INDICADOS ARRIBA SON UNOS DE PRUEBA */


static void dance_1(){
	int i,cont;
	//cont = 0;
	for (i=1; i < 14 ; i++){
		printf("\n");
		if(i==7){
			printf("							STANDARD DANCE!!!");
		}
	}

}


void almacenar_configuracion(conf *c){
	FILE *fil;
	char linea_completa[45],*tok;
	int cont=0;
	fil = fopen("configuracion.txt","r");
	if (fil == NULL){
		printf("Error del sistema.\n");
		exit(1);
	}
  fscanf(fil, "%[^/]/%[^/]/%[^/]/%[^/]/%[^/]/%[^/]/%[^/]/%[^/]/%[^/]", linea_completa);   /* Se lee la linea del archivo */
    char *elemento = strtok(linea_completa, "/"); 
    while(elemento != NULL)
    {
        printf("%i\n", elemento);
        elemento = strtok(NULL, "/");
        }
}

void configuracion(conf *c){
	FILE *fil;
	int c1,c2,c3,c4,c5,c6,c7,c8,c9;
	char ans;
	
	fil = fopen("configuracion.txt","w");
	if (fil == NULL){
		printf("Se ha producido un error en el sistema.\n");
		exit(1);
	}
	fprintf(fil,"\n");
	do{
		printf("Tamano maximo del mapa: ");
		scanf("%i",&c1);
		c->tam = c1;
		printf("Distancia maxima de los objetos: ");
		scanf("%i",&c2);
		c->dist_maxo = c2;
		printf("Distancia maxima para alcanzar un oponente: ");
		scanf("%i",&c3);
		c->dist_op = c3;
		printf("Monedas por defecto para cada jugador nuevo: ");
		scanf("%i",&c4);
		c->mon_def = c4;
		printf("Cantidad minima de jugadores por partida: ");
		scanf("%i",&c5);
		c->min_jug = c5;
		printf("Valor de paso de cada jugador: ");
		scanf("%i",&c6);
		c->paso_jug = c6;
		printf("Tamano de la mochila: ");
		scanf("%i",&c7);
		c->tam_moch = c7;
		printf("Numero de partidas ganadas para subir de nivel: ");
		scanf("%i",&c8);
		c->sub_niv = c8;
		printf("Numero maximo de acciones que puede realizar un jugador durante un turno: ");
		scanf("%i",&c9);
		c->acc_max = c9;
		
		printf("<< Son correctos los parametros que usted ha proporcionado? (S/N)>>\n");
		fflush(stdin);
		ans = getchar();
	}while(ans == 'n' || ans == 'N');
	
	fprintf(fil,"%i/%i/%i/%i/%i/%i/%i/%i/%i/\n",c1,c2,c3,c4,c5,c6,c7,c8,c9);
	fclose(fil);
}


static void standard_dance(){
	Beep(349,149);
	Beep(415,149);
	Beep(466,149);
	Beep(466,446);
	Beep(415,297);
	Beep(349,149);
	Beep(415,149);
	Beep(466,149);
	Beep(466,446);
	Beep(415,297);
	Beep(349,297);
	Beep(311,149);
	Beep(349,149);
	Beep(466,149);
	Beep(415,149);
	Beep(349,149);
	Beep(311,149);
	Beep(349,149);
}

static void emote(){
	int cont,n,m,w;
	cont=0;
	n= 14;
	do{
		putchar('*');
		cont++;
	}while(cont<=n);
	cont=0;
	w=n-2;
	do{
		putchar('\n');
		putchar('*');
		m=0;
		while(m<=w){
		 putchar(' ');
		 if(m == 7 && cont == 7) printf("F");
		  m++;
	    }
		putchar('*');
		putchar('\n');
		cont++;	
	}while(cont<=w);
	cont=0;
		do{
		putchar('*');
		cont++;
	}while(cont<=n);
	standard_dance();
}

static void objetos_map(char nombre){
	FILE *f;
	int posx,posy;
	
	srand(time(NULL));
	
	posx = rand()%ANCH;
	posy = rand()%ALT;
	
	if((f = fopen("mapa.txt","a")) != NULL){
		fprintf(f,"Objeto/");
		fprintf(f,"%s/",nombre);
		fprintf(f,"%i/",posx);
		fprintf(f,"%i",posy);
		fclose(f);
	}
}

static void menu_juego(char nick, int *hp, int *esc, int *x, int *y){
	int opci;
	
	/* El numero de acciones por turno viene determinado cuando usas objeto o disparas (1 accion de estas por turno) */
	
	
	/* MENU QUE USAMOS EN EL TURNO */
	printf("Estas en las coordenadas (%i,%i).\n",*x,*y);
	printf("Que desea hacer?\n"); //Arma que viene por defecto hay que añadirla
	printf("1. Usar objeto o Disparar.\n");
	printf("2. Ver o usar mochila.\n");
	printf("3. Mover jugador.\n");
	printf("4. Ver jugadores cercanos.\n");
	printf("5. Finalizar turno.\n");
	
	switch (opci){
		case 1:
			uso();
		
		case 3:
			mover(x,y);
		break;
		
		case 4:
			ver_jugadores();
		break;
		
		case 5:
			printf("Turno finalizado\n");
		break;
	}
			
}

void mover(int *x, int *y){
	int cuadrado;
	char sentido;
	
	
	printf("Introduzca los cuadrados que se pueda mover (MAXIMO 4 POR TURNO, POSITIVO DERECHA, NEGATIVO IZQUIERDA)\n");
	scanf("%i",&cuadrado);
	*x = *x + cuadrado;
	printf("Cuantos cuadrados hacia arriba?\n");
	scanf("%i",&cuadrado);
	*y = *y + cuadrado;
}


void lobby(char *nick){
	struct tm *local, *gm;
	time_t tiempo;
	FILE *f;
	int opt,cont,i;
	tiempo = time(NULL);
	local = localtime(&tiempo);
	printf(" %i / %i / %i \n", local -> tm_mday, local -> tm_mon+1, local -> tm_yday + 1948);
	
	printf("\n");
	
	printf("Esperando a que entren todos los jugadores...\n"); /*Esperando a que entren todos los jugadores*/
	
	cont = 1; //Por ahora no vamos a utilizar esta variable
	
		if ((f = fopen("mapa.txt","w")) != NULL){ //Cuando nuestro jugador se meta en partida
			fprintf(f,"\n");
			fprintf(f,"Jugador/");
			fprintf(f,"%s/",nick);
			fclose(f);
		}
		else printf("Se ha producido un error al abrir el archivo de texto.\n");
	
		printf("Esperando a que entren todos los jugadores...\n");
	
		scanf("%i",&opt);
	
	
		switch (opt){ 
			case 1: 
				system("cls");
				dance_1();
				system("pause");
				system("cls");
				printf("Esperando a que entren todos los jugadores...\n");
			break;
		
			case 2:
				system("cls");
				emote();
				printf("\n");
				system("pause");
				system("cls");
				printf("Esperando a que entren todos los jugadores...\n");
			break;
		}
}

void inicio(char nombre,int *x, int *y){
	printf("Las dimensiones del mapa son %i de ancho y %i de alto.\n",ANCH,ALT);
	printf("Introduzca en la posicion que quiere caer (Primero x y luego y) ");
	scanf("%i",x);
	scanf("%i",y);
	
	if(*x > ANCH|| *y > ALT){
		printf("Usted ha quedado eliminado por ti mismo porque has caido fuera del mapa.\n");
		/*Funcion para eliminar al jugador
		Funcion para salir al sistema*/
	}
}
/*
static void menu_juego(char *nombre, int salud, int escudo, int *x, int*y){
	int op;
	
	printf("QUE DESEAS HACER?\n");
	printf("1. Moverse lateralmente.\n");
	printf("2. Moverse verticalmente.\n");
	printf("3. Ver oponentes cercanos");
}

*/
void map(char nombre, int *salud, int *escudo){ 
	int cont,aux,initialx,initialy;
	
	inicio(nombre,&initialx,&initialy);
	
	menu_juego(nombre, salud, escudo,&initialx,&initialy);
	system("cls");
}
	
	//Funcion para guardar la posicion actual de cada jugador en el mapa en fichero 
