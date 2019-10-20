#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "order.h"
#include "customer.h"

/** \brief Indica que todas las posiciones en el array estan vacias, para eso se pone un FLAG (isEmpty) en TRUE en todas las posiciones del array
* \param Order array es el array de la estructura Order
* \param int size es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
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

/** \brief Busca el primer lugar vacio en un array
* \param Order array es el array de la estructura Order
* \param int size Tama�o del array
* \param int* position Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
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

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param Customer array es el array de la estructura Customer
* \param size int Tama�o del array
* \param int* position Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
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

/** \brief Solicita un ID para modificar los datos de una posici�n especifica en el array
* \param Order array es el array de la estructura Order
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int order_modify(Order array[], int size) {
    int retorno = -1;
    int position;
    int id;
    char option;
    if(array != NULL && size > 0) {
        utn_getUnsignedInt("\nId del pedido a modificar: ","\nError, ingrese un Id valido",1,sizeof(int),1,size,1,&id);
        if(order_searchID(array,size,id,&position) == -1) {
            printf("\nNo existe este Id de pedido");
        } else {
          printf("\n El id del pedido es: %d\n la cantidad de kg es: %d\n el status es: %s\n",
                        array[position].orderID, array[position].totalKg, array[position].status);
                        utn_getUnsignedInt("\nmodificar: Ingrese la cantidad de kilos totales que se recolectaran: ",
                                          "\nError, la cantidad es invalida",1,size,1,size,2,&array[position].totalKg);
          retorno = 0;
        }
  }
  return retorno;
}

/** \brief Borra un elemento del array por ID
* \param Order array es el array de la estructura Order
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int order_remove(Order array[], int size) {
    int retorno = -1;
    int position;
    int id;
    if(array != NULL && size > 0) {
        utn_getUnsignedInt("\nId del pedido a cancelar: ","\nError, ingrese un Id valido",1,sizeof(int),1,size,1,&id);
        if(order_searchID(array,size,id,&position) == -1) {
            printf("\nNo existe este Id");
        } else {
            array[position].isEmpty = 0;
            array[position].totalKg = 0;
            array[position].LDPE_kg = 0;
            array[position].HDPE_kg = 0;
            array[position].PP_kg = 0;
            strcpy(array[position].status,"");
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Solicita un ID del pedido al cliente y le pide ingresar la cantidad de plastico que sera recolectada por tipo de plastico
* \param Order array es el array de la estructura Order
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agregaron los datos exitosamente
*
*/
int order_processWaste(Order array[], int size) {
    int retorno = -1;
    int auxID;
    int position;
    int auxHDPE_kg;
    int auxLDPE_kg;
    int auxPP_kg;
    int auxtotalKg;

    if(order_searchEmpty(array,size,&position) == -1) {
        printf("\nNo hay lugares vacios");
    } else {
      utn_getUnsignedInt("\nIngrese el Id del pedido: ","\nError, Id invalido",1,size,1,size,2,&auxID);

        if(order_searchID(array, size, auxID, &position) == 0) {
          auxtotalKg = array[position].totalKg;
          printf("A continuacion deber� desglosar la cantidad por tipo de plastico que se procesara de la cantidad disponible, la cual es: %d\n", array[position].totalKg);

          utn_getUnsignedInt("\nIngrese la cantidad de HDPE(Polietileno de alta densidad): ","\nError, la cantidad es invalida",1,size,1,size,2,&auxHDPE_kg);

          while (auxHDPE_kg > auxtotalKg) {
              printf("La cantidad ingresada es mayor a la cantidad total en sistema");
              utn_getUnsignedInt("\nIngrese la cantidad de HDPE(Polietileno de alta densidad): ","\nError, la cantidad es invalida",1,size,1,size,2,&auxHDPE_kg);
          }
          if(auxHDPE_kg < auxtotalKg) {
            array[position].HDPE_kg = auxHDPE_kg;
            auxtotalKg = auxtotalKg - auxHDPE_kg;
          }

          utn_getUnsignedInt("\nIngrese la cantidad de LDPE(Polietileno de baja densidad): ","\nError, la cantidad es invalida",1,size,1,size,2,&auxLDPE_kg);

          while(auxLDPE_kg > auxtotalKg) {
              printf("La cantidad ingresada es mayor a la cantidad total en sistema");
              utn_getUnsignedInt("\nIngrese la cantidad de LDPE(Polietileno de baja densidad): ","\nError, la cantidad es invalida",1,size,1,size,2,&auxLDPE_kg);
          }
          if(auxLDPE_kg < auxtotalKg) {
            array[position].LDPE_kg = auxLDPE_kg;
            auxtotalKg = auxtotalKg - auxLDPE_kg;
          }

          utn_getUnsignedInt("\nIngrese la cantidad de PP(Polipropileno): ","\nError, la cantidad es invalida",1,size,1,size,2,&auxPP_kg);
          while (auxPP_kg > auxtotalKg) {
              printf("La cantidad ingresada es mayor a la cantidad total en sistema");
              utn_getUnsignedInt("\nIngrese la cantidad de PP(Polipropileno): ","\nError, la cantidad es invalida",1,size,1,size,2,&auxPP_kg);
          }
          if(auxPP_kg < auxtotalKg) {
            array[position].PP_kg = auxPP_kg;
            auxtotalKg = auxtotalKg - auxPP_kg;
          }

          array[position].discarded = auxtotalKg;

          auxtotalKg = 0;


          array[position].totalKg = auxtotalKg;
          array[position].isEmpty = 1;
          strcpy(array[position].status, "Completado");

          } else {
            printf("El Id ingresado no pertenece a ningun cliente");
          }
    retorno = 0;
    }
  return retorno;
}

