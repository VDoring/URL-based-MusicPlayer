#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

#define MAX_COUNT line_number + 1
#define MIXING_COUNT line_number + 31

FILE *fp; // .txt���� ���� ����������


int line_number;
int musiclist_arr[10000] = { 0, };
void No_overlap_random() { //������� ������ �迭�� ���� �� �迭�� ����
	int i, swap_temp, x, y, z1, z2;

	srand((unsigned int)time(NULL));

	for (i = 0; i < MAX_COUNT; i++) musiclist_arr[i] = i + 1; //1 ~ ���� ����ŭ �迭�� �� ����

	for (i = 0; i < MIXING_COUNT; i++) { //�迭�� ������ ���� �����Ѵ�.
		x = rand() % MAX_COUNT; //������ x
		y = rand() % MAX_COUNT; //������ y
		if (x != y) {
			swap_temp = musiclist_arr[x];
			musiclist_arr[x] = musiclist_arr[y];
			musiclist_arr[y] = swap_temp;
		}
	}
	//(���� �ڵ常���� musiclist_arr[0]�迭�� ���� ������ �ʴ� ������ �־ ���� �ڵ带 ���´�.
	z1 = rand() % MAX_COUNT; //������ z1
	z2 = rand() % MAX_COUNT; //������ z2
	swap_temp = musiclist_arr[0];
	musiclist_arr[0] = musiclist_arr[z1];
	musiclist_arr[z1] = swap_temp;

	//(�ٷ� ���� �ڵ常 �����ϸ� txt���� ù ������ ��ũ�� 
	swap_temp = musiclist_arr[z1];
	musiclist_arr[z1] = musiclist_arr[z2];
	musiclist_arr[z2] = swap_temp;
}

/*
[���� ����� ���� ����]

���� �� �������� üũ
������ϰ�� �ش� ������� musiclist_arr ���� ���� 0���� ����

���� musiclist_arr�� ���ڸ� ������ 0�̶�� �׳� �����ɷ� ����ǰ� �ϰ�, line_number���� �ϳ� ���̳ʽ���
*/


int empty_line_check_2 = 0; //����� üũ�� �ߴ��� Ȯ���ϴ� ����. 0�� 1�� ����
int arraynum_read = 0; //save_random_number �迭�� ���� �б����� ���ڸ� ����
char fileread[4096]; // .txt���� �����б�� ���ڿ�
int txt_empty_lines_number_save[10000] = { 0, }; //������� �迭 �� ��ȣ�� ����
int txt_empty_lines_number_save_loop_number = 0; //txt_empty_lines_number_save �迭 ���� ũ��
const char CMD_Static_command_4[100] = { "start chrome --incognito" }; // ũ�� ��ũ����� ���� ��ɾ�
char cache_Music1_4[100];
char cache_Music2_4[8092];
char *ptr_linkcut_result;
char *contact_4 = NULL; //cache_Music2_2 ���ڿ����� �ڸ� ������ ���ڿ��� ����
char Musiclink_4[8192] = { 0, }; // ���� ������� ��ɾ�
void No_overlap_Musiclist_play() { //(�����ߺ���� ����) �����÷���
	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);
	
	//�迭�� �ִ� ��ȣ�� ���� üũ. ������� �迭������ 0���� ����� �̸� line_number���� ������ �Ѵ�.
	if (empty_line_check_2 == 0) { //����� üũ�� ó���̸�
		empty_line_check_2++;
		while (1) {
			for (int j = 0; j < musiclist_arr[arraynum_read]; j++) {
				fgets(fileread, sizeof(fileread), fp);
			}

			if (fileread[0] == '\n') {
				musiclist_arr[arraynum_read] = -1;
				line_number--;
			}
			else if (musiclist_arr[arraynum_read] == 0) {
				arraynum_read = 0;
				break;
			}
			arraynum_read++;
			fileread[0] = 'x'; //���� musiclist_arr�� ������ �迭ĭ�� \n�ϰ�� 77�� ���� ����Ǿ� ������ �ʴ� ������ ����� ������ x��� ������ ���� �ִ´�.
			rewind(fp);
		}
	}

	/*(����)���� ���డ���� ��ũ�� �������� ���� ����Ǽ� ���̻� �����Ұ��� ��� �� ���ο� ���� üũ�� �Ѵ�. �̴� �������� �߱�
	while (1) {
		for (int j = 0; j < musiclist_arr[arraynum_read]; j++) {
			fgets(fileread, sizeof(fileread), fp);
		}

		if (fileread[0] == '\n') {
			if (musiclist_arr[arraynum_read] == '0') return;
			arraynum_read++;
			line_number--;
			rewind(fp);
		}
		else if (fileread[0] != '\n') break;
	}*/

	while (1) {
		if (musiclist_arr[arraynum_read] == -1) {
			arraynum_read++;
			continue;
		}

		for (int j = 0; j < musiclist_arr[arraynum_read]; j++) {
			fgets(fileread, sizeof(fileread), fp);
		}

		/*
		if (fileread[0] == -1) {
			arraynum_read++;
			rewind(fp);
			continue;
		}*/

		//if (fileread[0] != '\n')
		break;
	}

	sprintf_s(cache_Music1_4, sizeof(cache_Music1_4), "%s", CMD_Static_command_4);
	sprintf_s(cache_Music2_4, sizeof(cache_Music2_4), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_4, " ", &contact_4); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink_4, sizeof(Musiclink_4), "%s %s", cache_Music1_4, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink_4);

	arraynum_read++;

	fclose(fp);
}


void File_close4() { // .txt ���� ����
	arraynum_read = 0;
	empty_line_check_2 = 0;

	for (int i = 0; i < 10000; i++) {
		musiclist_arr[i] = 0;
	}

	fclose(fp);
}