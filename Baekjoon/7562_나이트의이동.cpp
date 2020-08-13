#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int T, N;
int xy[8][2] = { {2 ,1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, -2}, {-1, 2} };
bool visit[301][301] = { false };
queue<pair<int, int>> q;
int target_x, target_y;
int start_x, start_y;
int result = 0;

int BFS() {
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == target_x && y == target_y) return result;

			for (int i = 0; i < 8; i++) {
				int x_ = x + xy[i][0];
				int y_ = y + xy[i][1];
				if(x_>= 0 && y_ >= 0 && x_ < N && y_ < N)
					if (visit[x_][y_] == false) {
						visit[x_][y_] = true;
						q.push({ x_, y_ });
					}
			}
		}
		result++;
	}
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		// input
		cin >> N;
		cin >> start_x >> start_y >> target_x >> target_y;

		// init
		while (!q.empty()) q.pop();
		for (int i = 0; i < N; i++) memset(visit[i], false, sizeof(bool) * N);
		result = 0;

		// BFS
		q.push({ start_x, start_y });
		visit[start_x][start_y] = true;
		cout << BFS() << '\n';
	}

	return 0;
}
