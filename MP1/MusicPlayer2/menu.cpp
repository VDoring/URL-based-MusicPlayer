// VDoring made //

/*목표
1. 밑에서 위로 -- 만 재생모드 추가.
2. (여유가 있다면) 랜덤선택 알고리즘 개선
*/
#include <iostream>
#include "CUI.h"
#include "Func.h"

using namespace std;

int main() {
	int menu_input;

	cout << "URL Based Player" << endl << endl;
	cout << "[ Play Mode ]" << endl << endl;
	cout << "1. Top -> Bottom" << endl;
	cout << "2. Bottom -> Top" << endl;
	cout << "3. Random Overlap" << endl;
	cout << "4. Random No Overlap" << endl;
	cout << "5. Advance" << endl;

	cin >> menu_input;

	switch (menu_input)
	{
	case 1:
		TopToBottom();
		break;
	case 2:
		BottomToTop();
		break;
	case 3:
		RandomOverlap();
		break;
	case 4:
		RandomNoOverlap();
		break;
	case 5:
		Advance();
		break;
	default:
		cout << "Try Again." << endl;
		break;
	}

	return 0;
}