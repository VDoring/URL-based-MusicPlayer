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
void WinTitleTotal(); //������� ������ �� ���� ������ ����.(������Ÿ��Ʋ ����� ���� �Լ�)

/* ������� - 1�� ���*/
void Musiclist_line_Read_1(); // .txt���� ���� �� ī����
void Musiclist_FirstPlay_1(); // ���� ���� ���
void Musiclist_ContinuePlay_1(); // (���� ����)���� ���
void File_close(); // .txt ���� �ݱ� �� ������Ÿ��Ʋ �� �ʱ�ȭ

/* ������� - 2�� ��� */
void Musiclist_line_Read_2();
void Musiclist_FirstPlay_2();
void Musiclist_ContinuePlay_2();
void File_close2();

/* ������� - 3�� ��� */
void Musiclist_line_Read_3();
void Musiclist_FirstPlay_3();
void Musiclist_ContinuePlay_3();


#endif