#define TEXT_SIZE 51
#define TEXT_CUIT 20

typedef struct {
    int orderID;
    int customerID;
    int totalKg;
    int discarded;
    char status[TEXT_SIZE];
    int isEmpty;
    int HDPE_kg;
	int LDPE_kg;
	int PP_kg;
}Order;

int order_init(Order array[], int size);
int order_searchEmpty(Order array[], int size, int* position);
int order_searchID(Order array[], int size, int searchValue, int* position);

int order_modify(Order array[], int size);
int order_remove(Order array[], int size);
int order_show(Order* array, int size);
int order_processWaste(Order array[], int size);
int order_pendingStatus(Order* array, int size, int *countStatusPending, int customerID);
int orderPendingStatus_show(Order* array, int size);
int orderCompleteStatus_show(Order* array, int size);
void setOrder(Order array[], int searchEmpty, int orderIDAux, int customerIDAux, int totalKgAux, int HDPE_kgAux, int LDPE_kgAux,
int PP_kgAux, char statusAux[]);
int validateOrderData(Order* array, int size);
