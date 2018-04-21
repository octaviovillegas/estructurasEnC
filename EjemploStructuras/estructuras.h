#define TITULO_PROGRAMA DEFINIR_MACRO_STRING(SEGUIMIENTO DE ALUMNOS)
#define LARGO_NOMBRE_ALUMNO 50
#define CANT_ALUMNOS 5
#define LARGO_ITEM_MENU 50
#define NRO_MAX_OPCIONES_MENU 10

typedef struct
{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[LARGO_NOMBRE_ALUMNO];
    int estado;
} eAlumno;

typedef struct
{
    int cantOpciones;
    int codigos[NRO_MAX_OPCIONES_MENU];
    char descripciones[NRO_MAX_OPCIONES_MENU][LARGO_ITEM_MENU];
} eMenu;
