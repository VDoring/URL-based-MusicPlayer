#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용 파일포인터

int *line_num; // .txt파일 라인 수 임시저장
int line_number; // .txt파일 라인 수 저장
void Musiclist_line_Read() { // .txt파일 라인 수 카운팅
	fp = fopen("Mlist.txt", "rt");
	int line_count = 0;
	char tmp;

	while (fscanf(fp, "%c", &tmp) != EOF) { // .txt파일에 저장된 글자 하나하나 검사해 EOF인지 확인
		if (tmp == '\n')
			line_count++; // 파일 줄 수 최초 저장
	}
	line_num = &line_count;
	line_number = *line_num; // .txt파일 라인 수 최종 저장

	fclose(fp);

}


char fileread[4096]; // .txt파일 한줄읽기용 문자열
char cache_Music1[100] = { 0, };// 명령어 저장
char cache_Music2[8092] = { 0, };// fileread 문자열과 같은 역할
const char CMD_Static_command[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char Musiclink[8192] = { 0, }; // 최종 음악재생 명령어
char *ptr_linkcut_result; // 오직 링크만 저장
void  Musiclist_FirstPlay() { // 최초 음악 재생

	fp = fopen("Mlist.txt", "rt");
	fgets(fileread, sizeof(fileread), fp); // .txt파일 한줄을 읽어 fileread에 저장

	sprintf(cache_Music1, "%s", CMD_Static_command); // CMD_Static_command = cache_Music1 , 명령어 저장
	sprintf(cache_Music2, "%s", fileread); // fileread = cache_Music2 , 음악 링크 저장

	ptr_linkcut_result = strtok(cache_Music2, " "); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink);

}


void Musiclist_ContinuePlay() { // (최초 이후)음악 재생

	fgets(fileread, sizeof(fileread), fp);

	while (1) {
		if (fileread[0] == '\n') {
			fgets(fileread, sizeof(fileread), fp);
		}
		else break;
	}

	/*
	while (1) {
		if (fileread[0] == '\n') {
			fgets(fileread, sizeof(fileread), fp);
		}
	}
	*/

	sprintf(cache_Music1, "%s", CMD_Static_command);
	sprintf(cache_Music2, "%s", fileread);

	ptr_linkcut_result = strtok(cache_Music2, " ");

	sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut_result);

	system(Musiclink);

	Sleep(100); //정상 실행을 위한 약간의 텀

}

void File_close() { // .txt 파일 닫음
	fclose(fp);
}