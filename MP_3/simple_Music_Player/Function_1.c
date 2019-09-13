#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; //파일포인터 선언

void Musiclist_Read() {

	char fileread[4096]; //파일을 읽기 위한 일종의 캐시
	const char CMD_Static_command[100] = { "start /max iexplore.exe" }; //cmd창에 고정적으로 입력할 문구

	char cache_Music1[100] = { 0, };//고정적으로 입력할 부분을 담당하는 배열
	char cache_Music2[8000] = { 0, };//음악주소 저장을 담당하는 배열
	char Musiclink[8192] = { 0, }; //최종적인 음악재생 명령어

	fp = fopen("Mlist.txt", "rt"); //파일 열기
	fgets(fileread, sizeof(fileread), fp); //cache_read_1의 크기만큼 한줄을 읽는다.

	sprintf(cache_Music1, "%s", CMD_Static_command); //cache_MusicFront(고정적으로 입력할 문구)의 데이터를 cache_Music에 저장
	sprintf(cache_Music2, "%s", fileread); //cache_read_1(음악 주소 저장)의 데이터를 cache_Music2에 저장
	sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2); //cache_Music1와 cache_Music2를 합친 최종적인 음악재생 명령어

	system(Musiclink);


	for (int i = 0; i < 2; i++) { //이제 i를 파일에 있는 줄 수를 읽은걸 넣어야함
		Sleep(500);
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