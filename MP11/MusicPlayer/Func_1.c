#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; //���������� ����

int *line_num;
int line_number;
void Musiclist_line_Read() {

	fp = fopen("Mlist.txt", "rt"); //���� ����
	int line_count = 1;
	char tmp;
	while (fscanf(fp, "%c", &tmp) != EOF) {
		if (tmp == '\n')
			line_count++;
	}
	line_num = &line_count; //line_count(��ũ ��) �� �����.
							//������ �ٸ� �Լ��� �Ѿ�� line_num�� ���� �̻��ϰ� ���ϴ� ������ �߻�
	line_number = *line_num;
	fclose(fp);
	// https://security-nanglam.tistory.com/m/166?category=814722
	// Studylog������Ʈ�� txt_line_count
	//�׽�Ʈ�� testerz������Ʈ�� fgets_interesting

}


char fileread[4096]; //������ �б� ���� ������ ĳ��
char cache_Music1[100] = { 0, };//���������� �Է��� �κ��� ����ϴ� �迭
char cache_Music2[8092] = { 0, };//�����ּ� ������ ����ϴ� �迭
//const char CMD_Static_command[100] = { "start /max iexplore.exe" }; //���� ���ͳ� �ͽ��÷η��� ����
const char CMD_Static_command[100] = { "start chrome --incognito" }; //cmdâ�� ���������� �Է��� ����, ũ�� ��ũ������ ����
char Musiclink[8192] = { 0, }; //�������� ������� ��ɾ�
char *ptr_linkcut;

void  Musiclist_FirstPlay() {

	fp = fopen("Mlist.txt", "rt"); //���� ����
	fgets(fileread, sizeof(fileread), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.

	sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(���������� �Է��� ����)�� �����͸� cache_Music�� ����
	sprintf(cache_Music2, "%s", fileread); //cache_read_1(���� �ּ� ����)�� �����͸� cache_Music2�� ����

	ptr_linkcut = strtok(cache_Music2, " ");

	sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut); //cache_Music1�� cache_Music2�� ��ģ �������� ������� ��ɾ�

	system(Musiclink);


	// memcpy(liner, *line_num, sizeof(line_num));
	// line_num�� liner�� ������ ���� �ؿ� for�� �������ǿ� ������ �ȵǳ�? �� �۵��ȵ���?

	/*
	for (int i = 0; i < line_number - 1; i++) { //���� i�� ���Ͽ� �ִ� �� ���� ������ �־����
		Sleep(300);
		fgets(fileread, sizeof(fileread), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.

		sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(���������� �Է��� ����)�� �����͸� cache_Music�� ����
		sprintf(cache_Music2, "%s", fileread); //cache_read_1(���� �ּ� ����)�� �����͸� cache_Music2�� ����
		
		ptr_linkcut = strtok(cache_Music2, " ");

		sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut); //cache_Music1�� cache_Music2�� ��ģ �������� ������� ��ɾ�

		system(Musiclink); // ���⼭�� Musiclink�� ��ũ�� https�� �ƴ� )ttps�� ����Ǿ� �۵��Ұ�

		Sleep(300);

	}
	*/

}


void Musiclist_ContinuePlay() {
	
	for (int i = 0; i < line_number - 1; i++) { //���� i�� ���Ͽ� �ִ� �� ���� ������ �־����
		Sleep(300);
		fgets(fileread, sizeof(fileread), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.

		sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(���������� �Է��� ����)�� �����͸� cache_Music�� ����
		sprintf(cache_Music2, "%s", fileread); //cache_read_1(���� �ּ� ����)�� �����͸� cache_Music2�� ����

		ptr_linkcut = strtok(cache_Music2, " ");

		sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut); //cache_Music1�� cache_Music2�� ��ģ �������� ������� ��ɾ�

		system(Musiclink); // ���⼭�� Musiclink�� ��ũ�� https�� �ƴ� )ttps�� ����Ǿ� �۵��Ұ�

		Sleep(300);

	}
	
	// �迭 ������ �����ڷ�
	// https://dojang.io/mod/page/view.php?id=300
}

void File_close() {
	fclose(fp);
}