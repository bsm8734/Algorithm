#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
char map[101][101] = {'0'};
bool visit[101][101] = { false };
queue<pair<int, int>> q;
int xy[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int BFS() {
	int depth = 1;

	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == N - 1 && y == M - 1) return depth;

			for (int i = 0; i < 4; i++) {
				int x_ = x + xy[i][0];
				int y_ = y + xy[i][1];
				if(x_ >= 0 && y_ >= 0 && x_ < N && y_ < M)
					if (visit[x_][y_] == false && map[x_][y_] == '1') {
						q.push({ x_, y_ });
						visit[x_][y_] = true;
					}
			}

		}
		depth++;
	}

	return depth;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> map[i];

	// init
	q.push({ 0, 0 });
	visit[0][0] = true;

	// BFS
	cout << BFS() << '\n';

	return 0;
}