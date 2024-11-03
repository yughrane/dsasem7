#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 0, ch, pos;
    string bookname;
    string books[100];
    cout << "Welcome to the Stars Hollow Bookstore!\n";

    do {
        cout << "Please choose from the menu below:\n"
             << "1. Sell Books\n"
             << "2. Print Collection\n"
             << "3. Insert First\n"
             << "4. Insert Last\n"
             << "5. Insert Specific\n"
             << "6. Delete First\n"
             << "7. Delete Last\n"
             << "8. Delete Specific\n"
             << "9. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the number of books you want to sell: ";
                cin >> n;
                cin.ignore();  // to ignore the newline character left in the buffer
                cout << "Enter the name of the books you want to sell:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Book " << i + 1 << ": ";
                    getline(cin, books[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    cout << "There are no books in your collection!\n";
                } else {
                    cout << "The following is your collection:\n";
                    for (int i = 0; i < n; i++) {
                        cout << books[i] << "\n";
                    }
                }
                break;

            case 3:
                if (n < 100) {
                    cout << "Enter the name of the book to add at the start: ";
                    cin.ignore();
                    getline(cin, bookname);
                    for (int i = n; i > 0; i--) {
                        books[i] = books[i - 1];
                    }
                    books[0] = bookname;
                    n++;
                } else {
                    cout << "Collection is full. Cannot add more books.\n";
                }
                break;

            case 4:
                if (n < 100) {
                    cout << "Enter the name of the book to add at the last: ";
                    cin.ignore();
                    getline(cin, bookname);
                    books[n] = bookname;
                    n++;
                } else {
                    cout << "Collection is full. Cannot add more books.\n";
                }
                break;

            case 5:
                if (n < 100) {
                    cout << "Enter the position to insert the book (1 to " << n + 1 << "): ";
                    cin >> pos;
                    if (pos > 0 && pos <= n + 1) {
                        cout << "Enter the name of the book: ";
                        cin.ignore();
                        getline(cin, bookname);
                        for (int i = n; i >= pos; i--) {
                            books[i] = books[i - 1];
                        }
                        books[pos - 1] = bookname;
                        n++;
                    } else {
                        cout << "Invalid position!\n";
                    }
                } else {
                    cout << "Collection is full. Cannot add more books.\n";
                }
                break;

            case 6:
                if (n > 0) {
                    for (int i = 0; i < n - 1; i++) {
                        books[i] = books[i + 1];
                    }
                    n--;
                    cout << "First book deleted.\n";
                } else {
                    cout << "No books to delete.\n";
                }
                break;

            case 7:
                if (n > 0) {
                    n--;
                    cout << "Last book deleted.\n";
                } else {
                    cout << "No books to delete.\n";
                }
                break;

            case 8:
                if (n > 0) {
                    cout << "Enter the position of the book to delete (1 to " << n << "): ";
                    cin >> pos;
                    if (pos > 0 && pos <= n) {
                        for (int i = pos - 1; i < n - 1; i++) {
                            books[i] = books[i + 1];
                        }
                        n--;
                        cout << "Book at position " << pos << " deleted.\n";
                    } else {
                        cout << "Invalid position!\n";
                    }
                } else {
                    cout << "No books to delete.\n";
                }
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Please enter a number from 1-9!\n";
                break;
        }
    } while (ch != 9);

    return 0;
}
