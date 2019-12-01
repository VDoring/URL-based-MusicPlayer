#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {
	while (1) {
//		[메인화면]
		mainGUI();

		if (main_input == 1) { // [메인화면] - 1번
//			[플레이모드]
			playmodeGUI();

			if (play_input == 1) { // [플레이모드] - 1번
				Musiclist_line_Read_1(); // .txt파일 라인 수 카운팅
				WinTitleTotal(); // .txt파일 총 라인수 계산
				Musiclist_FirstPlay_1(); // 최초 음악 실행
				for (int i = 0; i < line_number; i++) { // .txt파일 라인 수만큼 반복
					Question_Continue(); // 다음곡 재생할지 질문
					if (play_continue_input == 1) Musiclist_ContinuePlay_1(); // Yes선택시 다음 링크 재생
					else if (play_continue_input == 2) return 0; // No 선택시 프로그램 종료
				}
				File_close(); // 재생 다했을시 파일닫기 및 특정변수 초기화
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
					else if (play_continue_input == 2) return 0;
				}
			}
		}

		else if (main_input == 2) { // [메인화면] - 2번
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