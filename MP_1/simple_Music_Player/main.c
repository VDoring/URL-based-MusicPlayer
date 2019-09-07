#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "head.h"

int main() {
	while (1) {
		Intro();
		if (input == 1) {
			File_Musiclist_Read();
		}
		else if (input == 2) {
			return 1;
		}
		else {
			printf("Please re-enter!"); Sleep(300);
		}
	}
}