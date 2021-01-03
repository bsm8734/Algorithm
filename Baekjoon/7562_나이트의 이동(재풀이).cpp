#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, N;
int cur_x, cur_y;
int target_x, target_y;
bool visit[301][301] = { false, };
queue<pair<int, int>> q;
int xy[8][2] = { {1, 2},{-1, 2},{1, -2},{-1, -2}, {2, 1},{-2, 1},{2, -1},{-2, -1} };

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = false;
	while (!q.empty()) q.pop();
}

int BFS() {
	int ret = 0;
	q.push({ cur_x, cur_y });
	visit[cur_x][cur_y] = true;

	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == target_x && y == target_y) return ret;

			for (int i = 0; i < 8; i++) {
				int x_ = x + xy[i][0];
				int y_ = y + xy[i][1];

				if (0 <= x_ && x_ < N && 0 <= y_ && y_ < N)
					if (visit[x_][y_] == false) {
						visit[x_][y_] = true;
						q.push({ x_, y_ });
					}
			}
		}
		ret++;
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N >> cur_x >> cur_y >> target_x >> target_y;
		init();
		cout << BFS() << '\n';
	}

	return 0;
}