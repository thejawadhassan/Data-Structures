#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    string CNIC;
    int age;

    Person(string n = "", string c = "", int a = 0)
        : name(n), CNIC(c), age(a) {}
    
    bool isSenior() const {
        return age >= 60;
    }
};

class BillQueue {
private:
    Person* arr;
    int front;
    int rear;
    int count;
    int capacity;

    void expand() {
        int newCapacity = capacity * 2;
        Person* newArr = new Person[newCapacity];

        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }

        delete[] arr;
        arr = newArr;
        front = 0;
        rear = count - 1;
        capacity = newCapacity;
    }

public:
    BillQueue(int cap = 10) : capacity(cap), front(-1), rear(-1), count(0) {
        arr = new Person[capacity];
    }

    ~BillQueue() {
        delete[] arr;
    }

    bool isFull() const {
        return count == capacity;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void enqueue(const Person& p) {
        if (isFull()) {
            expand();
        }

        if (front == -1) {
            front = 0;
        }

        if (p.isSenior()) {
            // Insert the senior at the front of the queue
            front = (front - 1 + capacity) % capacity;
            arr[front] = p;
        } else {
            // Normal person goes to the rear
            rear = (rear + 1) % capacity;
            arr[rear] = p;
        }
        
        count++;
        cout << "Person " << p.name << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Serving person: " << arr[front].name 
             << ", CNIC: " << arr[front].CNIC
             << ", Age: " << arr[front].age << endl;

        front = (front + 1) % capacity;
        count--;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No persons in the queue.\n";
            return;
        }

        cout << "Persons in the queue:\n";
        int i = front;
        for (int n = 0; n < count; n++) {
            cout << "Name: " << arr[i].name 
                 << ", CNIC: " << arr[i].CNIC 
                 << ", Age: " << arr[i].age << endl;
            i = (i + 1) % capacity;
        }
    }
};

int main() {
    BillQueue bq;
    int option;

    while (1) {
        cout << "\nSelect an option:\n";
        cout << "1. Add person to queue\n";
        cout << "2. Serve next person\n";
        cout << "3. Display all persons in queue\n";
        cout << "4. Exit\n";
        cin >> option;

        switch (option) {
            case 1: {
                string n, c;
                int a;
                cout << "Enter person's name: ";
                cin >> n;
                cout << "Enter person's CNIC: ";
                cin >> c;
                cout << "Enter person's age: ";
                cin >> a;

                Person p(n, c, a);
                bq.enqueue(p);
                break;
            }
            case 2:
                bq.dequeue();
                break;
            case 3:
                bq.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Wrong option, try again!\n";
                break;
        }
    }
}