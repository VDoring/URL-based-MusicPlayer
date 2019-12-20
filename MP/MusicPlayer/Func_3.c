#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용 파일포인터

int *line_num; // .txt파일 라인 수 임시저장
int line_number; // .txt파일 라인 수 저장
void Musiclist_line_Read_3() { // .txt파일 라인 수 카운팅

	fopen_s(&fp, "Mlist.txt", "rt");
	int line_count = 0;
	char tmp;

	while (fscanf_s(fp, "%c", &tmp, sizeof(tmp)) != EOF) { // .txt파일에 저장된 글자 하나하나 검사해 EOF인지 확인
		if (tmp == '\n')
			line_count++; // 파일 줄 수 최초 저장
	}
	line_num = &line_count;
	line_number = *line_num; // .txt파일 라인 수 최종 저장

	fclose(fp);

}


int random_number; //rand함수의 값을 담는 곳
int linkRandom_line_number = 0; // .txt파일 라인 수 저장
int Random; //random_number의 값을 받는 변수(랜덤숫자 최종)
void Random_Select() { //난수 기반으로 재생할 링크를 정하는 함수
	linkRandom_line_number = line_number; //line_number는 main.c에서도 사용하므로 혼동 생기지않게 똑같은 값을 가진 변수를 따로선언
	linkRandom_line_number += 2;
	Random = 0;
	
	while (Random <= 0) { // Random이 1 이상이 될때까지 반복
		srand((unsigned)time(NULL)); //프로그램 실행시마다 다른 랜덤숫자가 나오게 된다
		random_number = rand();
		Random = (int)random_number % linkRandom_line_number; // Random은 난수와 라인 수+2의 나머지다
	}
}


char fileread[4096]; // .txt파일 한줄읽기용 문자열
const char CMD_Static_command_3[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char cache_Music1_3[100];// 명령어 저장
char cache_Music2_3[8092];// fileread 문자열과 같은 역할
char *ptr_linkcut_result; // 오직 링크만 저장
char *contact_3 = NULL; //cache_Music2_2 문자열에서 자른 나머지 문자열을 저장
char Musiclink_3[8192] = { 0, }; // 최종 음악재생 명령어
void Musiclist_Play() {
	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	for (int i = 0; i < Random; i++) {
		fgets(fileread, sizeof(fileread), fp);
	}
	
	//나중에 빈 라인 처리코드 만들기

	sprintf_s(cache_Music1_3, sizeof(cache_Music1_3), "%s", CMD_Static_command_3);
	sprintf_s(cache_Music2_3, sizeof(cache_Music2_3), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_3, " ", &contact_3); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_3, sizeof(Musiclink_3), "%s %s", cache_Music1_3, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_3);

	fclose(fp);

}