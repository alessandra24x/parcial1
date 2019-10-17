#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "order.h"
#include "customer.h"

/** \brief Indica que todas las posiciones en el array estan vacias, para eso se pone un FLAG (isEmpty) en TRUE en todas las posiciones del array
* \param Customer array es el array de la estructura Customer
* \param int size es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int customer_init(Customer array[], int size) {
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
* \param Customer array es el array de la estructura Customer
* \param int size Tama�o del array
* \param int* position Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int customer_searchEmpty(Customer array[], int size, int* position) {
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
int customer_searchID(Customer array[], int size, int searchValue, int* position) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0;i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(array[i].customerID == searchValue) {
                retorno = 0;
                if(position != NULL) {
                *position = i;
                }
                break;
            }
        }
    }
    return retorno;
}


/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param Customer array es el array de la estructura Customer
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int customer_add(Customer array[], int size, int* countID) {
    int retorno = -1;
    int position;
    if(array != NULL && size > 0 && countID != NULL) {
        if(customer_searchEmpty(array,size,&position) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
            (*countID)++;
            array[position].customerID = *countID;
            array[position].isEmpty = 1;
            utn_getName("Ingrese el nombre de la compa�ia: ","\nError, ingrese un nombre valido",1,TEXT_SIZE,1,array[position].name);
            utn_getCUIT("Ingrese el CUIT de la compa�ia: ", "\nError, ingrese un CUIT valido", 1, array[position].cuit);
            utn_getText("\nIngrese su direccion: ","\nError, ingrese una direccion valida",1,TEXT_SIZE,1,array[position].adress);
            utn_getText("\nIngrese su localidad: ","\nError, ingrese una localidad valida",1,TEXT_SIZE,1,array[position].location);
            printf("\n Posicion: %d\n Id: %d\n Nombre: %s\n CUIT: %s\n Direccion: %s\n Localidad: %s",
                   position,array[position].customerID,array[position].name,array[position].cuit,array[position].adress,array[position].location);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Solicita un ID para modificar los datos de una posici�n especifica en el array
* \param Customer array es el array de la estructura Customer
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int customer_modify(Customer array[], int size) {
    int retorno = -1;
    int position;
    int id;
    char option;
    if(array != NULL && size > 0) {
        utn_getUnsignedInt("\nId a modificar: ","\nError, ingrese un Id valido",1,sizeof(int),1,size,1,&id);
        if(customer_searchID(array,size,id,&position) == -1) {
            printf("\nNo existe este Id de cliente");
        } else {
            do {
            	printf("\n Posicion: %d\n Id: %d\n Nombre: %s\n CUIT: %s\n Direccion: %s\n Localidad: %s",
            	                   position,array[position].customerID,array[position].name,array[position].cuit,array[position].adress,array[position].location);
                utn_getChar("\nModificar: A(domicilio) B(localidad) S(salir)","\nError, ingrese una opci�n valida",'A','Z',1,&option);
                switch(option) {
                    case 'A':
                    	utn_getText("\n Ingrese domicilio: ","\nError, ingrese un domicilio valido",1,TEXT_SIZE,1,array[position].adress);
                        break;
                    case 'B':
                    	utn_getText("\n Ingrese localidad: ","\nError, ingrese una localidad valida",1,TEXT_SIZE,1,array[position].location);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(option != 'S');
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param Customer array es el array de la estructura Customer
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int customer_remove(Customer array[], int size, Order arrayOrder[]) {
    int retorno = -1;
    int position;
    int id;
    if(array != NULL && size > 0) {
        utn_getUnsignedInt("\nId a cancelar: ","\nError, ingrese un Id valido",1,sizeof(int),1,size,1,&id);
        if(customer_searchID(array,size,id,&position) == -1) {
            printf("\nNo existe este Id");
        } else {
            array[position].isEmpty = 0;
            strcpy(array[position].name,"");
            strcpy(array[position].cuit,"");
            strcpy(array[position].adress,"");
            strcpy(array[position].location,"");
            arrayOrder[position].isEmpty = 0;
            arrayOrder[position].totalKg = 0;
            arrayOrder[position].LDPE_kg = 0;
            arrayOrder[position].HDPE_kg = 0;
            arrayOrder[position].PP_kg = 0;
            strcpy(arrayOrder[position].status,"");
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Lista los elementos del array Customer
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int customer_show(Customer* array, int size) {
  int retorno = -1;
  int i;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        printf("\n Id de cliente: %d\n Nombre: %s\n CUIT: %s\n Direcci�n: %s\n Localidad: %s\n",
                       array[i].customerID,array[i].name,array[i].cuit,array[i].adress,array[i].location);
      }
    }
    retorno = 0;
  }
 return retorno;
}

/** \brief Setea valores fijos para agilizar las pruebas
* \param Customer[] array es el array de la estructura Customer
* \param int size es la longitud del array
*
*/
void setCustomer(Customer array[], int searchEmpty, int customerIDAux, char nameAux[], char cuitAux[],
                char adressAux[], char locationAux[]) {
  array[searchEmpty].customerID = customerIDAux;
  strcpy(array[searchEmpty].name, nameAux);
  strcpy(array[searchEmpty].cuit, cuitAux);
  strcpy(array[searchEmpty].adress, adressAux);
  strcpy(array[searchEmpty].location, locationAux);
  array[searchEmpty].isEmpty = 1;
}

