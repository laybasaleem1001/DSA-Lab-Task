#include<iostream>
using namespace std;

struct Node{
Node *prev;
int marks;
Node *next;	
};


int main()
{
	Node *n1 = new Node();
	Node *n2 = new Node();
	Node *n3 = new Node();
	Node *n4 = new Node();
	
	n1->marks = 1;
	n1->prev = NULL;
	n1->next = n2;
	
	n2->marks = 45;
	n2->prev = n1;
	n2->next = n3;
	
	n3->marks = 60;
	n3->prev = n2;
	n3->next = n4;
	
	n4->marks = 12;
	n4->prev = n3;
	n4->next = NULL;
	
	Node *head = n1;
	if(head == NULL){
		cout<<"no list to display!!"<<endl;
		return 1;
	}
	cout<<"The list is :";
	Node *temp = head;
	while(temp !=NULL){
		cout<<temp->marks<<" ";
		temp = temp->next;
	}
	temp = head;
	cout<<"\n\t\tInsertion at the begining."<<endl;
	Node *newNode = new Node();
	newNode->marks = 99;
	newNode->next = head;
	newNode->prev = NULL;
	head->prev = newNode;
	head = newNode;
	
	cout<<"The list after insertion : ";
	temp = head;
	while(temp != NULL){
		cout<<temp->marks<<" ";
		temp = temp->next;
	}
	
	cout<<"\n\t\tInsertion at the end."<<endl;
	Node *newNode2 = new Node();
	newNode2->marks = 88;
	newNode2->prev = n4;
	newNode2->next = NULL;
	n4->next = newNode2;
	
	cout<<"The list after insertion at the end : ";
	temp = head;
	while(temp != NULL){
		cout<<temp->marks<<" ";
		temp = temp->next;
	}
	
	return 0;
}