#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

int main_input; // ����ȭ�� �Է�
int play_input; // �� ������ �Է�
int play_continue_input; // ��� ���� ��������� ���� �Ϳ� ���� �� �Է�
int play_random_mode_input; //������� ���� ���ÿ� ���� �� �Է�
int play_no_overlap_continue_input; //(�ߺ�������� ����)��� ���� ��������� ���� �Ϳ� ���� �� �Է�
char WindowSize[40] = { "mode con cols=40 lines=13" }; //â ũ�� ���� ��ɾ�

gotoxy(int x, int y) { // ���� ��ġ ���� �Լ�
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void mainGUI() { // ���� ȭ�� CUI
	system(WindowSize); int x = 0, y = 0;
	system("title Music Player");

	gotoxy(x + 8, y + 1); printf("[ [ VDoring's Player ] ]");
	gotoxy(x + 15, y + 4); printf("[1] Play");
	gotoxy(x + 15, y + 6); printf("[2] Exit");
	gotoxy(x, y + 8); printf("________________________________________");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x + 19, y + 10); main_input = getch();
}

void playmodeGUI() { // ��� ��� ���� CUI
	system(WindowSize); int x = 0, y = 0;
	system("title Music Player");

	gotoxy(x + 11, y + 1); printf("[ [ Play Mode ] ]");
	gotoxy(x, y + 3); printf("1. from Top to Bottom");
	gotoxy(x, y + 5); printf("2. from Bottom to Top");
	gotoxy(x, y + 7); printf("3. Random");
	gotoxy(x, y + 9); printf("________________________________________");
	gotoxy(x + 10, y + 11); printf("Input : ");
	gotoxy(x + 19, y + 11); play_input = getch();
}

void Question_Continue() { //���� �� ����Ҳ��� ���� CUI
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 10, y + 4); printf("Next Music Continue?");
	gotoxy(x + 11, y + 6); printf("[1] Yes     [2] No");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x + 19, y + 10); scanf_s("%d", &play_continue_input);
}

void Random_mode() { //������� ���� CUI
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 9, y + 2); printf("[ Select Random Mode ]");
	gotoxy(x + 5, y + 5); printf("[1] Overlap     [2] No Overlap");
	gotoxy(x + 10, y + 9); printf("Input : ");
	gotoxy(x + 19, y + 9); play_random_mode_input = getch();
}

void No_overlap_Qusetion_Continue() { //(�ߺ����������� ����)���� �� ����Ҳ��� ���� CUI
	system(WindowSize); int x = 0, y = 0;

	gotoxy(x + 8, y + 4); printf("Random Music Continue?");
	gotoxy(x + 11, y + 6); printf("[1] Yes     [2] No");
	gotoxy(x + 10, y + 10); printf("Input : ");
	gotoxy(x + 19, y + 10); scanf_s("%d", &play_no_overlap_continue_input);
}