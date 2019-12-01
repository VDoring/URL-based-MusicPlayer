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

const char WindowTitleCMD2[10] = { "title" }; //CMD에 고정적으로 입력되는 명령어
int NowCount2 = 0; //현재 몇번 실행했는지를 담는 변수
int WindowTitleNowcount; //윈도우타이틀 출력용 Nowcount2
int WindowtitleTotalcount; // 빈 라인을 제외한 .txt파일의 총 라인 수

char fileread[4096]; // .txt파일 한줄읽기용 문자열
const char CMD_Static_command_2[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char cache_Music1_2[100] = { 0, };// 명령어 저장
char cache_Music2_2[8092] = { 0, };// fileread 문자열과 같은 역할
char Musiclink_2[8192] = { 0, }; // 최종 음악재생 명령어
char *ptr_linkcut_result; // 오직 링크만 저장
char *contact_2 = NULL; //cache_Music2_2 문자열에서 자른 나머지 문자열을 저장
int strCopy; //최초 fileread(링크)를 before_fileread에 복사할지 결정하는 변수
char WindowTitle2[110] = { 0, }; //최종 아티틀 명령어
void Musiclist_FirstPlay_2() {

	strCopy = 0;

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

	fclose(fp);


	// WindowTitle 출력
	NowCount2++;

	WindowTitleNowcount = NowCount2;

	sprintf_s(WindowTitle2, sizeof(WindowTitle2), "%s Playing.. [%d/%d]", WindowTitleCMD2, WindowTitleNowcount, WindowtitleTotalcount);

	system(WindowTitle2);
}

int playcount = 0; //몇번 재생했는지를 세는 변수
int linkcheck_line_number = 0;  //기존 line_number의 값을 조작하게 되면 플레이에 문제가 있으므로, line_number와 동등한 값을 가진 (Musiclist_ContinuePlay_2함수 내에서만 사용하는)변수
char before_fileread[4096] = { 0, }; //가장 처음 실행한 링크를 저장(Firstplay)
void Musiclist_ContinuePlay_2() {

	fopen_s(&fp, "Mlist.txt", "rt");

	linkcheck_line_number = line_number; //main.c에서도 line_number를 사용하므로, 같은 값을 가지는 대체변수 선언


	if (strCopy == 0) { //최초 한정
		strcpy_s(before_fileread, sizeof(fileread), fileread); //fileread내용을 before_fileread로 복사
		strCopy++;
	}


AGAIN:
	for (int j = 0; j < linkcheck_line_number - playcount; j++) { // (.txt파일 전체 줄 갯수 - 재생된 휫수)만큼 반복
		fgets(fileread, sizeof(fileread), fp); // 결과적으로 마지막 링크에서 한칸 위 링크가 재생되게 됨
	}
	playcount++;

	if (fileread[0] == '\n') { //빈칸일때
		linkcheck_line_number--; //빈칸도 줄 수로 채웠을 것이므로 하나 마이너스
		playcount--; //빈칸이었기 때문에 플레이했다고 치치 않아야한다
		line_number--; //빈칸도 줄 수로 채웠을 것이므로 하나 마이너스
		rewind(fp); //라인 위치 초기화
		goto AGAIN;
	}


	sprintf_s(cache_Music1_2, sizeof(cache_Music1_2), "%s", CMD_Static_command_2);
	sprintf_s(cache_Music2_2, sizeof(cache_Music2_2), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_2, " ", &contact_2); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_2, sizeof(Musiclink_2), "%s %s", cache_Music1_2, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_2);


	rewind(fp);


	// WindowTitle 출력
	NowCount2++;

	WindowTitleNowcount = NowCount2;

	sprintf_s(WindowTitle2, sizeof(WindowTitle2), "%s Playing.. [%d/%d]", WindowTitleCMD2, WindowTitleNowcount, WindowtitleTotalcount);

	system(WindowTitle2);
	
}

void File_close2() { // .txt 파일 닫음
	playcount = 0; //재생휫수 초기화
	fclose(fp);
	NowCount2 = 0;
}

/* 발견한 버그
2번기능 한번 사용후 다시 2번기능 사용시 작동에러 발생

*/