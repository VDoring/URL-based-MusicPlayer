#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ���� ����������

int *line_num; // .txt���� ���� �� �ӽ�����
int line_number; // .txt���� ���� �� ����
void Musiclist_line_Read_1() { // .txt���� ���� �� ī����

	fopen_s(&fp, "Mlist.txt", "rt");
	int line_count = 0;
	char tmp;

	while (fscanf_s(fp, "%c", &tmp, sizeof(tmp)) != EOF) { // .txt���Ͽ� ����� ���� �ϳ��ϳ� �˻��� EOF���� Ȯ��
		if (tmp == '\n')
			line_count++; // ���� �� �� ���� ����
	}
	line_num = &line_count;
	line_number = *line_num; // .txt���� ���� �� ���� ����

	fclose(fp);

}


char fileread[4096]; // .txt���� �����б�� ���ڿ�
char cache_Music1[100] = { 0, };// ���ɾ� ����
char cache_Music2[8092] = { 0, };// fileread ���ڿ��� ���� ����
char *contact = NULL; //cache_Music2 ���ڿ����� �ڸ� ������ ���ڿ��� ����
const char CMD_Static_command[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� ���ɾ�
char Musiclink[8192] = { 0, }; // ���� ������� ���ɾ�
char *ptr_linkcut_result; // ���� ��ũ�� ����
void  Musiclist_FirstPlay_1() { // ���� ���� ���

	fopen_s(&fp, "Mlist.txt", "rt");
	fgets(fileread, sizeof(fileread), fp); // .txt���� ������ �о� fileread�� ����
	
	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command); // CMD_Static_command = cache_Music1 , ���ɾ� ����
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread); // fileread = cache_Music2 , ���� ��ũ ����

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����
	
	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result); // ���� ������� ���ɾ�

	system(Musiclink);

}


void Musiclist_ContinuePlay_1() { // (���� ����)���� ���
	
	fgets(fileread, sizeof(fileread), fp);

	while (1) {
		if (fileread[0] == '\n') { //���� .txt�����߰��� ���� ����� �������
			fgets(fileread, sizeof(fileread), fp); //���� ��ũ ���
			line_number--; //��ĭ�� �ټ��� ä���� ���̹Ƿ� �ϳ� ���̳ʽ�
		}
		else break;
	}

	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command);
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact);

	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result);

	system(Musiclink);

	Sleep(30); //���� ������ ���� �ణ�� ��

}

void File_close() { // .txt ���� ����
	fclose(fp);
}