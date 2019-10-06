#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {

	while (1) {
		mainTheme();
		if (main_input == 1) {
			playmode();
			if (play_input == 1) {
				Musiclist_line_Read();
				Musiclist_FirstPlay();
				for (int i = 0; i < line_number - 1; i++) {
					Question_Continue();
					if (play_continue_input == 1) {
						Musiclist_ContinuePlay();
					}
					else if (play_continue_input == 2) {
						return 5;
					} else return 10;
				}
			}
			else if (play_input == 2) {
				printf("2번 개발중");
				return 2;
			}
			else if (play_input == 3) {
				printf("3번 개발중");
				return 2;
			}
		}

		else if (main_input == 2) {
			if (fp != NULL) { //(음악)파일이 열어져 있을때
				File_close();
			}
			return 1;
		}

		else {
			printf("Please re-enter!"); Sleep(300);
		}
	}
}