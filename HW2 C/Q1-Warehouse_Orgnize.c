/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
/**************************************************************************************************/

/* Submitters
Name1: Privetname Familyname     ID: xxxxxxxx
Name2: Privetname Familyname     ID: xxxxxxxx
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
typedef struct item {
    char* name;
    int  id;
    struct wlst* warehouses;
} item;

typedef struct warehouse {
    char* location;
    int  code;
    struct itemlst* items;
} warehouse;

typedef struct itemlst {
    item* data;
    struct itemlst* next;
} itemlst;

typedef struct wlst {
    warehouse* data;
    struct wlst* next;
} wlst;


/******************************************* your's prototypes *******************************************************************************/



/******************************************* your's functions ********************************************************************************/

void print_error_message(int errid) {
#ifdef DEBUGON
    fprintf(stderr, "BGU ERROR %d\n", errid);
#else
    fprintf(stderr, "BGU ERROR\n");
#endif
    exit(-1);
}

/*DO NOT TOUCH THIS FUNCTION */
void getstring(char* buf, int length) {
    int len;
    //buf = fgets(buf, length, stdin);
    scanf("%100s", buf);
    len = (int)strlen(buf);
    if (buf[len - 1] == '\n')
        buf[len - 1] = '\0';
}

item *create_item(char *buf,int id) {
    // create dynamically an item the buf and id return the new item to add to the list
    item *new_item = (item*)malloc(sizeof(item));
    if (new_item==NULL) {
        print_error_message(1);
        return NULL;
    }
    new_item->name = (char*)malloc(strlen(buf)+1); //for /n
    if (!(new_item->name)){
        print_error_message(1);
        free(new_item);
        return NULL;
    }
    strcpy(new_item->name,buf);
    new_item->id = id;
    new_item ->warehouses = NULL;
    return new_item;
}

void add_item_to_list(itemlst **items,item *new_item) {
    // **items because  i need to move over the next item in the list
    //so i need a pointer to the pointer of the list
    itemlst *current_item = *items;
    itemlst *new_node_list = (itemlst *) malloc(sizeof(itemlst));
    if (new_node_list == NULL){
        print_error_message(1);
        free(new_node_list);
        return;
    }
    new_node_list->data = new_item;
    new_node_list->next = NULL;
    if (*items == NULL)
        *items = new_node_list;
    else {
        while (current_item->next) {
            // if it's the2 same dont change or readd to the list
            if (current_item->data->id == new_item->id) {
                printf("Item with ID %d already exists.\n", new_item->id);
                free(new_node_list);
                return;
            }
            current_item = current_item->next;
        }
        current_item->next = new_node_list;
    }
    printf(" Add new item:%s item id:%d\n", new_item->name, new_item->id);
}
//
//
warehouse *create_warehouse(char *buf,int num) {
    warehouse *new_warehouse = (warehouse *) malloc(sizeof(warehouse));
    if (new_warehouse == NULL){
        print_error_message(1);
        free(new_warehouse);
        return NULL;
    }
    new_warehouse->location = (char*)malloc(strlen(buf)+1); //for /n
    strcpy(new_warehouse->location,buf);
    if (!(new_warehouse->location)){
        print_error_message(1);
        free(new_warehouse);
        return NULL;
    }
    new_warehouse->code = num;
    new_warehouse ->items = NULL;
    return new_warehouse;
}

void add_warehouse_to_list(wlst **wlsts,warehouse *new_WareH) {
    // **wlst beacuse in need to move over the next warehouse in the list
    //so i need a pointer to the pointer of the list
    wlst *current_warehouse = *wlsts;
    wlst *new_node_warehouse = (wlst *) malloc(sizeof(wlst));
    if (new_node_warehouse == NULL) {
        print_error_message(1);
        return;
    }
    new_node_warehouse->data = new_WareH;
    new_node_warehouse->next = NULL;
    if (*wlsts == NULL)
        *wlsts = new_node_warehouse;
    else {
        while (current_warehouse->next) {
            // if it's the same dont change or readd to the list
            if (current_warehouse->data->code == new_WareH->code) {
                printf("Warehouse with Code %d already exists.\n", new_WareH->code);
                free(new_node_warehouse);
                return;
            }
            current_warehouse = current_warehouse->next;
        }
        current_warehouse->next = new_node_warehouse;
    }
    printf(" Add new Warehouse:%s Warehouse id:%d\n", new_WareH->location, new_WareH->code);
}


