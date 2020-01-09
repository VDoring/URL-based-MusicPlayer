#ifndef __HEAD_H__
#define __HEAD_H__

FILE *fp; // .txt���� ���� ����������
int main_input; // ����ȭ�� CUI�� �Է¿� ����
int play_input; // �� ������ CUI�� �Է¿� ����

/* GUI(�������̽�) ���� */
void mainGUI(); // ����ȭ�� GUI
void playmodeGUI(); // ��� ��� ���� CUI
void Question_Continue(); //���� �� ����Ҳ��� ���� CUI
void Random_mode(); //������� ���� CUI
void No_overlap_Qusetion_Continue(); //(�ߺ����������� ����)���� �� ����Ҳ��� ���� CUI

/* ������� ���� */
int play_continue_input; // ���� �� ����Ҳ��� ���� CUI�� �Է¿� ����
int line_number; // .txt���� ���� �� ����
int play_random_mode_input;
void WinTitleTotal(); //������� ������ �� ���� ������ ���� �Լ�(������Ÿ��Ʋ ����� ���� �Լ�)

/* ������� - 1�� ���*/
void Musiclist_line_Read_1(); // .txt���� ���� �� ī����
void Musiclist_FirstPlay_1(); // ���� ���� ���
void Musiclist_ContinuePlay_1(); // (���� ����)���� ���
void File_close(); // .txt ���� �ݱ� �� ������Ÿ��Ʋ �� �ʱ�ȭ

/* ������� - 2�� ��� */
void Musiclist_line_Read_2(); // .txt���� ���� �� ī����
void Musiclist_FirstPlay_2(); // ���� ���� ���
void Musiclist_ContinuePlay_2(); // (���� ����)���� ���
void File_close2(); // .txt ���� �ݱ� �� ������Ÿ��Ʋ �� �ʱ�ȭ

/* ������� - 3��(�ߺ������� ����) ��� */
void Musiclist_line_Read_3(); // .txt���� ���� �� ī����
void Random_Select(); // ������ ���� ������� ����� ��ũ�� ���ϴ� �Լ�
void Musiclist_Play(); // ���� ���
void File_Close3(); // .txt ���� �ݱ�, ������Ÿ��Ʋ �� �ʱ�ȭ �� ��ȸ�� ���� �ʱ�ȭ

/* ������� - 4��(�ߺ����� ����) ��� */
int play_no_overlap_continue_input; //(�ߺ����������� ����)���� �� ����Ҳ����� ���� �� �Է�
//void Save_RandomNum(); //���� ���� ���� �ѹ��� �����ϴ� �Լ�. (�ߺ����� ������ ����Ǵ°� �����ϱ� ����)
//void random_num_array_save(); //�ߺ����� �������ڸ� linecount�� ����ŭ ����
void No_overlap_random(); //������� ������ �迭�� ���� �� �迭�� ����
void No_overlap_Musiclist_play(); //(�����ߺ���� ����) �����÷���
void File_close4(); // .txt ���� �ݱ� �� ������Ÿ��Ʋ �� �ʱ�ȭ

#endif