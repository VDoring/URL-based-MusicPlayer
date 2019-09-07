#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int input; //메인화면에서 메뉴 선택시 사용

gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void Intro() { //실행시 화면 구성
	system("mode con cols=40 lines=13");
	int x = 0, y = 0;
	gotoxy(x + 8, y + 1); printf("[ [ VDoring's Player ] ]");
	gotoxy(x + 15, y + 4); printf("[1] Play");
	gotoxy(x + 15, y + 6); printf("[2] Exit");
	gotoxy(x, y + 8); printf("________________________________________");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x +19, y + 10); scanf("%d", &input);
}