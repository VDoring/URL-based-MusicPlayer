#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {
	while (1) {
//		[����ȭ��]
		mainGUI();

//		[����ȭ��] - 1��
		if (main_input == 49) {
//			[�÷��̸��] - �ȳ�â
			playmodeGUI();

//			[�÷��̸��] - 1��
			if (play_input == 49) {
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
//			[�÷��̸��] - 2��
			else if (play_input == 50) {
				Musiclist_line_Read_2(); // .txt���� ���� �� ī����
				WinTitleTotal(); //.txt���� �� ���μ� ���
				Musiclist_FirstPlay_2(); //���� ���� ����
				for (int i = 0; i < line_number; i++) { // .txt���� ���� ����ŭ �ݺ�
					Question_Continue(); // ������ ������� ����
					if (play_continue_input == 1) Musiclist_ContinuePlay_2(); // Yes���ý� ���� ��ũ ���
					else if (play_continue_input == 2) return 0; // No ���ý� ���α׷� ����
				}
				File_close2(); // ��� �������� ���ϴݱ� �� Ư������ �ʱ�ȭ
			}
//			[�÷��̸��] - 3��
			else if (play_input == 51) {
				Musiclist_line_Read_3(); // .txt���� ���� �� ī����
				Random_mode(); //������� ���� CUI
//				[�������] - 1��(�� �ߺ����� �������)
				if (play_random_mode_input == 49) {
					Random_Select(); //���� ��� ���� �� ����
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

//				[�������] - 2��(�� �ߺ��Ұ� �������)
				else if (play_random_mode_input == 50) {
					//random_num_array_save();
					No_overlap_random();
					No_overlap_Musiclist_play();
					for (int i = 0; i < line_number; i++) {
						No_overlap_Qusetion_Continue();
						if (play_no_overlap_continue_input == 1) {
							No_overlap_Musiclist_play();
						}
						else if (play_no_overlap_continue_input == 2) return 1;
					}
					File_close4();
				}
			}
		}

//		[����ȭ��] - 2��
		else if (main_input == 50) {
			if (fp == NULL) return 0; // .txt������ ���� ������
			else if (fp != NULL) { // .txt������ ������ ������
				File_close(); // ���� �ݱ�
				return 0;
			}
		}

//		[����ȭ��] - �ٸ� ���ڸ� �Է����� ���
		else {
			printf("re-enter Please!"); Sleep(300);
		}
	}
}