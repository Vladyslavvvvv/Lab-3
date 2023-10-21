#include <iostream>
#include "book.h"
#include "library.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Library library;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a book\n";
        cout << "2. Remove a book\n";
        cout << "3. Search for a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author, publisher;
            int year;

            cout << "Enter the book's title: ";
            cin >> title;
            cout << "Enter the author: ";
            cin >> author;
            cout << "Enter the publication year: ";
            cin >> year;
            cout << "Enter the publisher: ";
            cin >> publisher;

            Book book(title, author, year, publisher);

            library.AddBook(book);
            cout << "The book has been added to the library." << endl;
        }
        else if (choice == 2) {
            string removeTitle, removeAuthor, removePublisher;
            int removeYear;
            cout << "Enter the title of the book to remove: ";
            cin >> removeTitle;
            cout << "Enter the author of the book to remove: ";
            cin >> removeAuthor;
            cout << "Enter the publication year of the book to remove: ";
            cin >> removeYear;
            cout << "Enter the publisher of the book to remove: ";
            cin >> removePublisher;

            Book bookToRemove(removeTitle, removeAuthor, removeYear, removePublisher);

            library.RemoveBook(bookToRemove);
            cout << "The book has been removed from the library." << endl;
        }
        else if (choice == 3) {
            string criteria, value;
            cout << "Enter the search criteria (title/author/publisher/year): ";
            cin >> criteria;
            cout << "Enter the criteria value: ";
            cin >> value;

            library.SearchByCriteria(criteria, value);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
            exit(1);
        }
    }

    return 0;
}