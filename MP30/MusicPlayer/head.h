#ifndef __HEAD_H__
#define __HEAD_H__

FILE *fp; // .txt���� ���� ����������
int main_input; // ����ȭ�� �Է�
int play_input; // �� ������ �Է�

/* GUI ���� */
void mainGUI(); // ����ȭ�� GUI
void playmodeGUI(); // ���������� ���� GUI
void Question_Continue(); // ��� ���� �������� �÷������� ���� �Լ�

/* ������� ���� */
int play_continue_input; // ��� ���� ��������� ���� �Ϳ� ���� �� �Է�
int line_number; // .txt���� ���� �� ����

/* ������� - 1�� ���*/
void Musiclist_line_Read_1(); // .txt���� ���� �� ī����
void Musiclist_FirstPlay_1(); // ���� ���� ���
void Musiclist_ContinuePlay_1(); // (���� ����)���� ���

/* ������� - 2�� ��� */
void Musiclist_line_Read_2();
void Musiclist_FirstPlay_2();
void Musiclist_ContinuePlay_2();

/* mainȭ�� 2�� ��� */
void File_close(); // .txt ���� ����


#endif