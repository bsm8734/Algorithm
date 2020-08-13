#include <iostream>
#include <string.h>
using namespace std;

int N;
int map[100001][3] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	map[0][0] = map[0][1] = map[0][2] = 1;
	for (int i = 1; i < N; i++) {
		map[i][0] = (map[i - 1][0] + map[i - 1][1] + map[i - 1][2]) % 9901;
		map[i][1] = (map[i - 1][0] + map[i - 1][2]) % 9901;
		map[i][2] = (map[i - 1][0] + map[i - 1][1]) % 9901;
	}

	int result = map[N - 1][0] + map[N - 1][1] + map[N - 1][2];
	cout << result % 9901 << '\n';

	return 0;
}