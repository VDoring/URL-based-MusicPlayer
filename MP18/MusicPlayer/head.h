#ifndef __HEAD_H__
#define __HEAD_H__

FILE *fp; // .txt���� ���� ����������
int main_input; // ����ȭ�� �Է�
int play_input; // �� ������ �Է�

/* GUI ���� */
void mainGUI(); // ����ȭ�� GUI
void playmodeGUI(); // ���������� ���� GUI
void Question_Continue(); // ��� ���� �������� �÷������� ���� �Լ�

/* mainȭ�� 1�� ��� */
int line_number; // .txt���� ���� �� ����
void Musiclist_line_Read(); // .txt���� ���� �� ī����
void Musiclist_FirstPlay(); // ���� ���� ���
int play_continue_input; // ��� ���� ��������� ���� �Ϳ� ���� �� �Է�
void Musiclist_ContinuePlay(); // (���� ����)���� ���

/* mainȭ�� 2�� ��� */
void File_close(); // .txt ���� ����


#endif