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
        cout << "��������� ���������. ��������� ������ �����." << endl;
        exit(EXIT_FAILURE);
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
        cerr << "����� �� �������� � ��������." << endl;
        abort();
    }
}

void Library::SearchByCriteria(const string& criteria, const string& value) const {
    cout << "����� � ������� '" << criteria << "':\n";
    for (int i = 0; i < bookCount; i++) {
        if (criteria == "�����" && books[i].getTitle() == value) {
            cout << books[i].getTitle() << " ������� " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n";
        }
        else if (criteria == "�����" && books[i].getAuthor() == value) {
            cout << books[i].getTitle() << " ������� " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n";
        }
        else if (criteria == "�����������" && books[i].getPublisher() == value) {
            cout << books[i].getTitle() << " ������� " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n";
        }
        else if (criteria == "��" && std::to_string(books[i].getYear()) == value) {
            cout << books[i].getTitle() << " ������� " << books[i].getAuthor() << " (" << books[i].getYear() << ")\n";
        }
    }

    if (bookCount == 0) {
        cerr << "����� ����� � �������� �� ������� �������." << endl;
        exit(EXIT_FAILURE);
    }
}

Library Library::operator+(const Book& book) {
    Library result = *this;  // Making a copy of the current library
    result.AddBook(book);    // Adding a book to a library copy
    return result;
}

Library Library::operator-(const Book& book) {
    Library result = *this;    // Making a copy of the current library
    result.RemoveBook(book);    // Adding a book to a library copy
    return result;
}