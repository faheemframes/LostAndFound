#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Item
class Item {
public:
    string name;
    string description;
    string status; // "Lost" or "Found"

    Item(string n, string d, string s) : name(n), description(d), status(s) {}
};

// Lost & Found Manager
class LostFoundManager {
private:
    vector<Item> items;

public:
    void addItem() {
        string n, d, s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer properly
        cout << "Enter item name: ";
        getline(cin, n);
        cout << "Enter description: ";
        getline(cin, d);
        cout << "Enter status (Lost/Found): ";
        getline(cin, s);

        items.push_back(Item(n, d, s));
        cout << "Item added successfully!\n";
    }

    void viewItems() {
        if (items.empty()) {
            cout << "No items to show.\n";
            return;
        }
        cout << "\n--- Lost & Found Items ---\n";
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i + 1 << ". " << items[i].name
                 << " | " << items[i].description
                 << " | " << items[i].status << "\n";
        }
    }
};

int main() {
    LostFoundManager manager;
    int choice;

    while (true) {
        cout << "\n--- Lost & Found Menu ---\n";
        cout << "1. Add Item\n2. View Items\n3. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) { // input validation
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                manager.addItem();
                break;
            case 2:
                manager.viewItems();
                break;
            case 3:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}