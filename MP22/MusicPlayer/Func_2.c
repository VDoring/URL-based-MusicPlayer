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

void Musiclist_ContinuePlay_2() {

	int Conplay2_line_number = line_number;

	fopen_s(&fp, "Mlist.txt", "rt");

	Conplay2_line_number--;

	//ERROR. 라인 띄어쓰기를 고려하여 차례로 줄이 위로 가도록 만들기
	for (int i = 0; i < Conplay2_line_number; i++) { //띄어쓰기 되있는걸 무시하고 링크재생하는 구문
		if (i == 0) fgets(fileread, sizeof(fileread), fp); //처음 실행할때만 한줄을 먼저 읽게 함
		if (fileread[0] == '\n') { //만약 .txt파일중간에 줄이 띄워져 있을경우
			fgets(fileread, sizeof(fileread), fp); //다음 링크로 넘어감
		}
		else fgets(fileread, sizeof(fileread), fp);
	}


	sprintf_s(cache_Music1_2, sizeof(cache_Music1_2), "%s", CMD_Static_command_2);
	sprintf_s(cache_Music2_2, sizeof(cache_Music2_2), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_2, " ", &contact_2); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_2, sizeof(Musiclink_2), "%s %s", cache_Music1_2, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_2);

}


/* 앞으로의 계획(수정)

Musiclist_FirstPlay_2() 에서 사용된 line_number를 기반으로 사용할까 생각중.
for문을 이용하여 음악을 반복할때마다 line_number수를 하나씩 줄여 한칸 위로 올라가게 구현하면 될 것 같다.

*/