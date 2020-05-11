#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용

int line_number; // .txt파일 라인 수 저장
void dev_musiclist_line_read() { //txt파일 라인 수 카운트
	int line_count = 0;
	char tmp;

	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	while (fscanf_s(fp, "%c", &tmp, sizeof(tmp)) != EOF) { // .txt파일에 저장된 글자 하나하나 검사해 EOF인지 확인
		if (tmp == '\n')
			line_count++; //파일 줄 수 최초 저장
	}
	line_number = line_count; // 라인 수 임시 저장

	fclose(fp);
}

char fileread[4096]; // .txt파일 라인 읽기용
int dev_important_music_search(int link[]) { // -- 확인
	/*
	int array_length = 0; //링크가 저장된 가장 끝의 값을 구한다
	
	while (link[array_length] == '\0')
		array_length++;

	//!여기에 무언가 문제가 있음
	if ((link[array_length - 1] == '-') && (link[array_length] == '-')) return 1; //만약 -- 일경우
	else return -9; // --이 아닐경우
	*/

	char special_text[1000] = { 0, };

	char *ptr = strtok(fileread, " ");  // 먼저 " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

	
	while (1)
	{
		if (ptr == NULL) break; //만약 NULL이라면 종료

		//printf("%s\n", ptr); //<테스트코드> 동작확인
		strcpy(special_text, ptr); //--여부 확인위해 special로 문자열을 복사한다
		if (0 == strcmp(special_text, "--") || 0 == strcmp(special_text, "--\n")) break;
		
		ptr = strtok(NULL, " "); // 다음 문자열을 잘라서 포인터를 반환
	}

	//printf("%s", special); //<테스트코드> --여부 확인용

	/*
	if (special_text == "--\n") return 1; //--일떄
	else return -9; //-- 아닐떄
	*/

	if (0 == strcmp(special_text, "--") || 0 == strcmp(special_text, "--\n")) return 1; //--일떄
	else return -1; //-- 아닐떄

}

int music_number[10000] = { 0, }; //플레이가능한 링크의 줄 넘버를 저장
void dev_music_search() { // 전체 링크를 탐색해 --가 붙은 링크를 찾음
	int important_music_number = 0; // --표시된 링크였는지에 대한 여부를 저장

	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	line_number++;
	for (int i = 0; i < line_number; i++) {
		music_number[i] = i + 1; // 1 ~ (곡 수) 만큼 배열에 숫자 나열
	}

	for (int i = 0; i < line_number; i++) {
		fgets(fileread, sizeof(fileread), fp);

		important_music_number = dev_important_music_search(music_number); // -- 확인한 값을 important_music_number

		//if (fileread[0] == '\n') music_number[i] = -2; // 빈라인일경우 music_number 배열에 -2 표시
		if (important_music_number == -1) music_number[i] = -1; // --가 아닐경우나 공백일경우 music_number 배열에 -1 표시
		else if (important_music_number == 1) music_number[i] = 1; // --일경우 music_number 배열에 1 표시
	}

	//important_music_number = 0;
	rewind(fp);
	fclose(fp);
}

int first_music_play_count; //몇번째라인부터 첫곡을 시작하는지 저장.(i값을 저장)
char cache_Musiclink[8092] = { 0, }; //음악링크 전용
char *ptr_linkcut_result; // 라인의 가장 앞에있는 링크 저장(strtok함수의 값을 담음)
const char CMD_Static_command2[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 CMD 고정 명령어
char *contact2 = NULL; // cache_Music2 문자열에서 자른 나머지 문자열을 저장
char Musiclink5[8192] = { 0, }; // 최종 음악재생 문자열 저장(최종형식 : CMD명령어 + 링크)
void dev_music_play() { //음악 플레이
	int i;

	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);

	for (i = 0; i < line_number; i++) { //++i
		if (music_number[i] == 1) {
			fgets(fileread, sizeof(fileread), fp);
			first_music_play_count = i;
			break;
		}
		fgets(fileread, sizeof(fileread), fp);
	}

	sprintf_s(cache_Musiclink, sizeof(cache_Musiclink), "%s", fileread); // 음악 링크 저장

	ptr_linkcut_result = strtok_s(cache_Musiclink, " ", &contact2); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink5, sizeof(Musiclink5), "%s %s", CMD_Static_command2, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink5); //음악 재생


	//rewind(fp);
	//fclose(fp);
}

char temp1_fileread_save[4096];
char temp2_fileread_save[4096];
void dev_continue_music_play() { //(최초 이후)음악 플레이
	int *ptr_strtok;
	int i = first_music_play_count + 1;

	for (i; i < line_number; i++) {
		if (music_number[i] == 1) {
			fgets(fileread, sizeof(fileread), fp);
			break;
		}
		fgets(fileread, sizeof(fileread), fp);
	}

	/* 만약 읽을 music_number값이 0일경우 중단하는 코드 추가*/
	/*
	0. 먼저, temp2에 저장되있는게 있는지 확인한다. 있으면 temp1에 저장, 없으면 temp2에 저장
	1. fileread에 저장된 문자열을 먼저 temp2가 저장한다
	2. 링크 작동이후 다음 fileread값은 temp1가 저장한다
	3. temp2에 값이 저장됬는지 확인한다. temp2 값이 있으면 temp1랑 temp2이랑 문자열이 똑같은지 검사한다. temp2 값이 없으면 끝낸다.
	4. temp1과 temp2의 값이 같으면 dev_continue_music_play()함수를 종료하고 main.c에서도 프로그램을 종료하도록 한다.
	*/

	//strcpy(temp1_fileread_save, fileread);


	sprintf_s(cache_Musiclink, sizeof(cache_Musiclink), "%s", fileread); // 음악 링크 저장

	ptr_linkcut_result = strtok_s(cache_Musiclink, " ", &contact2); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink5, sizeof(Musiclink5), "%s %s", CMD_Static_command2, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink5); //음악 재생
}

void dev_file_close() {
	rewind(fp);
	fclose(fp);
	for (int i = 0; i < 10000; i++) music_number[i] = 0;
}