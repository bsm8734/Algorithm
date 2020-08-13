#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int M, N, H;
int arr[101][101][101] = { 0 };
bool visit[101][101][101] = { false };
queue<pair<int, pair<int, int>>> q;
int xyz[6][3] = { {0, 0, 1}, {0, 1, 0}, {0, -1, 0}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0} };

void BFS() {
	while (!q.empty()) {
		int h = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		visit[h][x][y] = true;

		for (int i = 0; i < 6; i++) {
			int h_ = h + xyz[i][0];
			int x_ = x + xyz[i][1];
			int y_ = y + xyz[i][2];
			if (h_ >= 0 && h_ < H && x_ >= 0 && x_ < N && y_ >= 0 && y_ < M) {
				if (visit[h_][x_][y_] == false) {
					if (arr[h_][x_][y_] == 0 || arr[h_][x_][y_] > arr[h][x][y] + 1) {
						arr[h_][x_][y_] = arr[h][x][y] + 1;
						q.push({ h_, {x_, y_} });
					}
					visit[h_][x_][y_] = true;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) q.push({ i, {j, k} });
			}
		}
	}

	BFS();

	bool success = true;
	int result = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					success = false;
					cout << -1 << '\n';
					return 0;
				}
				else result = max(result, arr[i][j][k]);
			}
		}
	}
	cout << result - 1 << '\n';

	return 0;
}