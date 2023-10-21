#include "book.h"

using namespace std;

class Library {
public:
    Library();
    void AddBook(const Book& book);
    void RemoveBook(const Book& book);
    void SearchByCriteria(const string& criteria, const string& value) const;
    Library operator+(const Book& book);
    Library operator-(const Book& book);

private:
    static const int maxBooks = 100;
    Book books[maxBooks];
    int bookCount;
};