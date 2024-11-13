#include<iostream>
#include<string>
using namespace std;

struct Book {
	string title;
	string authors;
	int edition;
	float price;
	Book* next;
};

class BookList {
	Book* head;
public:
	BookList() { head = NULL; }

	~BookList() {
		while (head != NULL) {
			Book* temp = head;
			head = head->next;
			delete temp;
		}
	}

	Book* createBook(const string& title, const string& authors, int edition, float price) {
		Book* newBook = new Book;
		newBook->title = title;
		newBook->authors = authors;
		newBook->edition = edition;
		newBook->price = price;
		newBook->next = NULL;
		return newBook;
	}

	void addBook(const string& title, const string& authors, int edition, float price) {
		Book* newBook = createBook(title, authors, edition, price);
		if (head == NULL) {
			head = newBook;
		} else {
			Book* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newBook;
		}
	}


	void displayBooks() {
		Book* temp = head;
		if (temp == NULL) {
			cout << "No books in the list." << endl;
			return;
		}
		while (temp != NULL) {
			cout << "Title: " << temp->title << ", Authors: " << temp->authors
			     << ", Edition: " << temp->edition << ", Price: " << temp->price << endl;
			temp = temp->next;
		}
	}

	
	void deleteExpensiveBooks() {
		while (head != NULL && head->price > 2000) {
			Book* temp = head;
			head = head->next;
			delete temp;
		}

		Book* current = head;
		while (current != NULL && current->next != NULL) {
			if (current->next->price > 2000) {
				Book* temp = current->next;
				current->next = current->next->next;
				delete temp;
			} else {
				current = current->next;
			}
		}
	}
};

int main() {
	BookList books;
	

	books.addBook("C++ Programming", "Bjarne Stroustrup", 4, 2500);
	books.addBook("Data Structures", "Mark Allen Weiss", 3, 1500);
	books.addBook("Operating Systems", "Abraham Silberschatz", 9, 3000);
	books.addBook("Database Systems", "Ramez Elmasri", 6, 1800);
	
	cout << "Books in the list:" << endl;
	books.displayBooks();
	

	books.deleteExpensiveBooks();
	
	cout << "\nBooks after deleting those with price > 2000:" << endl;
	books.displayBooks();
	
	return 0;
}
