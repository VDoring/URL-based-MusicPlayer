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
				Musiclist_Read();
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
				File_close(fp);
			}
			return 1;
		}

		else {
			printf("Please re-enter!"); Sleep(300);
		}
	}
}