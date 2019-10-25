#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용 파일포인터

int *line_num; // .txt파일 라인 수 임시저장
int line_number; // .txt파일 라인 수 저장
void Musiclist_line_Read_1() { // .txt파일 라인 수 카운팅

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
char cache_Music1[100] = { 0, };// 명령어 저장
char cache_Music2[8092] = { 0, };// fileread 문자열과 같은 역할
char *contact = NULL; //cache_Music2 문자열에서 자른 나머지 문자열을 저장
const char CMD_Static_command[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char Musiclink[8192] = { 0, }; // 최종 음악재생 명령어
char *ptr_linkcut_result; // 오직 링크만 저장
void  Musiclist_FirstPlay_1() { // 최초 음악 재생

	fopen_s(&fp, "Mlist.txt", "rt");
	fgets(fileread, sizeof(fileread), fp); // .txt파일 한줄을 읽어 fileread에 저장
	
	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command); // CMD_Static_command = cache_Music1 , 명령어 저장
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread); // fileread = cache_Music2 , 음악 링크 저장

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장
	
	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink);

}


void Musiclist_ContinuePlay_1() { // (최초 이후)음악 재생
	
	fgets(fileread, sizeof(fileread), fp);

	while (1) {
		if (fileread[0] == '\n') { //만약 .txt파일중간에 줄이 띄워져 있을경우
			fgets(fileread, sizeof(fileread), fp); //다음 링크 재생
			line_number--; //빈칸도 줄수로 채웠을 것이므로 하나 마이너스
		}
		else break;
	}

	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command);
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact);

	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result);

	system(Musiclink);

	Sleep(30); //정상 실행을 위한 약간의 텀

}

void File_close() { // .txt 파일 닫음
	fclose(fp);
}