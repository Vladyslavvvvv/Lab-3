#include <iostream>
#include "library.h"
#include <cstdlib>

using namespace std;

int main() {
    Library library;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a book\n";
        cout << "2. Delete the book\n";
        cout << "3. Book search\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author, publisher;
            int year;

            cout << "\nEnter the title of the book: ";
            cin >> title;
            cout << "Enter the author: ";
            cin >> author;
            cout << "Enter the year of publication: ";
            cin >> year;
            cout << "Enter the publisher: ";
            cin >> publisher;

            Book bookToAdd;
            bookToAdd.setTitle(title);
            bookToAdd.setAuthor(author);
            bookToAdd.setYear(year);
            bookToAdd.setPublisher(publisher);

            library = library + bookToAdd;
            cout << "\nThe book has been added to the library.\n" << endl;
        }
        else if (choice == 2) {
            string removeTitle, removeAuthor, removePublisher;
            int removeYear;
            cout << "Enter the name of the book to delete: ";
            cin >> removeTitle;
            cout << "Enter the author of the book to delete: ";
            cin >> removeAuthor;
            cout << "Enter the publication year of the book to delete: ";
            cin >> removeYear;
            cout << "Enter the publisher of the book to delete: ";
            cin >> removePublisher;

            Book bookToRemove;
            bookToRemove.setTitle(removeTitle);
            bookToRemove.setAuthor(removeAuthor);
            bookToRemove.setYear(removeYear);
            bookToRemove.setPublisher(removePublisher);

            library = library - bookToRemove;
            cout << "The book has been removed from the library.\n";
        }
        else if (choice == 3) {
            int choiceC;
            cout << "\nBy what criteria to search for a book?" << endl;
            cout << "1 - The title of the book" << endl;
            cout << "2 - The author of the book" << endl;
            cout << "3 - Year of publication" << endl;
            cout << "4 - Publishing house" << endl;
            cout << "Enter your choice: ";
            cin >> choiceC;
            if (choiceC == 1 || choiceC == 2 || choiceC == 4) {
                string Str;
                if (choiceC == 1) {
                    cout << "\nTitle: ";
                }
                else if (choiceC == 2) {
                    cout << "\nAuthor: ";
                }
                else if (choiceC == 4) {
                    cout << "\nPublisher: ";
                }
                cin >> Str;
                library.SearchByCriteria(Str, choiceC);
            }
            else if (choiceC == 3) {
                int Year;
                cout << "\nYear: ";
                cin >> Year;
                library.SearchByCriteria(Year);
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Wrong choice!" << endl;
            exit(1);
        }
    }

    return 0;
}