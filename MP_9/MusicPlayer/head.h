#ifndef __HEAD_H__
#define __HEAD_H__
FILE *fp; //파일포인터 선언
int main_input; //메인화면에서 메뉴 선택시 사용
int play_input; //곡 재생모드 선택시 사용

/* GUI */
void Intro(); //실행시 화면 구성
void playmode(); //어떤 모드로 플레이할껀지 화면 구성

/* 1번 기능 */
void Musiclist_line_Read();
void Musiclist_Read();


/* 2번 기능 */
void File_close();

#endif
