#ifndef __HEAD_H__
#define __HEAD_H__

FILE *fp; // .txt���� ���� ����������
int main_input; // ����ȭ�� �Է�
int play_input; // �� ������ �Է�

/* GUI ���� */
void mainGUI(); // ����ȭ�� GUI
void playmodeGUI(); // ���������� ���� GUI
void Question_Continue(); // ��� ���� �������� �÷������� ���� �Լ�
void Random_mode(); //������� ����
void No_overlap_Qusetion_Continue(); //(�ߺ����������� ����)���� �� ����Ҳ��� ����

/* ������� ���� */
int play_continue_input; // ��� ���� ��������� ���� �Ϳ� ���� �� �Է�
int line_number; // .txt���� ���� �� ����
int play_random_mode_input;
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

/* ������� - 3��(�ߺ������� ����) ��� */
void Musiclist_line_Read_3();
void Random_Select(); //������ ���� ��ũ�� ���Ѵ�
void Musiclist_Play(); //�����÷���

/* ������� - 4��(�ߺ����� ����) ��� */
int play_no_overlap_continue_input; //(�ߺ����������� ����)���� �� ����Ҳ����� ���� �� �Է�
void Save_RandomNum();  //���� ���� ���� �ѹ��� �����ϴ� �Լ�. �ߺ����� ������ ����Ǵ°� �����ϱ� ����
void No_overlap_Musiclist_play(); //������忡�� �ߺ���������� �ȵǴ� �����÷���
void File_close4();

#endif