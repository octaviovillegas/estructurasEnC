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