/** \brief Lista los elementos del array Order
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int order_show(Order* array, int size) {
  int retorno = -1;
  int i;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        printf("\n El id del pedido es: %d\n la cantidad de kg es: %d\n el status es: %s\n",
            array[i].orderID, array[i].totalKg, array[i].status);
      }
    }
    retorno = 0;
  }
 return retorno;
}

/** \brief Verifica que un pedido este en estado pendiente y lo devuelve
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \param *countStatusPending Puntero que hace relaci�n a un contador que ira acumulando la cantidad de pedidos en estado pendiente
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int order_pendingStatus(Order* array, int size, int *countStatusPending, int customerID) {
  int retorno = -1;
  int i;
  int countStatus = 0;
    if(array!= NULL && size > 0) {
      for(i = 0; i < size; i++) {
        if(array[i].isEmpty == 0) {
          continue;
        }
        if(array[i].customerID == customerID && strcmp(array[i].status, "Pendiente") == 0) {
          countStatus++;
        }
      }
      retorno = 0;
  }
  *countStatusPending = countStatus;
  return retorno;
}

/** \brief Lista los elementos del array Order con estado pendiente
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int orderPendingStatus_show(Order* array, int size) {
  int retorno = -1;
  int i;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else if(strcmp(array[i].status, "Pendiente") == 0) {
        printf("\nEl pedido con Id: %d tiene %d kilos de plastico recolectado\n", array[i].orderID, array[i].totalKg);
      }
    }
    retorno = 0;
  }
 return retorno;
}

/** \brief Lista los elementos del array Order con estado completado
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int orderCompleteStatus_show(Order* array, int size) {
  int retorno = -1;
  int i;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else if(strcmp(array[i].status, "Completado") == 0){
        printf("\nEl pedido con Id: %d se complet� con la siguiente cantidad de plastico recolectado: \n\n\n Polietileno de Alta Densidad: %d kg\n Polietileno de Baja Densidad: %d kg\n Polipropileno: %d kg\n", array[i].orderID, array[i].HDPE_kg, array[i].LDPE_kg, array[i].PP_kg);
      }
    }
    retorno = 0;
  }
 return retorno;
}

/** \brief Setea valores fijos para agilizar las pruebas
* \param Order array[] es el array de la estructura Order
* \param int size es la longitud del array
*
*/
void setOrder(Order array[], int searchEmpty, int orderIDAux, int customerIDAux, int totalKgAux, int HDPE_kgAux, int LDPE_kgAux,
int PP_kgAux, char statusAux[]) {
  array[searchEmpty].orderID = orderIDAux;
  array[searchEmpty].customerID = customerIDAux;
  array[searchEmpty].totalKg = totalKgAux;
  array[searchEmpty].HDPE_kg = HDPE_kgAux;
  array[searchEmpty].LDPE_kg = LDPE_kgAux;
  array[searchEmpty].PP_kg = PP_kgAux;
  array[searchEmpty].discarded = totalKgAux - HDPE_kgAux - LDPE_kgAux - PP_kgAux;
  strcpy(array[searchEmpty].status, statusAux);
  array[searchEmpty].isEmpty = 1;
}

/** \brief Valida que el array este vacio o con datos ya cargados
 * \param array Order*
 * \param size es la longitud del array
 * \return Esta funci�n devuelve -1 si el array ya contiene data, 0 si est� vacio.
 */
int validateOrderData(Order* array, int size) {
    int retorno;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 1) {
                retorno = 0;
                break;
            } else {
            	retorno = -1;
            }
        }
    }
    return retorno;
}
