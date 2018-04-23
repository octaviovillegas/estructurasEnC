/** \brief recibe un dato tipo alumno y lo muestra en pantalla
 *
 * \param eAlumno: un dato tipo alumno
 * \return void
 *
 */
void mostrarAlumno(const eAlumno);


/** \brief recibe un array de datos tipo alumno y los muestra en pantalla
 *
 * \param eAlumno[]: un array de datos tipo alumno
 * \return void
 *
 */
void mostrarListadoAlumnos(const eAlumno[]);


/** \brief pide al usuario ingresar un legajo y devuelve su valor.
 *
 * \return int: el legajo ingresado
 *
 */
int pedirLegajo();


/** \brief pide al usuario que ingrese la nota uno o dos segun parametro
 *
 * \param nroDeNota const int: el numero de nota para mostrar pedido en pantalla
 * \return int: el numero de nota
 *
 */
int pedirNota(const int);


/** \brief pide al usuario que ingrese un nombre
 *
 * \param retorno char*: devuelve el nombre ingresado en el parametro
 * \return void
 *
 */
void pedirNombre(char *retorno);


/** \brief pide al usuario el ingreso de datos de un tipo alumno y retorna una estructura cargada
 *
 * \return eAlumno
 *
 */
eAlumno pedirAlumno();


/** \brief busca el primer lugar libre en un array de tipo de dato alumno
 *
 * \param eAlumno[]: el array de tipo alumno
 * \return int: el numero de la posicion libre. -1 en caso de no encontrar lugar
 *
 */
int buscarLugarLibre(eAlumno[]);


/** \brief busca un alumno en un array tipo alumno
 *
 * \param eAlumno: el dato tipo alumno a buscar
 * \param eAlumno[]: el array de alumnos
 * \return int: la posicion del alumno buscado. -1 en caso de no encontrarlo
 *
 */
int buscarAlumno(eAlumno, eAlumno[]);


/** \brief recibe un array de datos tipo alumno y lo ordena descendente por el campo promedio
 *
 * \param [] eAlumno: el array de alumnos
 * \return void
 *
 */
void ordenarPorPromedio(eAlumno []);


/** \brief se encarga de toda la logica de dar de alta un alumno y guardarlo en el array recibido por parametro
 *
 * \param listadoAlumnos[] eAlumno: array de alumnos
 * \return void
 *
 */
void procesarAlta(eAlumno[]);


/** \brief se encarga de toda la logica de mostrar el listado de alumnos recibido por parametro
 *
 * \param listadoAlumnos[] eAlumno: array de alumnos
 * \return void
 *
 */
void procesarMostrarListado(eAlumno[]);


/** \brief se encarga de toda la logica de dar de baja un alumno del array recibido por parametro.
 *         solicita al usuario que ingrese el legajo y lo valida
 *
 * \param listadoAlumnos[] eAlumno: array de alumnos
 * \return void
 *
 */
void procesarBaja(eAlumno[]);


/** \brief recibe por referencia un alumno y solicita al usuario las modificaciones que desea realizar al registro
 *
 * \param alumno eAlumno*: el registro del alumno a modificar
 * \return void
 *
 */
void modificarAlumno(eAlumno *);


/** \brief se encarga de toda la logica de dar de modificar un alumno del array recibido por parametro.
 *
 * \param listadoAlumnos[] eAlumno: array de alumnos
 * \return void
 *
 */
void procesarModificacion(eAlumno[]);
