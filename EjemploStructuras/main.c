#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones_generales.h"
#include "procesamiento.h"
#include "menus.h"

int main()
{
    eMenu menuPrincipal = {
                            5, //cantidad de opciones
                            {1,2,3,4,9}, //codigos
                            {"1. Alta","2. Baja","3. ModificaciÓn","4. Listar alumnos","9. Salir"}, //descripciones
                            {"+--------------------+\n| GESTION DE ALUMNOS |\n+--------------------+"} //titulo del menu
                           };
    eAlumno listadoAlumnos[CANT_ALUMNOS] = {};
    int opcion;
    char salirDelPrograma = 'N';

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);

        opcion = pedirOpcion(menuPrincipal);
        switch(opcion)
        {
            case 1:
                procesarAlta(listadoAlumnos);
                break;
            case 2:
                procesarBaja(listadoAlumnos);
                break;
            case 3:
                procesarModificacion(listadoAlumnos);
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