/** \brief Solicita un ID de cliente para crear un pedido nuevo
* \param Order array es el array de la estructura Order
* \param size int Tama�o del array de Order
* \param Customer arrayCustomer es el array de la estructura Customer
* \param sizeCustomer es el Tama�o del array de Customer
* \param order_countID int* Puntero al ID unico que se va a asignar al nuevo pedido
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo pedido exitosamente
*
*/
int order_pickup(Order array[], int size, Customer arrayCustomer[], int sizeCustomer, int* order_countID) {
    int retorno = -1;
    int auxID;
    int position;
    if(order_searchEmpty(array,size,&position) == -1) {
        printf("\nNo hay lugares vacios");
    } else {
      utn_getUnsignedInt("\nIngrese el Id del cliente: ","\nError, Id invalido",1,size,1,size,2,&auxID);

        if(customer_searchID(arrayCustomer, sizeCustomer, auxID, NULL) == 0) {
          array[position].customerID = auxID;
          utn_getUnsignedInt("\nIngrese la cantidad de kilos totales que se recolectaran: ",
                "\nError, la cantidad es invalida",1,size,1,size,2,&array[position].totalKg);
          (*order_countID)++;
          array[position].orderID = *order_countID;
          array[position].isEmpty = 1;
          strcpy(array[position].status, "Pendiente");
          } else {
            printf("El Id ingresado no pertenece a ningun cliente");
          }

    retorno = 0;
    }

  return retorno;
}

/** \brief Lista los elementos del array Customer con la cantidad de pedidos en estado pendiente que tengan
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de Customer
* \param order* arrayOrder es el array de la estructura Order
* \param int size es la longitud del array de Order
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int customerPendingStatus_show(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int countStatusPending = 0;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        order_pendingStatus(arrayOrder, sizeOrder,&countStatusPending, array[i].customerID);
        printf("\n Id de cliente: %d\n Nombre: %s\n CUIT: %s\n Direcci�n: %s\n Localidad: %s\n Cantidad de Ordenes con estado pendiente: %d\n\n",
                       array[i].customerID,array[i].name,array[i].cuit,array[i].adress,array[i].location, countStatusPending);
      }
    }
    retorno = 0;
  }
 return retorno;
}

/** \brief Valida que el array este vacio o con datos ya cargados
 * \param array Customer*
 * \param size es la longitud del array
 * \return Esta funci�n devuelve -1 si el array ya contiene data, 0 si est� vacio.
 */
int validateCustomerData(Customer* array, int size) {
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
