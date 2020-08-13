#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int M, N;
int arr[1001][1001] = { 0 };
bool visit[1001][1001] = { false };
int depth = 0;
queue<pair<int, int>> q, mat_tom;
int xy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];
			if (x_ >= 0 && y_ >= 0 && x_ < N && y_ < M)
				if (visit[x_][y_] == false) {
					if (arr[x_][y_] == 0 || arr[x_][y_] > arr[x][y] + 1) {
						arr[x_][y_] = arr[x][y] + 1;
						q.push({ x_, y_ });
					}
					visit[x_][y_] = true;
				}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ i, j });
		}
	}

	BFS();

	bool success = true;
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) success = false;
			else result = max(result, arr[i][j]);
		}
	}

	if (success == false) cout << -1 << '\n';
	else if (result == 1) cout << 0 << '\n';
	else cout << result - 1 << '\n';

	return 0;
}