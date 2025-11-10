#include <iostream>
#include <string>
using namespace std;

struct Applicant {
    int applicant_id;
    float height;
    float weight;
    float eyesight;
    string test_status;
    Applicant* prev;
    Applicant* next;
};

class ApplicantQueue {
private:
    Applicant* front;
    Applicant* rear;

public:
    ApplicantQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to create a new applicant node
    Applicant* createApplicant(int id, float h, float w, float e, string status) {
        Applicant* newApp = new Applicant;
        newApp->applicant_id = id;
        newApp->height = h;
        newApp->weight = w;
        newApp->eyesight = e;
        newApp->test_status = status;
        newApp->prev = newApp->next = nullptr;
        return newApp;
    }

    // Enqueue: add applicant at end
    void enqueue(Applicant* newApp) {
        if (rear == nullptr) {
            front = rear = newApp;
        } else {
            rear->next = newApp;
            newApp->prev = rear;
            rear = newApp;
        }
    }

    // Dequeue: remove from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Applicant* temp = front;
        front = front->next;
        if (front != nullptr)
            front->prev = nullptr;
        else
            rear = nullptr;
        cout << "Applicant " << temp->applicant_id << " has given the test and left the line.\n";
        delete temp;
    }

    // Remove from a specific position (e.g., 2nd person)
    void removeFromPosition(int pos) {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Applicant* temp = front;
        int count = 1;

        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position.\n";
            return;
        }

        cout << "Applicant " << temp->applicant_id << " had urgency and left the line.\n";

        // If removing first node
        if (temp == front)
            front = temp->next;
        // If removing last node
        if (temp == rear)
            rear = temp->prev;
        // Reconnect links
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
    }

    // Display the current queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Applicant* temp = front;
        cout << "\nCurrent Line of Applicants:\n";
        cout << "----------------------------------------------\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->applicant_id
                 << " | Height: " << temp->height
                 << " | Weight: " << temp->weight
                 << " | Eyesight: " << temp->eyesight
                 << " | Status: " << temp->test_status << endl;
            temp = temp->next;
        }
        cout << "----------------------------------------------\n";
    }
};

int main() {
    ApplicantQueue line;

    // Initial 7 applicants
    for (int i = 1; i <= 7; i++) {
        line.enqueue(line.createApplicant(i, 170 + i, 65 + i, 6.0 + (i * 0.1), "Pending"));
    }

    cout << "Initial Queue of Applicants:\n";
    line.display();

    // 2nd applicant leaves suddenly
    cout << "\n--- Urgent Situation: Applicant at 2nd position leaves ---\n";
    line.removeFromPosition(2);
    line.display();

    // Front applicant gives test and leaves
    cout << "\n--- Applicant at front gives test ---\n";
    line.dequeue();
    line.display();

    // New applicant joins at end
    cout << "\n--- New applicant joins at the end ---\n";
    line.enqueue(line.createApplicant(8, 178, 72, 6.5, "Pending"));
    line.display();

    return 0;
}