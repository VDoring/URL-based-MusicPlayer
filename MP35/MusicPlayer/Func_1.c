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
							//이 방식의 문제점:마지막 링크가 있는 줄은 카운트에 포함하지 않는다.
							//고로, WindowTitleTotal함수에서는 별도로 non_blank_line_number의 값을 1 더해주고 시작했다.
							//음악을 실행하는 부분에선 왜 잘 작동하는가?: 아마도 무한반복 함수
	}
	line_num = &line_count;
	line_number = *line_num; // .txt파일 라인 수 최종 저장

	fclose(fp);

}


char fileread[4096]; // .txt파일 한줄읽기용 문자열
const char WindowTitleCMD[10] = { "title" }; //CMD에 고정적으로 입력되는 명령어
int NowCount = 0; //현재 몇번 실행했는지를 담는 변수
int WindowTitleNowcount; //윈도우타이틀 출력용 Nowcount
int WindowtitleTotalcount; // 빈 라인을 제외한 .txt파일의 총 라인 수

void WinTitleTotal() {

	int non_blank_line_number = line_number; //이때는 빈 라인 휫수가 포함된 상태
	non_blank_line_number++; //line_number에서 마지막 링크는 카운트하지 않은 버그로 미리 1을 더함
							//이것은 어떤 상황이든 간에 공통으로 적용됨

	int non_blank_for = non_blank_line_number; //for문 조건식에 사용할 변수

	fopen_s(&fp, "Mlist.txt", "rt");

	for (int n = 0; n < non_blank_for; n++) {  /* .txt파일을 먼져 돌려 봄으로써 빈 라인 확인 */
		fgets(fileread, sizeof(fileread), fp);
		if (fileread[0] == '\n') {
			non_blank_line_number--;
		}
	}

	WindowtitleTotalcount = non_blank_line_number; //이때는 빈라인 휫수가 제거된 상태

	rewind(fp); //위치 초기화

	fclose(fp);

}


char cache_Music1[100] = { 0, };// 명령어 저장
char cache_Music2[8092] = { 0, };// fileread 문자열과 같은 역할
char *contact = NULL; //cache_Music2 문자열에서 자른 나머지 문자열을 저장
const char CMD_Static_command[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char Musiclink[8192] = { 0, }; // 최종 음악재생 명령어
char *ptr_linkcut_result; // 오직 링크만 저장
char WindowTitle[110] = { 0, }; //최종 아티틀 명령어

void  Musiclist_FirstPlay_1() { // 최초 음악 재생

	fopen_s(&fp, "Mlist.txt", "rt");

	fgets(fileread, sizeof(fileread), fp); // .txt파일 한줄을 읽어 fileread에 저장
	
	while (1) {
		if (fileread[0] == '\n') { //만약 .txt파일중간에 줄이 띄워져 있을경우
			fgets(fileread, sizeof(fileread), fp); //다음 링크 재생
			line_number--; //빈칸도 줄수로 채웠을 것이므로 하나 마이너스
		}
		else break;
	}

	sprintf_s(cache_Music1, sizeof(cache_Music1), "%s", CMD_Static_command); // CMD_Static_command = cache_Music1 , 명령어 저장
	sprintf_s(cache_Music2, sizeof(cache_Music2), "%s", fileread); // fileread = cache_Music2 , 음악 링크 저장

	ptr_linkcut_result = strtok_s(cache_Music2, " ", &contact); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장
	
	sprintf_s(Musiclink, sizeof(Musiclink), "%s %s", cache_Music1, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink);

	
	// WindowTitle 출력
	NowCount++;
	
	WindowTitleNowcount = NowCount;

	sprintf_s(WindowTitle, sizeof(WindowTitle), "%s Playing.. [%d/%d]", WindowTitleCMD, WindowTitleNowcount, WindowtitleTotalcount);

	system(WindowTitle);
	

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

	
	// WindowTitle 출력
	NowCount++;

	WindowTitleNowcount = NowCount;

	sprintf_s(WindowTitle, sizeof(WindowTitle), "%s Playing.. [%d/%d]", WindowTitleCMD, WindowTitleNowcount, WindowtitleTotalcount);

	system(WindowTitle);
	

}

void File_close() { // .txt 파일 닫음
	fclose(fp);
	NowCount = 0;
}