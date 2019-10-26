#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

int main_input; // 메인화면 입력
int play_input; // 곡 재생모드 입력
int play_continue_input; // 계속 음악 재생할지를 묻는 것에 대한 값 입력
char WindowSize[40] = { "mode con cols=40 lines=13" }; //창 크기 설정 명령어

gotoxy(int x, int y) { // 글자 위치 조정 함수
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void mainGUI() { // 메인 화면
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 8, y + 1); printf("[ [ VDoring's Player ] ]");
	gotoxy(x + 15, y + 4); printf("[1] Play");
	gotoxy(x + 15, y + 6); printf("[2] Exit");
	gotoxy(x, y + 8); printf("________________________________________");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x + 19, y + 10); scanf_s("%d", &main_input);
}

void playmodeGUI() { // 재생 모드 선택
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 11, y + 1); printf("[ [ Play Mode ] ]");
	gotoxy(x, y + 3); printf("1. from Top to Bottom");
	gotoxy(x, y + 5); printf("2. from Bottom to Top");
	gotoxy(x, y + 7); printf("3. Random");
	gotoxy(x, y + 9); printf("________________________________________");
	gotoxy(x + 10, y + 11); printf("Input : ");
	gotoxy(x + 19, y + 11); scanf_s("%d", &play_input);
}

void Question_Continue() { //다음 곡 재생할껀지 물음
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 10, y + 4); printf("Next Music Continue?");
	gotoxy(x + 11, y + 6); printf("[1] Yes     [2] No");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x + 19, y + 10); scanf_s("%d", &play_continue_input);
}