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
    printf("Intregrantes:\n>-- Facundo Franco Lastiri\n>-- Carloz Vazquez\n>-- \n\n\n");
    printf("-------------Menu Principal-------------\n\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir del programa\n");
}

void agregar(EPersona personas[CANT])
{
    printf("\nAGREGANDO\n");
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
    printf("\n\n-------------Lista de Personas-------------\n\n\n");
    for( int i = 0 ; i < CANT ; i++ ) {
        if(personas[i].estado == ACTIVO){
            printf("\n|%s|%3.d |%12.d|\n\n",
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
    printf("\n\n\nCargando....\n");
    getchar();
    system("cls");
}


void imprimirListaOrdenada(EPersona personas[CANT])
{

}
void imprimirGraficoEdades(EPersona personas[CANT])
{

}
