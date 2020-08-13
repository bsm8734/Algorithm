#include <iostream>
#include <string.h>
using namespace std;

int N, M, x, y, cmd_cnt;
int map[30][30] = { 0 };
int dice[4][3] = { 0 };
int xy[5][2] = { {0,0}, {0, 1}, {0, -1} ,{-1, 0}, {1, 0}};
int cmd[1001] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M >> x >> y >> cmd_cnt;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int i = 0; i < cmd_cnt; i++) cin >> cmd[i];

	// command
	for (int t = 0; t < cmd_cnt; t++) {
		int dir = cmd[t];
		if (x + xy[dir][0] < 0 || x + xy[dir][0] >= N || y + xy[dir][1] < 0 || y + xy[dir][1] >= M) continue;
		
		if (dir == 1) { // >
			int tmp = dice[1][0];
			dice[1][0] = dice[1][1];
			dice[1][1] = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = tmp;
		}
		else if (dir == 2) { // <
			int tmp = dice[1][2];
			dice[1][2] = dice[1][1];
			dice[1][1] = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = tmp;
		}
		else if (dir == 3) { // ¤µ
			int tmp = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = dice[1][1];
			dice[1][1] = dice[0][1];
			dice[0][1] = tmp;
		}
		else if (dir == 4) { // v
			int tmp = dice[0][1];
			dice[0][1] = dice[1][1];
			dice[1][1] = dice[2][1];
			dice[2][1] = dice[3][1];
			dice[3][1] = tmp;
		}

		x = x + xy[dir][0];
		y = y + xy[dir][1];

		// top print
		cout << dice[3][1] << '\n';

		// bottom change
		if (map[x][y] == 0) map[x][y] = dice[1][1];
		else {
			dice[1][1] = map[x][y];
			map[x][y] = 0;
		}
	}

	return 0;
}