/*****************************************new objects and insert object functions******************************************************/



/****************************************find Matchings and register item to Warehouse*************************************************/
item *find_item(itemlst **items,int id){
    // find the item with a specific code that we want to assign
    // we need to go over all the items list and return the item with the id
    itemlst *current_items = *items;
    if (*items == NULL){
        return NULL;
    }
    while (current_items) {
        if (current_items->data->id == id){
            return (current_items->data);
    }
        current_items = current_items->next;
    }
    return NULL;
}

warehouse *find_warehouse(wlst **warehouses,int code){
    // find the warehouse with a specific code that we want to assign and return the warehouse
    wlst *current_warehouse = *warehouses;
    if (current_warehouse == NULL){
        return NULL;
    }
    while (current_warehouse) {
        if (current_warehouse->data->code == code){
            return (current_warehouse->data);
    }
        current_warehouse = current_warehouse->next;
    }
    return NULL;
}

void assign_item_to_warehouse(item *the_item,warehouse *the_warehouse){
    // create a node for the warehouse list of the specific list
    wlst *new_node_warehouse = (wlst *)malloc(sizeof(wlst));
    if (new_node_warehouse == NULL) {
        print_error_message(1);
        return;
    }
    new_node_warehouse->data = the_warehouse;
    new_node_warehouse->next = NULL;
    // create a node of the item warehouse to move over all the warehouse he is located
    wlst *current_warehouse_node = the_item->warehouses;
    if (current_warehouse_node == NULL) {
        the_item->warehouses = new_node_warehouse;
    } else {
        // go over the item warehouse list and add the new warehouse assign
        while (current_warehouse_node->next) {
            current_warehouse_node = current_warehouse_node->next;
        }
        current_warehouse_node->next = new_node_warehouse;
    }
}

void assign_warehouse_to_item(item *the_item,warehouse *the_warehouse){
    // create a node for this warehouse
    itemlst *new_item_node = (itemlst *) malloc(sizeof (itemlst));
    if (new_item_node == NULL) {
        print_error_message(1);
        return;
    }
    new_item_node->data = the_item;
    new_item_node->next = NULL;
    itemlst *current_item_list = the_warehouse->items;
    // there is no item in the warehouse at all just but the new node at first
    if (current_item_list==NULL)
        the_warehouse->items = new_item_node;
    // list not empty we go to the last node and assert
    else {
        while (current_item_list->next) {
            current_item_list = current_item_list->next;
        }
        current_item_list->next = new_item_node;
    }
}



/********************************************uregisters objects*************************************************************************/

void remove_item_from_warehouse(item *item_remove,warehouse *warehouse_remove){
    itemlst *current_warehouse_location= warehouse_remove->items;
    itemlst *prev_warehouse_location=NULL;
    while (current_warehouse_location){
        if (current_warehouse_location->data == item_remove){
            // need to remove the first item
            if (prev_warehouse_location==NULL)
                // current is a pointer, so i need to update the warehouse list itself
                // i could do also *current = *(current->next)
                warehouse_remove->items = current_warehouse_location->next;

            else
                prev_warehouse_location->next = current_warehouse_location->next;
            free(current_warehouse_location);
            printf("The item %d has been removed\n",item_remove->id);
            return;
        }
        prev_warehouse_location = current_warehouse_location;
        current_warehouse_location = current_warehouse_location->next;
    }
    printf("didnt find item %d in the warehouse %d",item_remove->id,warehouse_remove->code);
}

