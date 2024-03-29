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
  int option_submenu;
  int countID = 0;
  int order_countID = 0;

	Customer arrayCustomer[QTY_CUSTOMER];
	customer_init(arrayCustomer,QTY_CUSTOMER);
	Order arrayOrder[QTY_ORDER];
	order_init(arrayOrder,QTY_ORDER);

  setCustomer(arrayCustomer, 1, 1, "Telefonica", "30112233445", "Lima 1234", "CABA");
  setCustomer(arrayCustomer, 2, 2, "DATASOFT", "30445566776", "Corrientes 2547", "CABA");
  setCustomer(arrayCustomer, 3, 3, "NESTLE", "30889955219", "Cucha Cucha 555", "Lanus");
  setCustomer(arrayCustomer, 4, 4, "TERRABUSI", "30567814235", "Rocha 784", "Quilmes");
  setCustomer(arrayCustomer, 5, 5, "DIA", "31545812533", "Mitre 750", "Avellaneda");
  setCustomer(arrayCustomer, 6, 6, "QUILMES", "30514857596", "Rocha 741", "Quilmes");
  
  setOrder(arrayOrder, 1, 1, 1, 1000, 200, 145, 230, "Completado");
  setOrder(arrayOrder, 2, 2, 1, 800, 210, 45, 30, "Completado");
  setOrder(arrayOrder, 3, 3, 2, 100, 0, 0, 0, "Pendiente");
  setOrder(arrayOrder, 4, 4, 2, 300, 0, 0, 0, "Pendiente");
  setOrder(arrayOrder, 5, 5, 3, 1500, 500, 150, 270, "Completado");
  setOrder(arrayOrder, 6, 6, 4, 750, 100, 50, 70, "Completado");
  setOrder(arrayOrder, 7, 7, 1, 200, 0, 0, 0, "Pendiente");
  setOrder(arrayOrder, 8, 8, 5, 30, 10, 5, 3, "Completado");
  setOrder(arrayOrder, 9, 9, 6, 456, 0, 0, 0, "Pendiente");

  do {
		 utn_getUnsignedInt("\n\n1) Alta del Cliente \n2) Modificar Cliente \n3) Baja del Cliente \n4) Crear Pedido de Recoleccion \n5) Modificar Pedido \n6) Baja del Pedido \n7) Procesar Residuos \n8) Imprimir Clientes \n9) Imprimir pedidos Pendientes \n10) Imprimir pedidos Completados \n11) Informes \n12) Salir\n\n",
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
                } else {
                  printf("Debe cargar un Pedido antes");
                }
              break;
              case 11:
              if(validateOrderData(arrayOrder, QTY_ORDER) == 0) {
                  printf("Informes");
                  utn_getUnsignedInt("\n\n1) Cliente con mas pedidos Pendientes \n2) Cliente con mas pedidos Completados \n3) Cliente con mas pedidos \n4) Cliente que recicló mas kilos \n5) Cliente que recicló menos kilos \n6) Cantidad de clientes que reciclaron mas de 1000 kilos y menos de 100 kilos \n7) Imprimir pedidos Completados con % de plástico reciclado \n8) Pedidos pendientes por Localidad \n9) Cantidad de kilos de Polipropileno reciclado promedio por cliente \n10) Cantidad de kilos totales reciclada por tipo de plástico\n11) Salir\n\n",
                 "\nError",1,sizeof(int),1,11,1,&option_submenu);
                } else {
                  printf("Debe cargar algún dato antes");
                }
                  switch(option_submenu) {
                    case 1:
                      printf("\nCliente con mas pedidos Pendientes\n");
                      customer_moreOrderPendingStatus(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 2:
                      printf("\nCliente con mas pedidos Completados\n");
                      customer_moreOrderCompleteStatus(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 3:
                      printf("\nCliente con mas pedidos\n");
                      customer_moreOrder(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 4:
                      printf("\nCliente que recicló mas kilos\n");
                      customer_moreRecycle(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 5:
                      printf("\nCliente que recicló menos kilos\n");
                      customer_LessRecycle(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 6:
                      printf("\nCantidad de clientes que reciclaron mas de 1000 kilos y menos de 100 kilos\n");
                      customer_more1000KgLess100KgRecycle(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 7:
                      printf("\nImprimir pedidos Completados con porcentaje de plástico reciclado\n");
                      order_statusCompleteWithAverage(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 8:
                      printf("\nPedidos pendientes por Localidad\n");
                      customer_location(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 9:
                      printf("\nCantidad de kilos de Polipropileno reciclado promedio por cliente\n");
                      customer_averageKgPP(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 10:
                      printf("\nCantidad de kilos totales reciclada por tipo de plástico\n");
                      customer_totalKgWasteShow(arrayCustomer,QTY_CUSTOMER,arrayOrder, QTY_ORDER);
                    break;
                    case 11:
                      printf("Salir\n");
                    break;
                    default:
                      printf("\nOpcion no valida");
                  }
              break;
              case 12:
            	  printf("Salir");
            	  printf("\nSaliendo...");
              break;

	            default:
	              printf("\nOpcion no valida");
	        }
	    }
	    while(option != 12);
	    return 0;
}
