#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones_generales.h"
#include "procesamiento.h"


int main()
{
    //eAlumno listadoAlumnos[CANT_ALUMNOS];
    eAlumno alumno;

    alumno = pedirAlumno();

    mostrarAlumno(alumno);

    ejecutarEnConsola(HACER_PAUSA);

    return 0;
}
