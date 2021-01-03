#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// var
int N, M;
bool visit[125][125] = { false, };
string s;
queue<pair<int, int>> q;
int result = 0;
int xy[4][2] = { {1, 0},{0, 1},{-1, 0},{0, -1} };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++)
			if (s[j] == '1') visit[i][j] = true;
	}

	// bfs
	q.push({ 0, 0 });
	visit[0][0] = false;
	
	int cnt = 0;
	while (!q.empty()) {
		int q_size = q.size();
		cnt++;
		for (int t = 0; t < q_size; t++) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			if ((cur_x == N - 1) && (cur_y == M - 1)) result = cnt;

			for (int i = 0; i < 4; i++) {
				int x = cur_x + xy[i][0];
				int y = cur_y + xy[i][1];

				if (0 <= x && x < N && 0 <= y && y < M)
					if (visit[x][y] == true) {
						q.push({ x, y });
						visit[x][y] = false;
					}

			}
		}
	}

	cout << result;

	return 0;
}