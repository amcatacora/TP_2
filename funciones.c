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
#define COLOR_GRIS 8
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

void borrarTodos(EPersona personas[CANT]) {
    init(personas);
    printf("\n\nLos datos fueron borrados con exito!");
    borrado();
}

void initPersonas(EPersona personas[CANT])
{
    strcpy(personas[0].nombre, "Carlos Rodriguez");
    personas[0].edad = 15;
    personas[0].dni = 123;
    personas[0].estado = ACTIVO;

    strcpy(personas[1].nombre, "Hector Moron");
    personas[1].edad = 45;
    personas[1].dni = 456;
    personas[1].estado = ACTIVO;

    strcpy(personas[2].nombre, "Luis Perez");
    personas[2].edad = 65;
    personas[2].dni = 789;
    personas[2].estado = ACTIVO;

    strcpy(personas[3].nombre, "Agustin Lopez");
    personas[3].edad = 12;
    personas[3].dni = 123;
    personas[3].estado = ACTIVO;

    strcpy(personas[4].nombre, "Fernando Herrero");
    personas[4].edad = 33;
    personas[4].dni = 111;
    personas[4].estado = ACTIVO;

    printf("\n\nLos datos fueron cargados con exito!");
    borrado();
}

void menu(){
    printf("------------- Trabajo Practico Nro 2 ------------- \n");
    printf("Intregrantes:\n>-- Facundo Franco Lastiri\n>-- Carloz Vazquez\n>-- Aaron Espindola\n>-- Adrian Catacora\n\n");
    printf("------------- Menu Principal -------------\n\n");
    printf("1- Agregar personas\n");
    printf("2- Borrar persona\n");
    printf("3- Ordenar por nombre e imprimir lista\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Imprimir lista\n");
    printf("6- Cargar datos de prueba\n");
    printf("7- Borrar todos los datos\n");
    printf("8- Salir del programa\n");
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
            printf("\n|Nombre: %20s | Edad: %3.d | DNI: %12.d|\n",
               personas[i].nombre,
               personas[i].edad,
               personas[i].dni);
        }
    }
    borrado();
}

void borrado()
{
    //getchar();
    printf("\n\nPresione una tecla para continuar...\n");
    getchar();
    system("cls");
}


void imprimirListaOrdenada(EPersona personas[CANT])
{
    //MOSTRAR LISTA
    printf("\n Personas base\n");
    //FUNCION ORDENAR LISTA
    for (int i = 0; i < CANT; i++){
        for (int j = 0; j < CANT-1; j++){
            if( strcmp(personas[j].nombre,personas[j+1].nombre) >=0 )
            {
                EPersona aux;
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

    //calcula porcentajes en matriz de 20x3
    int graficoDatos[20][3];
    for(int i=0; i<20; i++) {
        if(i < cantidadMenores) {
            graficoDatos[i][0] = 1;
        } else {
            graficoDatos[i][0] = 0;
        }
        if(i < cantidadAdultos) {
            graficoDatos[i][1] = 1;
        } else {
            graficoDatos[i][1] = 0;
        }
        if(i < cantidadMayores) {
            graficoDatos[i][2] = 1;
        } else {
            graficoDatos[i][2] = 0;
        }
    }

    system("cls");
    printf("\n\n                                  GRAFICO DE EDADES \n\n");
    printf("              %c", 94);

    //imprime valores de matriz
    for(int i=19; i>=0; i--) {
        printLineValue(i+1, graficoDatos[i][0], graficoDatos[i][1], graficoDatos[i][2], COLOR_AZUL, COLOR_VERDE, COLOR_ROJO);
    }

    printf("\n              %c",192);
    printChar(196, 62);
    printf("%c \n",62);
    printf("                  Menores de 18      De 19 a 35       Mayores de 35");

    borrado();
}
void printLineValue(int line, int col1, int col2, int col3, int color1, int color2, int color3) {
    switch(line) {
        case 20: printf("\n  Cantidad  %2d%c", line, 179); break;
        case 19: printf("\n     de     %2d%c", line, 179); break;
        case 18: printf("\n  personas  %2d%c", line, 179); break;
        default: printf("\n            %2d%c", line, 179); break;
    }

    initSpace();
    printValue(col1, color1);
    printValue(col2, color2);
    printValue(col3, color3);
}
void printChar(char c, int a) {
    for(int i=0;i<a;i++) {
        printf("%c", c);
    }
}
void initSpace(){
    setColor(COLOR_NEGRO, COLOR_GRIS);
    printChar(95, 5);
    setColor(COLOR_NEGRO, COLOR_BLANCO);
}
void printValue(int v, int color) {
    if(v == 1) {
        setColor(COLOR_NEGRO, color);
        printf("%c%c%c%c%c%c%c%c", 219,219,219,219,219,219,219,219);
        setColor(COLOR_NEGRO, COLOR_GRIS);
        printChar(95, 10);
        setColor(COLOR_NEGRO, COLOR_BLANCO);
    } else {
        setColor(COLOR_NEGRO, COLOR_GRIS);
        printChar(95, 18);
        setColor(COLOR_NEGRO, COLOR_BLANCO);
    }
}
void printSpaces(int c) {
    for(int i=0; i<c; i++) {
        printf(" ");
    }
}

int buscarPor(EPersona personas[CANT])
{
    int opcion = 0;
    int dato;
    char nombre[25];
    int posi = -1;

    printf("\n Que que tipo de dato sea buscar?\n\n");
    printf("\n - [ 1 ] Nombre y Apellido \n");
    printf("\n - [ 2 ] DNI \n");
    printf("\n - [ 3 ] EDAD \n");
    do{
        scanf("%d",&opcion);
    }while(opcion != 1  && opcion != 2 && opcion != 3 );

    if(opcion!=4){printf("\n Ingrese el dato:");}
    switch(opcion){
        case 1 : getchar();gets(nombre);break;
        case 2 : scanf("%d",&dato);break;
        case 3 : scanf("%d",&dato);break;
    }

    printf("Dato obtenido: %d %d %s",dato,dato,nombre);

    for(int i = 0 ; i < CANT ; i++ ){
        if(opcion == 1 && (strcmp(personas[i].nombre,nombre) == 0 )&& personas[i].estado == ACTIVO){
            posi = i;
            break;
        }
        if(opcion == 2 && personas[i].dni == dato && personas[i].estado == ACTIVO ){
            posi = i;
            break;
        }
        if(opcion == 3 && personas[i].edad == dato && personas[i].estado == ACTIVO ){
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
