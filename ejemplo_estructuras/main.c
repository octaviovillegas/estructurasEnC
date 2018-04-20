#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    int legajo;
    int notaUno;
    int notaDos;
    float promedio;
    char nombre[50];
    int estado;
    int i;

    eAlumnno listadoDelMain[TAM];

    for(i=0; i<TAM ;i++)
    {
        listadoDelMain[i].estado=0;
    }//esto sirve para buscar el lugar libre



}eAlumnos;

void pedirAlumno ();

int main()
{
    eAlumnos listadoDeAlumos;

    listadoDeAlumos.legajo;
    listadoDeAlumos.notaUno;
    listadoDeAlumos.notaDos;
    listadoDeAlumos.promedio;
    listadoDeAlumos.nombre;
    listadoDeAlumos.estado;


    modificarAlumno()
    {

    }

    borrarAlumno()
    {

    }



    return 0;
}

void mostrarAlumnos(eAlumnos listadoDeAlumos[])
{

}

void mostrarUnAlumno(alumno)
{
    printf()
}

odenarPorPromedio(eAlumnos listadoDeAlumos[])
{

}


int buscarLugarLibre (eAlumnos listadoDeAlumos[], int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if (listado[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarAlumno (eAlumnos listadoDeAlumos[], alumno)
{

}

alumno pedirAlumno (void)
{
    eAlumnos alumno;

    printf("Ingrese legajo: ");
    fflush(stdin);
    scanf("%d", &alumno.legajo);
    printf("\nIngrese nombre: ");
    gets(alumno.nombre);
    printf("\nIngrese nota: ");
    scanf("%d", &alumno.notaUno);
    printf("Ingrese segunda nota: ");
    scanf("%d", &alumno.notaDos);

    return alumno;
}

float calcularPromedio(int notaUno, int notaDos)
{
    promedio= ((notaUno + notaDos)/2.0);

    return promedio;
}

int insertarEnLaLista(eAlumnos listadoDeAlumos[], indice, alumno)
{

}
