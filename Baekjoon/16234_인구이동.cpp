#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int xy[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int N, L, R;
int arr[52][52] = { 0, };
int visit[52][52] = {0, };
int result = 0;

queue <pair<int, int>> q;

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
}

void unit_calculate(int c) {
	int count = 0; int sum_of_union = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (visit[i][j] == c) {
				count++;
				sum_of_union += arr[i][j];
			}

	int avg = sum_of_union / count;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			if(visit[i][j] == c)
				arr[i][j] = avg;
}

bool in_range(int p1, int p2) {
	int p = abs(p1 - p2);
	if (L <= p && p <= R) return true;
	else return false;
}

int BFS(int c, int start_x, int start_y) { // 방문한 곳을 c로 표시할 것
	int ret = 1;
	// cout << "BFS start ==== " << endl;
	q.push({ start_x, start_y });
	visit[start_x][start_y] = c;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//cout << x << ' ' << y << endl;

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];
			if (0 <= x_ && x_ < N && 0 <= y_ && y_ < N)
				if (visit[x_][y_] == 0) {
					if (in_range(arr[x][y], arr[x_][y_])) {
						visit[x_][y_] = c;
						ret++;
						q.push({ x_, y_ });
					}
				}
		}
	}
	return ret;
}

bool movement() {
	init(); // visit array init
	int c = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				int r = BFS(c, i, j);
				
				if(r != 1)
					unit_calculate(c);
				c++;
			}
		}
	
	if (c == 1 + (N * N)) return false;
	else {
		result++;
	}
	return true;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	while (1) {
		if (!movement()) break; // BFS() -> true 시, 종료
	}
	cout << result << '\n';

	return 0;
}

/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cout << arr[i][j] << ' ';
			cout << endl;
}*/