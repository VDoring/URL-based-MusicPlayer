#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {

	while (1) {
		mainGUI();

		if (main_input == 1) { // ����ȭ�� 1�� ���ý�
			playmodeGUI();

			if (play_input == 1) { //�� ���� ��� 1�� ���ý�
				Musiclist_line_Read_1();
				Musiclist_FirstPlay_1();
				for (int i = 0; i < line_number; i++) { // .txt������ �� �� ��ŭ �ݺ�
					Question_Continue(); // ��� ������� �����
					if (play_continue_input == 1) Musiclist_ContinuePlay_1(); // Yes ���ý�
					else if (play_continue_input == 2) return 2; // No ���ý�
				}
				File_close();
			}

			else if (play_input == 2) { //�� ���� ��� 2�� ���ý�
				Musiclist_line_Read_2(); //ù ���� �÷����ϱ� ���� ���� ������ ����
				Musiclist_FirstPlay_2(); //ù �� �÷���
				for (int i = 0; i < line_number; i++) {
					Question_Continue();
					if (play_continue_input == 1) {
						Musiclist_ContinuePlay_2();
					}
					else if (play_continue_input == 2) return 3;
				}
				File_close();
			}

			else if (play_input == 3) { //�� ���� ��� 3�� ���ý�
				printf("3�� ������");
				return 4;
			}
		}

		else if (main_input == 2) { // ����ȭ�� 2�� ���ý�
			if (fp == NULL) { // .txt������ ���� ������
				return 1;
			}
			else if (fp != NULL) { // .txt������ ������ ������
				File_close();
				return 1;
			}
		}

		else {
			printf("Please re-enter!"); Sleep(300);
		}
	}
}