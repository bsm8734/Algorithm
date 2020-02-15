#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include <deque>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		string cmd;
		int len;
		string arr_str;
		cin >> cmd >> len >> arr_str;
		
		arr_str = arr_str.substr(1, arr_str.length() - 2);

		cout << arr_str << '\n';
		char* ch_arr = new char[arr_str.length() + 1];
		strcpy(ch_arr, arr_str.c_str());
		



	}

	return 0;
}