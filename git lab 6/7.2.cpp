#include<iostream>
#include<string>
using namespace std;
class book{
	string title;
	string author;
	double price;
	int id;
public:
	 book(int bid,string bt,string ba,float bp)
	{
	title=bt;
	author=ba;
	price=bp;
	id=bid;
	}
	void print()
	{
		cout<<"title: "<<title<<endl;
  		cout<<"author: "<<author<<endl;
  		cout<<"price: "<<price<<endl;
  		cout<<"id: "<<id<<endl;	
     }
};
class list{
	book *arr[10];
	int count;
	int size;
	public:
	list()
	{
		size =10;
		count=0;
	}
	public:
	void insert(int bid,string bt,string ba,float bp)
	{
		if(!isfull())
        {
		arr[count]=new book(bid,bt,ba,bp);
        count++;
    	}
    	else
    	cout<<"no more space";
	}
	  void insertAt(int index, int bid, string bt, string ba, float bp) {
        if (isfull()) {
            cout << "No more space to insert a new book." << endl;
            return;
        }
        if (index < 0 || index > count) {
            cout << "Invalid index." << endl;
            return;
        }
        arr[index] = new book(bid, bt, ba, bp);
        count++;
    }
    void deleteAt(int index) {
        if (isempty()) {
            cout << "No books to delete." << endl;
            return;
        }
        if (index < 0 || index >= count) {
            cout << "Invalid index." << endl;
            return;
        }
        delete arr[index];
        for (int i = index; i < count - 1; i++) 
		{
            arr[i] = arr[i + 1];
        }
        count--;
    }
	void delseq()
	{
	   if (!isempty()) 
	   {
        delete arr[--count]; 
        cout << "Deleted last book from the list." << endl;
      } 
	else 
	{
        cout << "No books to delete." << endl;
    }	
	}
	void display()
	{
		if(!isempty())
        {
		cout<<"all books are:"<<endl;
		for(int i=0;i<count;i++)
			{
			arr[i]->print();	 						
			}
	    }
	}
	int total()
	{
	return count;	
	}
	bool isfull()
	{
		return count==size;
	}
	bool isempty()
	{
		return count==0;
	}
};
main()
{
list l;
int bid,option,index;
float bp;
string bt,ba;


while(1)
{
cout<<"\n1.insert book sequential \n2.delete book sequential \n3.insert at ur value \n4.delete at ur value \n5.display books \n6.show no of books \nenter ans: ";
cin>>option;
switch(option)
{
case 1:
cout<<"enter book id:";
cin>>bid;
cout<<"enter book title:";
cin>>bt;
cout<<"enter book author:";
cin>>ba;
cout<<"enter book price:";
cin>>bp;
l.insert(bid,bt,ba,bp);
break;
case 2:
l.delseq();	
break;
case 3:
cout << "Enter index to insert at: ";
  cin >> index;
   cout << "Enter book ID: ";
     cin >> bid;
     cout << "Enter book title: ";
      cin >> bt;
     cout << "Enter book author: ";
    cin >> ba;
     cout << "Enter book price: ";
     cin >> bp;
   l.insertAt(index, bid, bt, ba, bp);
break;
case 4:
cout << "Enter index to delete at: ";
 cin >> index;
l.deleteAt(index);
break;
case 5:
l.display();
break;	
case 6:
cout<<"total books are:"<<l.total();	
break;
default:
cout<<"invalid"<<endl;
}
}	
}