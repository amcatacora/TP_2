#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    EPersona personas[CANT];
    init(personas);
    int opcion = 0;


    do{
        menu();
        scanf("%d",&opcion);
        switch(opcion){
            case 1 : agregar(personas); break;
            case 2 : borrarPersona(personas); break;
            case 3 : mostrar(personas); break;
            case 4 : imprimirGraficoEdades(personas); break;
        }
    }while(opcion != 5);
}
