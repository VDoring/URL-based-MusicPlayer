#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ���� ����������

int *line_num; // .txt���� ���� �� �ӽ�����
int line_number; // .txt���� ���� �� ����
void Musiclist_line_Read_3() { // .txt���� ���� �� ī����

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


int random_number; //rand�Լ��� ���� ��� ��
int linkRandom_line_number = 0; // .txt���� ���� �� ����
int Random; //random_number�� ���� �޴� ����(�������� ����)
void Random_Select() { //���� ������� ����� ��ũ�� ���ϴ� �Լ�
	linkRandom_line_number = line_number; //line_number�� main.c������ ����ϹǷ� ȥ�� �������ʰ� �Ȱ��� ���� ���� ������ ���μ���
	linkRandom_line_number += 2;
	Random = 0;
	
	while (Random <= 0) { // Random�� 1 �̻��� �ɶ����� �ݺ�
		srand((unsigned)time(NULL)); //���α׷� ����ø��� �ٸ� �������ڰ� ������ �ȴ�
		random_number = rand();
		Random = (int)random_number % linkRandom_line_number; // Random�� ������ ���� ��+2�� ��������
	}
}


char fileread[4096]; // .txt���� �����б�� ���ڿ�
const char CMD_Static_command_3[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� ��ɾ�
char cache_Music1_3[100];// ��ɾ� ����
char cache_Music2_3[8092];// fileread ���ڿ��� ���� ����
char *ptr_linkcut_result; // ���� ��ũ�� ����
char *contact_3 = NULL; //cache_Music2_2 ���ڿ����� �ڸ� ������ ���ڿ��� ����
char Musiclink_3[8192] = { 0, }; // ���� ������� ��ɾ�
void Musiclist_Play() {
	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	for (int i = 0; i < Random; i++) {
		fgets(fileread, sizeof(fileread), fp);
	}
	
	//���߿� �� ���� ó���ڵ� �����

	sprintf_s(cache_Music1_3, sizeof(cache_Music1_3), "%s", CMD_Static_command_3);
	sprintf_s(cache_Music2_3, sizeof(cache_Music2_3), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_3, " ", &contact_3); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink_3, sizeof(Musiclink_3), "%s %s", cache_Music1_3, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink_3);

	fclose(fp);

}