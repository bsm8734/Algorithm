#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N;
int map[21][21] = { 0 };
bool visit[21][21] = { false };
int cur_x = 0, cur_y = 0, cur_body = 2, cur_ate = 0;
int xy[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
int food_x, food_y;
int move_for_food = 0;
queue<pair<int, int>> q;
int result = 0;
int num = 1;
int nn[21][21];


void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = false;
	while (!q.empty()) q.pop();
}

bool find_food() { // BFS
	init();

	q.push({ cur_x, cur_y });
	visit[cur_x][cur_y] = true;

	bool ret = false;
	int cnt = 1;
	while (!q.empty()) {
		int q_size = q.size();
		for (int t = 0; t < q_size; t++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x_ = x + xy[i][0];
				int y_ = y + xy[i][1];
				if (0 <= x_ && x_ < N && 0 <= y_ && y_ < N)
					if (visit[x_][y_] == false)
						if (map[x_][y_] <= cur_body) {
							if (map[x_][y_] < cur_body && map[x_][y_] != 0) {
								if (ret == false || (x_ < food_x) || (x_ == food_x && y_ < food_y)) {
									food_x = x_;
									food_y = y_;
								}
								ret = true;
							}
							visit[x_][y_] = true;
							q.push({ x_, y_ });
						}
			}
		}
		if (ret == true) {
			move_for_food = cnt;
			cur_ate++;
			return true;
		}
		cnt++;
	}
	return false;
}

void update_all() {
	if (cur_ate == cur_body) {
		cur_ate = 0;
		cur_body++;
	}
	cur_x = food_x;
	cur_y = food_y;
	map[food_x][food_y] = 0;
	result += move_for_food;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				cur_x = i;
				cur_y = j;
				map[i][j] = 0;
			}
		}

	while (1) {
		if (find_food())
			update_all();
		else break;
	}
	cout << result << '\n';

	return 0;
}