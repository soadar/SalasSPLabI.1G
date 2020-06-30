#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "bicis.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBikers LinkedList*
 * \return int
 *
 */
int parser_bikersFromText(FILE* pFile, LinkedList* pArrayListBikers)
{
    int cant;
    int retorno=1;
    int flag=0;
    int repetido=0;
    char buffer[4][100];
    cant = ll_len(pArrayListBikers);
    eBicicleta* auxbiker;
    eBicicleta* list;
    while ( !feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
        if (cant == 4)
        {
            if (esNumerica(buffer[0], sizeof(buffer[0])))
            {
                repetido=0;
                for (int i=0; i < ll_len(pArrayListBikers); i++)
                {
                    list = (eBicicleta*) ll_get(pArrayListBikers, i);
                    if (list->id_bike == atoi(buffer[0]))
                    {
                        repetido=1;
                        flag=1;
                        break;
                    }
                }
                if (repetido == 0)
                {
                    auxbiker = bikers_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

                    if (!ll_add(pArrayListBikers, auxbiker))
                    {
                        retorno = 0;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    if (flag==1)
    {
        printf("No se cargaron datos duplicados\n");
    }
    return retorno;
}
