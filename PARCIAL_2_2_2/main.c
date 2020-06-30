#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "bicis.h"
#include "controller.h"

int main()
{
    srand (time(NULL));

    LinkedList* listaBikes = ll_newLinkedList();
    LinkedList* listaFiltrada = NULL;
    LinkedList* listaTiempos = NULL;
    int resp =1;
    int check=0;
    int carga=0;
    int tipos;
    char archivo[20];
    do
    {
        switch(menu())
        {
        case 1:
            utn_getDescripcion(archivo,20,"Ingrese el nombre del archivo: ", "Ingreso algun dato incorrecto",3);
            controller_loadFromText(archivo,listaBikes);
            carga=1;
            system("pause>nul");
            break;
        case 2:
            if (carga==1)
            {
                controller_listBikers(listaBikes);
            }
            else
            {
                printf("\nAun no se cargaron los datos\n");
            }
            system("pause>nul");
            break;
        case 3:
            if (carga==1)
            {
                listaBikes= ll_map(listaBikes, tiempoRandom);
                controller_listBikers(listaBikes);
                check=1;
            }
            else
            {
                printf("\nAun no se cargaron los datos\n");
            }
            system("pause>nul");
            break;
        case 4:
            if (carga==1)
            {
                utn_getNumero(&tipos, "Tipos de bici\n\n1) BMX\n2) Playera\n3) MTB \n4) Paseo\n\nIngrese tipo: ", "Debe ingresar de 1 a 4",1, 4, 3);
                switch(tipos)
                {
                    case 1 :
                        listaFiltrada= ll_filter(listaBikes, filtrarBMX);
                        break;
                    case 2 :
                        listaFiltrada= ll_filter(listaBikes, filtrarPlayera);
                        break;
                    case 3 :
                        listaFiltrada= ll_filter(listaBikes, filtrarMTB);
                        break;
                    case 4 :
                        listaFiltrada= ll_filter(listaBikes, filtrarPASEO);
                        break;
                }
                controller_saveAsText("tipos.csv",listaFiltrada);
                printf("\nSe genero la lista filtrada en el archivo tipos.csv");
            }
            else
            {
                printf("\nAun no se cargaron los datos\n");
            }
            system("pause>nul");
            break;
        case 5:
            if (check == 1)
            {
                listaTiempos=ll_clone(listaBikes);
                ll_sort(listaTiempos,ordenXTiempo, 0);
                controller_listBikers(listaTiempos);
            }
            else
            {
                printf("Aun no se listaron los tiempos\n");
            }
            system("pause>nul");
            break;
        case 6:
            if (check == 1)
            {
                controller_saveAsText("listaTiempos.csv",listaTiempos);
                printf("se guardo\n");
            }
            else
            {
                printf("Aun no se listaron los tiempos\n");
            }
            system("pause>nul");
            break;
        case 7:
            resp=0;
        }
    }
    while(resp != 0);
    printf("\n\nSaliendo del programa...");

    ll_deleteLinkedList(listaBikes);
    ll_deleteLinkedList(listaTiempos);
    ll_deleteLinkedList(listaFiltrada);

    return 0;
}
