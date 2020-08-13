#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int map[20][3] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i][0] >> map[i][1];
		if (map[i][0] + i > N) {
			map[i][0] = 1;
			map[i][1] = 0;
		}
	}

	map[N - 1][2] = map[N - 1][1];

	for (int i = N - 2; i >= 0; i--) {
		map[i][2] = max(map[i + map[i][0]][2] + map[i][1], map[i + 1][2]); // 현재_선택, 현재_미선택
	}
	cout << map[0][2] << '\n';


	return 0;
}