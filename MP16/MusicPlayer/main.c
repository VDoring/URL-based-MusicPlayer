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
				Musiclist_line_Read();
				Musiclist_FirstPlay();

				for (int i = 0; i < line_number; i++) { // .txt������ �� �� ��ŭ �ݺ�
					Question_Continue(); // ��� ������� �����

					if (play_continue_input == 1) { // Yes ���ý�
						Musiclist_ContinuePlay();
					}
					else if (play_continue_input == 2) { // No ���ý�
						return 3;
					}
				}

			}
			else if (play_input == 2) { //�� ���� ��� 2�� ���ý�
				printf("2�� ������");
				return 2;
			}
			else if (play_input == 3) { //�� ���� ��� 3�� ���ý�
				printf("3�� ������");
				return 2;
			}
		}

		else if (main_input == 2) { // ����ȭ�� 2�� ���ý�
			if (fp != NULL) { // .txt������ ������ ������
				File_close();
			}
			return 1;
		}

		else {
			printf("Please re-enter!"); Sleep(300);
		}
	}
}