#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tienda.h"
#include "partida.h"

void inicio_sesion();

int main(){

    int n;
        system("cls");

        puts("Bienvenido a Esinite");
        puts("----------------------------------");
        sound();
        puts("Seleccione una opcion:");
        puts("1. Inicio de sesion.\n");
        puts("2. Salir del programa.\n");

        scanf("%i",&n);

        system("cls");

       if (n == 1){
       		menu_principal(); /* Se abre el menu principal */
	   }
	   
	   return 0;
}

void sound(){
	Beep(349,149);
	Sleep(149);
	Beep(415,149);
	Sleep(149);
	Beep(466,149);
	Sleep(149);
	Beep(466,446);
	Sleep(446);
	Beep(415,297);
	Sleep(1485);
	Beep(349,149);
	Sleep(149);
	Beep(415,149);
	Sleep(149);
	Beep(466,149);
	Sleep(149);
	Beep(466,446);
	Sleep(446);
	Beep(415,297);
	Sleep(297);
	Beep(349,297);
	Sleep(297);
	Beep(311,149);
	Sleep(149);
	Beep(349,149);
	Sleep(595);
	Beep(466,149);
	Sleep(149);
	Beep(415,149);
	Sleep(149);
	Beep(349,149);
	system("pause");
}

void menu_principal(){
	int n = 0;
	
 	while(n!=5){

        system("cls");

        puts("MENU INICIO");
        puts("------------------------------");
        puts("Seleccione una opcion:");
        puts("1. Configuracion");
        puts("2. Iniciar Juego");
        puts("3. Tienda");
        puts("4. Perfil");
        puts("5. Salir del programa");

        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                puts("CONFIGURACION");
                puts("---------------");
    			configura();
                system("pause");
                break;

            case 2:
                puts("INICIAR JUEGO");
                puts("-------------------");
                mapa();
                system("pause");
                break;

            case 3:
                puts("\n----------------------TIENDA---------------------\n");
                menu_tienda();
                puts("\n---------------------------------------------------------\n");
                system("pause");
                break;

            case 4:
                puts("PERFIL");
                puts("------------------");
                menu_jugadores();
                system("pause");
                break;

            case 5:break;
        }

    }

    guardar();
    

}	
}

/*
void inicio_sesion(){


	FILE *f;
	char user[20], psswrd[10];
	int i;
	
	printf ("Introducir usuario: ");
	fflush(stdin);
	fgets(user, 20, stdin);
	//swap(user);
	
	printf("Introducir contraseña: ");
	fflush(stdin);
	fgets(psswrd, 10, stdin);
	//swap(psswrd);
	
	for(i=0; user[i] != '\n';i++){
		if((user[i] != '\n' && i == 19)){ 
			printf("No se permiten introducir mas caracteres, por favor introduzca de nuevo el usuario.\n");
		}
	}
	
	for(i=0; psswrd[i] != '\n';i++){
		if(psswrd[i] != '\n' && i == 9){
			printf("No se permiten introducir mas caracteres, por favor introduzca de nuevo la contrasena.\n");
		}
	}
	
	f = fopen("usuario.txt","r");
	
	if (f == NULL){
		printf("No se ha podido abrir el fichero.\n");
		exit(1);
	}
	
	
	
	
	
   

    

    system("pause");
*/
    while(n!=5){

        system("cls");

        puts("MENU INICIO");
        puts("------------------------------");
        puts("Seleccione una opcion:");
        puts("1. Configuracion");
        puts("2. Iniciar Juego");
        puts("3. Tienda");
        puts("4. Perfil");
        puts("5. Salir del programa");

        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                puts("CONFIGURACION");
                puts("---------------");
                //FUNCION CONFIGURACIÓN
                system("pause");
                break;

            case 2:
                puts("INICIAR JUEGO");
                puts("-------------------");
                //FUNCION JUEGO
                system("pause");
                break;

            case 3:
                puts("\n----------------------TIENDA---------------------\n");
                //FUNCION TIENDA
                puts("\n---------------------------------------------------------\n");
                system("pause");
                break;

            case 5:
                break;
        }

    }

    guardar();
    

}
