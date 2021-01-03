#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	string str;
	cin >> str;
	answer += str.length();

	for (auto i : str) {
		int c = i - 'A';

		if (c == 18 || c == 21 || c >= 24) (c /= 3)--;
		else c /= 3;
		answer += (c + 2);
	}

	cout << answer << '\n';
	
	return 0;
}
