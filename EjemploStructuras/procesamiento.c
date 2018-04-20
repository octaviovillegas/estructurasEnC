#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones_generales.h"

void mostrarAlumno(const eAlumno alumno)
{
    printf("\nLegajo: %d - %s - nota1: %d - nota2: %d - promedio: %.2f", alumno.legajo, alumno.nombre, alumno.nota1, alumno.nota2, alumno.promedio);
}

eAlumno pedirAlumno()
{
    eAlumno retorno;

    ejecutarEnConsola(LIMPIAR_PANTALLA);

    retorno.legajo = pedirInt("\nIngrese legajo:");

    pedirString(&(*retorno.nombre), "\nIngrese nombre:");

    retorno.nota1 = pedirInt("\nIngrese nota1:");

    retorno.nota2 = pedirInt("\nIngrese nota2:");

    retorno.promedio = calcularPromedio(retorno.nota1, retorno.nota2);

    return retorno;
}

int buscarLugarLibre(eAlumno listadoAlumnos[])
{
    int retorno = -1;
    int i;

    for(i=0 ; i<CANT_ALUMNOS ; i++)
    {
        if(listadoAlumnos[i].legajo == 0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
