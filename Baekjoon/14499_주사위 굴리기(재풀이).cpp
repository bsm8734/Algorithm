#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, M, x, y, K, dir;
int arr[30][30] = { 0, };
int l[4] = { 0, };
int r[4] = { 0, };
int xy[5][2] = { {0, 0},{0, 1},{0, -1},{-1, 0},{1, 0} };

// up, down
pair<int, int> dice_roll(int dir) {
	if (dir == 1) {
		int tmp = l[3];
		for (int i = 2; i >= 0; i--) {
			l[i + 1] = l[i];
		}
		l[0] = tmp;
		r[1] = l[1];
		r[3] = l[3];
	}
	else if (dir == 2) {
		int tmp = l[0];
		for (int i = 1; i <= 3; i++) {
			l[i - 1] = l[i];
		}
		l[3] = tmp;
		r[1] = l[1];
		r[3] = l[3];
	}
	else if (dir == 3) {
		int tmp = r[3];
		for (int i = 2; i >= 0; i--) {
			r[i + 1] = r[i];
		}
		r[0] = tmp;
		l[1] = r[1];
		l[3] = r[3];
	}
	else if (dir == 4) {
		int tmp = r[0];
		for (int i = 1; i <= 3; i++) {
			r[i - 1] = r[i];
		}
		r[3] = tmp;
		l[1] = r[1];
		l[3] = r[3];
	}

	return {l[1], l[3]};
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int k = 0; k < K; k++) {
		cin >> dir;

		// (x, y) change
		int cur_x = x + xy[dir][0];
		int cur_y = y + xy[dir][1];
		if (cur_x < 0 || N <= cur_x || cur_y < 0 || M <= cur_y) continue;
		x = cur_x;
		y = cur_y;

		// dice change
		pair<int, int> points = dice_roll(dir);

		// check arr's num
		if (arr[x][y] == 0) {
			arr[x][y] = points.second;
		}
		else {
			l[3] = r[3] = arr[x][y];
			arr[x][y] = 0;
		}
		cout << points.first <<'\n';
	}




	return 0;
}