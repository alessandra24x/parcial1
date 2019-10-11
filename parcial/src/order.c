#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "customer.h"
#include "order.h"

int order_init(Order array[], int size) {
    int retorno = -1;
    int i;
    if(array != NULL && size > 0) {
        for(i = 0; i < size; i++) {
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int order_searchEmpty(Order array[], int size, int* position) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0 && position != NULL) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0) {
                retorno = 0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}

int order_searchID(Order array[], int size, int searchValue, int* position) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for( i= 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(array[i].orderID == searchValue) {
                retorno = 0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}

int order_pickup(Order array[], int size, Customer arrayCustomer[], int sizeCustomer)
{
    int retorno = -1;
    int position;
    if(array != NULL && size > 0) {
        if(order_searchEmpty(array,size,&position) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
        	printf("\n Posicion: %d\n Id: %d\n Nombre: %s\n CUIT: %s\n Direccion: %s\n Localidad: %s",
        	                   position,arrayCustomer[position].customerID,arrayCustomer[position].name,arrayCustomer[position].cuit,arrayCustomer[position].adress,arrayCustomer[position].location);
            utn_getUnsignedInt("Ingrese el Id del cliente\n: ","\nError, Id invalido",1,size,1,size,2,&arrayCustomer[position].customerID);

            /**if(order_searchID(arrayCustomer, sizeCustomer, arrayCustomer[position].customerID, &position) == 0) {
            	int id = 0;
            	for(int i = 0; i < sizeCustomer; i++) {
					utn_getUnsignedInt("Ingrese la cantidad de kilos totales que se recolectaran\n: ",
							"\nError, la cantidad es invalida",1,size,1,size,2,&array[position].totalKg);
					array[position].isEmpty = 1;
					strcpy(array[position].status, "pendiente");
					id++;
					array[position].orderID = id;
            	}
            } else {
            	printf("El Id ingresado no pertenece a ningun cliente");

          }*/
            retorno=0;
        }
    }
    return retorno;
}
