#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt���� ���� ����������

int *line_num; // .txt���� ���� �� �ӽ�����
int line_number; // .txt���� ���� �� ����
void Musiclist_line_Read() { // .txt���� ���� �� ī����

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

/* �������� ��ȹ
fseek�� ����Ͽ� ������ �� ������ �̵���Ų��.
(�ǳ����� �̵��Ѵٴ°� ���ڿ����� ������, ���ο����� �������� Ȯ�� �ʿ�)
(���� �ǳ��� ���ڿ����� ���̸� (�� ������ ���� ù ���ڷ� �̵���)�� ���� ���� ���θ� Ȯ���Ͽ� ��ũ�� ���� �� �ֵ��� �������Ѵ�)

�ѹ� ���� �ڷ� �ݺ����� fseek�� ����� ���� ������ ��ĭ�� ���� �ö󰡵��� �Ѵ�.

*/