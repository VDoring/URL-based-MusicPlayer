#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <tchar.h>
#include <string.h>


void File_Musiclist_Read() {

	FILE *fp; //파일포인터 선언
	char cache_read_1[1000] = { 0, }; //파일을 읽기 위한 일종의 캐시
	char cache_MusicFront[100] = { "start /max iexplore.exe" }; //cmd창에 고정적으로 입력할 문구

	char cache_Music1[1000] = { 0, };//고정적으로 입력할 부분을 담당하는 배열
	char cache_Music2[1000] = { 0, };//음악주소 저장을 담당하는 배열
	char Musiclink[1000] = { 0, }; //최종적인 음악재생 명령어


	fp = fopen("Mlist.txt", "rt"); //파일 열기
	fgets(cache_read_1, sizeof(cache_read_1), fp); //cache_read_1의 크기만큼 한줄을 읽는다.
	// puts(cache_read_1); Sleep(3000); //한줄 출력(테스트 코드)

	sprintf(cache_Music1, "%s", cache_MusicFront); //cache_MusicFront(고정적으로 입력할 문구)의 데이터를 cache_Music에 저장

	sprintf(cache_Music2, "%s", cache_read_1); //cache_read_1(음악 주소 저장)의 데이터를 cache_Music2에 저장

	sprintf(Musiclink, "%s %s", cache_Music1, cache_Music2);

	//system("start /max iexplore.exe"); //그냥 cache_read_1같은 변수는 입력 불가능. 또한 프라이빗 모드로 열 방법을 찾아야 함
	system(Musiclink);
	
	/* printf("%s", cache_Music); Sleep(500); //sprintf가 잘 동작하는지 확인(cache_read_1의 문자열이 cache_Music에 잘 저장되는지 확인) */

	fclose(fp);
}