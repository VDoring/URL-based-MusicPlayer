#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {

	while (1) {

		Intro();

		if (main_input == 1) {
			playmode();
			if (play_input == 1) {
				/*
				if (fp == NULL) {
					exit(0);
				}
				���� Mlist���Ͽ� �ƹ��͵� ������ ����ǰ� �����
				*/
				Musiclist_line_Read();
				Musiclist_Read();
			}
			else if (play_input == 2) {
				printf("2�� ������");
				return 2;
			}
			else if (play_input == 3) {
				printf("3�� ������");
				return 2;
			}
		}

		else if (main_input == 2) {
			if (fp != NULL) { //(����)������ ������ ������
				File_close(fp);
			}
			return 1;
		}

		else {
			printf("Please re-enter!"); Sleep(300);
		}
	}
}