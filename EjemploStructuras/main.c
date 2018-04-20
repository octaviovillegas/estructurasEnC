#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones_generales.h"
#include "procesamiento.h"


int main()
{
    eAlumno listadoAlumnos[CANT_ALUMNOS] = {};
    eAlumno alumno;
    int posicion;

    alumno = pedirAlumno();

    posicion = buscarLugarLibre(listadoAlumnos);
    if(posicion != -1)
    {
        listadoAlumnos[posicion] = alumno;
    }

    mostrarListadoAlumnos(listadoAlumnos);

    ejecutarEnConsola(HACER_PAUSA);

    return 0;
}
