#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getCuit(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado,int longitud);
int esDescripcion(char* cadena,int longitud);
int getDescripcion(char* pResultado, int longitud);
int getCuit(char* pResultado, int longitud);

#endif // UTN_H_INCLUDED
