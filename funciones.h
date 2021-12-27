#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define CANT 5
#define VACIO 0
#define ACTIVO 1

typedef struct {
    char nombre[50];
    int edad;
    int dni;
    int estado;
} EPersona;


void init(EPersona personas[CANT]);
void menu();
void agregar(EPersona personas[CANT]);
void mostrar(EPersona personas[CANT]);
void borrarPersona(EPersona personas[CANT]);
void borrado(void);
void imprimirListaOrdenada(EPersona personas[CANT]);
void imprimirGraficoEdades(EPersona personas[CANT]);
void setColor(int background, int text);

#endif // FUNCIONES_H_INCLUDED
