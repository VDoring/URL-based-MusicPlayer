#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {
	while (1) {
//		[����ȭ��]
		mainGUI();

		if (main_input == 1) { // [����ȭ��] - 1��
//			[�÷��̸��]
			playmodeGUI();

			if (play_input == 1) { // [�÷��̸��] - 1��
				Musiclist_line_Read_1(); // .txt���� ���� �� ī����
				WinTitleTotal(); // .txt���� �� ���μ� ���
				Musiclist_FirstPlay_1(); // ���� ���� ����
				for (int i = 0; i < line_number; i++) { // .txt���� ���� ����ŭ �ݺ�
					Question_Continue(); // ������ ������� ����
					if (play_continue_input == 1) Musiclist_ContinuePlay_1(); // Yes���ý� ���� ��ũ ���
					else if (play_continue_input == 2) return 0; // No ���ý� ���α׷� ����
				}
				File_close(); // ��� �������� ���ϴݱ� �� Ư������ �ʱ�ȭ
			}

			else if (play_input == 2) { //�� ���� ��� 2�� ���ý�
				Musiclist_line_Read_2(); //ù ���� �÷����ϱ� ���� ���� ������ ����
				WinTitleTotal();
				Musiclist_FirstPlay_2(); //ù �� �÷���
				for (int i = 0; i < line_number; i++) {
					Question_Continue();
					if (play_continue_input == 1) Musiclist_ContinuePlay_2();
					else if (play_continue_input == 2) return 0;
				}
				File_close2();
			}

			else if (play_input == 3) { //�� ���� ��� 3�� ���ý�
				Musiclist_line_Read_3();
				Random_Select();
				Musiclist_Play();
				for (int i = 0; i < line_number; i++) {
					Question_Continue();
					if (play_continue_input == 1) {
						Random_Select();
						Musiclist_Play();
					}
					else if (play_continue_input == 2) return 0;
				}
			}
		}

		else if (main_input == 2) { // [����ȭ��] - 2��
			if (fp == NULL) return 0; // .txt������ ���� ������
			else if (fp != NULL) { // .txt������ ������ ������
				File_close();
				return 0;
			}
		}

		else {
			printf("re-enter Please!"); Sleep(300);
		}
	}
}