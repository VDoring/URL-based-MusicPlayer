#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

//�������� ����(��������)
FILE *fp; //���������� ����

int *line_num;
int line_number;
// int liner;
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

void Musiclist_processCPUTIME_Read() {
	/* �ϴ� tasklist /V�ϸ� ������ ������ �״�� ������ ���� */
	char ImageName[30];
	char PID[10];
	char Session[10];
	char memUse[30];
	char Status[10];
	char UserName[100];
	char CPUTime[10] = { 0, }; //���������� ����� ����
	char WindowTitle[100];

	//���� CMD���� tasklist /V /FI "IMAGENAME eq chrome.exe"�� ������ �����͸� txt���Ϸ� �����ϰ� �Ѵ�.
	// CMD���� ��µ� ����� ���Ϸ� �����ϴ� ��� : https://www.google.com/search?q=cmd+%EB%82%B4%EC%9A%A9+%EC%A0%80%EC%9E%A5&sa=X&ved=2ahUKEwjzsvPIve7kAhWCGqYKHTXVDOwQ1QIoB3oECAoQCA&biw=1372&bih=818

	// ���� ������ �̰� ����(������ Ȯ���ϱ�) : https://dojang.io/mod/page/view.php?id=608


	/* ���ǰ��� ��� �Ϸ�Ǿ������� ���� ���� �ڵ�
	FILE *fp2 = fopen("CPUTIME.txt", "r");
	fscanf(fp2, "%s %s %s %s %s %s %s %s", ImageName, PID, Session, memUse, Status, UserName, CPUTime, WindowTitle);
	//���� CPUTime�� ���� ���� Musiclist_Read������ ���� �ְ� �ؾ���
	fclose(fp2);
	*/

}

void Musiclist_Read() {

	char fileread[4096]; //������ �б� ���� ������ ĳ��
	//const char CMD_Static_command[100] = { "start /max iexplore.exe" }; //���� ���ͳ� �ͽ��÷η��� ����
	const char CMD_Static_command[100] = { "start chrome --incognito" }; //cmdâ�� ���������� �Է��� ����, ũ�� ��ũ������ ����
	char cache_Music1[100] = { 0, };//���������� �Է��� �κ��� ����ϴ� �迭
	char cache_Music2[8092] = { 0, };//�����ּ� ������ ����ϴ� �迭
	char Musiclink[8192] = { 0, }; //�������� ������� ��ɾ�

	fp = fopen("Mlist.txt", "rt"); //���� ����
	fgets(fileread, sizeof(fileread), fp); //cache_read_1�� ũ�⸸ŭ ������ �д´�.

	sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(���������� �Է��� ����)�� �����͸� cache_Music�� ����
	sprintf(cache_Music2, "%s", fileread); //cache_read_1(���� �ּ� ����)�� �����͸� cache_Music2�� ����
	sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2); //cache_Music1�� cache_Music2�� ��ģ �������� ������� ��ɾ�

	system(Musiclink);


	// memcpy(liner, *line_num, sizeof(line_num));
	// line_num�� liner�� ������ ���� �ؿ� for�� �������ǿ� ������ �ȵǳ�? �� �۵��ȵ���?


	for (int i = 0; i < line_number - 1; i++) { //���� i�� ���Ͽ� �ִ� �� ���� ������ �־����
		//�������� ���� ����
		Sleep(15000);
		/*
		char ChromeEXIT[100] = { "taskkill /F /IM chrome.exe" }; //ũ�� ��ü�� �����ϱ⶧���� �ٸ����� ����ؾ���
		system(ChromeEXIT);
		Sleep(3000);
		*/
		//�������� ���� ��


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