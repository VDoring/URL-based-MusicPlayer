#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

int main_input; // ����ȭ�� �Է�
int play_input; // �� ������ �Է�
int play_continue_input; // ��� ���� ��������� ���� �Ϳ� ���� �� �Է�
char WindowSize[40] = { "mode con cols=40 lines=13" }; //â ũ�� ���� ���ɾ�

gotoxy(int x, int y) { // ���� ��ġ ���� �Լ�
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void mainGUI() { // ���� ȭ��
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 8, y + 1); printf("[ [ VDoring's Player ] ]");
	gotoxy(x + 15, y + 4); printf("[1] Play");
	gotoxy(x + 15, y + 6); printf("[2] Exit");
	gotoxy(x, y + 8); printf("________________________________________");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x + 19, y + 10); scanf_s("%d", &main_input);
}

void playmodeGUI() { // ��� ��� ����
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 11, y + 1); printf("[ [ Play Mode ] ]");
	gotoxy(x, y + 3); printf("1. from top to bottom");
	gotoxy(x, y + 5); printf("2. from bottom to top");
	gotoxy(x, y + 7); printf("3. random");
	gotoxy(x, y + 9); printf("________________________________________");
	gotoxy(x + 10, y + 11); printf("Input : ");
	gotoxy(x + 19, y + 11); scanf_s("%d", &play_input);
}

void Question_Continue() { //���� �� ����Ҳ��� ����
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 10, y + 4); printf("Nwxt Music Continue?");
	gotoxy(x + 11, y + 6); printf("[1] Yes     [2] No");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x + 19, y + 10); scanf_s("%d", &play_continue_input);
}