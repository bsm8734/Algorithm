#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// #include <string>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char str[1000001];
	cin.getline(str, 1000001);
	char *ptr = strtok(str, " ");
	int cnt = 0;

	while (ptr != NULL) {
		cnt++;
		// cout << ptr << "\n";
		ptr = strtok(NULL, " ");
	}

	cout << cnt;
	return 0;
}