#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "order.h"
#include "customer.h"

/** \brief Calcula el cliente con la mayor cantidad de Ordenes en estado "Pendiente"
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param sizeOrder es la longitud del array de la estructura Order
* \return int Return (-1) si hay algún error con el array o su longitud [Invalid length or NULL pointer] - (0) si encuentra el cliente exitosamente
*
*/
int customer_moreOrderPendingStatus(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int indexMax;
  int countStatusPending = 0;
  int max = 0;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        order_pendingStatus(arrayOrder, sizeOrder,&countStatusPending, array[i].customerID);
        if(countStatusPending > max) {
        	indexMax = i;
        	max = countStatusPending;
        }
      }
    }
    printf("\nEl cliente con la mayor cantidad de Ordenes con estado pendiente es: %s\n",array[indexMax].name);
    retorno = 0;
  }
 return retorno;
}

/** \brief Verifica los pedidos en estado "Completado" y a través de un contador devuelve la cantidad de estos
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \param *countStatusComplete Puntero que hace relación a un contador que ira acumulando la cantidad de pedidos en estado "Completado"
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente con pedido en estado "Completado").
*/
int order_completeStatus(Order* array, int size, int *countStatusComplete, int customerID) {
  int retorno = -1;
  int i;
  int countStatus = 0;
    if(array!= NULL && size > 0) {
      for(i = 0; i < size; i++) {
        if(array[i].isEmpty == 0) {
          continue;
        } 
        if(array[i].customerID == customerID && strcmp(array[i].status, "Completado") == 0) {
          countStatus++;
        }
      }
      retorno = 0;
  }
  *countStatusComplete = countStatus;
  return retorno;
}

/** \brief Calcula el cliente con la mayor cantidad de Ordenes en estado "Completado"
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param sizeOrder es la longitud del array de la estructura Order
* \return int Return (-1) si hay algún error con el array o su longitud [Invalid length or NULL pointer] - (0) si encuentra el cliente exitosamente
*
*/
int customer_moreOrderCompleteStatus(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int indexMax;
  int countStatusComplete = 0;
  int max =0;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        order_completeStatus(arrayOrder, sizeOrder,&countStatusComplete, array[i].customerID);
        if(countStatusComplete > max) {
        	indexMax = i;
        	max = countStatusComplete;
        }
      }
    }
    printf("\nEl cliente con la mayor cantidad de Ordenes con estado completado es: %s\n",array[indexMax].name);
    retorno = 0;
  }
 return retorno;
}

/** \brief Verifica todos los pedidos y a través de un contador devuelve la cantidad de estos
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \param *countOrder Puntero que hace relación a un contador que ira acumulando la cantidad de pedidos
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente con pedido).
*/
int order(Order* array, int size, int *countOrder, int customerID) {
  int retorno = -1;
  int i;
  int countOrderAux = 0;
    if(array!= NULL && size > 0) {
      for(i = 0; i < size; i++) {
        if(array[i].isEmpty == 0) {
          continue;
        }
        if(array[i].customerID == customerID) {
          countOrderAux++;
        }
      }
      retorno = 0;
  }
  *countOrder = countOrderAux;
  return retorno;
}

/** \brief Calcula el cliente con la mayor cantidad de Ordenes
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param sizeOrder es la longitud del array de la estructura Order
* \return int Return (-1) si hay algún error con el array o su longitud [Invalid length or NULL pointer] - (0) si encuentra el cliente exitosamente
*
*/
int customer_moreOrder(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int indexMax;
  int countOrder = 0;
  int max = 0;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        order(arrayOrder, sizeOrder,&countOrder, array[i].customerID);
        if(countOrder > max) {
        	indexMax = i;
        	max = countOrder;
        }
      }
    }
    printf("\nEl cliente con la mayor cantidad de Ordenes es: %s\n",array[indexMax].name);
    retorno = 0;
  }
 return retorno;
}

