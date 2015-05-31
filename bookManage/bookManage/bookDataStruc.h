
#ifndef BOOKDATASTRUC_H
#define BOOKDATASTRUC_H

#define BOOK_LEN 50
#define AUTHOR_LEN 50

extern int numBook;
extern int librarySize;

#define can_Borrow 99
#define cannot_Borrow 100;

typedef struct book {
	int bookcode;
	char name[BOOK_LEN + 1];
	char author[AUTHOR_LEN + 1];
	int canBorrow;
	enum { fiction = 1, nonfiction = 2 } genre;
} Book;

extern Book* library;


#endif