
#ifndef BOOKDATASTRUC_H
#define BOOKDATASTRUC_H

extern int numBook;
extern int librarySize;

typedef struct book {
	int bookcode;
	char name[BOOK_LEN + 1];
	int borrowWhether;
	enum { fiction = 1, nonfiction = 2 } genre;
} Book;

extern Book* library;


#endif