#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"

///definicion de colores
#define COLOR_NEGRO 0
#define COLOR_AZUL 1
#define COLOR_VERDE 2
#define COLOR_VERDE_CLARO 10
#define COLOR_CELESTE 3
#define COLOR_ROJO 4
#define COLOR_GRIS 8
#define COLOR_BLANCO 15
#define COLOR_VIOLETA 5
#define COLOR_AMARILLO 14

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
    printf("\n");
    imprimirMensaje("Los datos fueron borrados con exito.");
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

    printf("\n");
    imprimirMensaje("Los datos fueron cargados con exito.");
    borrado();
}

void menu(){

    setColor(COLOR_NEGRO, COLOR_AZUL);
    printChar(220, 102);
    printf("\n");
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("                                       TRABAJO PRACTICO N%c2", 248);
    printChar(32, 43);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_AZUL);
    printChar(223, 102);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_BLANCO);

    printf("  Intregrantes\n  %c Facundo Franco Lastiri\n  %c Carloz Vazquez\n  %c Aaron Espindola\n  %c Adrian Catacora\n",175,175,175,175);

    imprimirTitulo("Menu Principal");
    printf("  1- Agregar personas\n");
    printf("  2- Borrar persona\n");
    printf("  3- Ordenar por nombre e imprimir lista\n");
    printf("  4- Imprimir grafico de edades\n");
    printf("  5- Imprimir lista\n");
    printf("  6- Cargar datos de prueba\n");
    printf("  7- Borrar todos los datos\n");
    printf("  8- Salir del programa\n");
}

void agregar(EPersona personas[CANT])
{
    for(int i = 0 ; i < CANT ; i++ ){
        system("cls");
        printf("\n");
        imprimirTitulo("Agregar personas");

        if( personas[i].estado == VACIO ){

            // imprimir subtitulo
            printf(" ");
            setColor(COLOR_NEGRO, COLOR_AZUL);
            printChar(220, 40);
            printf("\n ");
            setColor(COLOR_AZUL, COLOR_BLANCO);
            printf(" %c  Nueva persona #%d                    \n", 175, i+1);
            setColor(COLOR_NEGRO, COLOR_AZUL);
            printf(" ");
            printChar(223, 40);
            printf("\n");
            setColor(COLOR_NEGRO, COLOR_BLANCO);

            printf("  ->  Nombre: ");
            gets(personas[i].nombre);
            printf("  ->  Edad: ");
            scanf("%d",&personas[i].edad);
            printf("  ->  DNI: ");
            scanf("%d",&personas[i].dni);
            personas[i].estado = ACTIVO;
            for( int c = getchar(); c != EOF && c != ' ' && c != '\n' ; c = getchar());
            imprimirMensaje("La persona fue agregada con exito.");
            if(i+1 < CANT) {
                borrado();
            }
        }else{
            //printf("Lugar [%d] Ocupado  \n",i+1);
            char titulo[30];
            sprintf(titulo, "Lugar #%d ocupado", i+1);
            imprimirError(titulo);
            if(i+1 < CANT) {
                borrado();
            }
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

void imprimirTitulo(char titulo[]) {
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_VERDE);
    printChar(220, 102);
    printf("\n");
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf(" %c  %-89s", 175, titulo);
    printChar(32, 9);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_VERDE);
    printChar(223, 102);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
}

void imprimirMensaje(char titulo[]) {
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_VERDE_CLARO);
    printChar(220, 102);
    printf("\n");
    setColor(COLOR_VERDE_CLARO, COLOR_BLANCO);
    printf(" <%c>  %-89s", 33, titulo);
    printChar(32, 7);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_VERDE_CLARO);
    printChar(223, 102);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
}

void imprimirError(char titulo[]) {
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_ROJO);
    printChar(220, 102);
    printf("\n");
    setColor(COLOR_ROJO, COLOR_BLANCO);
    printf(" <%c>  %-89s", 158, titulo);
    printChar(32, 7);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_ROJO);
    printChar(223, 102);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
}

