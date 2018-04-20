#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)

void ejecutarEnConsola(const char *);

char pedirConfirmacion(const char *);

int pedirInt(const char[]);

float pedirFloat(const char[]);

void pedirString(char *retorno, const char[]);

float calcularPromedio(float, float);
