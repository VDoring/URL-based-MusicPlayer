#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ���� ����������

int Random;
int Play_Random_count = 0;
int save_random_number[10000] = { 0, };
void Save_RandomNum() { //���� ���� ���� �ѹ��� �����ϴ� �Լ�. �ߺ����� ������ ����Ǵ°� �����ϱ� ����
	Play_Random_count++;

	for (int i = 0; i < Play_Random_count; i++) {
		save_random_number[i] = Random;
	}
}


char fileread[4096]; // .txt���� �����б�� ���ڿ�
const char CMD_Static_command_4[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� ��ɾ�
char cache_Music1_4[100];
char cache_Music2_4[8092];
char *ptr_linkcut_result;
char *contact_4 = NULL; //cache_Music2_2 ���ڿ����� �ڸ� ������ ���ڿ��� ����
char Musiclink_4[8192] = { 0, }; // ���� ������� ��ɾ�
void No_overlap_Musiclist_play() { //������忡�� �ߺ���������� �ȵǴ� �����÷���
	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);
	
	for (int i = 0; i < Random; i++) {
		fgets(fileread, sizeof(fileread), fp);
	}

	sprintf_s(cache_Music1_4, sizeof(cache_Music1_4), "%s", CMD_Static_command_4);
	sprintf_s(cache_Music2_4, sizeof(cache_Music2_4), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_4, " ", &contact_4); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink_4, sizeof(Musiclink_4), "%s %s", cache_Music1_4, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink_4);

	fclose(fp);
}