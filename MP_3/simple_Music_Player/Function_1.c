#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; //���������� ����

void Musiclist_Read() {

	char fileread[4096]; //������ �б� ���� ������ ĳ��
	const char CMD_Static_command[100] = { "start /max iexplore.exe" }; //cmdâ�� ���������� �Է��� ����

	char cache_Music1[100] = { 0, };//���������� �Է��� �κ��� ����ϴ� �迭
	char cache_Music2[8000] = { 0, };//�����ּ� ������ ����ϴ� �迭
	char Musiclink[8192] = { 0, }; //�������� ������� ��ɾ�

	fp = fopen("Mlist.txt", "rt"); //���� ����
	fgets(fileread, sizeof(fileread), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.

	sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(���������� �Է��� ����)�� �����͸� cache_Music�� ����
	sprintf(cache_Music2, "%s", fileread); //cache_read_1(���� �ּ� ����)�� �����͸� cache_Music2�� ����
	sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2); //cache_Music1�� cache_Music2�� ��ģ �������� ������� ��ɾ�

	system(Musiclink);


	for (int i = 0; i < 2; i++) { //���� i�� ���Ͽ� �ִ� �� ���� ������ �־����
		Sleep(500);
		fgets(fileread, sizeof(fileread), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.

		sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(���������� �Է��� ����)�� �����͸� cache_Music�� ����
		sprintf(cache_Music2, "%s", fileread); //cache_read_1(���� �ּ� ����)�� �����͸� cache_Music2�� ����
		sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2); //cache_Music1�� cache_Music2�� ��ģ �������� ������� ��ɾ�

		system(Musiclink);

		Sleep(500);

	}

}

void File_close() {
	fclose(fp);
}