#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)


/** \brief corre comandos en la consola del sistema operativo
 *
 * \param  const char*: el string del comando
 * \return void
 *
 */
void ejecutarEnConsola(const char *);


/** \brief pide confirmacion por S o N al usuario y devuelve la letra validada
 *
 * \param  const char*: S o N
 * \return char: S o N validado
 *
 */
char pedirConfirmacion(const char *);


/** \brief pide que se ingrese un numero entero
 *
 * \param char[] const: el mensaje al usuario
 * \return int: el numero entero
 *
 */
int pedirInt(const char[]);

/** \brief pide que se ingrese un numero float
 *
 * \param char[] const: el mensaje al usuario
 * \return float: el numero float
 *
 */
float pedirFloat(const char[]);


/** \brief pide que se ingrese una cadena de texto y la asigna a una variable
 *
 * \param retorno char*: la variable donde se retorna la cadena ingresada
 * \param char[] const: el mensaje al usuario
 * \return void
 *
 */
void pedirString(char *retorno, const char[]);


/** \brief calcula el promedio entre dos numeros float
 *
 * \param float: el numero 1
 * \param float: el numero 2
 * \return float: el promedio entre ambos numeros
 *
 */
float calcularPromedio(float, float);
