#include <stdio.h>
#include <stdlib.h>
#define CANT 1
#define VACIO 0
#define ACTIVO 1
#define BORRADO 2
#include "funciones.h"
//llamado ?
void Menu();

int main()
{
    EPersona personas[CANT];
    init(personas);
    int opcion = 0;

    do{
        Menu();
        scanf("%d",&opcion);
        switch(opcion){
            case 1 : Agregar(personas); break;
            case 2 : Mostrar(personas); break;

        }




    }while(opcion != 6);



}
