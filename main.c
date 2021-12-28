#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    EPersona personas[CANT];
    init(personas);

    int opcion = 0;

    do{
        menu();
        opcion = getch();
        switch(opcion){
            case 49 : agregar(personas); break;// tecla 1
            case 50 : borrarPersona(personas); break;//tecla 2
            case 51 : imprimirListaOrdenada(personas); break;//tecla 3
            case 52 : imprimirGraficoEdades(personas); break;//tecla 4
            case 53 : mostrar(personas);break;//tecla 5
            case 54 : initPersonas(personas);break;//tecla 6
            case 55 : borrarTodos(personas);break;//tecla 7
        }

    }while(opcion != 56);//salir 8
}
