#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

		int result = 0;
		char dial[20];
		cin >> dial;

		for (int i = 0; i < strlen(dial); i++) {
			if (dial[i] - 65 < 18) result += ((dial[i] - 65) / 3 + 3);
			else if (dial[i] == 'S') result += 8;
			else if (strchr("TUV", dial[i]) != NULL) result += 9;
			else result += 10;
		}

		cout << result;
	
	return 0;
}