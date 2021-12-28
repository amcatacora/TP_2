#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define CANT 20
#define VACIO 0
#define ACTIVO 1

typedef struct {
    char nombre[50];
    int edad;
    int dni;
    int estado;
} EPersona;


void init(EPersona personas[CANT]);
void initPersonas(EPersona personas[CANT]);
void borrarTodos(EPersona personas[CANT]);
void menu();
void agregar(EPersona personas[CANT]);
void mostrar(EPersona personas[CANT]);
void borrarPersona(EPersona personas[CANT]);
void borrado(void);
void imprimirListaOrdenada(EPersona personas[CANT]);
void imprimirGraficoEdades(EPersona personas[CANT]);
void imprimirMensaje(char titulo[]);
void imprimirTitulo(char titulo[]);
void imprimirError(char titulo[]);
void borrarTodos(EPersona personas[CANT]);
void mostrarGrilla(EPersona personas[CANT]);
void setColor(int background, int text);
void printLineValue(int line, int col1, int col2, int col3, int color1, int color2, int color3);
void printChar(char c, int a);
void initSpace();
void printValue(int v, int color);
void printChar(char c, int a);
void gotoxy(int x, int y);

#endif // FUNCIONES_H_INCLUDED
