#define TEXT_SIZE 51
#define TEXT_CUIT 20

typedef struct {
    int orderID;
    int totalKg;
    char status[TEXT_SIZE];
    int isEmpty;
}Order;

order_init(Order array[], int size);
order_searchEmpty(Order array[], int size, int* position);
order_searchID(Order array[], int size, int searchValue, int* position);
order_pickup(Order array[], int size, Customer arrayCustomer[], int sizeCustomer);
