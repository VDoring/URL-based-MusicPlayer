#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; //파일포인터 선언

int *line_num;
int line_number;
void Musiclist_line_Read() {

	fp = fopen("Mlist.txt", "rt"); //파일 열기
	int line_count = 1;
	char tmp;
	while (fscanf(fp, "%c", &tmp) != EOF) {
		if (tmp == '\n')
			line_count++;
	}
	line_num = &line_count; //line_count(링크 수) 잘 저장됨.
							//하지만 다른 함수로 넘어갈때 line_num의 값이 이상하게 변하는 문제가 발생
	line_number = *line_num;
	fclose(fp);
	// https://security-nanglam.tistory.com/m/166?category=814722
	// Studylog프로젝트에 txt_line_count
	//테스트는 testerz프로젝트에 fgets_interesting

}


char fileread[4096]; //파일을 읽기 위한 일종의 캐시
char cache_Music1[100] = { 0, };//고정적으로 입력할 부분을 담당하는 배열
char cache_Music2[8092] = { 0, };//음악주소 저장을 담당하는 배열
//const char CMD_Static_command[100] = { "start /max iexplore.exe" }; //기존 인터넷 익스플로러로 실행
const char CMD_Static_command[100] = { "start chrome --incognito" }; //cmd창에 고정적으로 입력할 문구, 크롬 시크릿모드로 실행
char Musiclink[8192] = { 0, }; //최종적인 음악재생 명령어
char *ptr_linkcut;

void  Musiclist_FirstPlay() {

	fp = fopen("Mlist.txt", "rt"); //파일 열기
	fgets(fileread, sizeof(fileread), fp); //cache_read_1의 크기만큼 한줄을 읽는다.

	sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(고정적으로 입력할 문구)의 데이터를 cache_Music에 저장
	sprintf(cache_Music2, "%s", fileread); //cache_read_1(음악 주소 저장)의 데이터를 cache_Music2에 저장

	ptr_linkcut = strtok(cache_Music2, " ");

	sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut); //cache_Music1와 cache_Music2를 합친 최종적인 음악재생 명령어

	system(Musiclink);


	// memcpy(liner, *line_num, sizeof(line_num));
	// line_num을 liner로 복사한 값을 밑에 for문 멈춤조건에 넣으면 안되나? 왜 작동안되지?

	/*
	for (int i = 0; i < line_number - 1; i++) { //이제 i를 파일에 있는 줄 수를 읽은걸 넣어야함
		Sleep(300);
		fgets(fileread, sizeof(fileread), fp); //cache_read_1의 크기만큼 한줄을 읽는다.

		sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(고정적으로 입력할 문구)의 데이터를 cache_Music에 저장
		sprintf(cache_Music2, "%s", fileread); //cache_read_1(음악 주소 저장)의 데이터를 cache_Music2에 저장
		
		ptr_linkcut = strtok(cache_Music2, " ");

		sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut); //cache_Music1와 cache_Music2를 합친 최종적인 음악재생 명령어

		system(Musiclink); // 여기서의 Musiclink의 링크가 https가 아닌 )ttps로 저장되어 작동불가

		Sleep(300);

	}
	*/

}


void Musiclist_ContinuePlay() {
	
	for (int i = 0; i < line_number - 1; i++) { //이제 i를 파일에 있는 줄 수를 읽은걸 넣어야함
		Sleep(300);
		fgets(fileread, sizeof(fileread), fp); //cache_read_1의 크기만큼 한줄을 읽는다.

		sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(고정적으로 입력할 문구)의 데이터를 cache_Music에 저장
		sprintf(cache_Music2, "%s", fileread); //cache_read_1(음악 주소 저장)의 데이터를 cache_Music2에 저장

		ptr_linkcut = strtok(cache_Music2, " ");

		sprintf(Musiclink, "%s %s", cache_Music1, ptr_linkcut); //cache_Music1와 cache_Music2를 합친 최종적인 음악재생 명령어

		system(Musiclink); // 여기서의 Musiclink의 링크가 https가 아닌 )ttps로 저장되어 작동불가

		Sleep(300);

	}
	
	// 배열 포인터 참고자료
	// https://dojang.io/mod/page/view.php?id=300
}

void File_close() {
	fclose(fp);
}