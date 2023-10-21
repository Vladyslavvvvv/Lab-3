#include <iostream>
#include "book.h"
#include "library.h"
#include <cstdlib>

using namespace std;

int main() {
    Library library;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a book\n";
        cout << "2. Delete the book\n";
        cout << "3. Book search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author, publisher;
            int year;

            cout << "Enter the title of the book: ";
            cin >> title;
            cout << "Enter the author: ";
            cin >> author;
            cout << "Enter the year of publication: ";
            cin >> year;
            cout << "Enter the publisher: ";
            cin >> publisher;

            Book book(title, author, year, publisher);

            library.AddBook(book);
            cout << "The book has been added to the library.\n";
        }
        else if (choice == 2) {
            string removeTitle, removeAuthor, removePublisher;
            int removeYear;
            cout << "Enter the name of the book to delete: ";
            cin >> removeTitle;
            cout << "Enter the author of the book to delete: ";
            cin >> removeAuthor;
            cout << "Enter the publication year of the book to delete: ";
            cin >> removeYear;
            cout << "Enter the publisher of the book to delete: ";
            cin >> removePublisher;

            Book bookToRemove(removeTitle, removeAuthor, removeYear, removePublisher);

            library.RemoveBook(bookToRemove);
            cout << "The book has been removed from the library.\n";
        }
        else if (choice == 3) {
            string criteria, value;
            cout << "Enter search criteria (title/author/publisher/year): ";
            cin >> criteria;
            cout << "Enter the criteria value: ";
            cin >> value;

            library.SearchByCriteria(criteria, value);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Wrong choice!." << endl;
            exit(1);
        }
    }

    return 0;
}