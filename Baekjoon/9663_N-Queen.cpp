#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int N, result = 0;
int map[20] = { 0 };

bool check(int i, int depth) {
	for (int j = 1; j <= N; j++) {
		if (i == j) continue;
		else if (map[j] == 0) continue;
		else if (abs(j - i) == abs(depth + 1 - map[j])) return false;
	}
	return true;
}

void func(int depth) {
	if (depth == N) {
		result++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (map[i] != 0) continue; // 25번째 줄과 26번째 줄의 순서가 바뀌면 시간초과
		if (check(i, depth) == false) continue;
		map[i] = depth + 1;
		func(depth + 1);
		map[i] = 0;
		
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		map[i] = 1;
		func(1);
		map[i] = 0;
	}

	cout << result << '\n';

	return 0;
}