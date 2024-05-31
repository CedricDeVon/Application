// #include <iostream>
// #include <cstring>

// using namespace std;

// struct Book
// {
//     char title[32];
//     char author[64];
//     char subject[32];
//     float price = 0;
//     int id;
// };

// Book create_book(char title[], char author[], char subject[], float price = 0)
// {
//     struct Book book;
//     strcpy(book.title, title);
//     strcpy(book.author, author);
//     strcpy(book.subject, subject);
//     book.price = price;
//     book.id = rand();
//     return book;
// }

// void print_book(struct Book book)
// {
//     cout << book.title << endl;
//     cout << book.author << endl;
//     cout << book.subject << endl;
//     cout << book.price << endl;
//     cout << book.id << endl;
// }

// Book update_book(Book book, char title[], char author[], char subject[], float price = 0)
// {
//     strcpy(book.title, title);
//     strcpy(book.author, author);
//     strcpy(book.subject, subject);
//     book.price = price;
//     return book;
// }

// Book delete_book(Book book)
// {
//     strcpy(book.title, "[No title]");
//     strcpy(book.author, "[No author]");
//     strcpy(book.subject, "[No subject]");
//     book.price = 0;
//     book.id = 0;
//     return book;
// }

// int main(char argc, char *args[])
// {
//     char title[] = "title";
//     char author[] = "author";
//     char subject[] = "subject";
//     struct Book book = create_book(title, author, subject, 10.9);
//     print_book(book);
//     book = update_book(book, book.title, book.author, book.subject, 100.69);
//     print_book(book);
//     book = delete_book(book);
//     print_book(book);

//     return 0;
// }
