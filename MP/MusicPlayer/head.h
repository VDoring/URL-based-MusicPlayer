#ifndef __HEAD_H__
#define __HEAD_H__

FILE *fp; // .txt파일 전용 파일포인터
int main_input; // 메인화면 입력
int play_input; // 곡 재생모드 입력

/* GUI 관련 */
void mainGUI(); // 메인화면 GUI
void playmodeGUI(); // 음악재생모드 선택 GUI
void Question_Continue(); // 계속 도는 다음곡을 플레이할지 묻는 함수

/* 음악재생 공통 */
int play_continue_input; // 계속 음악 재생할지를 묻는 것에 대한 값 입력
int line_number; // .txt파일 라인 수 저장

/* 음악재생 - 1번 기능*/
void Musiclist_line_Read_1(); // .txt파일 라인 수 카운팅
void Musiclist_FirstPlay_1(); // 최초 음악 재생
void Musiclist_ContinuePlay_1(); // (최초 이후)음악 재생

/* 음악재생 - 2번 기능 */
void Musiclist_line_Read_2();
void Musiclist_FirstPlay_2();
void Musiclist_ContinuePlay_2();

/* main화면 2번 기능 */
void File_close(); // .txt 파일 닫음


#endif