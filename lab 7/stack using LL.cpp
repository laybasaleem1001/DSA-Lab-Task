#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

class stack{
	private:
		Node* top;
	public:
	    stack(){
	    	top = NULL;
		}
		void push(int value){
			Node* newNode = new Node();
			newNode->data = value;
			newNode->next = top;
			top = newNode;
			cout<<value<<" pushed into stack."<<endl;
		}
		void pop(){
			if(isEmpty()){
				cout<<"Stck underflow cannot pop."<<endl;
				return;
			}
			Node* temp = top;
			cout<<top->data<<" poped from stack."<<endl;
			top = top->next;
			delete(temp);
		}
		bool isEmpty(){
			return top == NULL;
		}
		void display(){
			if(isEmpty()){
				cout<<"stack is empty."<<endl;
			}
			Node* temp = top;
			while(temp != NULL)
			{
				cout<<temp->data <<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};

int main(){
	stack s1;
	s1.push(10);
	s1.push(32);
	s1.push(50);
	s1.display();
	s1.pop();
	s1.display();
	return 0;
}