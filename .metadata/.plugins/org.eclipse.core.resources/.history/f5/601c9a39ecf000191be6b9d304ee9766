#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "customer.h"
#include "utn.h"

#define QTY_CUSTOMER 100
#define QTY_ORDER 1000


int main() {

  int option;
  int countID = 0;
  int order_countID = 0;

	Customer arrayCustomer[QTY_CUSTOMER];
	customer_init(arrayCustomer,QTY_CUSTOMER);
	Order arrayOrder[QTY_ORDER];
	order_init(arrayOrder,QTY_ORDER);

  //setCustomer(arrayCustomer, 1, 1, "Banco Galicia", "25896523587", "Chile 215", "CABA");
  //setCustomer(arrayCustomer, 2, 2, "Automotores", "65445455000", "Salta 456", "Cordoba");
  //setCustomer(arrayCustomer, 3, 3, "Flores SA", "22254486369", "Ramallo 4185", "Tucuman");
  //setCustomer(arrayCustomer, 4, 4, "Jazmin", "25896545174", "Av Independencia 2854", "CABA");
  //setCustomer(arrayCustomer, 5, 5, "Romero SRL", "23696645655", "Av Santa Fe 5501", "Santa Fe");

  do {
		 utn_getUnsignedInt("\n\n1) Alta del Cliente \n2) Modificar Cliente \n3) Baja del Cliente \n4) Crear Pedido de Recoleccion \n5) Procesar Residuos \n6) Imprimir Clientes \n7) Imprimir pedidos Pendientes \n8) Imprimir pedidos Completados \n9) Salir\n",
                 "\nError",1,sizeof(int),1,11,1,&option);
	        switch(option) {
	            case 1: //Alta
                printf("Alta de Cliente\n");
                customer_add(arrayCustomer,QTY_CUSTOMER,&countID);
	              break;
	            case 2: //Modificar
                  printf("Modificar el registro de un Cliente\n");
                  customer_modify(arrayCustomer,QTY_CUSTOMER);
                break;
	            case 3: //Baja
                  printf ("Dar de baja un Cliente\n");
                  customer_remove(arrayCustomer,QTY_CUSTOMER, arrayOrder);
                break;
	            case 4:
	                printf("Crear Pedido de Recoleccion\n");
                  customer_show(arrayCustomer,QTY_CUSTOMER);
	                order_pickup(arrayOrder, QTY_ORDER, arrayCustomer, QTY_CUSTOMER, &order_countID);
                break;
	            case 5:
                  printf("Procesar Residuos\n");
                  order_show(arrayOrder, QTY_ORDER);
                  order_processWaste(arrayOrder, QTY_ORDER);
	              break;
	            case 6:
                  printf("Imprimir Clientes\n");
                  customerPendingStatus_show(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                break;
              case 7:
                  printf("Imprimir pedidos Pendientes\n");
                  orderPendingStatus_show(arrayOrder, QTY_ORDER);
                  break;
              case 8:
                  printf("Imprimir pedidos Completados\n");
                  orderCompleteStatus_show(arrayOrder, QTY_ORDER);
                  break;
              case 9:
                  printf("Salir");
	                printf("\nSaliendo...");
                  break;
	            default:
	              printf("\nOpcion no valida");
	        }
	    }
	    while(option != 9);
	    return 0;
}
