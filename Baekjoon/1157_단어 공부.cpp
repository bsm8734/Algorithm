#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string word;
	cin >> word;

	int max = 0;
	int iter = 0;
	bool repeat = false;

	unsigned short count[100] = { 0 };
	for (int i = 0; i < word.length(); i++) {
		// 0: 48, a:97, A:65
		// 대소문자를 가리지 않는 것을 감안
		unsigned short tmp = word[i];
		if (tmp < 97) count[tmp]++;
		else count[tmp - 32]++;
	}

	for (int i = 65; i < (65 + 26); i++) {
		if (max < count[i]) {
			iter = i;
			max = count[i];
			repeat = false;
		}
		else if (max == count[i]) repeat = true;
	}

	if (repeat == true) cout << "?";
	else cout << (char)iter;

	return 0;
}