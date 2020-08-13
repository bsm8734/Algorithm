#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int T, N, M, K;
int xy[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
int map[51][51] = { 0 };
queue<pair<int, int>> q;
queue<pair<int, int>> start_q;
int a, b;
int cnt = 0;

void BFS(int x, int y) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];
			if(x_ >= 0 && y_ >= 0 && x_ < N && y_ < M)
				if (map[x_][y_] == 1) {
					map[x_][y_] = 0;
					q.push({ x_, y_ });
				}
		}
	}
}

int main(void) {
	cin >> T;
	while (T--) {
		// init
		cin >> N >> M >> K;
		cnt = 0;
		while (!q.empty()) q.pop();
		while (!start_q.empty()) start_q.pop();
		for (int i = 0; i < N; i++) 
			memset(map[i], 0, sizeof(int) * M);
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			map[a][b] = 1;
			start_q.push({ a, b });
		}

		// BFS
		while (!start_q.empty()) {
			int tmp_x = start_q.front().first;
			int tmp_y = start_q.front().second;
			start_q.pop();
			if (map[tmp_x][tmp_y] == 1) {
				map[tmp_x][tmp_y] = 0;
				q.push({ tmp_x, tmp_y });
				cnt++;
				BFS(tmp_x, tmp_y);
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}