#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용


int *line_num; // .txt파일 라인 수 (임시)저장
int line_number; // .txt파일 라인 수 저장

/* .txt파일 라인 수 카운팅 */
void Musiclist_line_Read_1() {
	fopen_s(&fp, "Mlist.txt", "rt");
	int line_count = 0;
	char tmp;

	while (fscanf_s(fp, "%c", &tmp, sizeof(tmp)) != EOF) { // .txt파일에 저장된 글자 하나하나 검사해 EOF인지 확인
		if (tmp == '\n')
			line_count++; //파일 줄 수 최초 저장
							//이 방식의 문제점:마지막 링크가 있는 줄은 카운트에 포함하지 않는다.
							//고로, WindowTitleTotal함수에서는 별도로 non_blank_line_number의 값을 1 더해주고 시작했다.
							//음악을 실행하는 부분에선 왜 잘 작동하는가?: line_number가 main.c에서 사용되기 전에 먼저 한번 재생되기 때문.
	}
	line_num = &line_count; // 라인 수 임시 저장
	line_number = *line_num; // 라인 수 최종 저장

	fclose(fp);
}


char fileread[4096]; // .txt파일 라인 읽기용
const char WindowTitleCMD[10] = { "title" }; // CMD 고정 명령어
int NowCount = 0; // 현재 실행한 휫수
int WindowTitleNowcount; // (윈도우타이틀 출력용)현재 재생한 휫수 저장
int WindowtitleTotalcount; // (윈도우타이틀 출력용)빈 라인을 제외한 .txt파일의 총 라인 수

/* .txt파일 총 라인수 계산 */
void WinTitleTotal() { //빈라인을 제외한 총 라인 갯수를 세는 함수(윈도우타이틀 출력을 위한 함수)
	int non_blank_line_number = line_number; // 빈라인 휫수 포함한 line_number의 값을 non_blank_line_number에 저장
	non_blank_line_number++; // (왜 1을 더했는진 22~24줄의 주석을 참고하세요)
	int non_blank_for = non_blank_line_number; // for문에 사용할 변수. 빈 라인 휫수가 포함되있는 상태

	fopen_s(&fp, "Mlist.txt", "rt");
	for (int n = 0; n < non_blank_for; n++) {  // .txt파일의 줄 수만큼 반복
		fgets(fileread, sizeof(fileread), fp);
		if (fileread[0] == '\n') { // 만약 빈 라인일때
			non_blank_line_number--; // 라인 수를 하나 뺀다.
		}
	}
	WindowtitleTotalcount = non_blank_line_number; //빈라인 카운팅이 없어진 non_blank_line_number를 윈도우타이틀 출력을 위한 변수인 WindowtitleTotalcount에 저장

	rewind(fp); //라인 위치 초기화
	fclose(fp);
}


char cache_Music1[100] = { 0, }; // CMD_Static_command(크롬 시크릿모드 실행 명령어)의 문자열을 저장
char cache_Music2[8092] = { 0, }; // fileread(.txt파일 라인 읽기)의 문자열을 저장
char *contact = NULL; // cache_Music2 문자열에서 자른 나머지 문자열을 저장
const char CMD_Static_command[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 CMD 고정 명령어
char Musiclink[8192] = { 0, }; // 최종 음악재생 문자열 저장(최종형식 : CMD명령어 + 링크)
char *ptr_linkcut_result; // 라인의 가장 앞에있는 링크 저장(strtok함수의 값을 담음)
char WindowTitle[110] = { 0, }; //최종 윈도우타이틀 문자열 저장

/* 최초 음악 실행 */
void  Musiclist_FirstPlay_1() { // 최초 음악 재생
	fopen_s(&fp, "Mlist.txt", "rt");

	fgets(fileread, sizeof(fileread), fp); // .txt파일 한줄을 읽어 fileread에 저장
	
	/* 첫 라인 공백 제거 & 공백라인 그 다음줄 링크 읽기 */
	while (1) {
		if (fileread[0] == '\n') { // 만약 .txt파일에서 읽은 한줄이 공백일경우
			fgets(fileread, sizeof(fileread), fp); // 그다음줄 링크 저장
			line_number--; // 빈칸을 줄수로 채웠을 것이므로 링크카운트 마이너스 1
		}
		else break; // 만약 공백이 아니라면 반복문 종료
	}

	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command); // CMD 고정 명령어 저장
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread); // 음악 링크 저장

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장
	
	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink); //음악 재생

	
	/* WindowTitle 출력 */
	NowCount++; //실행 휫수 +1
	
	WindowTitleNowcount = NowCount; //실행한 휫수를 WindowTitleNowcount(윈도우타이틀 출력용 변수)에 저장

	sprintf_s(WindowTitle, sizeof(WindowTitle), "%s Playing.. [%d/%d]", WindowTitleCMD, WindowTitleNowcount, WindowtitleTotalcount); // 각 문자 조합해 구문을 만들어 WindowTitle에 저장

	system(WindowTitle); //윈도우타이틀 출력
}

/* 두번째 이후부터의 음악재생 */
void Musiclist_ContinuePlay_1() {
	fgets(fileread, sizeof(fileread), fp);

	/* 첫 라인 공백 제거 & 공백라인 그 다음줄 링크 읽기 */
	while (1) {
		if (fileread[0] == '\n') { // 만약 .txt파일에서 읽은 한줄이 공백일경우
			fgets(fileread, sizeof(fileread), fp); // 그다음줄 링크 저장
			line_number--; // 빈칸을 줄수로 채웠을 것이므로 링크카운트 마이너스 1
		}
		else break; // 만약 공백이 아니라면 반복문 종료
	}

	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command); // CMD 고정 명령어 저장
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread); // 음악 링크 저장

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink); //음악 재생

	
	// WindowTitle 출력
	NowCount++; //실행 휫수 +1

	WindowTitleNowcount = NowCount; //실행한 휫수를 WindowTitleNowcount(윈도우타이틀 출력용 변수)에 저장

	sprintf_s(WindowTitle, sizeof(WindowTitle), "%s Playing.. [%d/%d]", WindowTitleCMD, WindowTitleNowcount, WindowtitleTotalcount); // 각 문자 조합해 구문을 만들어 WindowTitle에 저장

	system(WindowTitle); //윈도우타이틀 출력
}

/* 파일닫기 및 특정변수 초기화 */
void File_close() {
	fclose(fp);
	NowCount = 0;
}