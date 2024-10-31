#include <iostream>
#include <string>
using namespace std;

class candidate {
public:
    string name;
    int experience;
    string qualification;
    int marks;

    candidate(string n = "", int exp = 0, string qual = "", int m = 0) 
        : name(n), experience(exp), qualification(qual), marks(m) {}

    bool criteria() const {
        return experience > 3 && qualification == "MS";
    }
};

class pqueue {
private:
    candidate* arr;
    int front;
    int rear;
    int count;
    int capacity;

    void expand() {
        int newCapacity = capacity * 2;
        candidate* newArr = new candidate[newCapacity];

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
    pqueue(int cap = 10) : capacity(cap) {
        arr = new candidate[capacity];
        front = -1;
        rear = -1;
        count = 0;
    }

    ~pqueue() {
        delete[] arr;
    }

    bool isFull() const {
        return count == capacity;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void enqueue(const candidate& c) {
        if (!c.criteria()) {
            cout << "Candidate does not meet criteria.\n";
            return;
        }

        if (isFull()) {
            expand();
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = c;
        count++;
        cout << "Candidate " << c.name << " added to the priority queue.\n";
        prioritize();
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Calling candidate for interview:\n";
        cout << "Name: " << arr[front].name << ", Experience: " << arr[front].experience
             << " years, Qualification: " << arr[front].qualification 
             << ", Written Test Marks: " << arr[front].marks << endl;

        front = (front + 1) % capacity;
        count--;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No candidates in the priority queue.\n";
            return;
        }

        cout << "Candidates in the priority queue:\n";
        int i = front;
        for (int n = 0; n < count; n++) {
            cout << "Name: " << arr[i].name << ", Experience: " << arr[i].experience
                 << " years, Qualification: " << arr[i].qualification 
                 << ", Written Test Marks: " << arr[i].marks << endl;
            i = (i + 1) % capacity;
        }
    }

    void prioritize() {
        for (int i = 0; i < count; i++) {
            for (int j = (i + 1) % capacity; j != (rear + 1) % capacity; j = (j + 1) % capacity) {
                if (arr[i].experience < arr[j].experience ||
                   (arr[i].experience == arr[j].experience && arr[i].marks < arr[j].marks)) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
};

int main() {
    pqueue pq;
    int option;

    while (1) {
        cout << "\nSelect an option:\n";
        cout << "1. Add candidate\n";
        cout << "2. Call candidate for interview\n";
        cout << "3. Display all candidates\n";
        cout << "4. Exit\n";
        cin >> option;

        switch (option) {
            case 1: {
                string n, q;
                int e, m;
                cout << "Enter candidate's name: ";
                cin >> n;
                cout << "Enter candidate's years of experience: ";
                cin >> e;
                cout << "Enter candidate's qualification (e.g. MS, BS, FSc): ";
                cin >> q;
                cout << "Enter candidate's written test marks (out of 50): ";
                cin >> m;

                candidate c(n, e, q, m);
                pq.enqueue(c);
                break;
            }
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
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