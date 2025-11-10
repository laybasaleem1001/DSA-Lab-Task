#include<iostream>
using namespace std;

class book{
	public:
		string title;
		double price;
		int ed;
		double page;
	book() {}
    book(string t, double p, int e, double pg) {
        title = t;
        price = p;
        ed = e;
        page = pg;
    }

    void display() const {
        cout << "Title: " << title
             << ", Price: " << price
             << ", Edition: " << ed
             << ", Pages: " << page<< endl;
    }	
};

struct Node{
	book data;
	Node* next;
};

class stack{
	private:
		Node* top;
	public:
	    stack(){
	    	top = NULL;
		}	
		void push(book b){
		    Node* newNode = new Node();
            newNode->data = b;
            newNode->next = top;
            top = newNode;
            cout << "Book \"" << b.title << "\" pushed into stack." << endl;
		}
		void pop(){
			if(isEmpty()){
				cout<<"Stck underflow cannot pop."<<endl;
				return;
			}
			Node* temp = top;
			cout<<"Book \"" << top->data.title << "\" popped from stack." << endl;
			top = top->next;
			delete(temp);
		}
		
		bool isEmpty() {
            return top == NULL;
            }
            
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
                return;
            }

            Node* temp = top;
            cout << "\nBooks currently in stack:\n";
            while (temp != NULL) {
                temp->data.display();
                temp = temp->next;
            }
    } 
	void peek(){
		if(isEmpty()){
			cout << "Stack is empty." << endl;
            return;
		}
		cout << "Top Book -> ";
        top->data.display();
	}   
};

int main(){
	stack s1;
	s1.push(book("PF", 3000, 5, 746));
	s1.push(book("Java", 9000, 4, 2450));
	s1.push(book("OOP", 2000, 9, 3400));
	s1.push(book("TBW", 5000, 6, 450));
	s1.push(book("OOP", 7000, 2, 5400));
	
	cout<<"top element of the stack is:"<<endl;
	s1.peek();
	
	cout<<"poping top 2 books from the stack."<<endl;
	s1.pop();
	s1.pop();
	
	s1.display();
	return 0;
}