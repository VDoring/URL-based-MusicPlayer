#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

#define MAX_COUNT line_number + 1
#define MIXING_COUNT line_number + 30

FILE *fp; // .txt파일 전용 파일포인터

/*
int Random;
int Play_Random_count = 0;
int save_random_number[10000] = { 0, };
void Save_RandomNum() { //랜덤 모드시 라인 넘버를 저장하는 함수. (중복으로 음악이 실행되는걸 방지하기 위함)
	save_random_number[Play_Random_count] = Random;
	Play_Random_count++;
}*/

/*int line_number;
int no_overlap_line_number = 0;
void random_num_array_save() { //중복없는 랜덤숫자를 line_number의 수만큼 뽐음
	extern void Random_Select();

	no_overlap_line_number = line_number; //line_number와 똑같은 밑의 for문에 사용할 새로운 변수 선언
	no_overlap_line_number++;

	Save_RandomNum();
	for (int i = 1; i < no_overlap_line_number; i++) {
		Random_Select();
		Save_RandomNum();
		for (int j = 0; j < i; j++) {
			if (save_random_number[i] == save_random_number[j]) {
				i--;
				Play_Random_count--;
				break;
			}
		}
	}
}*/


//999로 되어있는곳은 define인 MAX_COUNT가 들어가야함
int line_number;
int musiclist_arr[10000] = { 0, };
void No_overlap_random() { //순서대로 나열된 배열을 셔플 및 배열에 저장
	int i, swap_temp, x, y, z;

	srand((unsigned int)time(NULL));

	for (i = 0; i < MAX_COUNT; i++) musiclist_arr[i] = i + 1;

	for (i = 0; i < MIXING_COUNT; i++) {
		x = rand() % MAX_COUNT;
		y = rand() % MAX_COUNT;
		if (x != y) {
			swap_temp = musiclist_arr[x];
			musiclist_arr[x] = musiclist_arr[y];
			musiclist_arr[y] = swap_temp;
		}
	}
	z = rand() % MAX_COUNT;
	swap_temp = musiclist_arr[0];
	musiclist_arr[0] = musiclist_arr[z];
	musiclist_arr[z] = swap_temp;
}



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
void No_overlap_Musiclist_play() { //(음악중복재생 방지) 음악플레이
	fopen_s(&fp, "Mlist.txt", "rt");
	rewind(fp);
	

	for (int j = 0; j < musiclist_arr[arraynum_read]; j++) {
		fgets(fileread, sizeof(fileread), fp);
	}
	arraynum_read++;

	
	/*줄이 공백일경우
	while (1) {
		if (fileread[0] == '\n') {
			//이제 빈라인은 배열에 -1로 표기. -1인지 아닌지에 따라 음악플레이 여부가 달라짐

			save_random_number_arraynum_read--; //줄 57. 다음 읽기를 위해 미리 1을 더했으므로, 빈라인을 체크해야하는 특성상 현재는 마이너스를 해야한다. 이후 배열 블럭 값을 마이너스해 해당 배열 값을 한번더 읽게 한다
			txt_empty_lines_number_save[txt_empty_lines_number_save_loop_number] = save_random_number[save_random_number_arraynum_read]; //빈 라인의 줄 번호를 저장하는 배열 = (중복안되는)랜덤넘버를 저장하는 배열 (현재상태는 빈라인이 있는 줄 번호가 저장된 상태).
			Random_Select();
			for (int j = 0; j < save_random_number[save_random_number_arraynum_read]; j++) {
				fgets(fileread, sizeof(fileread), fp);
			}
			
			//Random_Select();
			//Save_RandomNum();
			

			if (save_random_number[save_random_number_arraynum_read] == txt_empty_lines_number_save[txt_empty_lines_number_save_loop_number]) {
				
			}
		}
	}*/

	sprintf_s(cache_Music1_4, sizeof(cache_Music1_4), "%s", CMD_Static_command_4);
	sprintf_s(cache_Music2_4, sizeof(cache_Music2_4), "%s", fileread);

	ptr_linkcut_result = strtok_s(cache_Music2_4, " ", &contact_4); // 한줄 읽은 내용을 띄어쓰기 기준으로 나누어 ptr_linkcut_result에 저장

	sprintf_s(Musiclink_4, sizeof(Musiclink_4), "%s %s", cache_Music1_4, ptr_linkcut_result); // 최종 음악재생 명령어

	system(Musiclink_4);

	fclose(fp);
}


void File_close4() { // .txt 파일 닫음
	arraynum_read = 0;

	for (int i = 0; i < 10000; i++) {
		musiclist_arr[i] = 0;
	}

	fclose(fp);
}