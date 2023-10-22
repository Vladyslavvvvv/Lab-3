#include "book.h"

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
    return year;
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
    year = newYear;
}

void Book::setPublisher(const string& newPublisher) {
    publisher = newPublisher;
}