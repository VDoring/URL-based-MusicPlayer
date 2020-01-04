#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {
	while (1) {
//		[메인화면]
		mainGUI();

//		[메인화면] - 1번
		if (main_input == 49) {
//			[플레이모드] - 안내창
			playmodeGUI();

//			[플레이모드] - 1번
			if (play_input == 49) {
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
//			[플레이모드] - 2번
			else if (play_input == 50) {
				Musiclist_line_Read_2(); // .txt파일 라인 수 카운팅
				WinTitleTotal(); //.txt파일 총 라인수 계산
				Musiclist_FirstPlay_2(); //최초 음악 실행
				for (int i = 0; i < line_number; i++) { // .txt파일 라인 수만큼 반복
					Question_Continue(); // 다음곡 재생할지 질문
					if (play_continue_input == 1) Musiclist_ContinuePlay_2(); // Yes선택시 다음 링크 재생
					else if (play_continue_input == 2) return 0; // No 선택시 프로그램 종료
				}
				File_close2(); // 재생 다했을시 파일닫기 및 특정변수 초기화
			}
//			[플레이모드] - 3번
			else if (play_input == 51) {
				Musiclist_line_Read_3(); // .txt파일 라인 수 카운팅
				Random_mode(); //랜덤모드 선택 CUI
//				[랜덤모드] - 1번(곡 중복가능 랜덤모드)
				if (play_random_mode_input == 49) {
					Random_Select(); //난수 기반 랜덤 곡 정함
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

//				[랜덤모드] - 2번(곡 중복불가 랜덤모드)
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

//		[메인화면] - 2번
		else if (main_input == 50) {
			if (fp == NULL) return 0; // .txt파일이 닫혀 있을시
			else if (fp != NULL) { // .txt파일이 열어져 있을시
				File_close(); // 파일 닫기
				return 0;
			}
		}

//		[메인화면] - 다른 숫자를 입력했을 경우
		else {
			printf("re-enter Please!"); Sleep(300);
		}
	}
}