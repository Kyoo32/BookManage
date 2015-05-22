//
//  main.c
//  bookManagement
//
//  Created by Kate KyuWon on 5/8/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "function_bookManagement.h"
#include "UI_bookmanage.h"
#include "bookDataStruc.h"

int numBook = 0;
Book *library;
int librarySize = 1;

int main(int argc, const char * argv[]) {
    
    
    library = (Book*)malloc( sizeof(Book) * librarySize );
    
	show_logo();

    char command = 0;
    
	while (command !='q'){
	
		system("cls");

		show_command();
		scanf(" %c", &command);
		while (getchar() != '\n');
		userChoose(command); 

    }
    
	system("cls");
	show_theEnd();
    
	free(library);
    
    return 0;

}



