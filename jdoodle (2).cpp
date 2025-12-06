#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int id;
};

// Binary search to find an item by ID
int binarySearch(Item items[], int size, int searchID) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (items[mid].id == searchID) {
            return mid;
        }
        else if (searchID < items[mid].id) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1; // not found
}

int main() {

    int size = 100;

    // Allocate memory for 100 items
    Item* inventory = new Item[size];

    // Fill the array with sorted IDs and names
    // IDs go from 1 to 100
    for (int i = 0; i < size; i++) {
        inventory[i].id = i + 1;
        inventory[i].name = "Item_" + to_string(i + 1);
    }

    // Ask user to search for an ID
    int searchID;
    cout << "Enter an ID to search for (1 - 100): ";
    cin >> searchID;

    // Run binary search
    int result = binarySearch(inventory, size, searchID);

    if (result != -1) {
        cout << "Item found:\n";
        cout << "Name: " << inventory[result].name << endl;
        cout << "ID: " << inventory[result].id << endl;
    } 
    else {
        cout << "Item not found.\n";
    }

    // Free memory
    delete[] inventory;

    return 0;
}
