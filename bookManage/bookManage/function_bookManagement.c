//
//  function_bookManagement.c
//  bookManagement
//
//  Created by Kate KyuWon on 5/8/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//


#define _CRT_SECURE_NO_WARNINGS
#include "function_bookManagement.h"
#include "UI_bookmanage.h"
#include "bookDataStruc.h"
#include "line.h"



void userChoose(char command){

	switch (command){
	case 'i':case'I': insertBook();
		break;
	case 's':case'S':  searchBook();
		break;
	case 'p':case'P': printLibrary();
		break;
	case 'q':case'Q': return;
	default: 
		gotoxy(20, 15);
		printf("Illegal command\n");
		Sleep(300);
		break;
	}
}


int findBookByCode(int bookcode){
    int i;
    
    for(i=0; i<numBook; i++){
        if (library[i].bookcode == bookcode) {
            return i;
        }
    }
    return -1;
}

int findBookByName(char* name){
	int i = 0;
	
	for (i = 0; i < numBook; i++){
		if (!strcmp(library[i].name, name))
			return i;
	}

	return -1;
}


void insertBook(void){
	int x = 20, y = 15;
    
    int bookcode;
	char name[BOOK_LEN + 1];
    char check;
    
    if(numBook >= librarySize){
       // printf("Database is full; can't add more books.\n");
        extendLib(&library);    
    }
   
	gotoxy(x, y);
    printf("Enter bookcode: "); 
    while(scanf("%d%c",&bookcode,&check) != 2 || check != '\n')
    {
		y++;
		gotoxy(x, y);
        printf("Please enter an integer only: ");
        if(check == '\n'){
            scanf("%c",&check);
           
        }
        else
        {
            while(check != '\n') {
                scanf("%c",&check);
            }
                }
        
        check = 0;
    }   
    if (findBookByCode(bookcode) >= 0){
		y++;
		gotoxy(x, y);
        printf("Book you want to add already exists.\n");
		y += 2;
		gotoxy(x, y);
		printf("Press enter to go main");
		getc(stdin);
        return;
    }
    library[numBook].bookcode = bookcode;




	y++;
	gotoxy(x, y);
    printf("Enter book name: ");
    read_line(name, BOOK_LEN);
	if (findBookByName(name) >= 0){
		y++;
		gotoxy(x, y);
		printf("Book you want to add already exists.\n");
		y += 2;
		gotoxy(x, y);
		printf("Press enter to go main");
		getc(stdin);
		return;
	}
	strcpy(library[numBook].name, name);




	y++;
	gotoxy(x, y);
    printf("Enter the genre(fiction = 1 /nonfiction = 2): ");
    scanf("%d", &library[numBook].genre);
    clearLineFromReadBuffer();
    while(library[numBook].genre != 1 && library[numBook].genre != 2){
		y++;
		gotoxy(x, y);
        printf("Wrong input, try to enter again: ");
        scanf("%d", &library[numBook].genre);
        clearLineFromReadBuffer();
    }

    numBook++;

	y += 2;
	gotoxy(x, y);
	textColor(DARK_SKY_BLUE);
	puts("The book is inserted, thanX:)");
	y++;
	gotoxy(x, y);
	puts("Press enter to go main");
	y++;
	gotoxy(x, y);
	getc(stdin);
	y++;
	gotoxy(x, y);
	textColor(GRAY);


}

void extendLib (struct book ** originalLib){
   
    *originalLib = (Book*)realloc( *originalLib, sizeof(Book)* librarySize * 2);
   
    (librarySize) *= 2;
    
    return ;
}

void searchBook(void){
	int x = 20, y = 14;

	if (numBook <= 0) {
		gotoxy(x, y);
		printf("NO book in Library\n");
		Sleep(300);
		return;
	}

	y++;
	textColor(GRAY);
	gotoxy(x, y);
	printf("旨收收收收<Choose one>收收收收收旬");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("早 n   : Search by name         早");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("早 c   : Search by code         早");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("曲收收收收收收收收收收收收收收收旭");
	y++;
	gotoxy(x+10, y);


	char command = 0;
	scanf("%c", &command);
	getchar();
	while (command != 'c' && command != 'n'&& command != 'C' && command != 'N'){
		y++;
		gotoxy(x, y);
		puts("wrong input, try again: ");
		y++;
		gotoxy(x, y);
		scanf("%c", &command);
		clearLineFromReadBuffer();
	}

    int i, bookcode;
	char userSearch[BOOK_LEN + 1];
    
	if (command == 'c' || command == 'C'){

		y++;
		gotoxy(x, y);
	    printf("Enter part bookcode: ");
		y++;
		gotoxy(x, y);
	    scanf("%d", &bookcode);
	    clearLineFromReadBuffer();
	    i=findBookByCode(bookcode);
	    
		if (i >= 0){

			y +=2;
			gotoxy(x, y);
			printf("Book name :%s\n", library[i].name);
			y++;
			gotoxy(x, y);
			printf("Book genre: ");
			if (library[i].genre == 0) printf("%s\n", "fiction");
			else printf("%s\n", "nonfiction");

			afterSearchBook(i,y); return;
		}
		else{

			y += 2;
			gotoxy(x, y);
			printf("Book not found.\n");
			Sleep(200);
		}
	}

	else if (command == 'n' || command == 'N'){

		y++;
		gotoxy(x, y);
		printf("Enter book name: ");
		y++;
		gotoxy(x, y);
		scanf("%s", &userSearch);
		clearLineFromReadBuffer();
		i = findBookByName(userSearch);

		if (i >= 0){

			y += 2;
			gotoxy(x, y);
			printf("Book code :%6d\n", library[i].bookcode);
			y++;
			gotoxy(x, y);
			printf("Book genre: ");
			if (library[i].genre == 0) printf("%s\n", "fiction");
			else printf("%s\n", "nonfiction");

			afterSearchBook(i, y); return;
		}
		else{
			y += 2;
			gotoxy(x, y);
			printf("Book not found.\n");
			Sleep(200);
		}
	}

	return;
}

