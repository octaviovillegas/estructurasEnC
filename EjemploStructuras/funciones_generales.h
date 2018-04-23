#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)


/** \brief corre comandos en la consola del sistema operativo
 *
 * \param  lineaDeComando const char*: el string del comando
 * \return void
 *
 */
void ejecutarEnConsola(const char *);


/** \brief pide confirmacion por S o N al usuario y devuelve la letra validada
 *
 * \param  mensajeAlUsuario const char*: mensaje al usuario
 * \return char: S o N validado
 *
 */
char pedirConfirmacion(const char *);


/** \brief pide que se ingrese un numero entero
 *
 * \param mensajeIngreso char[] const: el mensaje al usuario
 * \return int: el numero entero
 *
 */
int pedirInt(const char[]);

/** \brief pide que se ingrese un numero float
 *
 * \param mensajeIngreso char[] const: el mensaje al usuario
 * \return float: el numero float
 *
 */
float pedirFloat(const char[]);


/** \brief pide que se ingrese una cadena de texto y la asigna a una variable
 *
 * \param retorno char*: la variable donde se retorna la cadena ingresada
 * \param mensajeIngreso char[] const: el mensaje al usuario
 * \return void
 *
 */
void pedirString(char *, const char[]);


/** \brief calcula el promedio entre dos numeros float
 *
 * \param numero1 float: el primer numero
 * \param numero2 float: el segundo numero
 * \return float: el promedio entre ambos numeros
 *
 */
float calcularPromedio(float, float);


/** \brief busca coincidencia de un valor entero dentro de un array
 *
 * \param buscar const int: el numero entero a buscar
 * \param array[] const int: el array donde buscar
 * \param cant const int: la cantidad de elementos del array
 * \return int la posicion del elemento buscado. -1 en caso de no encontrarlo
 *
 */
int buscarEnArrayInt(const int, const int[], const int);


/** \brief escribe el texto recibido con un printf
 *
 * \param texto const char*: la cadena de texto a mostrar
 * \return void
 *
 */
void imprimirEnPantalla(const char *);
