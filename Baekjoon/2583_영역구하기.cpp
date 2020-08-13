#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
bool map[101][101] = { false };
int xy[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int x_1, x_2, y_1, y_2;
queue<pair<int, int>> q;
vector<int> v;

int BFS(int start_x, int start_y) {
	q.push({ start_x, start_y });
	map[start_x][start_y] = true;
	int ret = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];
			
			if (x_ >= 0 && y_ >= 0 && x_ < N && y_ < M) {
				if (map[x_][y_] == false) {
					map[x_][y_] = true;
					q.push({ x_, y_ });
					ret++;
				}
			}
		}
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int a = x_1; a < x_2; a++)
			for (int b = y_1; b < y_2; b++)
				map[a][b] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == false) {
				v.push_back(BFS(i, j));
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (auto i : v) cout << i << " ";

	return 0;
}