void mostrarGrilla(EPersona personas[CANT])
{
    system("cls");
    imprimirTitulo("Listado de personas");

    printChar(218, 1);
    printChar(196, 50);
    printChar(194, 1);
    printChar(196, 29);
    printChar(194, 1);
    printChar(196, 19);
    printChar(191, 1);
    printf("\n");

    printChar(179, 1);
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%-50s", "  NOMBRE");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
    printChar(179, 1);
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%-29s", "              DNI");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
    printChar(179, 1);
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%-19s", "       EDAD");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
    printChar(179, 1);
    printf("\n");

    printChar(195, 1);
    printChar(196, 50);
    printChar(197, 1);
    printChar(196, 29);
    printChar(197, 1);
    printChar(196, 19);
    printChar(180, 1);
    printf("\n");


    for( int i = 0 ; i < CANT ; i++ ) {
        if(personas[i].estado == ACTIVO){
            printf("%c%-50s%c%-29d%c%-19d%c\n",179,
               personas[i].nombre,179,
               personas[i].dni,179,
               personas[i].edad,179);
            if(i+1 < CANT) {
                printChar(195, 1);
                printChar(196, 50);
                printChar(197, 1);
                printChar(196, 29);
                printChar(197, 1);
                printChar(196, 19);
                printChar(180, 1);
                printf("\n");
            }
        }
    }

    printChar(192, 1);
    printChar(196, 50);
    printChar(193, 1);
    printChar(196, 29);
    printChar(193, 1);
    printChar(196, 19);
    printChar(217, 1);
    printf("\n");

    borrado();
}

void borrado()
{
    setColor(COLOR_NEGRO, COLOR_GRIS);
    printf("\n Presione una tecla para continuar...");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
    getchar();
    system("cls");
}


void imprimirListaOrdenada(EPersona personas[CANT])
{
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
    mostrarGrilla(personas);
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
    imprimirTitulo("GRAFICO DE EDADES");
    printf("              %c", 94);

    //imprime valores de matriz
    for(int i=19; i>=0; i--) {
        printLineValue(i+1, graficoDatos[i][0], graficoDatos[i][1], graficoDatos[i][2], COLOR_AZUL, COLOR_VERDE, COLOR_ROJO);
    }

    printf("\n              %c",192);
    printChar(196, 62);
    printf("%c \n",62);
    printf("                  Menores de 18      De 19 a 35       Mayores de 35\n\n");

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

    system("cls");
    printf("\n");
    char titulo[30];
    sprintf(titulo, "%cQue que tipo de dato desea buscar?", 168);
    imprimirTitulo(titulo);
    printf("\n");

    printf("- [ 1 ] Nombre y Apellido \n");
    printf("- [ 2 ] DNI \n");
    printf("- [ 3 ] Edad \n");
    do{
        opcion = getch();
    }while(opcion != 49  && opcion != 50 && opcion != 51);

    switch(opcion){
        case 49 : printf("\n Ingrese el nombre: "); getchar();gets(nombre);break;// tecla 1
        case 50 : printf("\n Ingrese el DNI: "); scanf("%d",&dato);break;// tecla 2
        case 51 : printf("\n Ingrese la edad: "); scanf("%d",&dato);break;// tecla 3
    }

    //printf("Dato obtenido: %d %d %s",dato,dato,nombre);

    for(int i = 0 ; i < CANT ; i++ ){
        if(opcion == 49 && (strcmp(personas[i].nombre,nombre) == 0 )&& personas[i].estado == ACTIVO){
            posi = i;
            break;
        }
        if(opcion == 50 && personas[i].dni == dato && personas[i].estado == ACTIVO ){
            posi = i;
            break;
        }
        if(opcion == 51 && personas[i].edad == dato && personas[i].estado == ACTIVO ){
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

    if( posi != -1) {
        personas[posi].estado = VACIO;
        printf("\n");
        imprimirMensaje("Dato encontrado y eliminado con exito.");
        printf("\n");

    } else {
        printf("\n");
        imprimirError("Dato no encontrado.");
        printf("\n");
    }

    borrado();
}

void setColor(int background, int text){
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 int ncolor = text + (background * 16);
 SetConsoleTextAttribute(console, ncolor);
}