/** \brief Verifica que un cliente tenga al menos un pedido en estado "Completado", calcula el total de kilos reciclados y lo devuelve
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \param *countKg Puntero que hace relación a un contador que ira acumulando la cantidad de kilos reciclados
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente con pedido "Completado").
*/
int customer_qtyRecycle(Order* array, int size, int *countKg, int customerID) {
	int retorno = -1;
	  int i;
	  int countKgAux = 0;
    int sum = 0;
	    if(array!= NULL && size > 0) {
	      for(i = 0; i < size; i++) {
	        if(array[i].isEmpty == 0) {
	          continue;
	        }
	        if(array[i].customerID == customerID && strcmp(array[i].status, "Completado") == 0) {
	          sum = sum + array[i].HDPE_kg + array[i].LDPE_kg + array[i].PP_kg;
            
              countKgAux = sum;
            
	        }
	      }
	      retorno = 0;
	  }
	  *countKg = countKgAux;
	  return retorno;
}

/** \brief Calcula el cliente con la mayor cantidad de kilos reciclados
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param sizeOrder es la longitud del array de la estructura Order
* \return int Return (-1) si hay algún error con el array o su longitud [Invalid length or NULL pointer] - (0) si encuentra el cliente exitosamente
*
*/
int customer_moreRecycle(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int indexMax;
  int count_Kg = 0;
  int max;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        customer_qtyRecycle(arrayOrder, sizeOrder,&count_Kg, array[i].customerID);
        if(count_Kg > max) {
        	indexMax = i;
        	max = count_Kg;
        }
      }
    }
    printf("\nEl cliente con la mayor cantidad de Kilos es: %s\n",array[indexMax].name);
    retorno = 0;
  }
 return retorno;
}

/** \brief Calcula el cliente con la menor cantidad de kilos reciclados
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param sizeOrder es la longitud del array de la estructura Order
* \return int Return (-1) si hay algún error con el array o su longitud [Invalid length or NULL pointer] - (0) si encuentra el cliente exitosamente
*
*/
int customer_LessRecycle(Customer* array, int size, Order* arrayOrder, int sizeOrder) { 
  int retorno = -1;
  int i;
  int indexMax;
  int count_Kg = 0;
  int min = 1;
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        customer_qtyRecycle(arrayOrder, sizeOrder,&count_Kg, array[i].customerID);

        if(count_Kg > 0) {
          if(count_Kg < min)
            indexMax = i;
            min = count_Kg;
        }
      }
    }
    printf("\nEl cliente con la menor cantidad de Kilos es: %s\n",array[indexMax].name);
    retorno = 0;
  }
 return retorno;
}

/** \brief Calcula el cliente con mas de 1000 kilos reciclados y el cliente con menos de 100 kilos reciclados
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param sizeOrder es la longitud del array de la estructura Order
* \return int Return (-1) si hay algún error con el array o su longitud [Invalid length or NULL pointer] - (0) si encuentra los clientes exitosamente
*
*/
int customer_more1000KgLess100KgRecycle(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int indexMax;
  int count_Kg = 0;
  int countMore1000 = 0;
  int countMore100 = 0;
  
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        customer_qtyRecycle(arrayOrder, sizeOrder,&count_Kg, array[i].customerID);
      
        if(count_Kg > 1000) {
        	countMore1000++;
        } else if(count_Kg < 100 && count_Kg > 0) {
          countMore100++;
        }
      }
    }
    printf("\nCantidad de clientes que reciclaron mas de 1000 kilos: %d\n", countMore1000);
    printf("\nCantidad de clientes que reciclaron menos de 100 kilos: %d\n", countMore100);
    retorno = 0;
  }
 return retorno;
}

/** \brief Verifica que un cliente tenga al menos un pedido en estado "Completado", calcula el promedio de kilos reciclados y lo devuelve junto con el cuit del cliente
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \param char* cuit es el cuit del cliente
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente con pedido "Completado" y emite el calculo del promedio).
*/
int customer_averageRecycle(Order* array, int size, int customerID, char* cuit) {
	int retorno = -1;
	  int i;
    float sumTotal = 0, sumProcesados = 0;
    float averageAux;
    int indexAux;
	    if(array!= NULL && size > 0) {
	      for(i = 0; i < size; i++) {
	        if(array[i].isEmpty == 0) {
	          continue;
	        }
	        if(array[i].customerID == customerID && strcmp(array[i].status, "Completado") == 0) {
	          sumTotal =  array[i].HDPE_kg + array[i].LDPE_kg + array[i].PP_kg + array[i].descartados;

            sumProcesados = array[i].HDPE_kg + array[i].LDPE_kg + array[i].PP_kg;
            averageAux = sumProcesados / sumTotal * 100;
            printf("\nPedido id %d\nCuit: %s\nPorcentaje: %.2f\n\n", array[i].orderID, cuit, averageAux);    
	        }
	      }
	      retorno = 0;
	  }
	  return retorno;
}

