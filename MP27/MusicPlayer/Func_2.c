#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ���� ����������

int *line_num; // .txt���� ���� �� �ӽ�����
int line_number; // .txt���� ���� �� ����
void Musiclist_line_Read_2() { // .txt���� ���� �� ī����

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
const char CMD_Static_command_2[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� ���ɾ�
char cache_Music1_2[100] = { 0, };// ���ɾ� ����
char cache_Music2_2[8092] = { 0, };// fileread ���ڿ��� ���� ����
char Musiclink_2[8192] = { 0, }; // ���� ������� ���ɾ�
char *ptr_linkcut_result; // ���� ��ũ�� ����
char *contact_2 = NULL; //cache_Music2_2 ���ڿ����� �ڸ� ������ ���ڿ��� ����
void Musiclist_FirstPlay_2() {

	fopen_s(&fp, "Mlist.txt", "rt");
	
	for (int i = 0; i < line_number; i++) { //���� ���ִ°� �����ϰ� ��ũ����ϴ� ����
		if(i == 0) fgets(fileread, sizeof(fileread), fp); //ó�� �����Ҷ��� ������ ���� �а� ��
		if (fileread[0] == '\n') { //���� .txt�����߰��� ���� ����� �������
			fgets(fileread, sizeof(fileread), fp); //���� ��ũ�� �Ѿ
		} else fgets(fileread, sizeof(fileread), fp);
	}


	sprintf_s(cache_Music1_2, sizeof(cache_Music1_2), "%s", CMD_Static_command_2);
	sprintf_s(cache_Music2_2, sizeof(cache_Music2_2), "%s", fileread); 

	ptr_linkcut_result = strtok_s(cache_Music2_2, " ", &contact_2); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink_2, sizeof(Musiclink_2), "%s %s", cache_Music1_2, ptr_linkcut_result); // ���� ������� ���ɾ�

	system(Musiclink_2);

	fclose(fp);
}

int playcount = 0; //��� ����ߴ����� ���� ����
int linkcheck_line_number = 0;  //���� line_number�� ���� �����ϰ� �Ǹ� �÷��̿� ������ �����Ƿ�, line_number�� ������ ���� ���� (Musiclist_ContinuePlay_2�Լ� �������� ����ϴ�)����
void Musiclist_ContinuePlay_2() {

	fopen_s(&fp, "Mlist.txt", "rt");

	linkcheck_line_number = line_number; //main.c������ line_number�� ����ϹǷ�, ���� ���� ������ ��ü���� ����

	for (int j = 0; j < linkcheck_line_number - playcount; j++) { // (.txt���� ��ü �� ���� - ����� �ܼ�)��ŭ �ݺ�
		fgets(fileread, sizeof(fileread), fp); // ��������� ������ ��ũ���� ��ĭ �� ��ũ�� ����ǰ� ��

		while(1) {
			if (fileread[0] != '\n') break;

			if (fileread[0] == '\n') {
				fgets(fileread, sizeof(fileread), fp);
				line_number--;
				linkcheck_line_number--;
				if (fileread[0] == '\n') break;
				continue;
			}
		}
	}
	playcount++;

	sprintf_s(cache_Music1_2, sizeof(cache_Music1_2), "%s", CMD_Static_command_2);
	sprintf_s(cache_Music2_2, sizeof(cache_Music2_2), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_2, " ", &contact_2); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink_2, sizeof(Musiclink_2), "%s %s", cache_Music1_2, ptr_linkcut_result); // ���� ������� ���ɾ�

	system(Musiclink_2);

}


/* �߰��� ����
2����� �ѹ� ����� �ٽ� 2����� ���� �۵����� �߻�

*/