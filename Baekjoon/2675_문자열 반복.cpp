#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int T = 0; T < num; T++) {
		int repeat = 0;
		char s[8] = { "" };
		cin >> repeat >> s;
		for (int i = 0; i < strlen(s); i++)
			for (int j = 0; j < repeat; j++)
				cout << s[i];
		cout << "\n";
	}

	return 0;
}