#include <iostream>
#include <string>
using namespace std;

// Struct for each inventory item
struct Item {
    string name;
    int id;
};

// Fill the array with sorted sample data
// The ids go from 1000 to 1099, and names are "Item 0", "Item 1", ...
void fillInventory(Item* inventory, int size) {
    for (int i = 0; i < size; ++i) {
        inventory[i].id = 1000 + i;                 // increasing ids
        inventory[i].name = "Item " + to_string(i); // simple names
    }
}

// Binary search by id
// Returns the index if found, or -1 if not found
int binarySearchById(Item* inventory, int size, int targetId) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (inventory[mid].id == targetId) {
            return mid; // found
        } else if (targetId < inventory[mid].id) {
            right = mid - 1; // look in left half
        } else {
            left = mid + 1;  // look in right half
        }
    }

    return -1; // not found
}

int main() {
    const int NUM_ITEMS = 100;

    // Dynamically allocate an array of Items on the heap
    Item* inventory = new Item[NUM_ITEMS];

    // Populate the array with sorted sample data
    fillInventory(inventory, NUM_ITEMS);

    // Ask user for an ID to search for
    int searchId;
    cout << "Enter an item ID to search for (1000 - 1099): ";
    cin >> searchId;

    // Use binary search to find the item
    int index = binarySearchById(inventory, NUM_ITEMS, searchId);

    if (index != -1) {
        cout << "Item found!" << endl;
        cout << "Index: " << index << endl;
        cout << "Name: " << inventory[index].name << endl;
        cout << "ID: " << inventory[index].id << endl;
    } else {
        cout << "Item with ID " << searchId << " was not found." << endl;
    }

    // Free the memory
    delete[] inventory;

    return 0;
}

------------------------------------------------------------------------------

creates a dynamic array of Item structs,

fills it with 100 sample items,

asks the user for an ID,

uses binary search to find and print the matching item,

and frees the dynamic memory at the end.

