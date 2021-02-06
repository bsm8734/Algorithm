#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, M, result = 100;
int arr[10][10] = { 0, };
bool visit[10][10] = { false, };
bool visit_saved[10][10] = { false, };
int xy[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };
vector<pair<int, int>> cctv;
vector<int> starts;

void reset_visit() {
	memcpy(visit, visit_saved, sizeof(visit_saved));
}

void move_side(int x, int y, int dir) {
	visit[x][y] = true;
	int x_ = x + xy[dir][0];
	int y_ = y + xy[dir][1];
	if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M) {
		if (arr[x_][y_] == 6) return;
		move_side(x_, y_, dir);
	}
	return;
}

void dir_maker(int i) {
	int x = cctv[i].first;
	int y = cctv[i].second;
	int tp = arr[x][y];
	int a, b, c;

	if (tp == 1) {
		a = (starts[i]) % 4;
		move_side(x, y, a);
	}
	else if (tp == 2) {
		a = (starts[i] + 1) % 4;
		b = (starts[i] + 3) % 4;
		move_side(x, y, a);
		move_side(x, y, b);
	}
	else if (tp == 3) {
		a = starts[i] % 4;
		b = (starts[i] + 1) % 4;
		move_side(x, y, a);
		move_side(x, y, b);
	}
	else if (tp == 4) {
		a = starts[i] % 4;
		b = (starts[i] + 1) % 4;
		c = (starts[i] + 3) % 4;
		move_side(x, y, a);
		move_side(x, y, b);
		move_side(x, y, c);
	}
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
			if (arr[i][j] != 0)	// cctv & wall
				visit[i][j] = true;
			
			if (arr[i][j] == 5)								// (5 type) 4 side type
				for (int k = 0; k < 4; k++) 
					move_side(i, j, k);
			else if (0 < arr[i][j] && arr[i][j] < 5) {		// (1, 2, 3, 4 type)
				cctv.push_back({i, j});
				starts.push_back(0);
			}
		}
	memcpy(visit_saved, visit, sizeof(visit)); // save visit

	int size_ = cctv.size();
	int T = pow(2, (2 * size_));

	for (int t = 0; t < T; t++) {
		reset_visit();
		int cnt = 0;
		for (int i = 0; i < size_ * 2; i += 2) {
			int n = 0;
			if (t & (1 << i)) n += 1;
			if (t & (1 << (i + 1))) n += 2;
			starts[i / 2] = n;
			dir_maker(i/2);
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (visit[i][j] == false) cnt++;
		result = min(result, cnt);
	}
	
	cout << result;

	return 0;
}