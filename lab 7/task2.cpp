#include <iostream>
using namespace std;

class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    Inventory() {
        serialNum = 0;
        manufactYear = 0;
        lotNum = 0;
    }

    Inventory(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    // Set values
    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    // Display values
    void display() const {
        cout << "Serial Number: " << serialNum
             << ", Manufacture Year: " << manufactYear
             << ", Lot Number: " << lotNum << endl;
    }
};

struct Node {
    Inventory data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    // Push new part
    void push(Inventory inv) {
        Node* newNode = new Node();
        newNode->data = inv;
        newNode->next = top;
        top = newNode;
        cout << "? Part added to inventory.\n";
    }

    // Pop top part
    void pop() {
        if (isEmpty()) {
            cout << "?? Inventory is empty. Cannot remove part.\n";
            return;
        }
        Node* temp = top;
        cout << "\n ? Part removed from inventory:\n";
        top->data.display();
        top = top->next;
        delete temp;
    }

    // Display all inventory parts
    void displayAll() {
        if (isEmpty()) {
            cout << "\n  Inventory is empty.\n";
            return;
        }

        cout << "\n Current Inventory:\n";
        Node* temp = top;
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

int main() {
    Stack inventoryStack;
    int choice;

    cout << "=== INVENTORY MANAGEMENT SYSTEM ===\n";

    do {
        cout << "\n1. Add a part to inventory";
        cout << "\n2. Remove a part from inventory";
        cout << "\n3. View all inventory items";
        cout << "\n4. Exit program";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int serial, year, lot;
            cout << "Enter Serial Number: ";
            cin >> serial;
            cout << "Enter Manufacture Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

            Inventory part(serial, year, lot);
            inventoryStack.push(part);
        }
        else if (choice == 2) {
            inventoryStack.pop();
        }
        else if (choice == 3) {
            inventoryStack.displayAll();
        }
        else if (choice == 4) {
            cout << "\nExiting program...\n";
            inventoryStack.displayAll();
        }
        else {
            cout << "? Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}