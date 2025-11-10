#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

int main(){
	Node *first = new Node();
	first->data = 10;
	
	Node *second = new Node();
	second->data = 20;
	
	Node *third = new Node();
	third->data = 30;
	
	Node *fourth = new Node();
	fourth->data = 40;
	
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	
	
	cout<<"Original list: ";
	Node *temp = first;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	temp = first;
	int pos;
	cout<<"\nenter the posistion u want to delete: ";
	cin>>pos;
	
	if(pos == 1 && temp != NULL)
	{
		Node *del = first;
		first = first->next;
		delete (del);
	}
	else
	{
		Node *prev = first;
        for (int i = 1; i < pos-1 && prev != NULL; i++) 
		{
            prev = prev->next;
        }
        if (prev != NULL && prev->next != NULL) 
		{
            Node *del = prev->next;
            prev->next = del->next;
            delete(del);
        } else {
            cout << "Invalid position!\n";
        }
	}

	cout<<"\nAfter deletion: ";
	temp = first;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	return 0;
}