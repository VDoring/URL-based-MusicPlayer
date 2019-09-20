#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int main_input; //메인화면에서 메뉴 선택시 사용
int play_input; //곡 재생모드 선택시 사용

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
	gotoxy(x +19, y + 10); scanf_s("%d", &main_input);
}

void playmode() {
	system("mode con cols=40 lines=13");
	int x = 0, y = 0;
	gotoxy(x + 11, y + 1); printf("[ [ Play Mode ] ]");
	gotoxy(x, y + 3); printf("1. from top to bottom");
	gotoxy(x, y + 5); printf("2. from bottom to top");
	gotoxy(x, y + 7); printf("3. random");
	gotoxy(x, y + 9); printf("________________________________________");
	gotoxy(x + 10, y + 11); printf("Input : ");
	gotoxy(x + 19, y + 11); scanf_s("%d", &play_input);
}