#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

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
            printf("TODO LOS ESPACIOS FUERON COMPLETADOS \n");
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
    getchar();
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
                EPersona aux[1];
                //init(aux);

                aux[0] = personas[j];
                personas[j] = personas[j+1];
                personas[j+1] = aux[0];
            }

        }

    }
    //MOSTRAR LISTA ORDENADA
    printf("\n Personas ordenadas por nombre\n");
    mostrar(personas);
}

void imprimirGraficoEdades(EPersona personas[CANT])
{

}


int buscarPor(EPersona personas[CANT])
{
    int opcion = 0;
    int dato;
    char nombre[25];
    int posi = -1;

    do{
        printf("\n¿ Que que tipo de dato sea buscar ?\n\n");
        printf("\n - [ 1 ] Nombre y Apellido \n");
        printf("\n - [ 2 ] DNI \n");
        printf("\n - [ 3 ] EDAD \n");
        scanf("%d",&opcion);
        if(opcion!=4){printf("\n Ingrese el dato.  ");}
        switch(opcion)
        {
            case 1 : getchar();gets(nombre);break;
            case 2 : scanf("%d",&dato);break;
            case 3 : scanf("%d",&dato);break;
        }

      for(int i = 0 ; i<CANT ; i++)
        {
            if(opcion == 1 && strcmp(personas[i].nombre,nombre) == 0 && personas[i].estado == ACTIVO)
                {
                    posi = i;
                    opcion = 4 ;

                }
            if(opcion == 2 && personas[i].dni == dato && personas[i].estado == ACTIVO)
                {
                    posi = i;
                    opcion = 4 ;

                }
            if(opcion == 3 && personas[i].edad == dato && personas[i].estado == ACTIVO)
                {
                    posi = i;
                    opcion = 4 ;

                }
            else{opcion=4;}
        }

        }while(opcion!=4);
return(posi);
}

void borrarPersona(EPersona personas[CANT])
{
int posi = 0;
posi = buscarPor(personas);
borrado();
if( posi != -1)
    {
        personas[posi].estado = BORRADO;
        printf("\n Dato Encontrado y Eliminado con Exito \n");

    }
else
    {
        printf("\n [ERROR] Dato no Encontrado \n");
    }

    getchar();
    system("cls");

}
