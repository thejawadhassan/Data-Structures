#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class List
 {
 	Node* head;
	 public:
	 List()
 	{
 		head=NULL;
	 }
	  bool isempty()
	    {
		    return head==NULL;	
		}
	 Node* createnode()
	  {
	    Node* cur=new Node;
		readnode(cur);
		cur->next=NULL;	
	  }
    void readnode(Node* cur)
     {
    	cout<<"enter integer value:";
 		cin>>cur->data;
    	}
   	void insertathead()
	{
		Node* cur=createnode();
        if(isempty())
        {
        	head=cur;
		}
		 else
		 {
			cur->next=head;
			head=cur;    	   	
         }   
	 }
	  void insertattail()
	{
		Node* cur=createnode();
        if(isempty())
        {
        	head=cur;
		}
		 else
		 {
		   	Node* last=lastnode();
	        last->next=cur;  	   	
         }   
	 }
	  Node* lastnode()
	    {
    	Node* h=head;
     	 while(h->next!=NULL)
     	  {
  	    	 h=h->next;
		   }
 	     return h;
		}
		 void display()
	    {
    	if(!isempty())
		{
		cout<<"displayed elements are: \n";
    	Node* h=head;
     	 while(h!=NULL)
     	  {
     	    cout<<h->data<<endl;	
  	    	 h=h->next;
		   }
		}
		 else
		 {
		   	
		 }
		 }
		 void search(int n)
		  {
		   	Node* h =head;
			while(h!=NULL)
		     {
				if(h->data==n)
				 {
		 	     cout<<"element found!"<<endl;
				 }
				  else
           	{cout<<"element not found"<<endl;} 							   
				h=h->next;   			  		   	
			 } 	     	
	    	}
	  
	 		 
};
main()
{
	List l;
int n,opt;
while(1)
{
	cout<<"1.Insert at head\n2.Insert at tail\n3.Display Elements\n4.search Element\n5.exit\nEnter: ";
	cin>>opt;
	switch(opt)
	{
		case 1:
 	    l.insertathead();
 		break;
        case 2:
 	    l.insertattail();
 		break;
         case 3:
 	    l.display();
 		break;
        case 4:
	    cout<<"enter integer element to search: ";
        cin>>n;
 	    l.search(n);
 		break;
        case 5:
		exit(0);
		default:
		cout<<"invalid input"<<endl;     
	}
	}	
}