#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


void File_Musiclist_Read() {

	FILE *fp; //���������� ����
	char cache_read_1[1000] = { 0, }; //������ �б� ���� ������ ĳ��

	fp = fopen("Mlist.txt", "rt"); //���� ����

	fgets(cache_read_1, sizeof(cache_read_1), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.
	puts(cache_read_1); //���� ���

	fclose(fp);
}