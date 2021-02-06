#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int result = 0;
int visit[20] = { 0, };

bool checker(int T, int target) {
	for (int i = 0; i < T; i++) 
		if (visit[i] == target) return false;
	for (int i = 0; i < T; i++)
		if (abs(T - i) == abs(target - visit[i])) return false;
	return true;
}

void func(int T) {
	if (T == N) {
		result++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (checker(T, i) == false) continue; // (visit[T] = i) -> ok?
		visit[T] = i;
		func(T + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	func(0);

	cout << result;

	return 0;
}