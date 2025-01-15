#include <iostream>
using namespace std;
class Node

{
	public:
	int data;
	Node *next;
	Node(int value, Node *nextnode=0)
	{
	data=value;
	next=nextnode;
	}
};

class SingleList
{
	public:
	Node *head, *tail;
	
	//node1->data=101;
	
	SingleList()
	{
	head=NULL;
	tail=NULL;
	}
	
	
	
	// Method to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Method to display the elements of the list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
	
};


int main()

{
SingleList l1;

    // Adding the first element to the list
    Node* newNode1 = new Node(42);
    l1.head = newNode1;
    l1.tail = newNode1;
    
    

    // Displaying the first element
    cout << "First element in the list: " << l1.head->data << endl;

    // Adding the second element to the list
    Node* newNode2 = new Node(24);
    l1.tail->next = newNode2; // Linking the new node to the existing list
    l1.tail = newNode2; // Updating the tail pointer to the new node

    // Displaying both elements
    cout << "First element in the list: " << l1.head->data << endl;
    cout << "Second element in the list: " << l1.head->next->data << endl;

    l1.display();
    
    l1.insert(36);
    l1.insert(48); 
	l1.display();
    l1.display();
    l1.display();
    l1.display();
    l1.display();
    l1.display();
    
	

	
}
