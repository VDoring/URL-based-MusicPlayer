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

void Musiclist_FirstPlay_2() {

	fopen_s(&fp, "Mlist.txt", "rt");
	int size;
	fseek(fp, 0, SEEK_END); //���� �����͸� ������ ������ �̵�
	size = ftell(fp); //���� �������� ���� ��ġ�� size�� ����
	printf("%d\n", size); Sleep(50000);
}

void Musiclist_ContinuePlay_2() {
	
}


/* �������� ��ȹ
fseek�� ����Ͽ� ������ �� ������ �̵���Ų��.
(�ǳ����� �̵��Ѵٴ°� ���ڿ����� ���̴�.)
(���� �ǳ��� ���ڿ����� ���̸� (�� ������ ���� ù ���ڷ� �̵���)�� ���� ���� ���θ� Ȯ���Ͽ� ��ũ�� ���� �� �ֵ��� �������Ѵ�)
(�׷��� ���ؼ� �� ���� ���⸦ Ȯ���� ��ũ�� Ȯ���ϰų� �迭�� ��üũ��� ���Ⱓ�� ��Ʈ ���� �̿��� ��ũ�� ���ϴ� ����� �������̶� ����ȴ�)

�ѹ� ���� �ڷ� �ݺ����� fseek�� ����� ���� ������ ��ĭ�� ���� �ö󰡵��� �Ѵ�.

*/