#include "library.h"
#include <iostream>

using namespace std;

Library::Library() : bookCount(0) {}

void Library::AddBook(const Book& book) {
    try {
        if (bookCount < maxBooks) {
            books[bookCount] = book;
            bookCount++;
        }
        else {
            throw LibraryException("Бібліотека заповнена. Неможливо додати книгу.");
        }
    }
    catch (const LibraryException& ex) {
        cout << ex.what() << endl;
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
        throw LibraryException("Книга не знайдена в бібліотеці.");
    }
}

void Library::SearchByCriteria(const string& criteria, const string& value) const {
    try {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if ((criteria == "назва" && books[i].getTitle() == value) ||
                (criteria == "автор" && books[i].getAuthor() == value) ||
                (criteria == "видавництво" && books[i].getPublisher() == value) ||
                (criteria == "рік" && to_string(books[i].getYear()) == value)) {
                cout << "Книги з критерієм '" << criteria << "':\n";
                cout << books[i].getTitle() << " написав " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n";
                found = true;
            }
        }

        if (!found) {
            throw LibraryException("Жодна книга в бібліотеці не відповідає критерію.");
        }
    }
    catch (const LibraryException& ex) {
        cout << ex.what() << endl;
    }
}

Library Library::operator+(const Book& book) {
    Library result = *this;
    try {
        result.AddBook(book);
    }
    catch (const LibraryException& ex) {
        cout << ex.what() << endl;
    }
    return result;
}

Library Library::operator-(const Book& book) {
    Library result = *this;
    try {
        result.RemoveBook(book);
    }
    catch (const LibraryException& ex) {
        cout << ex.what() << endl;
    }
    return result;
}