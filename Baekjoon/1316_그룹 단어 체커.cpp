#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;
	int result = num;
	string *str = new string[num];
	
	for (int i = 0; i < num; i++) {
		bool alpha[26] = { false }; //  a: 97 -> 0
		cin >> str[i];
		char before = str[i][0];

		for (int j = 0; j < str[i].length(); j++) {
			if (alpha[str[i][j] - 97] == true && str[i][j] != before) {
				result--;
				break;
			}
			else if (alpha[str[i][j] - 97] == false) {
				alpha[str[i][j] - 97] = true;
				before = str[i][j];
			}
		}
	}
	
	cout << result;

	return 0;
}