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
        cout << "." << endl;
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
        cout << "." << endl;
        exit(1);
    }
}

void Library::SearchByCriteria(const string& criteria, const string& value) const {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if ((criteria == "" && books[i].getTitle() == value) ||
            (criteria == "" && books[i].getAuthor() == value) ||
            (criteria == "" && books[i].getPublisher() == value) ||
            (criteria == "" && to_string(books[i].getYear()) == value)) {
            cout << " '" << criteria << "':\n";
            cout << books[i].getTitle() << "  " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "." << endl;
        exit(1);
    }
}

Library Library::operator+(const Book& book) {
    Library result = *this;
    try {
        result.AddBook(book);
    }
    catch (...) {
        cout << "Помилка додавання книги." << endl;
    }
    return result;
}

Library Library::operator-(const Book& book) {
    Library result = *this;
    try {
        result.RemoveBook(book);
    }
    catch (...) {
        cout << "Помилка видалення книги." << endl;
    }
    return result;
}