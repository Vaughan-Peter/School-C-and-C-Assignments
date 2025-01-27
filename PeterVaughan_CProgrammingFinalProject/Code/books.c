#include <stdio.h>
#include <string.h>
#include "book.h"
#include <stdlib.h>
#include <stdbool.h>

/*
** All the needed headers above
** Get user input first then opens file to put all thr info in
** More info with some lines
*/
int addBook(){
    FILE *file;
    Book book;

    //Get book info
    printf("Enter the book title: \n");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0';
        
    printf("Enter the book author: \n");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0';
    
    printf("Enter the book isbn: \n");
    fgets(book.isbn, sizeof(book.isbn), stdin);
    book.isbn[strcspn(book.isbn, "\n")] = '\0';
    
    printf("Enter the book year: \n");
    scanf("%d", &book.year);
    getchar();//Consume the newline character left in the input buffer

    //Get book dat file to put info in
    file = fopen("book.dat", "ab");
    
    if(file == NULL){
        printf("Error opening file");
        return 1;
    }

    fwrite(&book, sizeof(Book), 1, file);
    
    if(ferror(file)){
        printf("Error writing file!\n");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;

}

/*
** Opens two files
** Copies old file excluding one book to new file
** Deletes old file and renames new file
** More info on some lines
*/
int deleteBook(){

    //variables
    FILE *readFile;
    FILE *writeFile;
    char ISBN[13];
    size_t bookTotal = 0;
    
    //opening files
    readFile = fopen("book.dat", "rb");
    
    if(readFile == NULL){
        printf("Error opening file");
        return 1;
    }

    writeFile = fopen("temp.dat", "wb");
    
    if(writeFile == NULL){
        printf("Error opening file");
        return 1;
    }

    // Changed this to fgets to match the input method from add book, more likely to get consistent input
    printf("Enter the book isbn: \n");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    // This "ptr" is a throw away pointer, so there is space in memory to read the books while we get the total.
    Book ptr;
    while(fread(&ptr, sizeof(Book), 1, readFile) == 1){
    	bookTotal++;
    	printf("Reading book \n");
    }    
    
    // It is probably "best practices" to use fseek here, but this seems to work
    fclose(readFile);
    readFile = fopen("book.dat", "rb");

    Book *bookList = malloc(sizeof(Book) * bookTotal);
    Book *newList = malloc(sizeof(Book) * (bookTotal-1));

    if(fread(bookList, sizeof(Book), bookTotal, readFile) != bookTotal){
    	free(bookList);
      return 1;    
    } 
    
    // We loop over the books to make sure that we can find it before proceeding
    for(int i = 0; i < bookTotal; i++){
      if (strcmp(ISBN, bookList[i].isbn) == 0)
        break;
      if (i == bookTotal - 1) {
        printf("Book not found");
        return 0;
      }
    }

    // SMoving over books
    bool found = false;
    for(int i = 0; i < bookTotal; i++){
    	if(strcmp(ISBN, bookList[i].isbn) == 0)
    		found = true;
    	if(!found){
    		newList[i] = bookList[i];
    	}else{
    		if(i + 1 < bookTotal){
    			newList[i] = bookList[i + 1];
    		}
    	}
    }
    
    fwrite(newList, sizeof(Book), bookTotal - 1, writeFile);

    // We do some document manipulation
    remove("book.dat");
    fclose(readFile);

    rename("temp.dat", "book.dat");
    fclose(writeFile);

    free(bookList);
    free(newList);
    printf("Book deleted \n");
    return 0;
}

/*
** Opens file to search for a book
** Display book
** More info on some lines
*/
int searchBook(){

    FILE *file;
    Book book;
    char name[256];
    
    //Open the file and checking file is opened
    file = fopen("book.dat", "rb");

    if(file == NULL){
        printf("Error opening file");
        return 1;
    }
    printf("Enter the book name: \n");
    scanf("%s", name);
    getchar();
    
    //Read one element of type Book at a time
    while(fread(&book, sizeof(Book), 1, file) == 1){
        if(strcmp(name, book.title) == 0){
        	printf("Title: %s\n", book.title);
        	printf("Author: %s\n", book.author);
        	printf("ISBN: %s\n", book.isbn);
        	printf("Year: %d\n", book.year);
        	printf("\n");
        	}
    }

    //Check if an error occurred while reading the file
    if(ferror(file)){
        printf("Error reading file!\n");
        fclose(file);
        return 1;
    }

    //Close the file
    fclose(file);  
    printf("Search Done \n");
    return 0;
}

/*
** Opens file to display all books
** Display book info as it loops through the files until it finds no more info
** More info on some lines
*/
int listBooks(){
    FILE *file;
    Book book;

    //Open the file
    file = fopen("book.dat", "rb");

    //Checking file is opened
    if(file == NULL){
        printf("Error opening file");
        return 1;
    }

    //Read one element of type Book at a time
    while(fread(&book, sizeof(Book), 1, file) == 1){

        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("ISBN: %s\n", book.isbn);
        printf("Year: %d\n", book.year);
        printf("\n");
    }

    //Check if an error occurred while reading the file
    if(ferror(file)){
        printf("Error reading file!\n");
        fclose(file);
        return 1;
    }

    //Close the file
    fclose(file);
    return 0;
}

/*
** Technically I did not need this because I was closing it in each section
** This is so that I can open it in different ways so I need to close the file first
** More info on some lines
*/
int saveBooks(){

    FILE *file;
    
    //Books are updated within each function. I want to verify any issues by opening the file and closing it.
    file = fopen("book.dat", "ab");
    
    //Checking file is opened
    if(file == NULL){
        printf("Error opening file");
        return 1;
    }

    //prints out unless there is issues and close the file
    printf("Books are saved!\n");
    fclose(file);
    return 0;
}

/*
** I found out that fopen created a file if the file did not exist. I thought I needed more code.
** It will give an error or load to the main while loop in main program
** More info on some lines
*/
int loadBooks(){

    FILE *file;
    
    //This makes sure that this file exist. Otherwise, it creates it on my system.
    file = fopen("book.dat", "ab");
    
    //Checking file is opened
    if(file == NULL){
        printf("Error opening file");
        return 1;
    }

    //prints out unless there is issues and close the file
    printf("If book.dat did not exist, it exists now!\n");
    printf("Books can now be viewed!\n");
    fclose(file);
    return 0;
}
