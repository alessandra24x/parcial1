#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "customer.h"
#include "utn.h"
#include "report.h"

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

  //setOrder(arrayOrder, 1, 1, 2, 90, "Pendiente");
  //setOrder(arrayOrder, 2, 2, 3, 110, "Pendiente");
  //setOrder(arrayOrder, 3, 3, 1, 30, "Pendiente");
  //setOrder(arrayOrder, 4, 4, 1, 90, "Pendiente");

  //setWaste(arrayOrder, 1, 1,  30, 40, 18, "Completado");
  //setWaste(arrayOrder, 2, 4, 60, 20, 9, "Completado");
  //setWaste(arrayOrder, 3, 3, 18, 2, 10, "Completado");
  //setWaste(arrayOrder, 4, 2, 18, 82, 10, "Completado");


  do {
		 utn_getUnsignedInt("\n\n1) Alta del Cliente \n2) Modificar Cliente \n3) Baja del Cliente \n4) Crear Pedido de Recoleccion \n5) Modificar Pedido \n6) Baja del Pedido \n7) Procesar Residuos \n8) Imprimir Clientes \n9) Imprimir pedidos Pendientes \n10) Imprimir pedidos Completados \n11) Salir\n",
                 "\nError",1,sizeof(int),1,11,1,&option);
	        switch(option) {
	            case 1:
                printf("Alta de Cliente\n");
                customer_add(arrayCustomer,QTY_CUSTOMER,&countID);
	              break;
	            case 2:
                if(validateCustomerData(arrayCustomer,QTY_CUSTOMER) == 0) {
                  printf("Modificar el registro de un Cliente\n");
                  customer_modify(arrayCustomer,QTY_CUSTOMER);
                } else {
                  printf("Debe cargar un Cliente antes");
                }
              break;
	            case 3:
                if(validateCustomerData(arrayCustomer,QTY_CUSTOMER) == 0) {
                  printf ("Dar de baja un Cliente\n");
                  customer_remove(arrayCustomer,QTY_CUSTOMER, arrayOrder);
                } else {
                  printf("Debe cargar un Cliente antes");
                }
              break;
	            case 4:
                if(validateCustomerData(arrayCustomer,QTY_CUSTOMER) == 0) {
                  printf("Crear Pedido de Recoleccion\n");
                  customer_show(arrayCustomer,QTY_CUSTOMER);
                  order_pickup(arrayOrder, QTY_ORDER, arrayCustomer, QTY_CUSTOMER, &order_countID);
                } else {
                  printf("Debe cargar un Cliente antes");
                }
              break;
              case 5:
                if(validateOrderData(arrayOrder, QTY_ORDER) == 0) {
                  printf("Modificar Pedido");
                  order_modify(arrayOrder, QTY_ORDER);
                } else {
                  printf("Debe cargar un Pedido antes");
                }
              break;
              case 6:
                if(validateOrderData(arrayOrder, QTY_ORDER) == 0) {
                  printf("Baja del Pedido");
                  order_remove(arrayOrder, QTY_ORDER);
                } else {
                  printf("Debe cargar un Pedido antes");
                }
              break;
	            case 7:
                if(validateOrderData(arrayOrder, QTY_ORDER) == 0) {
                  printf("Procesar Residuos\n");
                  order_show(arrayOrder, QTY_ORDER);
                  order_processWaste(arrayOrder, QTY_ORDER);
                } else {
                  printf("Debe cargar un Pedido antes");
                }
	            break;
	            case 8:
                if(validateCustomerData(arrayCustomer,QTY_CUSTOMER) == 0) {
                  printf("Imprimir Clientes\n");
                  customerPendingStatus_show(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                } else {
                  printf("Debe cargar un Cliente antes");
                }
              break;
              case 9:
                if(validateOrderData(arrayOrder, QTY_ORDER) == 0) {
                  printf("Imprimir pedidos Pendientes\n");
                  orderPendingStatus_show(arrayOrder, QTY_ORDER);
                } else {
                  printf("Debe cargar un Pedido antes");
                }
              break;
              case 10:
                if(validateOrderData(arrayOrder, QTY_ORDER) == 0) {
                  printf("Imprimir pedidos Completados\n");
                  orderCompleteStatus_show(arrayOrder, QTY_ORDER);
                  customer_mostWaste(arrayOrder, QTY_ORDER);
                } else {
                  printf("Debe cargar un Pedido antes");
                }
              break;
              case 11:
                  printf("Salir");
	                printf("\nSaliendo...");
                  break;
	            default:
	              printf("\nOpcion no valida");
	        }
	    }
	    while(option != 11);
	    return 0;
}
