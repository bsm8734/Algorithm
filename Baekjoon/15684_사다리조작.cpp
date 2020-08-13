#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// variable
int N, M, H;
int a, b;
int map[50][50] = { 0 };
int depth = 4;

// check right pair made
bool checker() {
	for (int i = 0; i < M; i++) {
		int ind = i;
		for (int j = 0; j < N; j++)
			ind = ind + map[j][ind];
		if (ind != i) return false;
	}
	return true;
}

// 재귀적으로 찾아가지고, 3개째 그었을때 바로 3을 리턴하면 틀림
// 1 > 2 > 3(찾음!) > 2(찾음!) > 1 상태일때, 결과는 2이어야함

// make all case (0~3)
void func(int t) { // t는 내가 추가할 다리의 갯수 번호

	if (t == 4) return;

	for (int i = 0; i < (M - 1) * N; i++) { // i: 추가하고자하는 사다리 번호(1차원)
		//  다리를 놓을 수 있는지 확인
		int x = i / (M - 1);
		int y = i % (M - 1);
		if (map[x][y] == 1 || map[x][y] == -1 || map[x][y + 1] == 1) continue;

		// 다리를 놓음
		map[x][y] = 1;
		map[x][y + 1] = -1;

		// 체크를 함
		if (checker() == true) {
			depth = t;
			map[x][y] = map[x][y + 1] = 0;
			return;
		}

		// +1 된 깊이에서 찾지 못했었다면, 더 들어가는 거임
		if(t + 1 < depth) func(t + 1);

		// 다리를 제거
		map[x][y] = map[x][y + 1] = 0;
	}

	return;
}

// main
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input & init
	cin >> M >> H >> N;
	for (int i = 0; i < H; i++) {
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = -1;
	}

	// check with no additional bridge
	if (checker() == true) {
		cout << '0' << '\n';
		return 0;
	}

	func(1);
	if (depth != 4) cout << depth << '\n';
	else cout << -1 << '\n';

	return 0;
}