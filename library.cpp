#include "library.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Library::Library() : bookCount(0) {}

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
            cout << "The book by this criterion was not found!" << endl;
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
            cout << "The book by this criterion was not found!" << endl;
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
    if (bookCount < maxBooks) {
        books[bookCount] = book;
        bookCount++;
    }
    else {
        cout << "Error: Library is full, cannot add the book." << endl;
    }
    return *this; // Повертаємо посилання на поточний об'єкт бібліотеки
}

Library Library::operator-(const Book& book) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle() == book.getTitle() &&
            books[i].getAuthor() == book.getAuthor() &&
            books[i].getYear() == book.getYear() &&
            books[i].getPublisher() == book.getPublisher()) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            return *this; // Повертаємо посилання на поточний об'єкт бібліотеки
        }
    }
    cout << "Error: Book not found in the library." << endl;
    return *this; // Повертаємо посилання на поточний об'єкт бібліотеки
}