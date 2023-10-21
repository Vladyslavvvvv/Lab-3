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
        cout << "Library is full. Unable to add the book." << endl;
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
        cout << "The book was not found in the library." << endl;
        exit(1);
    }
}

void Library::SearchByCriteria(const string& criteria, const string& value) const {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if ((criteria == "title" && books[i].getTitle() == value) ||
            (criteria == "author" && books[i].getAuthor() == value) ||
            (criteria == "publisher" && books[i].getPublisher() == value) ||
            (criteria == "year" && to_string(books[i].getYear()) == value)) {
            cout << "Books with the '" << criteria << "' criteria:\n";
            cout << books[i].getTitle() << " written by " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No book in the library matches the criteria." << endl;
        exit(1);
    }
}

Library Library::operator+(const Book& book) {
    Library result = *this;
    if (bookCount < maxBooks) {
        result.books[result.bookCount] = book;
        result.bookCount++;
    }
    else {
        cout << "Library is full. Unable to add the book." << endl;
        exit(1);
    }
    return result;
}

Library Library::operator-(const Book& book) {
    Library result = *this;
    bool bookFound = false;
    for (int i = 0; i < result.bookCount; i++) {
        if (result.books[i].getTitle() == book.getTitle() &&
            result.books[i].getAuthor() == book.getAuthor() &&
            result.books[i].getYear() == book.getYear() &&
            result.books[i].getPublisher() == book.getPublisher()) {
            for (int j = i; j < result.bookCount - 1; j++) {
                result.books[j] = result.books[j + 1];
            }
            result.bookCount--;
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        cout << "The book was not found in the library." << endl;
        exit(1);
    }

    return result;
}