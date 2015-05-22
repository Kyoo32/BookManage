//
//  Header_bookManagement.h
//  bookManagement
//
//  Created by Kate KyuWon on 5/8/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//

#ifndef fUNCTION_BOOKMANAGEMENT_h
#define fUNCTION_BOOKMANAGEMENT_h

#include <stdio.h>

#define BOOK_LEN 50
#define borrow 99;
#define yetBorrow 100;

void userChoose(char command);

int findBookByCode(int bookcode);
int findBookByName(char* name);

void insertBook(void);
void searchBook(void);
void printLibrary(void);
void printLibraryWithFile(void);

void afterSearchBook(int, int yPos);
void deleteBook(int bookPos, int yPos);
void amendBookInfor(int bookPos, int yPos);

void extendLib (struct book**);


#endif
