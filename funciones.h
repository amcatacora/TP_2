#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



//defino las variables de la estructura
typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;


}EPersona;
///
void init(EPersona personas[CANT])
{
    for(int i = 0 ; i<CANT ; i++ )
        {
    strcpy(personas[i].nombre,"");
    personas[i].edad = 0 ;
    personas[i].dni = 0 ;
    personas[i].estado = VACIO ;

        }
}

void Menu(){
        printf("-------------Trabajo Practico N-2------------- \n");
        printf("Intregrantes:\n>-- Facundo Franco Lastiri\n>-- Carloz Vazquez\n>-- \n\n\n");
        printf("-------------Menu Principal-------------\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
}

void Agregar(EPersona personas[CANT])
{
    printf("AGREGANDO\n");
    for(int i = 0 ; i < CANT ; i++ ){
        if( personas[i].estado == VACIO )
            {
                    printf("----------NUEVO----------\n");
                    printf(" >-- Nombre : ");
                    getchar();
                    gets(personas[i].nombre);
                    printf(" >-- Edad : ");
                    scanf("%d",&personas[i].edad);
                    printf(" >-- D.N.I : ");
                    scanf("%d",&personas[i].dni);
                    personas[i].estado = ACTIVO;
            }else{printf("TODO LOS ESPACIOS FUERON COMPLETADOS \n");}
    }
    Borrado();
}
void Mostrar(EPersona personas[CANT])
{
    printf("-------------Lista de Personas-------------\n");
    for( int i = 0 ; i < CANT ; i++ )
    {
        if(personas[i].estado == ACTIVO)
        {
            printf("|%s|%3.d |%12.d|\n",
                   personas[i].nombre,
                   personas[i].edad,
                   personas[i].dni);
        }
    }
    Borrado();
}

void Borrado(void)
{
 getchar();
 printf("Cargando....\n");
 getchar();
 system("cls");

}

#endif // FUNCIONES_H_INCLUDED