void remove_warehouse_from_item(item *item_remove,warehouse *warehouse_remove){
    wlst *current_items_location= item_remove->warehouses;
    wlst *prev_items_location=NULL;
    while (current_items_location){
        if (current_items_location->data == warehouse_remove){
            // need to remove the first item
            if (prev_items_location==NULL)
                // current is a pointer, so i need to update the warehouse list itself
                // i could do also *current = *(current->next)
                item_remove->warehouses = current_items_location->next;

            else
                prev_items_location->next = current_items_location->next;
            free(current_items_location);
            printf("The item %d current_warehouse_location has been removed\n",item_remove->id);
            return;
        }
        prev_items_location = current_items_location;
        current_items_location = current_items_location->next;
    }
    printf("didnt find item %d in the warehouse %d",item_remove->id,warehouse_remove->code);
}





/***********************************************printout functions***********************************************************************/

void print_items(itemlst **items) {
    itemlst *current_items = *items;
    printf("item LIST:\n");
    if (current_items==NULL) {
        printf("No item in the list\n");
        return;
    }
    while (current_items) {
        printf("%d:%s\n", current_items->data->id, current_items->data->name);
        wlst *item_warehouse_list = current_items->data->warehouses;
        if (item_warehouse_list) {
            printf("Item Warehouses: %d-%s", item_warehouse_list->data->code, item_warehouse_list->data->location);
            item_warehouse_list = item_warehouse_list->next;
            while (item_warehouse_list) {
                printf(",%d-%s", item_warehouse_list->data->code, item_warehouse_list->data->location);
                item_warehouse_list = item_warehouse_list->next;
            }
        }
        printf("\n");
        current_items = current_items->next;
    }
}

void print_warehouses(wlst **warehouses) {
    wlst *current_warehouses = *warehouses;
    printf("warehouse LIST:\n");
    if (current_warehouses==NULL) {
        printf("No warehouse in the list");
        return;
    }
    while (current_warehouses) {
        printf("\nWarehouse code %d,Warehouse name: %s\n",
               current_warehouses->data->code, current_warehouses->data->location);
        printf("Items: ");
        itemlst *warehouse_item_list = current_warehouses->data->items;
        while (warehouse_item_list) {
            printf("ID %d Name %s |",warehouse_item_list->data->id,warehouse_item_list->data->name);
            warehouse_item_list = warehouse_item_list->next;
        }
        current_warehouses = current_warehouses->next;
    }
}








/***************************************************free**********************************************************************************/


/*******************************************Generate And Assign Items And Warehouses******************************************************/



/*DO NOT TOUCH THIS FUNCTION */


