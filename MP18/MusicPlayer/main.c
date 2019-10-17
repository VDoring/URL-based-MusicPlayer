#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {

	while (1) {
		mainGUI();

		if (main_input == 1) { // 메인화면 1번 선택시
			playmodeGUI();

			if (play_input == 1) { //곡 선택 모드 1번 선택시
				Musiclist_line_Read();
				Musiclist_FirstPlay();

				for (int i = 0; i < line_number; i++) { // .txt파일의 줄 수 만큼 반복
					Question_Continue(); // 계속 재생할지 물어본다

					if (play_continue_input == 1) { // Yes 선택시
						Musiclist_ContinuePlay();
					}
					else if (play_continue_input == 2) { // No 선택시
						return 3;
					}
				}

			}
			else if (play_input == 2) { //곡 선택 모드 2번 선택시
				printf("2번 개발중");
				return 2;
			}
			else if (play_input == 3) { //곡 선택 모드 3번 선택시
				printf("3번 개발중");
				return 2;
			}
		}

		else if (main_input == 2) { // 메인화면 2번 선택시
			if (fp != NULL) { // .txt파일이 열어져 있을때
				File_close();
			}
			return 1;
		}

		else {
			printf("Please re-enter!"); Sleep(300);
		}
	}
}