#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용 파일포인터

int Random;
int Play_Random_count = 0;
int save_random_number[10000] = { 0, };
void Save_RandomNum() { //랜덤 모드시 라인 넘버를 저장하는 함수. (중복으로 음악이 실행되는걸 방지하기 위함)
	save_random_number[Play_Random_count] = Random;
	Play_Random_count++;
}

int line_number;
int no_overlap_line_number = 0;
//중복없는 랜덤숫자를 line_number의 수만큼 뽐음
void random_num_array_save() {
	extern void Random_Select();

	no_overlap_line_number = line_number; //line_number와 똑같은 밑의 for문에 사용할 새로운 변수 선언
	no_overlap_line_number++;

	Save_RandomNum();
	for (int i = 1; i < no_overlap_line_number; i++) {
		Random_Select();
		Save_RandomNum();
		for (int j = 0; j < i; j++) {
			if (save_random_number[i] == save_random_number[j]) {
				i--;
				Play_Random_count--;
				break;
			}
			//break;
		}
	}
}


char fileread[4096]; // .txt파일 한줄읽기용 문자열
const char CMD_Static_command_4[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char cache_Music1_4[100];
char cache_Music2_4[8092];
char *ptr_linkcut_result;
char *contact_4 = NULL; //cache_Music2_2 문자열에서 자른 나머지 문자열을 저장
char Musiclink_4[8192] = { 0, }; // 최종 음악재생 명령어
void No_overlap_Musiclist_play() { //(음악중복재생 방지) 음악플레이
	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);
	
	//[!]save_random_number 배열값에 따라 곡이 나오게 수정하기
	for (int i = 0; i < line_number; i++) {
		fgets(fileread, sizeof(fileread), fp);
	}

	sprintf_s(cache_Music1_4, sizeof(cache_Music1_4), "%s", CMD_Static_command_4);
	sprintf_s(cache_Music2_4, sizeof(cache_Music2_4), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_4, " ", &contact_4); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_4, sizeof(Musiclink_4), "%s %s", cache_Music1_4, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_4);

	fclose(fp);
}


void File_close4() { // .txt 파일 닫음
	Play_Random_count = 0;

	for (int i = 0; i < 10000; i++) {
		save_random_number[i] = 0;
	}

	fclose(fp);
}