/** \brief Verifica que un cliente este "activo" y llama a la funcion que procesa el promedio de kilos reciclados enviando el id del cliente y el cuit del mismo
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param int sizeOrder es la longitud del array de la estructura Order
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente activo y envia los parametros necesarios para emitir el promedio).
*/
int order_statusCompleteWithAverage(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int indexMax;
  float average = 0;
  
  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {
        continue;
      } else {
        
        customer_averageRecycle(arrayOrder, sizeOrder, array[i].customerID, array[i].cuit);
      }
    }
    retorno = 0;
  }
 return retorno;
}
/** \brief Verifica los pedidos en estado pendiente y a través de un contador devuelve la cantidad de estos
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \param int* count Puntero que hace relación a un contador que ira acumulando la cantidad de pedidos en estado pendiente
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK(encuentra al menos un pedido).
*/
int order_statusPendingLocation(Order* array, int size, int* count, int customerID) {
  int retorno = -1;
	int i;
    
	    if(array!= NULL && size > 0) {
	      for(i = 0; i < size; i++) {
	        if(array[i].isEmpty == 0) {
	          continue;
	        }
	        if(customerID == array[i].customerID && strcmp(array[i].status, "Pendiente") == 0) {
	          (*count)++;
	        }
	      }
	      retorno = 0;
	  }
	  return retorno;
}

/** \brief Pide una localidad al usuario, recorre el array de Order verificando que un cliente este "activo" y tenga la localidad ingresada, si esto se cumple llama a la funcion que cuenta los pedidos pendientes y devuelve la cantidad relacionada con la localidad
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param int sizeOrder es la longitud del array de la estructura Order
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente activo).
*/
int customer_location(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
int retorno = -1;
int i, count = 0;
char location[51]; 

  utn_getName("\nIngrese una localidad: ", "Error, ingrese una localidad valida", 1,51, 2,location);

  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {  
        continue;
      } else if(strcmp(array[i].location,location) == 0) {
          order_statusPendingLocation(arrayOrder, sizeOrder, &count, array[i].customerID);
      }
    }
    printf("\nLos pedidos pendientes para la localidad: %s es: %d\n",location, count);
    retorno = 0;
  }
 return retorno;
}

/** \brief Verifica que el cliente tenga al menos un pedido y este en estado "Completado", si esto se cumple se aplica logica para contar cuantos clientes tienen pedidos en estado "Completado" y devuelve esa cantidad
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param int sizeOrder es la longitud del array de la estructura Order
* \return Esta función devuelve la cantidad de clientes con al menos un pedido en estado "Completado"
*/
int customer_count(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int count = 0;

  if(array!= NULL && size > 0) {
      for(int i = 0; i < size; i++) {
        if(array[i].isEmpty == 0) {  
        continue;
      }

        int customerHasOrder = 0;

        for(int j = 0; j < sizeOrder; j++) {
          if(array[i].isEmpty != 0 && strcmp(arrayOrder[i].status, "Completado") == 0) {
            customerHasOrder = 1;
            continue;
          } 
        }

        if(customerHasOrder == 1) {
            count++;
          }
    }
  }
  return count;
}

/** \brief Verifica los pedidos en estado "Completado" y aplica lógica para sumar la cantidad de Polipropileno reciclado y la devuelve
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \param *totalPPKg Puntero que hace relación a la cantidad de Polipropileno total reciclado por cliente
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente con pedido en estado "Completado").
*/
int order_completeStatusPP(Order* array, int size, int customerID, float *totalPPKg) {
  int retorno = -1;
  int i;
  float count = 0;
  int sum = 0, sumAux = 0;

    if(array!= NULL && size > 0) {
      for(i = 0; i < size; i++) {
        if(array[i].isEmpty == 0) {
          continue;
        } 
        if(array[i].customerID == customerID && strcmp(array[i].status, "Completado") == 0 && array[i].PP_kg > 0) {
          sum += array[i].PP_kg;
          sumAux = sum;
        }
      }
      *totalPPKg = sumAux;
      retorno = 0;
  }
  return retorno;
}

