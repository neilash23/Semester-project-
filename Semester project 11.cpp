#include <iostream>
#include <string.h>
using namespace std;

struct ItemEntry {
    float unit_price;
    int copies, product_id;
    char company[30], name[80];
};

class Store {
public:
    int numItems;
    ItemEntry database[100];

    Store() {
        numItems = 0;
    }

    void AddItem(char itemName[], char company[], int pid, int c, float p);
    void RemoveItem(char itemName[], int pid);
    ItemEntry* FindItem(char itemName[], int pid);
    void UpdateItem(char itemName[], int pid, int total, float price);
};

void Store::AddItem(char itemName[], char company[], int pid, int c, float p) {
    strcpy(database[numItems].name, itemName);
    strcpy(database[numItems].company, company);
    database[numItems].product_id = pid;
    database[numItems].copies = c;
    database[numItems].unit_price = p;
    cout << "ITEM ADDED SUCCESSFULLY \n";
    numItems++;
}

void Store::RemoveItem(char itemName[], int pid) {
    for (int i = 0; i < numItems; i++) {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid)) {
            for (int j = i; j < numItems - 1; j++) {
                database[j] = database[j + 1];
            }
            numItems--;
            cout << "ITEM REMOVED SUCCESSFULLY \n";
            return;
        }
    }
    cout << "ITEM NOT FOUND \n";
}

ItemEntry* Store::FindItem(char itemName[], int pid) {
    for (int i = 0; i < numItems; i++) {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid)) {
            return &database[i];
        }
    }
    return NULL;
}

void Store::UpdateItem(char itemName[], int pid, int total, float p) {
    ItemEntry* item = FindItem(itemName, pid);
    if (item != NULL) {
        item->copies += total;
        item->unit_price = p;
        cout << "ITEM UPDATED SUCCESSFULLY \n";
    } else {
        cout << "ITEM NOT FOUND \n";
    }
}

int main() {
    Store store;
    char name[80], company[30];
    int product_id, copies, unit_price, option;
    do {
    	cout << "\t========================= \n";
        cout << "\t ||DEPARTMENTAL STORE||\n";
        cout << "\t=========================\n\n";
        cout << "===========\n";
        cout << "||MENU|| \n";
        cout << "===========\n";
        cout << "\n 1. Add Item";
        cout << "\n 2. Remove Item";
        cout << "\n 3. Find Item";
        cout << "\n 4. Update Item";
        cout << "\n 5. Exit";
        cout << "\nEnter your choice:";
        cin >> option;
        switch (option) {
            case 1:
                cin.ignore();
                cout << "\n Enter Name of Item:";
                cin.getline(name, 80);
                cout << "\n Company:";
                cin.getline(company, 30);
                cout << "\n Enter Product ID:";
                cin >> product_id;
                cout << "\n No of Copies:";
                cin >> copies;
                cout << "\n Unit Price per Item:";
                cin >> unit_price;
                store.AddItem(name, company, product_id, copies, unit_price);
                break;

            case 2:
                cin.ignore();
                cout << "\n Enter Name of Item:";
                cin.getline(name, 80);
                cout << "\n Enter Product ID:";
                cin >> product_id;
                store.RemoveItem(name, product_id);
                break;

            case 3:
                cin.ignore();
                cout << "\n Enter Name of Item: ";
                cin.getline(name, 80);
                cout << "\n Enter Product ID: ";
                cin >> product_id;
                ItemEntry* result;
                result = store.FindItem(name, product_id);
                if (result != NULL) {
                	cout << "====================\n";
                    cout << "\n ||Search Result|| \n";
                    cout << "====================\n";
                    cout << "\n ITEM FOUND" << "\n Name of the Item:" << result->name
                         << "\n Company Name:" << result->company << "\n Product ID:" << result->product_id
                         << "\n Number of Copies Available:" << result->copies << "\n Unit Price"
                         << result->unit_price << endl;
                } else {
                    cout << "\nITEM NOT FOUND" << endl;
                }
                break;

            case 4:
                cin.ignore();
                cout << "\n Enter Name of Item: ";
                cin.getline(name, 80);
                cout << "\n Enter Product ID: ";
                cin >> product_id;
                cout << "\n Enter Total New Entry: ";
                cin >> copies;
                cout << "\n Enter New Price: ";
                cin >> unit_price;
                store.UpdateItem(name, product_id, copies, unit_price);
                break;
        }
    } while (option != 5);

    return 0;
}
