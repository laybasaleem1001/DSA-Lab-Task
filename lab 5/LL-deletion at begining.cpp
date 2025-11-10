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
	
	Node *head;
	head = first;
//	Node *i;
//	i = head;
	
	head = second;
	delete (first);
//	i = head;
	
	cout<<"\nAfter deletion: ";
	temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	return 0;
}