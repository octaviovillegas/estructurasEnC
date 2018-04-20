#define LARGO_NOMBRE_ALUMNO 50

typedef struct
{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[LARGO_NOMBRE_ALUMNO];
    int estado;
} eAlumno;
