#ifndef __HEAD_H__
#define __HEAD_H__
FILE *fp; //���������� ����
int main_input; //����ȭ�鿡�� �޴� ���ý� ���
int play_input; //�� ������ ���ý� ���

/* GUI */
void Intro(); //����� ȭ�� ����
void playmode(); //� ���� �÷����Ҳ��� ȭ�� ����

/* 1�� ��� */
void Musiclist_line_Read();
void Musiclist_Read();


/* 2�� ��� */
void File_close();

#endif
