#include <string>

using namespace std;

class Book {
public:
    Book();
 
    const string& getTitle() const;
    const string& getAuthor() const;
    int getYear() const;
    const string& getPublisher() const;

    void setTitle(const string& newTitle);
    void setAuthor(const string& newAuthor);
    void setYear(int newYear);
    void setPublisher(const string& newPublisher);

private:
    string title;
    string author;
    int year;
    string publisher;
};