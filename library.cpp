#include "library.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Library::Library() : bookCount(0) {}

void Library::AddBook(const Book& book) {
    if (bookCount < maxBooks) {
        books[bookCount] = book;
        bookCount++;
    }
    else {
        cout << "Incorrect input!" << endl;
        exit(1);
    }
}

void Library::RemoveBook(const Book& book) {
    bool bookFound = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle() == book.getTitle() &&
            books[i].getAuthor() == book.getAuthor() &&
            books[i].getYear() == book.getYear() &&
            books[i].getPublisher() == book.getPublisher()) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        cout << "Incorrect input!" << endl;
        exit(1);
    }
}

void Library::SearchByCriteria(const string& Str, int Choice) {
    bool found = false;
    switch (Choice)
    {
    case 1:
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == Str) {
                cout << "\nSearch by title '" << Str << "':\n";
                cout << books[i].getTitle() << " written by " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "." << endl;
            exit(1);
        }
        break;

    case 2:
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getAuthor() == Str) {
                cout << "\nSearch by author '" << Str << "':\n";
                cout << books[i].getTitle() << " written by " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "." << endl;
            exit(1);
        }
        break;

    case 4:
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getPublisher() == Str) {
                cout << "\nSearch by publisher '" << Str << "':\n";
                cout << books[i].getTitle() << " written by " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "The book by this criterion was not found!" << endl;
            exit(1);
        }
        break;
    }
}

void Library::SearchByCriteria(const int Year) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getYear() == Year) {
            cout << "\nSearch by year '" << Year << "':\n";
            cout << books[i].getTitle() << " written by " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "The book by this criterion was not found!" << endl;
        exit(1);
    }
}

Library Library::operator+(const Book& book) {
    Library result = *this;
    try {
        result.AddBook(book);
    }
    catch (...) {
        cout << "Error adding book." << endl;
    }
    return result;
}

Library Library::operator-(const Book& book) {
    Library result = *this;
    try {
        result.RemoveBook(book);
    }
    catch (...) {
        cout << "Error deleting book." << endl;
    }
    return result;
}