#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

///definicion de colores
#define COLOR_NEGRO 0
#define COLOR_AZUL 1
#define COLOR_VERDE 2
#define COLOR_CELESTE 3
#define COLOR_ROJO 4
#define COLOR_BLANCO 15

void init(EPersona personas[CANT])
{
    for(int i = 0 ; i<CANT ; i++ )
    {
        strcpy(personas[i].nombre,"");
        personas[i].edad = 0 ;
        personas[i].dni = 0 ;
        personas[i].estado = VACIO;
    }
}

void menu(){
    printf("-------------Trabajo Practico N-2------------- \n");
    printf("Intregrantes:\n>-- Facundo Franco Lastiri\n>-- Carloz Vazquez\n>-- Aaron Espindola\n>-- Adrian Catacora\n\n\n");
    printf("-------------Menu Principal-------------\n\n");
    printf("1- Agregar personas\n");
    printf("2- Borrar persona por DNI\n");
    printf("3- Ordenar por nombre e imprimir lista\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Imprimir lista\n");
    printf("6- Salir del programa\n");
}

void agregar(EPersona personas[CANT])
{
    printf("\n --- FUNCION DE AGREGANDO --- \n");
    for(int i = 0 ; i < CANT ; i++ ){
        if( personas[i].estado == VACIO ){
            printf("----------NUEVO----------\n");
            printf(" >-- Nombre : ");
            getchar();
            gets(personas[i].nombre);
            printf(" >-- Edad : ");
            scanf("%d",&personas[i].edad);
            printf(" >-- D.N.I : ");
            scanf("%d",&personas[i].dni);
            personas[i].estado = ACTIVO;
        }else{
            printf("Lugar [%d] Ocupado  \n",i+1);
        }
    }
    borrado();
}

void mostrar(EPersona personas[CANT])
{
    printf("\n\n-------------Lista de Personas-------------\n\n");
    for( int i = 0 ; i < CANT ; i++ ) {
        if(personas[i].estado == ACTIVO){
            printf("\n|Nombre: %s | Edad: %3.d | DNI: %12.d|\n",
               personas[i].nombre,
               personas[i].edad,
               personas[i].dni);
        }
    }
    borrado();
}

void borrado(void)
{
    //getchar();
    printf("\n\n\nPresione una tecla para continuar...\n");
    getchar();
    system("cls");
}


void imprimirListaOrdenada(EPersona personas[CANT])
{
    //MOSTRAR LISTA
    printf("\n Personas base\n");
    //mostrar(personas);
    //FUNCION ORDENAR LISTA
    for (int i = 0; i < CANT; i++){
        for (int j = 0; j < CANT-1; j++){
            if( strcmp(personas[j].nombre,personas[j+1].nombre) >=0 )
            {
                EPersona aux;
                //init(aux);

                aux = personas[j];
                personas[j] = personas[j+1];
                personas[j+1] = aux;
            }

        }

    }
    //MOSTRAR LISTA ORDENADA
    printf("\n Personas ordenadas por nombre\n");
    mostrar(personas);
}

void imprimirGraficoEdades(EPersona personas[CANT]) {

    int cantidadMenores = 0;
    int cantidadAdultos = 0;
    int cantidadMayores = 0;

    for( int i = 0 ; i < CANT ; i++ ) {
        if(personas[i].estado == ACTIVO){
            if(personas[i].edad <= 18) {
                cantidadMenores++;
            } else if(personas[i].edad > 18 && personas[i].edad <= 35) {
                cantidadAdultos++;
            } else if(personas[i].edad > 35) {
                cantidadMayores++;
            }
        }
    }

    system("cls");
    printf("\n\n                                  GRAFICO DE EDADES \n\n");
    printf("             %c  \n", 94);
    printf("  Cantidad   %c  \n", 179);
    printf("     de      %c  \n", 179);
    printf("  personas   %c  \n", 179);
    printf("             %c     %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c     %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c \n", 179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,62);
    printf("                 Menores de 18      De 19 a 35       Mayores de 35        ");

    borrado();

}


int buscarPor(EPersona personas[CANT])
{
    int opcion = 0;
    int dato;
    char nombre[25];
    int posi = -1;


        printf("\n¿ Que que tipo de dato sea buscar ?\n\n");
        printf("\n - [ 1 ] Nombre y Apellido \n");
        printf("\n - [ 2 ] DNI \n");
        printf("\n - [ 3 ] EDAD \n");
        do{
            scanf("%d",&opcion);
        }while(opcion != 1  && opcion != 2 && opcion != 3 );

        if(opcion!=4){printf("\n Ingrese el dato.  ");}
        switch(opcion)
        {
            case 1 : getchar();gets(nombre);break;
            case 2 : scanf("%d",&dato);break;
            case 3 : scanf("%d",&dato);break;
        }
        //

        printf("dato obtenido %d  %d   %s",dato,dato,nombre);

      for(int i = 0 ; i < CANT ; i++ )
        {
            if(opcion == 1 && (strcmp(personas[i].nombre,nombre) == 0 )&& personas[i].estado == ACTIVO)
                {
                    posi = i;
                    break;

                }
            if(opcion == 2 && personas[i].dni == dato && personas[i].estado == ACTIVO )
                {
                    posi = i;
                    break;

                }
            if(opcion == 3 && personas[i].edad == dato && personas[i].estado == ACTIVO )
                {
                    posi = i;
                    break;

                }
        }
    return(posi);
}

void borrarPersona(EPersona personas[CANT])
{
    int posi = 0;
    posi = buscarPor(personas);
    borrado();
    if( posi != -1)
    {
        personas[posi].estado = VACIO;
        printf("\n Dato Encontrado y Eliminado con Exito \n");

    }
    else
    {
        printf("\n [ERROR] Dato no Encontrado \n");
    }

    getchar();
    system("cls");

}

void setColor(int background, int text){
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 int ncolor = text + (background * 16);
 SetConsoleTextAttribute(console, ncolor);
}
