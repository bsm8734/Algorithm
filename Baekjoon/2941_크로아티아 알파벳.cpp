#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// 대상 문자열을 찾으면 바로 바꾸어 주는 것이 아니라
// special _word라는 변수를 통해 갯수만 세어주고
// 나중에 전체 문자 길이에서 빼준다.
// 예외 key : c-dz=d- 와 dz=dz=


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string dict[7] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
	string input;
	cin >> input;

	int special_word = 0;
	int result = input.length();

	input += "aaa";
	size_t pos1 = input.find("dz=");
	
	while (pos1 != string::npos) {
		input.replace(pos1, 2, "||"); // 아무런 연관이 없는 문자를 넣어줌
		// 아래처럼 하면 앞뒤 단어가 붙으면서 새로운 special word 생성
		// input.erase(pos1, pos1 + 2); 
		special_word += 2;
		pos1 = input.find("dz=");
	}

	for (int i = 0; i < 7; i++) {
		size_t pos = input.find(dict[i]);
		while (pos != string::npos) {
			special_word++;
			pos = input.find(dict[i], pos + 1);
		}
	}

	cout << result - special_word;

	return 0;
}