/** \brief Verifica que un cliente este "activo" y llama a la funcion que emite la cantidad de polipropileno reciclada por cliente, aplica logica para sacar el promedio total y lo devuelve
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param int sizeOrder es la longitud del array de la estructura Order
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente activo).
*/
int customer_averageKgPP(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
  int retorno = -1;
  int i;
  int count = 0;
  float totalPPKg = 0, average = 0, sum = 0;
  count = customer_count(array, size, arrayOrder, sizeOrder);
  if(array!= NULL && size > 0) {
      for(i = 0; i < size; i++) {
        if(array[i].isEmpty == 0) {
          continue;
        } else {
          order_completeStatusPP(arrayOrder, sizeOrder, array[i].customerID, &totalPPKg);
          sum += totalPPKg;
        }
    }
    average = sum / count;
    printf("\nLa cantidad de kilos de Polipropileno reciclada promedio es de %.2f\n", average);
    retorno = 0;
  }
    return retorno;
}

/** \brief Verifica que el cliente tenga al menos un pedido y este en estado "Completado", si esto se cumple se aplica logica para sacar el total de kilos reciclados por tipo de plastico, luego el usuario ingresa el tipo de plastico que desea chquear a través de un submenu y se muestra la información
* \param Order* array es el array de la estructura Order
* \param int size es la longitud del array de la estructura Order
* \param customerID es el ID del cliente con el que se relaciona el pedido
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un pedido).
*/
int order_totalKgWaste(Order* array, int size, int customerID, char* cuit) {
  int retorno = -1;
	int i, option;
  int totalHDPE_kg = 0;
  int totalLDPE_kg = 0;
  int totalPP_kg = 0;

	    if(array!= NULL && size > 0) {
	      for(i = 0; i < size; i++) {
	        if(array[i].isEmpty == 0) {
	          continue;
	        } if(array[i].customerID == customerID && strcmp(array[i] .status, "Completado") == 0) {
            totalHDPE_kg += array[i].HDPE_kg;
            totalLDPE_kg += array[i].LDPE_kg;
            totalPP_kg += array[i].PP_kg;
          }
	      }

    do {
       utn_getUnsignedInt("\n Ingrese uno de los 3 tipos de plástico: \n\n 1- HDPE(Polietileno de alta densidad)\n 2- LDPE(Polietileno de baja densidad)\n 3- PP(Polipropileno)\n 4- Salir \n\n", "\nError",1,sizeof(int),1,11,1,&option);

    switch(option) {
        case 1:
          printf("CUIT: %s\n", cuit);
          printf("La cantidad de kilos totales recicladas de HDPE es: %d\n", totalHDPE_kg);
        break;
        case 2:
          printf("CUIT: %s\n", cuit);
          printf("La cantidad de kilos totales recicladas de HDPE es: %d\n", totalLDPE_kg);
        break;
        case 3:
          printf("CUIT: %s\n", cuit);
          printf("La cantidad de kilos totales recicladas de HDPE es: %d\n", totalPP_kg);
        break;
        case 4:
        break;
        default:
        printf("Opción invalida");
      }

    } while(option != 4);
    	retorno = 0;
	  }

	  return retorno;
}

/** \brief Pide un cuit al usuario, recorre el array de Customer verificando que un cliente este "activo" y tenga el cuit ingresado, si esto se cumple llama a la funcion que procesa el total de kilos reciclados por tipo de plastico enviando el id del cliente y el cuit del mismo
* \param Customer* array es el array de la estructura Customer
* \param int size es la longitud del array de la estructura Customer
* \param Order* arrayOrder es el array de la estructura Order
* \param int sizeOrder es la longitud del array de la estructura Order
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK (encuentra al menos un cliente activo).
*/
int customer_totalKgWasteShow(Customer* array, int size, Order* arrayOrder, int sizeOrder) {
int retorno = -1;
int i;
char cuit[51];

  utn_getCUIT("\nIngrese Cuit:\n", "Error, Cuit invalido", 2, cuit);

  if(array!= NULL && size > 0) {
    for(i = 0; i < size; i++) {
      if(array[i].isEmpty == 0) {  
        continue;
      } else if(strcmp(array[i].cuit,cuit) == 0) {
          order_totalKgWaste(arrayOrder, sizeOrder, array[i].customerID, array[i].cuit);
      }
    }
    
    retorno = 0;
  }
 return retorno;
}
