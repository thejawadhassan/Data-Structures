#include<iostream>
using namespace std;

struct node{
	int data;
	node*next;
};

class list{
	node*head;
	int count; 
	public:
	list() { head=NULL; count=0; }

	~list() {
		while(head!=NULL) {
			node*temp=head;
			head=head->next;
			delete temp;
		}
	}

	node* createnode(int val) {
		node*cur=new node;
		cur->data=val;
		cur->next=NULL;
		return cur;
	}

	bool isempty() { return head==NULL; }

	bool isfull() { return count >= 10; }

	void insertathead(int val) {
		if(isfull()) {
			cout<<"Error: List is full"<<endl;
			return;
		}
		node*cur=createnode(val);
		if(isempty()) { head=cur; }
		else {
			cur->next=head;
			head=cur;
		}
		count++;
	}

	void insertattail(int val) {
		if(isfull()) {
			cout<<"Error: List is full"<<endl;
			return;
		}
		node*cur=createnode(val);
		if(isempty()) { head=cur; }
		else {
			node*last=lastnode();
			last->next=cur;
		}
		count++;
	}

	void insertafter(int target, int val) {
		if(isfull()) {
			cout<<"Error: List is full"<<endl;
			return;
		}
		node*cur=createnode(val);
		node*h=head;
		while(h!=NULL && h->data!=target) {
			h=h->next;
		}
		if(h==NULL) {
			cout<<"Error: Target "<<target<<" not found"<<endl;
			delete cur;
		} else {
			cur->next=h->next;
			h->next=cur;
			count++;
		}
	}

	void delatfront() {
		if(isempty()) {
			cout<<"Error: List is empty"<<endl;
			return;
		}
		node*temp=head;
		head=head->next;
		delete temp;
		count--;
	}

	void delattail() {
		if(isempty()) {
			cout<<"Error: List is empty"<<endl;
			return;
		}
		if(head->next==NULL) {
			delete head;
			head=NULL;
		} else {
			node*prev=NULL;
			node*temp=head;
			while(temp->next!=NULL) {
				prev=temp;
				temp=temp->next;
			}
			prev->next=NULL;
			delete temp;
		}
		count--;
	}

	void deletevalue(int val) {
		if(isempty()) {
			cout<<"Error: List is empty"<<endl;
			return;
		}
		if(head->data==val) {
			delatfront();
			return;
		}
		node*prev=NULL;
		node*temp=head;
		while(temp!=NULL && temp->data!=val) {
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL) {
			cout<<"Error: Value "<<val<<" not found"<<endl;
		} else {
			prev->next=temp->next;
			delete temp;
			count--;
		}
	}

	node* lastnode() {
		node*h=head;
		while(h->next!=NULL) {
			h=h->next;
		}
		return h;
	}

	void display() {
		node*h=head;
		while(h!=NULL) {
			cout<<"value is: "<<h->data<<endl;
			h=h->next;
		}
	}
};

int main() {
	list l;
	l.insertathead(10);
	l.insertattail(20);
	l.insertafter(10,15);
	l.insertattail(30);
	l.display();
	l.delatfront();
	l.delattail();
	l.deletevalue(15);
	l.display();
	for(int i=0;i<10;i++) l.insertattail(i+1); 
	l.insertattail(11); 
	return 0;
}
