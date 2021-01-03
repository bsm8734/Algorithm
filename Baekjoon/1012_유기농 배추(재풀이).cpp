#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int T, N, M, K;
int a, b;
bool visit[64][64] = { false , };
int result = 0;
queue<pair<int, int>> q;
int xy[4][2] = { {1, 0},{0, 1},{-1, 0},{0, -1} };

void init() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visit[i][j] = false;
	result = 0;
	while (!q.empty()) q.pop();
}

void BFS(int start_x, int start_y) {
	q.push({ start_x, start_y });
	visit[start_x][start_y] = false;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];

			if(0 <= x_ && x_ < N && 0 <= y_ && y_ < M)
				if (visit[x_][y_] == true) {
					q.push({ x_, y_ });
					visit[x_][y_] = false;
				}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			visit[a][b] = true;
		}

		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (visit[i][j] == true) {
					BFS(i, j);
					result++;
				}
			}

		cout << result << '\n';
	}

	return 0;
}