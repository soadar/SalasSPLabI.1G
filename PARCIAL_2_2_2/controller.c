#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "bicis.h"
#include "controller.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBikers LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListBikers)
{
    int retorno = 0;
    FILE* f;
    f = fopen (path, "r");
    if (f == NULL)
    {
        printf("ERROR");
        retorno = -1;
    }
    else
    {
        if ( !parser_bikersFromText(f, pArrayListBikers) )
        {
            printf("\nSe cargo exitosamente la lista de empleados.\n");
            retorno = 0;
        }
    }
    fclose(f);
    return retorno;
}



/** \brief Guarda los datos de los bikers segun el tipo que se elija en tipos.csv
 *
 * \param path char*
 * \param pArrayListBikers LinkedList*
 * \return int 1 si logro guardarlo, -1 en caso error
 *
 */
int controller_saveAsTextTipos(char* path, LinkedList* pArrayListBikers)
{
    int retorno=1;
    int resp;
    system("cls");
    eBicicleta* list;
    FILE* f = fopen(path, "w" );
    int tam = ll_len(pArrayListBikers);
    if (pArrayListBikers != NULL && path != NULL)
    {
        if (f == NULL)
        {
            printf("Problemas al abrir el archivo\n");
            return -1;
        }
        else
        {
            utn_getNumero(&resp, "Tipos de bici\n\n1) MBX\n2) Playera\n3) MTB \n4) Paseo\n\nIngrese tipo: ", "Debe ingresar de 1 a 4",1, 4, 3);

            for (int i=0; i < tam; i++)
            {
                list = (eBicicleta*) ll_get(pArrayListBikers, i);
                if (list != NULL)
                {
                    switch(resp)
                    {
                    case 1 :
                        if (strcmp(list->tipo, "BMX")==0)
                        {
                            fprintf(f,"%d,%s,%s,%d\n",list->id_bike, list->nombre, list->tipo, list->tiempo);
                            retorno=0;
                        }
                        break;
                    case 2 :
                        if (strcmp(list->tipo, "PLAYERA")==0)
                        {
                            fprintf(f,"%d,%s,%s,%d\n",list->id_bike, list->nombre, list->tipo, list->tiempo);
                            retorno=0;
                        }
                        break;
                    case 3 :
                        if (strcmp(list->tipo, "MTB")==0)
                        {
                            fprintf(f,"%d,%s,%s,%d\n",list->id_bike, list->nombre, list->tipo, list->tiempo);
                            retorno=0;
                        }
                        break;
                    case 4 :
                        if (strcmp(list->tipo, "PASEO")==0)
                        {
                            fprintf(f,"%d,%s,%s,%d\n",list->id_bike, list->nombre, list->tipo, list->tiempo);
                            retorno=0;
                        }
                        break;
                    }
                }
            }
            if (retorno == 0)
            {
                printf("Se genero el archivo con exito\n");
            }
        }
    }
    fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los bikers en archivo modo texto
 *
 * \param path char*
 * \param pArrayListBikers LinkedList*
 * \return int 1 si logro guardarlo, -1 en caso error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListBikers)
{
    int retorno=1;
    eBicicleta* list;
    FILE* f = fopen(path, "w" );
    int tam = ll_len(pArrayListBikers);
    if (pArrayListBikers != NULL && path != NULL)
    {
        if (f == NULL)
        {
            printf("Problemas al abrir el archivo\n");
            return -1;
        }
        else
        {
            for (int i=0; i < tam; i++)
            {
                list = (eBicicleta*) ll_get(pArrayListBikers, i);
                fprintf(f,"%d,%s,%s,%d\n",list->id_bike, list->nombre, list->tipo, list->tiempo);
                retorno=0;
            }
        }
    }
    fclose(f);
    return retorno;
}
