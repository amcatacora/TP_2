#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
   //EPersona personas[CANT];
   // init(personas);

    int opcion = 0;



 EPersona personas[CANT] = {{.nombre = "Pepe Wachon",.edad = 19,.dni = 123,.estado = ACTIVO},{.nombre = "Alexis Ybañez",.edad = 25,.dni = 40452157,.estado = ACTIVO},{.nombre = "Belen Acosta",.edad = 22,.dni = 39572157,.estado = ACTIVO},{.nombre = "Juan Roman Riquelme",.edad = 43,.dni = 23572157,.estado = ACTIVO},{.nombre = "Zsorro",.edad = 100,.dni = 20072157,.estado = ACTIVO},};



    do{
        menu();
        opcion = getch();
        switch(opcion){
            case 49 : agregar(personas); break;
            case 50 : borrarPersona(personas); break;
            case 51 : imprimirListaOrdenada(personas); break;
            case 52 : imprimirGraficoEdades(personas); break;
            case 53 : mostrar(personas);break;
        }

    }while(opcion != 54);
}
