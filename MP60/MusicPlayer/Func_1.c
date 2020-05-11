#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ����


int *line_num; // .txt���� ���� �� (�ӽ�)����
int line_number; // .txt���� ���� �� ����

/* .txt���� ���� �� ī���� */
void Musiclist_line_Read_1() {
	fopen_s(&fp, "Mlist.txt", "rt");
	int line_count = 0;
	char tmp;

	while (fscanf_s(fp, "%c", &tmp, sizeof(tmp)) != EOF) { // .txt���Ͽ� ����� ���� �ϳ��ϳ� �˻��� EOF���� Ȯ��
		if (tmp == '\n')
			line_count++; //���� �� �� ���� ����
							//�� ����� ������:������ ��ũ�� �ִ� ���� ī��Ʈ�� �������� �ʴ´�.
							//���, WindowTitleTotal�Լ������� ������ non_blank_line_number�� ���� 1 �����ְ� �����ߴ�.
							//������ �����ϴ� �κп��� �� �� �۵��ϴ°�?: line_number�� main.c���� ���Ǳ� ���� ���� �ѹ� ����Ǳ� ����.
	}
	line_num = &line_count; // ���� �� �ӽ� ����
	line_number = *line_num; // ���� �� ���� ����

	fclose(fp);
}


char fileread[4096]; // .txt���� ���� �б��
const char WindowTitleCMD[10] = { "title" }; // CMD ���� ��ɾ�
int NowCount = 0; // ���� ������ �ܼ�
int WindowTitleNowcount; // (������Ÿ��Ʋ ��¿�)���� ����� �ܼ� ����
int WindowtitleTotalcount; // (������Ÿ��Ʋ ��¿�)�� ������ ������ .txt������ �� ���� ��

/* .txt���� �� ���μ� ��� */
void WinTitleTotal() { //������� ������ �� ���� ������ ���� �Լ�(������Ÿ��Ʋ ����� ���� �Լ�)
	int non_blank_line_number = line_number; // ����� �ܼ� ������ line_number�� ���� non_blank_line_number�� ����
	non_blank_line_number++; // (�� 1�� ���ߴ��� 22~24���� �ּ��� �����ϼ���)
	int non_blank_for = non_blank_line_number; // for���� ����� ����. �� ���� �ܼ��� ���Ե��ִ� ����

	fopen_s(&fp, "Mlist.txt", "rt");
	for (int n = 0; n < non_blank_for; n++) {  // .txt������ �� ����ŭ �ݺ�
		fgets(fileread, sizeof(fileread), fp);
		if (fileread[0] == '\n') { // ���� �� �����϶�
			non_blank_line_number--; // ���� ���� �ϳ� ����.
		}
	}
	WindowtitleTotalcount = non_blank_line_number; //����� ī������ ������ non_blank_line_number�� ������Ÿ��Ʋ ����� ���� ������ WindowtitleTotalcount�� ����

	rewind(fp); //���� ��ġ �ʱ�ȭ
	fclose(fp);
}


char cache_Music1[100] = { 0, }; // CMD_Static_command(ũ�� ��ũ����� ���� ��ɾ�)�� ���ڿ��� ����
char cache_Music2[8092] = { 0, }; // fileread(.txt���� ���� �б�)�� ���ڿ��� ����
char *contact = NULL; // cache_Music2 ���ڿ����� �ڸ� ������ ���ڿ��� ����
const char CMD_Static_command[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� CMD ���� ��ɾ�
char Musiclink[8192] = { 0, }; // ���� ������� ���ڿ� ����(�������� : CMD��ɾ� + ��ũ)
char *ptr_linkcut_result; // ������ ���� �տ��ִ� ��ũ ����(strtok�Լ��� ���� ����)
char WindowTitle[110] = { 0, }; //���� ������Ÿ��Ʋ ���ڿ� ����

/* ���� ���� ���� */
void  Musiclist_FirstPlay_1() { // ���� ���� ���
	fopen_s(&fp, "Mlist.txt", "rt");

	fgets(fileread, sizeof(fileread), fp); // .txt���� ������ �о� fileread�� ����
	
	/* ù ���� ���� ���� & ������� �� ������ ��ũ �б� */
	while (1) {
		if (fileread[0] == '\n') { // ���� .txt���Ͽ��� ���� ������ �����ϰ��
			fgets(fileread, sizeof(fileread), fp); // �״����� ��ũ ����
			line_number--; // ��ĭ�� �ټ��� ä���� ���̹Ƿ� ��ũī��Ʈ ���̳ʽ� 1
		}
		else break; // ���� ������ �ƴ϶�� �ݺ��� ����
	}

	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command); // CMD ���� ��ɾ� ����
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread); // ���� ��ũ ����

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����
	
	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink); //���� ���

	
	/* WindowTitle ��� */
	NowCount++; //���� �ܼ� +1
	
	WindowTitleNowcount = NowCount; //������ �ܼ��� WindowTitleNowcount(������Ÿ��Ʋ ��¿� ����)�� ����

	sprintf_s(WindowTitle, sizeof(WindowTitle), "%s Playing.. [%d/%d]", WindowTitleCMD, WindowTitleNowcount, WindowtitleTotalcount); // �� ���� ������ ������ ����� WindowTitle�� ����

	system(WindowTitle); //������Ÿ��Ʋ ���
}

/* �ι�° ���ĺ����� ������� */
void Musiclist_ContinuePlay_1() {
	fgets(fileread, sizeof(fileread), fp);

	/* ù ���� ���� ���� & ������� �� ������ ��ũ �б� */
	while (1) {
		if (fileread[0] == '\n') { // ���� .txt���Ͽ��� ���� ������ �����ϰ��
			fgets(fileread, sizeof(fileread), fp); // �״����� ��ũ ����
			line_number--; // ��ĭ�� �ټ��� ä���� ���̹Ƿ� ��ũī��Ʈ ���̳ʽ� 1
		}
		else break; // ���� ������ �ƴ϶�� �ݺ��� ����
	}

	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command); // CMD ���� ��ɾ� ����
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread); // ���� ��ũ ����

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink); //���� ���

	
	// WindowTitle ���
	NowCount++; //���� �ܼ� +1

	WindowTitleNowcount = NowCount; //������ �ܼ��� WindowTitleNowcount(������Ÿ��Ʋ ��¿� ����)�� ����

	sprintf_s(WindowTitle, sizeof(WindowTitle), "%s Playing.. [%d/%d]", WindowTitleCMD, WindowTitleNowcount, WindowtitleTotalcount); // �� ���� ������ ������ ����� WindowTitle�� ����

	system(WindowTitle); //������Ÿ��Ʋ ���
}

/* ���ϴݱ� �� Ư������ �ʱ�ȭ */
void File_close() {
	fclose(fp);
	NowCount = 0;
}