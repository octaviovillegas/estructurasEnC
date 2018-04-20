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
    char salirDelPrograma = 'N';

    do
    {
        alumno = pedirAlumno();

        posicion = buscarLugarLibre(listadoAlumnos);
        if(posicion != -1)
        {
            listadoAlumnos[posicion] = alumno;
        }

        ejecutarEnConsola(LIMPIAR_PANTALLA);
        printf("\nANTES DE ORDENAR:");
        mostrarListadoAlumnos(listadoAlumnos);

        ordenarPorPromedio(listadoAlumnos);
        printf("\n\nDESPUES DE ORDENAR:");
        mostrarListadoAlumnos(listadoAlumnos);
        ejecutarEnConsola(HACER_PAUSA);

        salirDelPrograma = pedirConfirmacion("Desea salir del programa?");
    }
    while(salirDelPrograma == 'N');

    return 0;
}
