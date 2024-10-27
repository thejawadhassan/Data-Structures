#include<iostream>
using namespace std;
class Queue
{
private:
int *elements;
int size;
int rear, front;
////////////////////////////////// Constructor 
public:
Queue (int maxsize)
{
size=maxsize;
elements=new int[size];
rear = -1, front = -1;
}
/////////////////////////////////// Destructor 
~ Queue()
{
delete []elements;
}
/////////////////////////////////// Output the Queue structure 
void showStructure () 
{
if(!isEmpty())
{
for(int i=front;i<=rear;i++)
{
cout<<"Element:"<<elements[i]<<endl;
}
}
else
{
cout<<"Display: No items to be displayed. Queue is empty\n";
}
}
////////////////////////////////// Queue manipulation operations
// Insert in queue 
void Enqueue (int newDataItem) 
{
if(!isFull())
{
if(front==-1)
{front=0;}
rear++;
elements[rear]=newDataItem;

}
else
{cout<<"Insert: Cannot insert more items. List is full\n";}
}
// Remove data item
void Dequeue () 
{
if(!isEmpty())
{
//implement your logic here
cout<<"dequeued: "<<elements[front]<<endl;
front++;
if(front>rear)
{
	clear();
}
}
else
{
cout<<"Remove: Cannot remove the item. List is empty\n";
}
}
// Clear queue
void clear ()
{
//implement your logic here
front=rear=-1;
} 
/////////////////////////////////////// Queue status operations 
// check if queue is empty 
bool isEmpty () 
{
// implement your logic here
if(front==-1||front>rear)
{
	return true;
}
else 
return false;
} 
// check if queue is full 
bool isFull() 
{
if(rear<size-1)
{
	return false;
}
else 
return true;
}
};
main()
{
	int size;
	cout<<"enter size of queue:";
	cin>>size;
	Queue q(size);
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Dequeue();
	q.showStructure();
}