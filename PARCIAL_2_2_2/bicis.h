#ifndef BICIS_H_INCLUDED
#define BICIS_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[30];
    char tipo[30];
    int tiempo;
} eBicicleta;

#endif // BICIS_H_INCLUDED

int ordenXTipo(void* biker1, void* biker2);
int ordenXTiempo(void* biker1, void* biker2);
int filtrarPASEO(void* element);
int filtrarMTB(void* element);
int filtrarPlayera(void* element);
int filtrarBMX(void* element);
void* tiempoRandom(void* element);
int menu();

eBicicleta* biker_new();
eBicicleta* bikers_newParametros(char* id_bike,char* nombre,char* tipo, char* tiempo);

int getRandom();





