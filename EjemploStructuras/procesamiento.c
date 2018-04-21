#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones_generales.h"

void mostrarAlumno(const eAlumno alumno)
{
    printf("\nLegajo: %4d | %-20s | nota1: %d | nota2: %d | promedio: %.2f", alumno.legajo, alumno.nombre, alumno.nota1, alumno.nota2, alumno.promedio);
}

void mostrarListadoAlumnos(const eAlumno listadoAlumnos[])
{
    int i;

    for(i=0 ; i<CANT_ALUMNOS ; i++)
    {
        if(listadoAlumnos[i].estado == 1)
        {
            mostrarAlumno(listadoAlumnos[i]);
        }
    }
}

eAlumno pedirAlumno()
{
    eAlumno retorno;

    retorno.legajo = pedirInt("\nIngrese legajo:");

    pedirString(&(*retorno.nombre), "Ingrese nombre:");

    retorno.nota1 = pedirInt("Ingrese nota1:");

    retorno.nota2 = pedirInt("Ingrese nota2:");

    retorno.promedio = calcularPromedio(retorno.nota1, retorno.nota2);

    retorno.estado = 1;

    return retorno;
}

int buscarLugarLibre(eAlumno listadoAlumnos[])
{
    int retorno = -1;
    int i;

    for(i=0 ; i<CANT_ALUMNOS ; i++)
    {
        if(listadoAlumnos[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int buscarAlumno(eAlumno alumnoBuscar, eAlumno listadoAlumnos[])
{
    int retorno = -1;
    int i;

    for(i=0 ; i<CANT_ALUMNOS ; i++)
    {
        if(listadoAlumnos[i].legajo == alumnoBuscar.legajo)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void ordenarPorPromedio(eAlumno listadoAlumnos[])
{
    int i;
    int j;
    eAlumno aux;

    for(i=0 ; i<CANT_ALUMNOS-1 ; i++)
    {
        for(j=i+1 ; j<CANT_ALUMNOS ; j++)
        {
            if(listadoAlumnos[i].promedio < listadoAlumnos[j].promedio)
            {
                aux = listadoAlumnos[i];
                listadoAlumnos[i] = listadoAlumnos[j];
                listadoAlumnos[j] = aux;
            }
        }
    }

}

void procesarAlta(eAlumno listadoAlumnos[])
{
    eAlumno alumno;
    char confirmacion;
    int posicion;

    posicion = buscarLugarLibre(listadoAlumnos);
    if(posicion != -1)
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        escribirEnPantalla("+----------------+\n| ALTA DE ALUMNO |\n+----------------+");
        alumno = pedirAlumno();
        mostrarAlumno(alumno);

        confirmacion = pedirConfirmacion("Confirma que los datos ingresados son correctos?");

        if(confirmacion == 'S')
        {
            listadoAlumnos[posicion] = alumno;
            ordenarPorPromedio(listadoAlumnos);
            escribirEnPantalla("\nEl alumno se dio de alta.");
        }
        else
        {
            escribirEnPantalla("\nSe cancelà la gestiàn.");
        }
    }
    else
    {
        escribirEnPantalla("\nNo hay m s lugares disponibles para altas de alumnos.");
    }
    ejecutarEnConsola(HACER_PAUSA);
}

void procesarMostrarListado(eAlumno listadoAlumnos[])
{
    ejecutarEnConsola(LIMPIAR_PANTALLA);
    escribirEnPantalla("+--------------------+\n| LISTADO DE ALUMNOS |\n+--------------------+");
    mostrarListadoAlumnos(listadoAlumnos);
    ejecutarEnConsola(HACER_PAUSA);
}
