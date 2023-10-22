#include <iostream>
#include "library.h"
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Library library;

    while (true) {
        cout << "Меню:\n";
        cout << "1. Додати книгу\n";
        cout << "2. Видалити книгу\n";
        cout << "3. Пошук книги\n";
        cout << "4. Вихід\n";
        cout << "Введіть вибір: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author, publisher;
            int year;

            // Введення даних про книгу
            cout << "Введіть назву книги: ";
            cin >> title;
            cout << "Введіть автора: ";
            cin >> author;
            cout << "Введіть рік публікації: ";
            cin >> year;
            cout << "Введіть видавництво: ";
            cin >> publisher;

            Book book(title, author, year, publisher);

            // Додавання книги до бібліотеки
            library.AddBook(book);
            cout << "Книга додана до бібліотеки.\n";
        }
        else if (choice == 2) {
            string removeTitle, removeAuthor, removePublisher;
            int removeYear;
            cout << "Введіть назву книги для видалення: ";
            cin >> removeTitle;
            cout << "Введіть автора книги для видалення: ";
            cin >> removeAuthor;
            cout << "Введіть рік видання книги для видалення: ";
            cin >> removeYear;
            cout << "Введіть видавництво книги для видалення: ";
            cin >> removePublisher;

            Book bookToRemove(removeTitle, removeAuthor, removeYear, removePublisher);

            library.RemoveBook(bookToRemove);
            cout << "Книга видалена з бібліотеки.\n";
        }
        else if (choice == 3) {
            string criteria, value;
            cout << "Введіть критерій пошуку (назва/автор/видавництво/рік): ";
            cin >> criteria;
            cout << "Введіть значення критерію: ";
            cin >> value;

            library.SearchByCriteria(criteria, value);
        }
        else if (choice == 4) {
            break; // Вихід із програми
        }
        else {
            cout << "Неправильний вибір!." << endl;
            exit(1);
        }
    }

    return 0;
}