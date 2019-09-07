#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


void File_Musiclist_Read() {

	FILE *fp; //파일포인터 선언
	char cache_read_1[1000] = { 0, }; //파일을 읽기 위한 일종의 캐시

	fp = fopen("Mlist.txt", "rt"); //파일 열기

	fgets(cache_read_1, sizeof(cache_read_1), fp); //cache_read_1의 크기만큼 한줄을 읽는다.
	puts(cache_read_1); //한줄 출력

	fclose(fp);
}