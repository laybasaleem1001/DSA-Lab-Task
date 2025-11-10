#include<iostream>
using namespace std;

const int QUEUE_CAPACITY=128;

class Queue
{
	public:
		int myArray[QUEUE_CAPACITY];
		int front,rear;
		int count;
	

 Queue()
 {
 	front =rear=count=0;
 }
 public: bool isEmpty()
 {
 	if(count==0)
 		return true;
 	else
 	return false;
 }
 public: bool  isFull()
 {
 	if(count==QUEUE_CAPACITY)
 	return true;
 	else
 	return false;
 }
 public: int getFront()
 {
 	if(!isEmpty())
 	{
 		return myArray[front];
	 }
	 else 
	 return -1;
 }
  public: void enqueue(int value)
 {
 	if(! isFull())
 
 	{	
 		myArray[rear]=value;
 		rear=(rear+1)%QUEUE_CAPACITY;
 		count++;
 	cout<<" Enqueded"<<endl;
	 }
	 else cout<<" Queue Underflow";

 }
  public: void dequeue()
 {
 	if(! isEmpty())
 
 	{	
 	int val=	myArray[front];
 		front=(front+1)%QUEUE_CAPACITY;
 		count--;
 	cout<<" Dequeded"<<endl;
	 }
	 else cout<<" Queue Underflow";

 }
  public: void display()
  {
  	int p=front;
  	if(isEmpty()==1)
  	{
	  return;
}
  	while(p!=-1)
  	{
  		cout<<myArray[front]<<endl;
  		p--;
	  }
  }
};

 int main()
 {
 
 	Queue q;
 	q.enqueue(2);
 	q.enqueue(3);
 	q.display();
 	q.dequeue();
 	q.display();
 	return 0;
 }
