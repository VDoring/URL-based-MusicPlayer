#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <tchar.h>
#include <string.h>


void File_Musiclist_Read() {

	FILE *fp; //���������� ����
	char cache_read_1[1000] = { 0, }; //������ �б� ���� ������ ĳ��
	char cache_MusicFront[100] = { "start /max iexplore.exe" }; //cmdâ�� ���������� �Է��� ����

	char cache_Music1[1000] = { 0, };//���������� �Է��� �κ��� ����ϴ� �迭
	char cache_Music2[1000] = { 0, };//�����ּ� ������ ����ϴ� �迭
	char Musiclink[1000] = { 0, }; //�������� ������� ��ɾ�


	fp = fopen("Mlist.txt", "rt"); //���� ����
	fgets(cache_read_1, sizeof(cache_read_1), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.
	// puts(cache_read_1); Sleep(3000); //���� ���(�׽�Ʈ �ڵ�)

	sprintf(cache_Music1, "%s", cache_MusicFront); //cache_MusicFront(���������� �Է��� ����)�� �����͸� cache_Music�� ����

	sprintf(cache_Music2, "%s", cache_read_1); //cache_read_1(���� �ּ� ����)�� �����͸� cache_Music2�� ����

	sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2);

	//system("start /max iexplore.exe"); //�׳� cache_read_1���� ������ �Է� �Ұ���. ���� �����̺� ���� �� ����� ã�ƾ� ��
	system(Musiclink);
	
	/* printf("%s", cache_Music); Sleep(500); //sprintf�� �� �����ϴ��� Ȯ��(cache_read_1�� ���ڿ��� cache_Music�� �� ����Ǵ��� Ȯ��) */

	fclose(fp);
}