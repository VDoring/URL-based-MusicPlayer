#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

#define MAX_COUNT line_number + 1
#define MIXING_COUNT line_number + 31

FILE *fp; // .txt파일 전용 파일포인터


int line_number;
int musiclist_arr[10000] = { 0, };
void No_overlap_random() { //순서대로 나열된 배열을 셔플 및 배열에 저장
	int i, swap_temp, x, y, z1, z2;

	srand((unsigned int)time(NULL));

	for (i = 0; i < MAX_COUNT; i++) musiclist_arr[i] = i + 1; //1 ~ 라인 수만큼 배열에 수 나열

	for (i = 0; i < MIXING_COUNT; i++) { //배열에 나열된 수를 셔플한다.
		x = rand() % MAX_COUNT; //랜덤수 x
		y = rand() % MAX_COUNT; //랜덤수 y
		if (x != y) {
			swap_temp = musiclist_arr[x];
			musiclist_arr[x] = musiclist_arr[y];
			musiclist_arr[y] = swap_temp;
		}
	}
	//(위의 코드만으론 musiclist_arr[0]배열의 값이 섞이지 않는 문제가 있어서 따로 코드를 적는다.
	z1 = rand() % MAX_COUNT; //랜덤수 z1
	z2 = rand() % MAX_COUNT; //랜덤수 z2
	swap_temp = musiclist_arr[0];
	musiclist_arr[0] = musiclist_arr[z1];
	musiclist_arr[z1] = swap_temp;

	//(바로 위의 코드만 적용하면 txt파일 첫 라인의 링크가 
	swap_temp = musiclist_arr[z1];
	musiclist_arr[z1] = musiclist_arr[z2];
	musiclist_arr[z2] = swap_temp;
}


const char WindowTitleCMD4[10] = { "title" }; //CMD에 고정적으로 입력되는 명령어
int NowCount4 = 0; //현재 몇번 실행했는지를 담는 변수
int WindowTitleNowcount; //윈도우타이틀 출력용 Nowcount2
int WindowtitleTotalcount; // 빈 라인을 제외한 .txt파일의 총 라인 수

int empty_line_check_2 = 0; //빈라인 체크를 했는지 확인하는 변수. 0과 1로 구분
int arraynum_read = 0; //save_random_number 배열의 값을 읽기위한 숫자를 저장
char fileread[4096]; // .txt파일 한줄읽기용 문자열
int txt_empty_lines_number_save[10000] = { 0, }; //빈라인의 배열 블럭 번호를 저장
int txt_empty_lines_number_save_loop_number = 0; //txt_empty_lines_number_save 배열 전용 크기
const char CMD_Static_command_4[100] = { "start chrome --incognito" }; // 크롬 시크릿모드 실행 명령어
char cache_Music1_4[100];
char cache_Music2_4[8092];
char *ptr_linkcut_result;
char *contact_4 = NULL; //cache_Music2_2 문자열에서 자른 나머지 문자열을 저장
char Musiclink_4[8192] = { 0, }; // 최종 음악재생 명령어
char WindowTitle4[110] = { 0, }; //최종 아티틀 명령어
void No_overlap_Musiclist_play() { //(음악중복재생 방지) 음악플레이
	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);
	
	//배열에 있는 번호를 먼저 체크. 빈라인은 배열값에서 0으로 만들어 미리 line_number값을 빼도록 한다.
	if (empty_line_check_2 == 0) { //빈라인 체크가 처음일때만 실행
		empty_line_check_2++;
		while (1) {
			for (int j = 0; j < musiclist_arr[arraynum_read]; j++) {
				fgets(fileread, sizeof(fileread), fp);
			}

			if (fileread[0] == '\n') { //해당숫자가 빈라인일때
				musiclist_arr[arraynum_read] = -1; //-1을 저장함으로써 빈라인 구분
				line_number--; //줄 수에서도 마이너스
			}
			else if (musiclist_arr[arraynum_read] == 0) { //곡을 다 검사했을때
				arraynum_read = 0;
				WindowtitleTotalcount = line_number + 1; //윈도우타이틀 최대곡수 출력위한 값 복사
				break;
			}
			arraynum_read++;
			fileread[0] = 'x'; //만약 musiclist_arr의 마지막 배열칸을 읽은게 '\n'일경우 68번 줄이 실행되어 끝나지 않는 오류가 생기기 때문에 x라는 임의의 값을 넣는다.
			rewind(fp);
		}
	}

	while (1) {
		if (musiclist_arr[arraynum_read] == -1) { //빈 라인일경우
			arraynum_read++; //다음 배열칸으로 넘어감
			continue;
		}

		for (int j = 0; j < musiclist_arr[arraynum_read]; j++) {
			fgets(fileread, sizeof(fileread), fp);
		}
		break;
	}

	sprintf_s(cache_Music1_4, sizeof(cache_Music1_4), "%s", CMD_Static_command_4);
	sprintf_s(cache_Music2_4, sizeof(cache_Music2_4), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_4, " ", &contact_4); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_4, sizeof(Musiclink_4), "%s %s", cache_Music1_4, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_4);

	arraynum_read++;

	fclose(fp);


	// WindowTitle 출력
	NowCount4++;

	WindowTitleNowcount = NowCount4;

	sprintf_s(WindowTitle4, sizeof(WindowTitle4), "%s Playing.. [%d/%d]", WindowTitleCMD4, WindowTitleNowcount, WindowtitleTotalcount);

	system(WindowTitle4);
}


void File_close4() { // .txt 파일 닫음
	arraynum_read = 0;
	empty_line_check_2 = 0;

	for (int i = 0; i < 10000; i++) {
		musiclist_arr[i] = 0;
	}

	fclose(fp);

	NowCount4 = 0;
}