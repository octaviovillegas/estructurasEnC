#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones_generales.h"
#include "procesamiento.h"
#include "menus.h"

/**
+para el martes 24 de abril
+1-completar las funciones faltantes con sus implementaciones
+2- hacer un menu de opciones (en el main o en funciones)
+3- Terminar el alta baja y modificacion de un alumno del listado
+*/

int main()
{
    eMenu menuPrincipal = {5,{1,2,3,4,9},{"1. Alta","2. Baja","3. Modificaciàn","4. Listar alumnos","9. Salir"}};
    eAlumno listadoAlumnos[CANT_ALUMNOS] = {};
    int opcion;
    char salirDelPrograma = 'N';

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        printf(TITULO_PROGRAMA);

        opcion = pedirOpcion(menuPrincipal);
        switch(opcion)
        {
            case 1:
                procesarAlta(listadoAlumnos);
                break;
            case 2:
                escribirEnPantalla("procesarBaja(listadoAlumnos)");
                ejecutarEnConsola(HACER_PAUSA);
                break;
            case 3:
                escribirEnPantalla("procesarModificacion(listadoAlumnos)");
                ejecutarEnConsola(HACER_PAUSA);
                break;
            case 4:
                procesarMostrarListado(listadoAlumnos);
                break;
            case 9:
                salirDelPrograma = pedirConfirmacion("Desea salir del programa?");
                break;
        }
    }
    while(salirDelPrograma == 'N');

    return 0;
}
