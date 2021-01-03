#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm> // 없으면 컴파일에러
using namespace std;

int N, M;
int arr[501][501] = { 0, };
vector<int> v;
queue<pair<int, int>> q;
int xy[4][2] = { {1, 0},{0, 1},{-1, 0},{0, -1} };

int BFS(int start_x, int start_y) {
	int ret = 1;
	q.push({ start_x, start_y });
	arr[start_x][start_y] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];

			if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M)
				if (arr[x_][y_] == 1) {
					arr[x_][y_] = 0;
					q.push({ x_, y_ });
					ret++;
				}
		}
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if(arr[i][j] == 1)
				v.push_back(BFS(i, j));
		}


	sort(v.begin(), v.end());
	if (v.size() == 0) cout << 0 << '\n' << 0; // 그림이 없는 경우, 벡터 범위를 벗어난 참조로 인하여 런타임에러
	else cout << v.size() << '\n' << v[v.size() - 1];

	return 0;
}