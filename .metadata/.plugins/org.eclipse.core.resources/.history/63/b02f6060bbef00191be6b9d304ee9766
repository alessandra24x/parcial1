#define TEXT_SIZE 51
#define TEXT_CUIT 20

typedef struct {
    int customerID;
    int orderID;
    char name[TEXT_SIZE];
    char cuit[TEXT_CUIT];
    char adress[TEXT_SIZE];
    char location[TEXT_SIZE];
    int isEmpty;
}Customer;

int customer_init(Customer array[], int size);
int customer_searchEmpty(Customer array[], int size, int* position);
int customer_searchID(Customer array[], int size, int searchValue, int* position);
int customer_searchInt(Customer array[], int size, int searchValue, int* position);
int customer_searchString(Customer array[], int size, char* searchValue, int* index);
int customer_add(Customer array[], int size, int* countID);
int customer_modify(Customer array[], int size);
int customer_remove(Customer array[], int size);
int customer_sort(Customer* array, int size);
int customer_show(Customer* array, int size);
void setCustomer(Customer array[], int searchEmpty, int customerIDAux, char nameAux[], char cuitAux[],
                char adressAux[], char locationAux[]);
