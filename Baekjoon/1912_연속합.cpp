#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int map[100005][2] = { 0 };
// 0: 원래 자리의 수
// 1: 최대값(합, 본인포함)
// 2: 연속수(본인포함)

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i][0]; 
	
	map[0][1] = map[0][0];

	for (int i = 1; i < N; i++) {
		map[i][1] = max(map[i][0], map[i][0] + map[i - 1][1]);
	}

	int ret = map[0][1];
	for (int i = 1; i < N; i++)
		ret = max(ret, map[i][1]);
	cout << ret << '\n';

	return 0;
}