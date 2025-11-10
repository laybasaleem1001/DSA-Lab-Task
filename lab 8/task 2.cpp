#include <iostream>
#include <string>
using namespace std;

// ---------- Node for Queue and Stack ----------
struct Node {
    int truck_id;
    Node* next;
};

// ---------- Queue (for road) ----------
class RoadQueue {
private:
    Node* front;
    Node* rear;
public:
    RoadQueue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int id) {
        Node* newNode = new Node{id, nullptr};
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    bool searchAndRemove(int id) {
        Node* temp = front;
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->truck_id == id) {
                if (prev == nullptr)
                    front = temp->next;
                else
                    prev->next = temp->next;
                if (temp == rear)
                    rear = prev;
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->truck_id;
            if (temp->next != nullptr)
                cout << "_";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------- Stack (for garage) ----------
class GarageStack {
private:
    Node* top;
public:
    GarageStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int id) {
        Node* newNode = new Node{id, top};
        top = newNode;
    }

    int peek() {
        if (isEmpty()) return -1;
        return top->truck_id;
    }

    bool pop(int id) {
        if (isEmpty()) return false;
        if (top->truck_id == id) {
            Node* temp = top;
            top = top->next;
            delete temp;
            return true;
        }
        return false;
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }

        // Print stack bottom to top
        int trucks[50];
        int count = 0;
        Node* temp = top;
        while (temp != nullptr && count < 50) {
            trucks[count++] = temp->truck_id;
            temp = temp->next;
        }

        for (int i = count - 1; i >= 0; i--) {
            cout << trucks[i];
            if (i != 0)
                cout << "_";
        }
        cout << endl;
    }
};

// ---------- TruckManager class ----------
class TruckManager {
private:
    RoadQueue road;
    GarageStack garage;

public:
    void On_road(int truck_id) {
        road.enqueue(truck_id);
    }

    void Enter_garage(int truck_id) {
        bool found = road.searchAndRemove(truck_id);
        if (found)
            garage.push(truck_id);
        else
            cout << "Error: " << truck_id << " NO. Vehicle cannot enter into garage.\n";
    }

    void Exit_garage(int truck_id) {
        if (garage.isEmpty()) {
            cout << "Error: " << truck_id << " No. Vehicle cannot exit garage.\n";
            return;
        }

        int topTruck = garage.peek();
        if (topTruck == truck_id) {
            cout << truck_id << " No. vehicle leaving garage\n";
            garage.pop(truck_id);
        } else {
            cout << "Error: " << truck_id << " No. Vehicle cannot exit garage.\n";
        }
    }

    void Show_trucks(string where) {
        if (where == "road") {
            cout << "Road Vehicle: ";
            road.display();
        } else if (where == "garage") {
            cout << "Garage Vehicle: ";
            garage.display();
        }
    }
};

// ---------- Main Function ----------
int main() {
    TruckManager manager;

    manager.On_road(2);
    manager.On_road(5);
    manager.On_road(10);
    manager.On_road(9);
    manager.On_road(22);

    manager.Show_trucks("road");
    manager.Show_trucks("garage");

    manager.Enter_garage(2);
    manager.Show_trucks("road");
    manager.Show_trucks("garage");

    manager.Enter_garage(10);  // should fail
    manager.Enter_garage(5);

    manager.Exit_garage(2);    // should fail
    manager.Exit_garage(5);

    manager.Show_trucks("garage");

    return 0;
}