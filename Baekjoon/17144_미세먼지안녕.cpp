#include <iostream>
#include <string.h>
using namespace std;

int N, M, T;
int map[51][51] = { 0 };
int machine[2];
int xy[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int result = 0;
int tmp_map[51][51] = { 0 };

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp_map[i][j] = 0;
}

void spread() {
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 4) { // 어차피 4이하는 확산되지도않음
				int amount_spread = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int x_ = i + xy[k][0];
					int y_ = j + xy[k][1];
					if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M) // 범위확인
						if (map[x_][y_] != -1) { // 공기청정기 위치 아님을 확인
							tmp_map[x_][y_] += amount_spread;
							map[i][j] -= amount_spread;
						}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] += tmp_map[i][j];
}

void cleaner() {
	// M1(x, y) (machine[0][0], machine[0][1])
	// M2(x, y) (machine[1][0], machine[1][1])

	for (int i = machine[0]; i > 0; i--)
		map[i][0] = map[i - 1][0];
	for (int i = machine[1]; i < N - 1; i++)
		map[i][0] = map[i + 1][0];

	for (int i = 0; i < M-1; i++) {
		map[0][i] = map[0][i + 1];
		map[N - 1][i] = map[N - 1][i + 1];
	}

	for (int i = 0; i < machine[0]; i++)
		map[i][M - 1] = map[i + 1][M - 1];
	for (int i = N - 1; i > machine[1]; i--)
		map[i][M - 1] = map[i - 1][M - 1];
	
	for (int i = M-1; i > 0; i--) {
		map[machine[0]][i] = map[machine[0]][i - 1];
		map[machine[1]][i] = map[machine[1]][i - 1];
	}

	map[machine[0]][0] = map[machine[1]][0] = -1;
	map[machine[0]][1] = map[machine[1]][1] = 0;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input & init
	int t = 0;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				machine[t] = i;
				t++;
			}
		}

	// process for T mins
	for (int t = 0; t < T; t++) {
		spread();
		cleaner();
	}

	// output
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			result += map[i][j];
	cout << result + 2 << '\n';

	return 0;
}