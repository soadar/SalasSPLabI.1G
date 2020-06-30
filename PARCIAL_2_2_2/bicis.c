#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "bicis.h"

/** \brief reserva un espacio en memoria dinamica e inicializa las variables
 *
 * \param idStr id del usuario en formato texto
 * \param nombreStr nombre del usuario
 * \param horasTrabajadasStr horas trabajadas del usuario en formato texto
 * \param sueldoStr sueldo del usuario en formato texto
 * \return devuelve un espacio en memoria dinamica
 *
 */

eBicicleta* bikers_newParametros(char* id_bike,char* nombre,char* tipo, char* tiempo)
{
    eBicicleta* newbiker = biker_new();
    if (newbiker != NULL)
    {
        newbiker->id_bike=atoi(id_bike);
        strcpy(newbiker->nombre, nombre);
        strcpy(newbiker->tipo, tipo);
        newbiker->tiempo=atoi(tiempo);
    }
    return newbiker;
}

/** \brief reserva un espacio en memoria dinamica e inicializa las variables
 *
 * \return devuelve un espacio en memoria dinamica
 *
 */

eBicicleta* biker_new()
{
    eBicicleta* newbiker = (eBicicleta*) malloc(sizeof(eBicicleta));
    if (newbiker != NULL)
    {
        newbiker->id_bike = 0;
        newbiker->nombre[0] = ' ';
        newbiker->tipo[0] = ' ';
        newbiker->tiempo = 0;
    }
    return newbiker;
}

/** \brief asigna un tiempo random
 *
 * \param element puntero a void
 * \return returna puntero a void actualizado
 *
 */

void* tiempoRandom(void* element)
{
    void* list= NULL;
    if (element != NULL)
    {
        eBicicleta* list = (eBicicleta*) element;
        if ( list!= NULL)
        {
            list->tiempo=getRandom();
        }
    }
    return list;
}


/** \brief compara el tipo de dos bikers
 *
 * \param biker1 puntero a void
 * \param biker2 puntero a void
 * \return devuelve 0 si los ids son iguales, -1 si el biker1 tiene un ID mayor al biker2, 1 si el biker1 tiene un ID menor al biker2,
 *
 */
int ordenXTipo(void* biker1, void* biker2)
{
    int orden;
    eBicicleta* bikerA = (eBicicleta*) biker1;
    eBicicleta* bikerB = (eBicicleta*) biker2;
    if (strcmp(bikerA->tipo,bikerB->tipo)==0)
    {
        orden=0;
    }
    else if (strcmp(bikerA->tipo,bikerB->tipo)>0)
    {
        orden=-1;
    }
    else
    {
        orden=1;
    }
    return orden;
}

/** \brief compara el tiempo de dos bikers
 *
 * \param biker1 puntero a void
 * \param biker2 puntero a void
 * \return devuelve 0 si los ids son iguales, -1 si el biker1 tiene un ID mayor al biker2, 1 si el biker1 tiene un ID menor al biker2,
 *
 */
int ordenXTiempo(void* biker1, void* biker2)
{
    int orden;
    eBicicleta* bikerA = (eBicicleta*) biker1;
    eBicicleta* bikerB = (eBicicleta*) biker2;
    if (bikerA->tiempo == bikerB->tiempo)
    {
        orden=0;
    }
    else if (bikerA->tiempo > bikerB->tiempo)
    {
        orden=-1;
    }
    else
    {
        orden=1;
    }
    return orden;
}

/** \brief filtrar las bicis por BMX
 *
 * \param element puntero a void
 * \return devuelve 1 si encontre el dato buscado, 0 si es otro tipo
 *
 */
int filtrarBMX(void* element)
{
    int retorno=0;
    if (element != NULL)
    {
        eBicicleta* list = (eBicicleta*) element;
        if ( list!= NULL && strcmp(list->tipo, "BMX") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief filtrar las bicis por PLAYERA
 *
 * \param element puntero a void
 * \return devuelve 1 si encontre el dato buscado, 0 si es otro tipo
 *
 */
int filtrarPlayera(void* element)
{
    int retorno=0;
    if (element != NULL)
    {
        eBicicleta* list = (eBicicleta*) element;
        if ( list!= NULL && strcmp(list->tipo, "PLAYERA") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief filtrar las bicis por MTB
 *
 * \param element puntero a void
 * \return devuelve 1 si encontre el dato buscado, 0 si es otro tipo
 *
 */
int filtrarMTB(void* element)
{
    int retorno=0;
    if (element != NULL)
    {
        eBicicleta* list = (eBicicleta*) element;
        if ( list!= NULL && strcmp(list->tipo, "MTB") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief filtrar las bicis por PASEO
 *
 * \param element puntero a void
 * \return devuelve 1 si encontre el dato buscado, 0 si es otro tipo
 *
 */
int filtrarPASEO(void* element)
{
    int retorno=0;
    if (element != NULL)
    {
        eBicicleta* list = (eBicicleta*) element;
        if ( list!= NULL && strcmp(list->tipo, "PASEO") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}



/** \brief Muestra los datos de todos los empleados
 *
 * \param array del empleado
 * \return devuelve -1 en caso de error o 1 si esta todo ok
 *
 */
int controller_listBikers(LinkedList* pArrayListBikers)
{
    eBicicleta* list;
    int flag=0;
    int tam = ll_len(pArrayListBikers);
    if (tam > 0)
    {
        printf("____________________________________________________________________________\n");
        printf(" id_bike |             nombre          | tipo          |  tiempo\n");
        printf("____________________________________________________________________________\n");
    }
    if (pArrayListBikers != NULL)
    {
        for (int i=0; i < tam; i++)
        {
            list = (eBicicleta*) ll_get(pArrayListBikers, i);
            if (list != NULL)
            {
                printf("   %3d   |    %20s     |   %10s  |    %2d\n",list->id_bike, list->nombre, list->tipo, list->tiempo);
                flag = 1;
            }
        }
        if (flag != 1)
        {
            printf("No hay para listar\n");
        }
        return 0;
    }
    else
    {
        printf("No se pudo conseguir memoria\n");
        return -1;
    }
    return 1;
}


/** \brief genera un numero al azar
 *
 * \return aleatorio devuelve un numero al azar
 *
 */

int getRandom()
{
    int aleatorio;
    aleatorio = rand()%(71)+50;
    return aleatorio;
}

/** \brief Menu principal
 *
 * \return devuelve la opcion elejida
 *
 */
int menu()
{
    int opcion;
    system("cls");
    printf("************************************************\n");
    printf("*                Menu principal                *\n");
    printf("************************************************\n");
    printf("1) Cargar archivo\n");
    printf("2) Imprimir lista\n");
    printf("3) Asignar tiempos\n");
    printf("4) Filtrar por tipo\n");
    printf("5) Mostrar posiciones\n");
    printf("6) Guardar posiciones\n");
    printf("7. Salir\n");
    utn_getNumero(&opcion, "\nIngrese una opcion: ", "Error, debe ingresar de 1 a 8", 1, 7, 3);
    return opcion;
}
