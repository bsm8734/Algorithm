#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int x, y, cur_dir;
int arr[51][51] = { 0, };
bool visit[51][51] = { false, };
int result = 0;
int xy[4][2] = { {-1, 0},{0, 1},{1, 0}, {0, -1} }; // N E S W

int next_dir() {
	cur_dir = (cur_dir - 1 + 4) % 4;
	return cur_dir;
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M;
	cin >> x >> y >> cur_dir;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	while (1) {
		// step1: clean cur
		visit[x][y] = true;
		result++;

		// step2: find another
		bool moved = false;
		for (int t = 0; t < 4; t++) {
			next_dir();
			int x_ = x + xy[cur_dir][0];
			int y_ = y + xy[cur_dir][1];
			
			if (arr[x_][y_] == 1) continue;
			if (visit[x_][y_] == true) continue;
			else {
				x = x_;
				y = y_;
				moved = true;
				break;
			}
		}

		if (moved == true) continue;
		
		int x_ = x - xy[cur_dir][0];
		int y_ = y - xy[cur_dir][1];
		if (arr[x_][y_] == 1) break;
		x = x_; // 이거 빠져서 계속 무한루프
		y = y_;
		result--;
	}

	cout << result;

	return 0;
}