void afterSearchBook(int i, int y){
	char command = 0;

	 int x = 20;

	textColor(GRAY);
	y += 2;
	gotoxy(x, y);
	printf("旨收收收收<Choose one>收收收收收旬");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("早 a   : Amend book's infor     早");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("早 d   : Delete the book        早");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("早Enter: go back to main        早");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("曲收收收收收收收收收收收收收收收旭");
	y++;
	gotoxy(x + 10, y);


	scanf("%c", &command);
	//clearLineFromReadBuffer();

	while (command != '\n' && command != 'a' && command != 'A' && command != 'd' && command != 'D'){

		y++;
		gotoxy(x, y);
		puts("wrong input, try again: ");
		y++;
		gotoxy(x, y);
		scanf("%c", &command);
		clearLineFromReadBuffer();
	}


	switch (command){
	case 'd': case 'D': deleteBook(i, y);
		break;
	case 'a': case 'A': amendBookInfor(i, y);
		break;
	case '\n': return;
	}

}

void deleteBook(int bookPos, int y)
{
	int x = 20;

	int i = bookPos;

	for (i = bookPos; i < librarySize; i++){
		library[i] = library[i + 1];
	}

	y += 2;
	gotoxy(x, y);
	textColor(DARK_SKY_BLUE);
	puts("The book is deleted :)");
	y++;
	gotoxy(x, y);
	puts("Press enter to go main");
	y++;
	gotoxy(x, y);
	Sleep(400);
	getc(stdin);
	textColor(GRAY);

	numBook--;

}


void amendBookInfor(int bookPos, int y){

    char command =0;
	int x = 20;

	show_amend(y);

	clearLineFromReadBuffer();
	scanf("%c", &command);    
	getchar();
    
    switch(command){
	case 'c': case 'C':
				y++;
				gotoxy(x, y);
				printf("Enter the code: ");
				scanf("%d", &library[bookPos].bookcode);
				clearLineFromReadBuffer();
				break;
	case 'n': case 'N':
				y++;
				gotoxy(x, y);
	            printf("Enter book name: ");
	            read_line(library[bookPos].name, BOOK_LEN);
	            break;
	case 'g': case 'G':
				y++;
				gotoxy(x, y);
	            printf("Enter the genre(fiction = 1 /nonfiction = 2): ");
	            scanf("%d", &library[bookPos].genre);
	            clearLineFromReadBuffer();
	
				while (library[bookPos].genre != 1 && library[bookPos].genre != 2)
				{
					y++;
					gotoxy(x, y);
					printf("Wrong input, try to enter again: ");
					scanf("%d", &library[bookPos].genre);
					clearLineFromReadBuffer();
				}
				break;
    }
    

}


void printLibrary(void){
	int x = 10, y = 15;

	char command = 0;

	if (numBook <= 0) {
		gotoxy(20, 15);
		printf("NO book in Library\n");
		Sleep(400);
		return;
	}

	int i;
	
	gotoxy(x, y);
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	y++;
	gotoxy(x, y);
	printf("早  Book Code  早     Book Name     早     Book Genre   早");
  
    for(i=0; i<numBook ; i++){
		y++;
		gotoxy(x, y);
		printf("早%-9d    早%-19s", library[i].bookcode, library[i].name);
        if(library[i].genre == fiction) printf("早%18s早\n", "fiction");
        else printf("早%18s早\n", "nonfiction");
    }
	y++;
	gotoxy(x, y);
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	x += 5;
	y++;
	gotoxy(x, y);
	textColor(DARK_SKY_BLUE);
	puts("Do you want print it in file, too? (y=yes, n=no)");
	textColor(GRAY);
	y++;
	gotoxy(x, y);
	if ((command = getc(stdin)) == 'y' || command == 'Y') printLibraryWithFile();
	else return;

}

void printLibraryWithFile(void){


	int i = 0;

	FILE *fp = fopen("bookLiist.txt", "w");

	if (fp == NULL){
		puts("Write error");
		return;
	}

	fprintf(fp, "|Book Code  /     Book Name     /      Book Genre|\n");
	for (i = 0; i<numBook; i++){
		fprintf(fp, "%-10d    %-25s", library[i].bookcode, library[i].name);
		if (library[i].genre == fiction) fprintf(fp, "%10s\n", "fiction");
		else fprintf(fp, "%10s\n", "nonfiction");
	}

	fclose(fp);

}


