#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

//공통으로 샤용(전역변수)
FILE *fp; //파일포인터 선언

int *line_num;
int line_number;
// int liner;
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

void Musiclist_processCPUTIME_Read() {
	/* 일단 tasklist /V하면 나오는 순서들 그대로 변수를 만듬 */
	char ImageName[30];
	char PID[10];
	char Session[10];
	char memUse[30];
	char Status[10];
	char UserName[100];
	char CPUTime[10] = { 0, }; //실질적으로 사용할 변수
	char WindowTitle[100];

	//먼저 CMD에서 tasklist /V /FI "IMAGENAME eq chrome.exe"를 실행한 데이터를 txt파일로 저장하게 한다.
	// CMD에서 출력된 내용들 파일로 저장하는 방법 : https://www.google.com/search?q=cmd+%EB%82%B4%EC%9A%A9+%EC%A0%80%EC%9E%A5&sa=X&ved=2ahUKEwjzsvPIve7kAhWCGqYKHTXVDOwQ1QIoB3oECAoQCA&biw=1372&bih=818

	// 이후 내용은 이것 참조(동영상 확인하기) : https://dojang.io/mod/page/view.php?id=608


	/* 위의것이 모두 완료되었을때를 위한 샘플 코드
	FILE *fp2 = fopen("CPUTIME.txt", "r");
	fscanf(fp2, "%s %s %s %s %s %s %s %s", ImageName, PID, Session, memUse, Status, UserName, CPUTime, WindowTitle);
	//이제 CPUTime의 값을 추후 Musiclist_Read에서도 쓸수 있게 해야함
	fclose(fp2);
	*/

}

void Musiclist_Read() {

	char fileread[4096]; //파일을 읽기 위한 일종의 캐시
	//const char CMD_Static_command[100] = { "start /max iexplore.exe" }; //기존 인터넷 익스플로러로 실행
	const char CMD_Static_command[100] = { "start chrome --incognito" }; //cmd창에 고정적으로 입력할 문구, 크롬 시크릿모드로 실행
	char cache_Music1[100] = { 0, };//고정적으로 입력할 부분을 담당하는 배열
	char cache_Music2[8092] = { 0, };//음악주소 저장을 담당하는 배열
	char Musiclink[8192] = { 0, }; //최종적인 음악재생 명령어

	fp = fopen("Mlist.txt", "rt"); //파일 열기
	fgets(fileread, sizeof(fileread), fp); //cache_read_1의 크기만큼 한줄을 읽는다.

	sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(고정적으로 입력할 문구)의 데이터를 cache_Music에 저장
	sprintf(cache_Music2, "%s", fileread); //cache_read_1(음악 주소 저장)의 데이터를 cache_Music2에 저장
	sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2); //cache_Music1와 cache_Music2를 합친 최종적인 음악재생 명령어

	system(Musiclink);


	// memcpy(liner, *line_num, sizeof(line_num));
	// line_num을 liner로 복사한 값을 밑에 for문 멈춤조건에 넣으면 안되나? 왜 작동안되지?


	for (int i = 0; i < line_number - 1; i++) { //이제 i를 파일에 있는 줄 수를 읽은걸 넣어야함
		//개발중인 구문 시작
		Sleep(15000);
		/*
		char ChromeEXIT[100] = { "taskkill /F /IM chrome.exe" }; //크롬 자체를 종료하기때문에 다른것을 사용해야함
		system(ChromeEXIT);
		Sleep(3000);
		*/
		//개발중인 구문 끝


		fgets(fileread, sizeof(fileread), fp); //cache_read_1의 크기만큼 한줄을 읽는다.

		sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(고정적으로 입력할 문구)의 데이터를 cache_Music에 저장
		sprintf(cache_Music2, "%s", fileread); //cache_read_1(음악 주소 저장)의 데이터를 cache_Music2에 저장
		sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2); //cache_Music1와 cache_Music2를 합친 최종적인 음악재생 명령어

		system(Musiclink);

		Sleep(500);

	}

}

void File_close() {
	fclose(fp);
}