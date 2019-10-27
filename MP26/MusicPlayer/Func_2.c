#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용 파일포인터

int *line_num; // .txt파일 라인 수 임시저장
int line_number; // .txt파일 라인 수 저장
void Musiclist_line_Read_2() { // .txt파일 라인 수 카운팅

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

char fileread[4096]; // .txt파일 한줄읽기용 문자열
const char CMD_Static_command_2[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char cache_Music1_2[100] = { 0, };// 명령어 저장
char cache_Music2_2[8092] = { 0, };// fileread 문자열과 같은 역할
char Musiclink_2[8192] = { 0, }; // 최종 음악재생 명령어
char *ptr_linkcut_result; // 오직 링크만 저장
char *contact_2 = NULL; //cache_Music2_2 문자열에서 자른 나머지 문자열을 저장
void Musiclist_FirstPlay_2() {

	fopen_s(&fp, "Mlist.txt", "rt");
	
	for (int i = 0; i < line_number; i++) { //띄어쓰기 되있는걸 무시하고 링크재생하는 구문
		if(i == 0) fgets(fileread, sizeof(fileread), fp); //처음 실행할때만 한줄을 먼저 읽게 함
		if (fileread[0] == '\n') { //만약 .txt파일중간에 줄이 띄워져 있을경우
			fgets(fileread, sizeof(fileread), fp); //다음 링크로 넘어감
		} else fgets(fileread, sizeof(fileread), fp);
	}


	sprintf_s(cache_Music1_2, sizeof(cache_Music1_2), "%s", CMD_Static_command_2);
	sprintf_s(cache_Music2_2, sizeof(cache_Music2_2), "%s", fileread); 

	ptr_linkcut_result = strtok_s(cache_Music2_2, " ", &contact_2); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_2, sizeof(Musiclink_2), "%s %s", cache_Music1_2, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_2);

	//line_number--;

	fclose(fp);
}

int playcount = 0; //몇번 재생했는지를 세는 변수
int linkcheck_line_number = 0;  //기존 line_number의 값을 조작하게 되면 플레이에 문제가 있으므로, line_number와 동등한 값을 가진 (Musiclist_ContinuePlay_2함수 내에서만 사용하는)변수
void Musiclist_ContinuePlay_2() {

	//int Conplay2_line_number = line_number;

	fopen_s(&fp, "Mlist.txt", "rt");

	/*
	//구상안 0
	Conplay2_line_number--;
	
	//ERROR. 라인 띄어쓰기를 고려하여 차례로 줄이 위로 가도록 만들기
	for (int i = 0; i < Conplay2_line_number; i++) { //띄어쓰기 되있는걸 무시하고 링크재생하는 구문
		if (i == 0) fgets(fileread, sizeof(fileread), fp); //처음 실행할때만 한줄을 먼저 읽게 함
		if (fileread[0] == '\n') { //만약 .txt파일중간에 줄이 띄워져 있을경우
			Conplay2_line_number--;
			fgets(fileread, sizeof(fileread), fp); //다음 링크로 넘어감
		}
		else fgets(fileread, sizeof(fileread), fp);
	}
	*/

	/*
	//구상안 1
	line_number--;

	int Initial_play = 0;

	for (int i = 0; i < line_number; i++) { //띄어쓰기 되있는걸 무시하고 링크재생하는 구문
		if (i == 0) {
			fgets(fileread, sizeof(fileread), fp); //처음 실행할때만 한줄을 먼저 읽게 함
			Initial_play++;
		}
		if (fileread[0] == '\n') { //만약 .txt파일중간에 줄이 띄워져 있을경우
			while (1) {
				line_number--;
				fgets(fileread, sizeof(fileread), fp); //다음 링크로 넘어감
				if (fileread[0] != '\n') break; //링크가 발견됬을때
				else printf("반복");
			}
		}
		if (Initial_play == 1) {

		}
	}
	*/

	/*
	//구상안 2
	line_number--;
	fgets(fileread, sizeof(fileread), fp);
	int check_line_number = 0;

	int Before_if_Run = 0; //밑에 for문안에 아무것도 실행되지 않을경우
	int After_if_Run = 0; //밑에 for문안에 아무것도 실행되지 않을경우

	for (int i = 0; i < line_number; i++) {
		if (fileread[0] == '\n') {
			check_line_number = line_number;
			line_number--;
			After_if_Run++;
			for (int j = 0; j < check_line_number; j++) {
				fgets(fileread, sizeof(fileread), fp);
			}
			if (fileread[0] != '\n') break;
			//else continue;
		}
		if (Before_if_Run < After_if_Run) {
			Before_if_Run++;
			fgets(fileread, sizeof(fileread), fp);
		}
		else if (Before_if_Run == After_if_Run) {
			fgets(fileread, sizeof(fileread), fp);
		}
	}
	*/
	/*
	//구상안 2 원본내용
	linecount--;
	fgets(...);

	for(int i = 0; i < linecount; i++) {

	if (fileread[0] == '\n') { //공백일때
		line_count--; //공백 라인 수 제거
		for(int j = 0; j < line_count; j++) { //공백 라인 제거후 다시 찾기
			fgets(...); //파일 링크 읽음
		}
		if(fileread[0] != '\n') break; //링크일때
		else printf("return"); //링크 아니라면
	}

	*/


	//line_number--;

	linkcheck_line_number = line_number; //main.c에서도 line_number를 사용하므로, 같은 값을 가지는 대체변수 선언

	for (int j = 0; j < linkcheck_line_number - playcount; j++) { // (.txt파일 전체 줄 갯수 - 재생된 휫수)만큼 반복
		fgets(fileread, sizeof(fileread), fp); // 결과적으로 마지막 링크에서 한칸 위 링크가 재생되게 됨
		//linkcheck_line_number--;
	}
	playcount++;

	sprintf_s(cache_Music1_2, sizeof(cache_Music1_2), "%s", CMD_Static_command_2);
	sprintf_s(cache_Music2_2, sizeof(cache_Music2_2), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_2, " ", &contact_2); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_2, sizeof(Musiclink_2), "%s %s", cache_Music1_2, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_2);

}