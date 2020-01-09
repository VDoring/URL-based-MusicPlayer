#ifndef __HEAD_H__
#define __HEAD_H__

FILE *fp; // .txt파일 전용 파일포인터
int main_input; // 메인화면 CUI용 입력용 변수
int play_input; // 곡 재생모드 CUI용 입력용 변수

/* GUI(인터페이스) 관련 */
void mainGUI(); // 메인화면 GUI
void playmodeGUI(); // 재생 모드 선택 CUI
void Question_Continue(); //다음 곡 재생할껀지 묻는 CUI
void Random_mode(); //랜덤모드 선택 CUI
void No_overlap_Qusetion_Continue(); //(중복재생금지모드 전용)다음 곡 재생할껀지 물는 CUI

/* 음악재생 공통 */
int play_continue_input; // 다음 곡 재생할껀지 묻는 CUI용 입력용 변수
int line_number; // .txt파일 라인 수 저장
int play_random_mode_input;
void WinTitleTotal(); //빈라인을 제외한 총 라인 갯수를 세는 함수(윈도우타이틀 출력을 위한 함수)

/* 음악재생 - 1번 기능*/
void Musiclist_line_Read_1(); // .txt파일 라인 수 카운팅
void Musiclist_FirstPlay_1(); // 최초 음악 재생
void Musiclist_ContinuePlay_1(); // (최초 이후)음악 재생
void File_close(); // .txt 파일 닫기 및 윈도우타이틀 값 초기화

/* 음악재생 - 2번 기능 */
void Musiclist_line_Read_2(); // .txt파일 라인 수 카운팅
void Musiclist_FirstPlay_2(); // 최초 음악 재생
void Musiclist_ContinuePlay_2(); // (최초 이후)음악 재생
void File_close2(); // .txt 파일 닫기 및 윈도우타이틀 값 초기화

/* 음악재생 - 3번(중복가능한 랜덤) 기능 */
void Musiclist_line_Read_3(); // .txt파일 라인 수 카운팅
void Random_Select(); // 랜덤한 수를 기반으로 재생할 링크를 정하는 함수
void Musiclist_Play(); // 음악 재생
void File_Close3(); // .txt 파일 닫기, 윈도우타이틀 값 초기화 및 일회용 변수 초기화

/* 음악재생 - 4번(중복제외 랜덤) 기능 */
int play_no_overlap_continue_input; //(중복재생금지모드 전용)다음 곡 재생할껀지에 대한 값 입력
//void Save_RandomNum(); //랜덤 모드시 라인 넘버를 저장하는 함수. (중복으로 음악이 실행되는걸 방지하기 위함)
//void random_num_array_save(); //중복없는 랜덤숫자를 linecount의 수만큼 뽐음
void No_overlap_random(); //순서대로 나열된 배열을 셔플 및 배열에 저장
void No_overlap_Musiclist_play(); //(음악중복재생 방지) 음악플레이
void File_close4(); // .txt 파일 닫기 및 윈도우타이틀 값 초기화

#endif