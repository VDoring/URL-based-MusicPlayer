#ifndef __HEAD_H__
#define __HEAD_H__
FILE *fp; //���������� ����
int main_input; //����ȭ�鿡�� �޴� ���ý� ���
int play_input; //�� ������ ���ý� ���

/* GUI */
void mainTheme(); //����� ȭ�� ����
void playmode(); //� ���� �÷����Ҳ��� ȭ�� ����

/* 1�� ��� */
void Musiclist_line_Read(); //���Ͽ� ���� ������ �� ���� üũ
void Musiclist_FirstPlay(); //ù��° �÷���
int play_continue_input; //��� ������� ����(����)�� ��� ����


/* 2�� ��� */
void File_close();

#endif
