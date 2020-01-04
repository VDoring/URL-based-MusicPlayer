#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

#define MAX_COUNT line_number + 1
#define MIXING_COUNT line_number + 30

FILE *fp; // .txt���� ���� ����������

/*
int Random;
int Play_Random_count = 0;
int save_random_number[10000] = { 0, };
void Save_RandomNum() { //���� ���� ���� �ѹ��� �����ϴ� �Լ�. (�ߺ����� ������ ����Ǵ°� �����ϱ� ����)
	save_random_number[Play_Random_count] = Random;
	Play_Random_count++;
}*/

/*int line_number;
int no_overlap_line_number = 0;
void random_num_array_save() { //�ߺ����� �������ڸ� line_number�� ����ŭ ����
	extern void Random_Select();

	no_overlap_line_number = line_number; //line_number�� �Ȱ��� ���� for���� ����� ���ο� ���� ����
	no_overlap_line_number++;

	Save_RandomNum();
	for (int i = 1; i < no_overlap_line_number; i++) {
		Random_Select();
		Save_RandomNum();
		for (int j = 0; j < i; j++) {
			if (save_random_number[i] == save_random_number[j]) {
				i--;
				Play_Random_count--;
				break;
			}
		}
	}
}*/


//999�� �Ǿ��ִ°��� define�� MAX_COUNT�� ������
int line_number;
int musiclist_arr[10000] = { 0, };
void No_overlap_random() { //������� ������ �迭�� ���� �� �迭�� ����
	int i, swap_temp, x, y, z;

	srand((unsigned int)time(NULL));

	for (i = 0; i < MAX_COUNT; i++) musiclist_arr[i] = i + 1;

	for (i = 0; i < MIXING_COUNT; i++) {
		x = rand() % MAX_COUNT;
		y = rand() % MAX_COUNT;
		if (x != y) {
			swap_temp = musiclist_arr[x];
			musiclist_arr[x] = musiclist_arr[y];
			musiclist_arr[y] = swap_temp;
		}
	}
	z = rand() % MAX_COUNT;
	swap_temp = musiclist_arr[0];
	musiclist_arr[0] = musiclist_arr[z];
	musiclist_arr[z] = swap_temp;
}



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
	

	for (int j = 0; j < musiclist_arr[arraynum_read]; j++) {
		fgets(fileread, sizeof(fileread), fp);
	}
	arraynum_read++;

	
	/*���� �����ϰ��
	while (1) {
		if (fileread[0] == '\n') {
			//���� ������� �迭�� -1�� ǥ��. -1���� �ƴ����� ���� �����÷��� ���ΰ� �޶���

			save_random_number_arraynum_read--; //�� 57. ���� �б⸦ ���� �̸� 1�� �������Ƿ�, ������� üũ�ؾ��ϴ� Ư���� ����� ���̳ʽ��� �ؾ��Ѵ�. ���� �迭 �� ���� ���̳ʽ��� �ش� �迭 ���� �ѹ��� �а� �Ѵ�
			txt_empty_lines_number_save[txt_empty_lines_number_save_loop_number] = save_random_number[save_random_number_arraynum_read]; //�� ������ �� ��ȣ�� �����ϴ� �迭 = (�ߺ��ȵǴ�)�����ѹ��� �����ϴ� �迭 (������´� ������� �ִ� �� ��ȣ�� ����� ����).
			Random_Select();
			for (int j = 0; j < save_random_number[save_random_number_arraynum_read]; j++) {
				fgets(fileread, sizeof(fileread), fp);
			}
			
			//Random_Select();
			//Save_RandomNum();
			

			if (save_random_number[save_random_number_arraynum_read] == txt_empty_lines_number_save[txt_empty_lines_number_save_loop_number]) {
				
			}
		}
	}*/

	sprintf_s(cache_Music1_4, sizeof(cache_Music1_4), "%s", CMD_Static_command_4);
	sprintf_s(cache_Music2_4, sizeof(cache_Music2_4), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_4, " ", &contact_4); // ���� ���� ������ ���� �������� ������ ptr_linkcut_result�� ����

	sprintf_s(Musiclink_4, sizeof(Musiclink_4), "%s %s", cache_Music1_4, ptr_linkcut_result); // ���� ������� ��ɾ�

	system(Musiclink_4);

	fclose(fp);
}


void File_close4() { // .txt ���� ����
	arraynum_read = 0;

	for (int i = 0; i < 10000; i++) {
		musiclist_arr[i] = 0;
	}

	fclose(fp);
}