int customer_OrderPendingStatus(Order* array, int size, int *countStatusPending, int customerID);
int customer_moreOrderPendingStatus(Customer* array, int size, Order* arrayOrder, int sizeOrder);

int order_completeStatus(Order* array, int size, int *countStatusPending, int customerID);
int customer_moreOrderCompleteStatus(Customer* array, int size, Order* arrayOrder, int sizeOrder);

int order(Order* array, int size, int *countOrder, int customerID);
int customer_moreOrder(Customer* array, int size, Order* arrayOrder, int sizeOrder);

int customer_qtyRecycle(Order* array, int size, int *countKg, int customerID);
int customer_moreRecycle(Customer* array, int size, Order* arrayOrder, int sizeOrder);
int customer_LessRecycle(Customer* array, int size, Order* arrayOrder, int sizeOrder);
int customer_more1000KgLess100KgRecycle(Customer* array, int size, Order* arrayOrder, int sizeOrder);

int customer_averageRecycle(Order* array, int size, int customerID, char* cuit);
int order_statusCompleteWithAverage(Customer* array, int size, Order* arrayOrder, int sizeOrder);

int order_statusPendingLocation(Order* array, int size, int* count, int customerID);
int customer_location(Customer* array, int size, Order* arrayOrder, int sizeOrder);

int customer_count(Customer* array, int size, Order* arrayOrder, int sizeOrder);
int order_completeStatusPP(Order* array, int size, int customerID, float *totalPPKg, int *countCustomer);
int customer_averageKgPP(Customer* array, int size, Order* arrayOrder, int sizeOrder);

int order_totalKgWaste(Order* array, int size, int customerID, char* cuit);
int customer_totalKgWasteShow(Customer* array, int size, Order* arrayOrder, int sizeOrder);
