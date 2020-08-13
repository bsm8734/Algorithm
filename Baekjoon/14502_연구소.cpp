#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int min_num = 100;
int wall_num = 0;
int xy[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int arr[10][10] = { 0 };
bool visit[10][10] = { false };
int vir_num = 0;
queue<pair<int, int>> q;
vector<pair<int, int>> virus, v;

int BFS() {
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];

			if (x_ >= 0 && y_ >= 0 && x_ < N && y_ < M)
				if (visit[x_][y_] == false && arr[x_][y_] != 1) {
					visit[x_][y_] = true;
					q.push({ x_, y_ });
					if (vir_num + cnt > min_num) return 100;
					cnt++;
				}
		}
	}
	return cnt;
}

int wall_maker(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	// init
	for (int i = 0; i < N; i++)
		memset(visit[i], false, sizeof(bool) * M);
	while (!q.empty()) q.pop();
	visit[a.first][a.second] = visit[b.first][b.second] = visit[c.first][c.second] = true;

	// BFS
	vir_num = 0;
	for (int i = 0; i < virus.size(); i++) {
		int vir_dir_x = virus[i].first;
		int vir_dir_y = virus[i].second;
		if (visit[vir_dir_x][vir_dir_y] == false) {
			q.push({ vir_dir_x, vir_dir_y });
			visit[vir_dir_x][vir_dir_y] = true;
			vir_num += BFS();
		}
		if (vir_num > min_num) return 100;
	}

	return vir_num;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// initialize
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) { // empty
				v.push_back({ i, j });
			}
			else if (arr[i][j] == 1) { // wall
				wall_num++;
			}
			else if (arr[i][j] == 2) { // virus
				virus.push_back({ i, j });
			}
		}
	wall_num += 3;

	// for all case:
	for (int a = 0; a < v.size(); a++)
		for (int b = a + 1; b < v.size(); b++)
			for (int c = b + 1; c < v.size(); c++) {
				min_num = min(wall_maker(v[a], v[b], v[c]), min_num);
			}

	cout << (N * M) - min_num - wall_num << '\n';

	return 0;
}