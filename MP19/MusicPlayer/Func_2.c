#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

FILE *fp; // .txt파일 전용 파일포인터

int *line_num; // .txt파일 라인 수 임시저장
int line_number; // .txt파일 라인 수 저장
void Musiclist_line_Read() { // .txt파일 라인 수 카운팅

	fopen_s(&fp, "Mlist.txt", "rt");
	int line_count = 0;
	char tmp;

	while (fscanf_s(fp, "%c", &tmp, sizeof(tmp)) != EOF) { // .txt파일에 저장된 글자 하나하나 검사해 EOF인지 확인
		if (tmp == '\n')
			line_count++; // 파일 줄 수 최초 저장
	}
	line_num = &line_count;
	line_number = *line_num; // .txt파일 라인 수 최종 저장

	fclose(fp);

}

/* 앞으로의 계획
fseek를 사용하여 파일의 맨 끝으로 이동시킨다.
(맨끝으로 이동한다는게 글자에서의 끝인지, 라인에서의 끝줄인지 확인 필요)
(만약 맨끝이 글자에서의 끝이면 (그 마지막 줄의 첫 글자로 이동해)그 줄의 띄어쓰기 여부를 확인하여 링크만 읽을 수 있도록 만들어야한다)

한번 읽은 뒤론 반복문과 fseek를 사용해 읽은 곳에서 한칸식 위로 올라가도록 한다.

*/