#include <stdio.h>
#include <stdlib.h>


#include "funciones.h"

int main()
{
    //EPersona personas[CANT];
    //init(personas);

    int opcion = 0;


    EPersona personas[CANT] = {{.nombre = "Pepe Wachon",.edad = 19,.dni = 40572157,.estado = ACTIVO},{.nombre = "Alexis Ybañez",.edad = 25,.dni = 40452157,.estado = ACTIVO},{.nombre = "Belen Acosta",.edad = 22,.dni = 39572157,.estado = ACTIVO},{.nombre = "Juan Roman Riquelme",.edad = 43,.dni = 23572157,.estado = ACTIVO},{.nombre = "Zsorro",.edad = 100,.dni = 20072157,.estado = ACTIVO},};


    do{
        menu();
        scanf("%d",&opcion);
        switch(opcion){
            case 1 : agregar(personas); break;
            case 2 : borrarPersona(personas); break;
            case 3 : imprimirListaOrdenada(personas); break;
            case 4 : imprimirGraficoEdades(personas); break;
            case 6 : mostrar(personas);break;
        }

    }while(opcion != 5);
}
