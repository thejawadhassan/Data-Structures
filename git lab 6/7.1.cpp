#include<iostream>
using namespace std;
class List{
int *elements; 
int size; 
int length; 
////////////////////////////////// Constructor 
public:
List(int maxsize) 
{ 
size=maxsize; 
elements=new int[size]; 
length=0; 
} 
/////////////////////////////////// Destructor
~List () 
{ 
delete []elements; 
} 
/////////////////////////////////// Output the list structure 
void showStructure () 
{ 
if(!isEmpty()) 
{ 
for(int i=0;i<length;i++) 
{ 
cout<<"Element:"<<elements[i]<<endl; 

} 
} 
else 
{ 
cout<<"Display: No items to be displayed. List is empty\n"; 
} 
} 
////////////////////////////////// List manipulation operations
// Insert after cursor 
void insert (int newDataItem) 
{ 
if(!isFull()) 
{ 
elements[length]=newDataItem; 
length++; 
} 
else 
{ 
cout<<"Insert: Cannot insert more items. List is full\n"; 
} 
} 
// Remove data item 
int remove () 
{ 
if(!isEmpty()) 
{ 
length--; 
return elements[length]; 
} 

{ 
cout<<"Remove: Cannot remove the item. List is empty\n"; 
} 
} 
// Replace data item 
void replace ( int newDataItem, int position ) 
{ 
//Condition: List contains at least position+1 data items. 
//Result: Removes the data item present at the position from a list and replace the number requested by user at its position. 
if(position>length) 
{ 
cout<<"Replace: Cannot replace the item. Invalid position requested\n"; 
} 
else 
{ 
//implement your logic here
elements[position]=newDataItem;
} 
} 
// find any number 
bool find ( int searchDataItem ) 
{ 
//Condition: List is not empty. 
//Result: Check if the number is present in the list or not 
if(!isEmpty()) 
{ 
for(int i=0;i<length;i++) 
{ 
//implement your logic here 
if(searchDataItem==elements[i])
{
	cout<<"element found"<<endl;
	
}

} 
}
else
cout<<"array is empty \n" ;
}
/////////////////////////////////////// List status operations
// check if List is empty 
bool isEmpty () 
{ 
// implement your logic here 
return length==0;
} 
// check if List is full 
bool isFull () 
{ 
// implement your logic here 
return length==size;
}
};
main()
{
	List l(10);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(6);
	l.insert(9);
	cout<<l.remove()<<endl;
	l.find(4);
	
}