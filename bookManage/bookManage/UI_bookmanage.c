

#include "UI_bookmanage.h"


void textColor(int _colorValue)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _colorValue);
}

int gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void show_amend(int y){
	int x = 20;

	textColor(GRAY);
	y += 2;
	gotoxy(x, y);
	printf("┏━━━━<Choose one>━━━━━┓");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┃ c   : Amend book's code      ┃");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┃ n   : Ameand book's name     ┃");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┃ g   : Ameand book's genre    ┃");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┗━━━━━━━━━━━━━━━┛");
	y++;
	gotoxy(x + 10, y);

}

void show_theEnd(void){
	int x = 20, y = 7;


	textColor(GRAY);
	gotoxy(x, y);
	printf("┏━━━━━━━━━━━┓");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┃     햇살이 좋아,     ┃");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┃       ");
	textColor(DARK_GREEN);
	printf("글자");
	textColor(GRAY);
	printf("도         ┃");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┃      노릇노릇        ┃");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┃      잘 읽는다:)     ┃");
	Sleep(10);
	y++;
	gotoxy(x, y);
	printf("┗━━━━━━━━━━━┛");
	y++;
	gotoxy(x, y);
	puts("안녕, 다음에 봐");
	y++;
	gotoxy(x, y);

	getc(stdin); //꼭 나중에 지우기
	return;

}

void show_command(void){


	textColor(GRAY);
	gotoxy(20, 7);
	printf("┏━━━━<Choose one>━━━━━┓");
	Sleep(10);
	gotoxy(20, 8);
	printf("┃ i   : Insert book            ┃");
	Sleep(10);
	gotoxy(20, 9);
	printf("┃ s   : Search book            ┃");
	Sleep(10);
	gotoxy(20, 10);
	printf("┃ p   : Print library          ┃");
	Sleep(10);
	gotoxy(20, 11);
	printf("┃ q   : Quit Kyoo's Book       ┃");
	Sleep(10);
	gotoxy(20, 12);
	printf("┗━━━━━━━━━━━━━━━┛");
	gotoxy(30, 13);

	return;
}

int show_logo()
{
	int i, j;
	int cur_color = 0;
	gotoxy(40, 2);
	printf("Kyoo's");
	Sleep(100);
	gotoxy(20, 3);
	printf("┏━━━━━━━━━━━━━━━━━━━┓");
	Sleep(100);
	gotoxy(20, 4);
	printf("┃★★★      ★★      ★★    ★    ★┃");
	Sleep(100);
	gotoxy(20, 5);
	printf("┃★    ★  ★    ★  ★    ★  ★  ★  ┃");
	Sleep(100);
	gotoxy(20, 6);
	printf("┃★★★    ★    ★  ★    ★  ★★    ┃");
	Sleep(100);
	gotoxy(20, 7);
	printf("┃★    ★  ★    ★  ★    ★  ★  ★  ┃");
	Sleep(100);
	gotoxy(20, 8);
	printf("┃★★★      ★★      ★★    ★    ★┃");
	Sleep(100);
	gotoxy(20, 9);
	printf("┗━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(20, 10);
	puts("Ver 0.1");


	gotoxy(28, 20);
	printf("Please Press Any Key~!");

	for (i = 0; i >= 0; i++)
	{
		if (i % 8 == 0)
		{
			gotoxy(22, 19);
			for (j = 0; j<37; j++)
			{
				textColor((cur_color + j) % 16 * 16);
				printf(" ");

			}
			if (cur_color >0)
				cur_color--;
			else
				cur_color = 15;

		}
		if (kbhit())
			break;
		Sleep(30);
	}

	getche();
	textColor(GRAY);
	system("cls");

	return 0;
}
