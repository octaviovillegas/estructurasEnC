#include <stdio.h>
#include <stdlib.h>

void ejecutarEnConsola(const char *lineaDeComando)
{
    printf("\n");
    system(lineaDeComando);
}

char pedirConfirmacion(const char *texto)
{
    char retorno;

    printf("\n%s (S/N): ", texto);
    fflush(stdin);
    scanf("%c", &retorno);

    do
    {
        switch(retorno)
        {
            case 'S':
            case 's':
                retorno = 'S';
                break;
            case 'N':
            case 'n':
                retorno = 'N';
                break;
            default:
                printf("\nPor favor ingrese 'S' o 'N': ");
                fflush(stdin);
                scanf("%c", &retorno);
                break;
        }
    }
    while(retorno != 'S' && retorno != 'N');

    return retorno;
}

int pedirInt(const char mensajeIngreso[])
{
    int retorno;

    printf("%s", mensajeIngreso);
    fflush(stdin);
    scanf("%d", &retorno);


    return retorno;
}

float pedirFloat(const char mensajeIngreso[])
{
    float retorno;

    printf("%s", mensajeIngreso);
    fflush(stdin);
    scanf("%f", &retorno);


    return retorno;
}

void pedirString(char *retorno, const char mensajeIngreso[])
{
    printf("%s", mensajeIngreso);
    fflush(stdin);
    gets(retorno);
}

float calcularPromedio(float numero1, float numero2)
{
    float retorno;

    retorno = (numero1 + numero2) / 2;

    return retorno;
}
