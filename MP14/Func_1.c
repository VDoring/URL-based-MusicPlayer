#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ���� ����������

int *line_num; // .txt���� ���� �� �ӽ�����
int line_number; // .txt���� ���� �� ����
void Musiclist_line_Read() { // .txt���� ���� �� ī����
	fp = fopen("Mlist.txt", "rt");
	int line_count = 0;
	char tmp;

	while (fscanf(fp, "%c", &tmp) != EOF) { // .txt���Ͽ� ����� ���� �ϳ��ϳ� �˻��� EOF���� Ȯ��
		if (tmp == '\n')
			line_count++; // ���� �� �� ���� ����
	}
	line_num = &line_count;
	line_number = *line_num; // .txt���� ���� �� ���� ����

	fclose(fp);

}


char fileread[4096]; // .txt���� �����б�� ���ڿ�
char cache_Music1[100] = { 0, };// ��ɾ� ����
char cache_Music2[8092] = { 0, };// fileread ���ڿ��� ���� ����
const char CMD_Static_command[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� ��ɾ�
char Musiclink[8192] = { 0, }; // ���� ������� ��ɾ�
char *ptr_linkcut_result; // ���� ��ũ�� ����
void  Musiclist_FirstPlay() { // ���� ���� ���

	fp = fopen("Mlist.txt", "rt");
	fgets(fileread, sizeof(fileread), fp); // .txt���� ������ �о� fileread�� ����

	sprintf(cache_Music1, "%s", CMD_Static_command); // CMD_Static_command = cache_Music1 , ��ɾ� ����
	sprintf(cache_Music2, "%s", fileread); // fileread = cache_Music2 , ���� ��ũ ����

	ptr_linkcut_result = strtok(cache_Music2, " "); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink);

}


void Musiclist_ContinuePlay() { // (���� ����)���� ���

	fgets(fileread, sizeof(fileread), fp);

	while (1) {
		if (fileread[0] == '\n') {
			fgets(fileread, sizeof(fileread), fp);
		}
		else break;
	}

	/*
	while (1) {
		if (fileread[0] == '\n') {
			fgets(fileread, sizeof(fileread), fp);
		}
	}
	*/

	sprintf(cache_Music1, "%s", CMD_Static_command);
	sprintf(cache_Music2, "%s", fileread);

	ptr_linkcut_result = strtok(cache_Music2, " ");

	sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut_result);

	system(Musiclink);

	Sleep(100); //���� ������ ���� �ణ�� ��

}

void File_close() { // .txt ���� ����
	fclose(fp);
}