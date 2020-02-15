#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	char str[101];
	cin >> str;
	int len = strlen(str);

	// alphabet: 26
	for (int i = 97; i < (97 + 26); i++)
	{
		bool exist = false;
		for (int j = 0; j < len; j++) {
			if ((int)str[j] == i) {
				cout << j << " ";
				exist = true; break;
			}
		}
		if (exist == false) cout << "-1 ";
	}

	return 0;
}