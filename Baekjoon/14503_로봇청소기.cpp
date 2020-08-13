#include <iostream>
#include <string.h>
using namespace std;

int N, M, x, y, dir, result = 0;
int x_, y_;
int xy[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int arr[64][64] = { 0 };

#define next_dir (4 + dir - 1) % 4
#define back_dir (4 + dir - 2) % 4

int check_around() { // -1: terminate // 0: go back // 1: empty way remained
	// empty_remained
	for (int i = 0; i < 4; i++) {
		x_ = x + xy[i][0];
		y_ = y + xy[i][1];
		if (arr[x_][y_] == 0) return 1;
	}
	// can go back
	x_ = x + xy[back_dir][0];
	y_ = y + xy[back_dir][1];
	if (arr[x_][y_] == 2) return 0;

	// terminate
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input & init
	cin >> N >> M >> x >> y >> dir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	arr[x][y] = 2;
	result++;

	while(1){
		int state = check_around();

		if(state == -1) break;	// terminate
		else if (state == 0) {	// go back
			dir = back_dir;
			x += xy[dir][0];
			y += xy[dir][1];
			dir = back_dir;
		}
		else if (state == 1) {	// empty zone remains
			dir = next_dir;
			x_ = x + xy[dir][0];
			y_ = y + xy[dir][1];
			if (arr[x_][y_] == 0) {
				x = x_;
				y = y_;
				arr[x][y] = 2;
				result++;
			}
		}
	}

	cout << result << '\n';

	return 0;
}