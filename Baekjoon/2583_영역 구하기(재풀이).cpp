#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
int x_1, x_2, y_1, y_2;
queue<pair<int, int>> q;
vector<int> v;
bool arr[102][102] = { false, };
int result = 0;
int xy[4][2] = { {0, 1},{1, 0},{-1,0},{0,-1} };

int BFS(int start_x, int start_y) {
	int ret = 1;
	q.push({ start_x, start_y });
	arr[start_x][start_y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];

			if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M)
				if (arr[x_][y_] == false) {
					arr[x_][y_] = true;
					ret++;
					q.push({ x_, y_ });
				}
		}
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> y_1 >> x_1 >> y_2 >> x_2;
		for (int i = x_1; i < x_2; i++)
			for (int j = y_1; j < y_2; j++)
				arr[i][j] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == false) {
				v.push_back(BFS(i, j));
				result++;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << result << '\n';
	for (auto i : v) cout << i << ' ';

	return 0;
}