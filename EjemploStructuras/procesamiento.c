#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones_generales.h"
#include "menus.h"

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

int pedirLegajo()
{
    //por ahora retorna el entero
    //luego puede agregarse validacion
    int retorno;
    retorno = pedirInt("\nIngrese legajo: ");
    return retorno;
}

int pedirNota(const int nroDeNota)
{
    //por ahora retorna el entero
    //luego puede agregarse validacion
    int retorno;

    if(nroDeNota == 1)
    {
        retorno = pedirInt("Ingrese nota 1: ");
    }
    else
    {
        retorno = pedirInt("Ingrese nota 2: ");
    }

    return retorno;
}

void pedirNombre(char *retorno)
{
    pedirString(retorno, "Ingrese nombre: ");
}

eAlumno pedirAlumno()
{
    eAlumno retorno;

    retorno.legajo = pedirLegajo();

    pedirNombre((char *)&(retorno.nombre));

    retorno.nota1 = pedirNota(1);

    retorno.nota2 = pedirNota(2);

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
        imprimirEnPantalla("+----------------+\n| ALTA DE ALUMNO |\n+----------------+");
        alumno = pedirAlumno();
        mostrarAlumno(alumno);

        confirmacion = pedirConfirmacion("Confirma que los datos ingresados son correctos?");

        if(confirmacion == 'S')
        {
            listadoAlumnos[posicion] = alumno;
            ordenarPorPromedio(listadoAlumnos);
            imprimirEnPantalla("\nEl alumno se dio de alta.");
        }
        else
        {
            imprimirEnPantalla("\nSe cancelà la gestiàn.");
        }
    }
    else
    {
        imprimirEnPantalla("\nNo hay m s lugares disponibles para altas de alumnos.");
    }
    ejecutarEnConsola(HACER_PAUSA);
}

void procesarMostrarListado(eAlumno listadoAlumnos[])
{
    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirEnPantalla("+--------------------+\n| LISTADO DE ALUMNOS |\n+--------------------+");
    mostrarListadoAlumnos(listadoAlumnos);
    ejecutarEnConsola(HACER_PAUSA);
}

void procesarBaja(eAlumno listadoAlumnos[])
{
    eAlumno alumnoBuscar;
    char confirmacion;
    int posicion;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirEnPantalla("+----------------+\n| BAJA DE ALUMNO |\n+----------------+");

    alumnoBuscar.legajo = pedirInt("\n\nIngrese el legajo del alumno a dar de baja: ");

    posicion = buscarAlumno(alumnoBuscar, listadoAlumnos);
    if(posicion != -1)
    {
        if(listadoAlumnos[posicion].estado == 0)
        {
            imprimirEnPantalla("\nEl alumno ya se encontraba dado de baja");
        }
        else
        {
            mostrarAlumno(listadoAlumnos[posicion]);

            confirmacion = pedirConfirmacion("Confirma que desea dar de baja dicho alumno?");

            if(confirmacion == 'S')
            {
                listadoAlumnos[posicion].estado = 0;
                imprimirEnPantalla("\nEl alumno se dio de baja.");
            }
            else
            {
                imprimirEnPantalla("\nSe cancelà la gestiàn.");
            }
        }
    }
    else
    {
        imprimirEnPantalla("\nEl legajo del alumno ingresado por par metro no existe.");
    }
    ejecutarEnConsola(HACER_PAUSA);
}

void modificarAlumno(eAlumno *alumno)
{
    eMenu menuModificar = {
                            6, //cantidad de opciones
                            {1,2,3,4,5,9}, //codigos
                            {"1. Legajo","2. Nombre","3. Nota 1","4. Nota 2","5. Rehabilitar","9. Cancelar"}, //descripciones
                            {"\nQu‚ desea modificar?"} //titulo del menu
                           };
    int opcion;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirEnPantalla("+--------------------+\n| MODIFICANDO ALUMNO |\n+--------------------+\nDatos del alumno a modificar:");

    mostrarAlumno(*alumno);

    if(alumno->estado == 0)
    {
        imprimirEnPantalla("El alumno se encuentra dado de baja.");
    }

    opcion = pedirOpcion(menuModificar);
    switch(opcion)
    {
        case 1:
            alumno->legajo = pedirLegajo();
            break;
        case 2:
            pedirNombre((char *)&alumno->nombre);
            break;
        case 3:
            alumno->nota1 = pedirNota(1);
            break;
        case 4:
            alumno->nota2 = pedirNota(2);
            break;
        case 5:
            alumno->estado = 1;
            break;
        case 9:
            break;
    }
}

void procesarModificacion(eAlumno listadoAlumnos[])
{
    //bug: permite rehabilitar los legajos en cero
    eAlumno alumnoModificar;
    char confirmacion;
    int posicion;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirEnPantalla("+------------------------+\n| MODIFICACION DE ALUMNO |\n+------------------------+");

    alumnoModificar.legajo = pedirInt("\n\nIngrese el legajo del alumno a modificar: ");

    posicion = buscarAlumno(alumnoModificar, listadoAlumnos);
    if(posicion != -1)
    {
        alumnoModificar = listadoAlumnos[posicion];

        modificarAlumno(&alumnoModificar);

        if(listadoAlumnos[posicion].estado != alumnoModificar.estado)
        {
            confirmacion = pedirConfirmacion("Confirma que desea rehabilitar al alumno?");
        }
        else
        {
            if(listadoAlumnos[posicion].nota1 != alumnoModificar.nota1 ||
               listadoAlumnos[posicion].nota2 != alumnoModificar.nota2)
            {
                alumnoModificar.promedio = calcularPromedio(alumnoModificar.nota1, alumnoModificar.nota2);
            }

            ejecutarEnConsola(LIMPIAR_PANTALLA);

            imprimirEnPantalla("Alumno actual:");
            mostrarAlumno(listadoAlumnos[posicion]);

            imprimirEnPantalla("Alumno nuevo:");
            mostrarAlumno(alumnoModificar);

            confirmacion = pedirConfirmacion("Confirma que los datos ingresados son correctos?");
        }

        if(confirmacion == 'S')
        {
            listadoAlumnos[posicion] = alumnoModificar;
            ordenarPorPromedio(listadoAlumnos);
            imprimirEnPantalla("\nEl alumno se modificà.");
        }
        else
        {
            imprimirEnPantalla("\nSe cancelà la gestiàn.");
        }
    }
    else
    {
        imprimirEnPantalla("\nEl legajo del alumno ingresado por par metro no existe.");
    }
    ejecutarEnConsola(HACER_PAUSA);
}
