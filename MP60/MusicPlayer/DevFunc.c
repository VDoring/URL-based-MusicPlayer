#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ����

int *line_num; // .txt���� ���� �� (�ӽ�)����
int line_number; // .txt���� ���� �� ����
void dev_musiclist_line_read() { //txt���� ���� �� ī��Ʈ
	int line_count = 0;
	char tmp;

	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	while (fscanf_s(fp, "%c", &tmp, sizeof(tmp)) != EOF) { // .txt���Ͽ� ����� ���� �ϳ��ϳ� �˻��� EOF���� Ȯ��
		if (tmp == '\n')
			line_count++; //���� �� �� ���� ����
	}
	line_num = &line_count; // ���� �� �ӽ� ����
	line_number = *line_num; // ���� �� ���� ����

	fclose(fp);
}

char fileread[4096]; // .txt���� ���� �б��
int dev_important_music_search(char link[]) { // -- Ȯ��
	/*
	int array_length = 0; //��ũ�� ����� ���� ���� ���� ���Ѵ�
	
	while (link[array_length] == '\0')
		array_length++;

	//!���⿡ ���� ������ ����
	if ((link[array_length - 1] == '-') && (link[array_length] == '-')) return 1; //���� -- �ϰ��
	else return -9; // --�� �ƴҰ��
	*/

	char special_text[1000] = { 0, };

	char *ptr = strtok(fileread, " ");  // ���� " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ

	while (1)
	{
		if (ptr == NULL) break; //���� NULL�̶�� ����

		//printf("%s\n", ptr); //<�׽�Ʈ�ڵ�> ����Ȯ��
		strcpy(special_text, ptr); //--���� Ȯ������ special�� ���ڿ��� �����Ѵ�

		ptr = strtok(NULL, " "); // ���� ���ڿ��� �߶� �����͸� ��ȯ
	}

	//printf("%s", special); //<�׽�Ʈ�ڵ�> --���� Ȯ�ο�

	/*
	if (special_text == "--\n") return 1; //--�ϋ�
	else return -9; //-- �ƴҋ�
	*/

	if ((strcmp(special_text, "--") == 0) || (strcmp(special_text, "--\n") == 0)) return 1; //--�ϋ�
	else return -9; //-- �ƴҋ�

}

int music_number[10000] = { 0, }; //�÷��̰����� ��ũ�� �� �ѹ��� ����
void dev_music_search() { // ��ü ��ũ�� Ž���� --�� ���� ��ũ�� ã��
	int important_music_number = 0; // --ǥ�õ� ��ũ�������� ���� ���θ� ����

	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	line_number++;
	for (int i = 0; i < line_number; i++) {
		music_number[i] = i + 1; // 1 ~ (�� ��) ��ŭ �迭�� ���� ����
	}

	for (int i = 0; i < line_number; i++) {
		fgets(fileread, sizeof(fileread), fp);

		important_music_number = dev_important_music_search(music_number); // -- Ȯ���� ���� important_music_number

		//if (fileread[0] == '\n') music_number[i] = -2; // ������ϰ�� music_number �迭�� -2 ǥ��
		if (important_music_number == -9 || fileread[0] == '\n') music_number[i] = -1; // --�� �ƴҰ�쳪 �����ϰ�� music_number �迭�� -1 ǥ��
		else if (important_music_number == 1) music_number[i] = 1; // --�ϰ�� music_number �迭�� 1 ǥ��
	}

	//important_music_number = 0;
	rewind(fp);
	fclose(fp);
}

int first_music_play_count; //���°���κ��� ù���� �����ϴ��� ����.(i���� ����)
char cache_Musiclink[8092] = { 0, }; //���Ǹ�ũ ����
char *ptr_linkcut_result; // ������ ���� �տ��ִ� ��ũ ����(strtok�Լ��� ���� ����)
const char CMD_Static_command2[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� CMD ���� ��ɾ�
char *contact2 = NULL; // cache_Music2 ���ڿ����� �ڸ� ������ ���ڿ��� ����
char Musiclink5[8192] = { 0, }; // ���� ������� ���ڿ� ����(�������� : CMD��ɾ� + ��ũ)
void dev_music_play() { //���� �÷���
	int i;

	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	for (i = 0; i < line_number; i++) {
		if (music_number[i] == 1) {
			fgets(fileread, sizeof(fileread), fp);
			first_music_play_count = i;
			break;
		}
		fgets(fileread, sizeof(fileread), fp);
	}

	sprintf_s(cache_Musiclink, sizeof(cache_Musiclink), "%s", fileread); // ���� ��ũ ����

	ptr_linkcut_result = strtok_s(cache_Musiclink, " ", &contact2); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink5, sizeof(Musiclink5), "%s %s", CMD_Static_command2, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink5); //���� ���


	//rewind(fp);
	//fclose(fp);
}

char temp1_fileread_save[4096];
char temp2_fileread_save[4096];
void dev_continue_music_play() { //(���� ����)���� �÷���
	int i = first_music_play_count + 1;

	for (i; i < line_number; i++) {
		if (music_number[i] == 1) {
			fgets(fileread, sizeof(fileread), fp);
			break;
		}
		fgets(fileread, sizeof(fileread), fp);
	}

	/* ���� ���� music_number���� 0�ϰ�� �ߴ��ϴ� �ڵ� �߰�*/
	/*
	0. ����, temp2�� ������ִ°� �ִ��� Ȯ���Ѵ�. ������ temp1�� ����, ������ temp2�� ����
	1. fileread�� ����� ���ڿ��� ���� temp2�� �����Ѵ�
	2. ��ũ �۵����� ���� fileread���� temp1�� �����Ѵ�
	3. temp2�� ���� �������� Ȯ���Ѵ�. temp2 ���� ������ temp1�� temp2�̶� ���ڿ��� �Ȱ����� �˻��Ѵ�. temp2 ���� ������ ������.
	4. temp1�� temp2�� ���� ������ dev_continue_music_play()�Լ��� �����ϰ� main.c������ ���α׷��� �����ϵ��� �Ѵ�.
	*/

	//strcpy(temp1_fileread_save, fileread);


	sprintf_s(cache_Musiclink, sizeof(cache_Musiclink), "%s", fileread); // ���� ��ũ ����

	ptr_linkcut_result = strtok_s(cache_Musiclink, " ", &contact2); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink5, sizeof(Musiclink5), "%s %s", CMD_Static_command2, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink5); //���� ���
}

void dev_file_close() {
	rewind(fp);
	fclose(fp);
	for (int i = 0; i < 10000; i++) music_number[i] = 0;
}