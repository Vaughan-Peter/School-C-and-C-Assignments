// book.h
#ifndef BOOK_H
#define BOOK_H

typedef struct {
    char title[256];
    char author[100];
    char isbn[13]; // ISBN-13 format
    int year;
} Book;

int addBook();
int deleteBook();
int searchBook();
int listBooks();
int saveBooks();
int loadBooks();

#endif