/*DO NOT TOUCH THIS MAIN TEMPLATE - ONLY ADD YOUR FUNCTIONS CALLS */
int main() {
    itemlst* items = 0;
    wlst* warehouses = 0;
    char  c;
    char  buf[100];
    int   id, num;
    int validInput=0;



    do {
        printf("Choose:\n"
            "    i - new item\n"
            "    w - new warehouse\n"
            "    a - assign an item to a warehouse\n"
            "    u - unassign an item from a warehouse(not delete!)\n"
            "    p - print status\n"
			"    g - generating and assigning 100 items to 10 warehouses\n"
            "    q - quit\n");

        while ((c = (char)getchar()) == '\n');
        getchar();

        switch (c) {
            case 'i':
                printf("Adding new item.\n");

                printf("item name: ");
                getstring(buf, 100);
                 // Flag to track valid input
                validInput=0;
                while (!validInput) {
                    printf("item ID: ");
                    if (scanf("%100d", &id) != 1) {
                        printf("Error: Please enter a valid ID.\n");
                        // Clear the input buffer to prevent infinite loop
                        while (getchar() != '\n');
                    } else {
                        validInput = 1; // Set the flag to exit the loop
                    }
                }

                item *new_item = create_item(buf, id);
                if (new_item != NULL)
                    add_item_to_list(&items, new_item);
                break;

            case 'w':
                printf("Adding new warehouse.\n");

                printf("\n warehouse name: ");
                getstring(buf, 100);
                validInput=0;
                while (!validInput) {
                    printf("\n warehouse code: ");
                    if (scanf("%100d", &num) != 1) {
                        printf("Error: Please enter a valid ID.\n");
                        // Clear the input buffer to prevent infinite loop
                        while (getchar() != '\n');
                    } else {
                        validInput = 1; // Set the flag to exit the loop
                    }
                }

                warehouse *new_warehouse = create_warehouse(buf, num);
                if (new_warehouse != NULL)
                    add_warehouse_to_list(&warehouses, new_warehouse);
                //your function

                break;

            case 'a':
                printf("Assign an item to a warehouse.\n");

                printf("item ID: ");
                scanf("%d", &id);

                printf("warehouse code: ");
                scanf("%d", &num);
                printf("list %d\n", items->data->id);
                printf("warehouse %d\n", warehouses->data->code);
                // finding the needed item and warehouse with there speaciel id and code
                item *the_item_assign = find_item(&items, id);
                warehouse *the_warehouse_assign = find_warehouse(&warehouses, num);
                if (the_warehouse_assign != NULL && the_item_assign != NULL){
                    // assign the item to warehouse and the opposite
                    assign_item_to_warehouse(the_item_assign, the_warehouse_assign);
                    assign_warehouse_to_item(the_item_assign, the_warehouse_assign);
                  }
            break;

        case 'u':
            printf("Remove an item from a warehouse.\n");

            printf("item ID: ");
            scanf("%d", &id);

            printf("warehouse code: ");
            scanf("%d", &num);
            // find the item and warehouse
            item *the_item_remove = find_item( &items, id);
            warehouse *the_warehouse_remove = find_warehouse(&warehouses ,num);
            if (the_warehouse_remove==NULL || the_item_remove==NULL)
                break;
            remove_item_from_warehouse(the_item_remove,the_warehouse_remove);
            remove_warehouse_from_item(the_item_remove,the_warehouse_remove);
           //your function

            break;

        case 'p':
            printf("Printing status.\n");

            print_items(&items);
            print_warehouses(&warehouses);

            //your function

            break;

		case 'g':  // generating and assigning items and warehouses
			printf("Generating and assigning items to warehouses\n");
            srand(1948);
            itemlst* items_temp = 0;
            wlst* warehouses_temp = 0;
            for (int j=0;j<10;j++) {
                char location[11];
                sprintf(location, "Warehouse%d", j);
                warehouse *find_the_warehouse = find_warehouse(&warehouses,j);
                if (find_the_warehouse !=NULL) {
                    add_warehouse_to_list(&warehouses_temp,find_the_warehouse);
                }
                else{
                    warehouse *new_warehouse_generated = create_warehouse(location, j);
                    if (new_warehouse_generated != NULL)
                        add_warehouse_to_list(&warehouses_temp, new_warehouse_generated);
                }
            }
            for (int i=0 ; i<100 ;i++) {
                char name[7];
                sprintf(name, "Item%d", i);
                //create an item
                item *find_the_item = find_item(&items,i);
                if (find_the_item !=NULL) {
                    add_item_to_list(&items_temp,find_the_item);
                    int randomCode = rand() % 10;
                    warehouse *the_warehouse_gen_find = find_warehouse(&warehouses_temp, randomCode);
                    if (the_warehouse_gen_find != NULL) {
                        assign_item_to_warehouse(find_the_item, the_warehouse_gen_find);
                        assign_warehouse_to_item(find_the_item, the_warehouse_gen_find);
                    }
                }// check if i add to the temp warehouse
                // then save the temp to the original
                // same for the list.
                else {
                    item *new_item_generated = create_item(name, i);
                    if (new_item_generated != NULL) {
                        add_item_to_list(&items_temp, new_item_generated);
                        // generate a code value and then assign the item to the warehouse
                        int randomCode = rand() % 10;
                        warehouse *the_warehouse_gen_find = find_warehouse(&warehouses_temp, randomCode);
                        if (the_warehouse_gen_find != NULL) {
                            assign_item_to_warehouse(new_item_generated, the_warehouse_gen_find);
                            assign_warehouse_to_item(new_item_generated, the_warehouse_gen_find);
                        }
                    }
                }
            }
            items =items_temp;
            warehouses = warehouses_temp;
       //     free(items_temp);
      //      free(warehouses_temp);
			break;

        case 'q':
            printf("Quitting...\n");
            break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    //your free functions
	exit(0);

}

