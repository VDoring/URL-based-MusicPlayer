#ifndef __HEAD_H__
#define __HEAD_H__

FILE *fp; // .txt파일 전용 파일포인터
int main_input; // 메인화면 입력
int play_input; // 곡 재생모드 입력

/* GUI 관련 */
void mainGUI(); // 메인화면 GUI
void playmodeGUI(); // 음악재생모드 선택 GUI
void Question_Continue(); // 계속 도는 다음곡을 플레이할지 묻는 함수
void Random_mode(); //랜덤모드 선택

/* 음악재생 공통 */
int play_continue_input; // 계속 음악 재생할지를 묻는 것에 대한 값 입력
int line_number; // .txt파일 라인 수 저장
int play_random_mode_input;
void WinTitleTotal(); //빈라인을 제외한 총 라인 갯수를 센다.(윈도우타이틀 출력을 위한 함수)

/* 음악재생 - 1번 기능*/
void Musiclist_line_Read_1(); // .txt파일 라인 수 카운팅
void Musiclist_FirstPlay_1(); // 최초 음악 재생
void Musiclist_ContinuePlay_1(); // (최초 이후)음악 재생
void File_close(); // .txt 파일 닫기 및 윈도우타이틀 값 초기화

/* 음악재생 - 2번 기능 */
void Musiclist_line_Read_2();
void Musiclist_FirstPlay_2();
void Musiclist_ContinuePlay_2();
void File_close2();

/* 음악재생 - 3-1번(중복가능한 랜덤) 기능 */
void Musiclist_line_Read_3();
void Random_Select(); //랜덤한 수로 링크를 정한다
void Musiclist_Play(); //음악플레이

/* 음악재생 - 3-2번(중복제외 랜덤) 기능 */



/*
void Musiclist_FirstPlay_3();
void Musiclist_ContinuePlay_3();
*/

#endif