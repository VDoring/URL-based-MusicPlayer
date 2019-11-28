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
				Musiclist_line_Read_1();
				WinTitleTotal();
				Musiclist_FirstPlay_1();
				for (int i = 0; i < line_number; i++) { // .txt파일의 줄 수 만큼 반복
					Question_Continue(); // 계속 재생할지 물어본다
					if (play_continue_input == 1) Musiclist_ContinuePlay_1(); // Yes 선택시
					else if (play_continue_input == 2) return 0; // No 선택시
				}
				File_close();
			}

			else if (play_input == 2) { //곡 선택 모드 2번 선택시
				Musiclist_line_Read_2(); //첫 곡을 플레이하기 위해 라인 갯수를 센다
				WinTitleTotal();
				Musiclist_FirstPlay_2(); //첫 곡 플레이
				for (int i = 0; i < line_number; i++) {
					Question_Continue();
					if (play_continue_input == 1) Musiclist_ContinuePlay_2();
					else if (play_continue_input == 2) return 0;
				}
				File_close2();
			}

			else if (play_input == 3) { //곡 선택 모드 3번 선택시
				Musiclist_line_Read_3();
				Random_Select();
				Musiclist_Play();
				for (int i = 0; i < line_number; i++) {
					Question_Continue();
					if (play_continue_input == 1) {
						Random_Select();
						Musiclist_Play();
					}
					else if (play_continue_input == 2) return 1;
				}
			}
		}

		else if (main_input == 2) { // 메인화면 2번 선택시
			if (fp == NULL) return 0; // .txt파일이 닫혀 있을때
			else if (fp != NULL) { // .txt파일이 열어져 있을때
				File_close();
				return 0;
			}
		}

		else {
			printf("re-enter Please!"); Sleep(300);
		}
	}
}