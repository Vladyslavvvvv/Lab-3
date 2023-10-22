#include "book.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Book::Book() : title(""), author(""), year(0), publisher("") {}

Book::Book(const string& title, const string& author, int year, const string& publisher)
    : title(title), author(author), year(year), publisher(publisher) {}

const string& Book::getTitle() const {
    return title;
}

const string& Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    try {
        if (year < 0) {
            throw invalid_argument("Year is invalid.");
        }
        return year;
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
        return 1;
    }
}

const string& Book::getPublisher() const {
    return publisher;
}

void Book::setTitle(const string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const string& newAuthor) {
    author = newAuthor;
}

void Book::setYear(int newYear) {
    try {
        if (newYear < 0) {
            throw invalid_argument("Year cannot be negative.");
        }
        year = newYear;
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}

void Book::setPublisher(const string& newPublisher) {
    publisher = newPublisher;
}