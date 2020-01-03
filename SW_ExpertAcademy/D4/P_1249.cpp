#define _CRT_SECURE_NO_WARNINGS		// to avoid warning
#include <stdio.h>					// to avoid warning

#include <iostream>
#include <string>
using namespace std;

int map[100][100];
int max_num = 0;
int min_num = 100000;
bool visit[100][100];

void dfs(int cost, int x, int y, int depth) {
	visit[x][y] = true;
	cost += map[x][y];

	if (cost <= min_num && depth < max_num * 2) {
		if (x == max_num - 1 && y == max_num - 1) {
			if (cost < min_num) min_num = cost;
			//cout << cost << endl;
		}
		else {
			if (y - 1 >= 0) if (visit[x][y - 1] == false) dfs(cost, x, y - 1, depth + 1);
			if (x - 1 >= 0) if (visit[x - 1][y] == false) dfs(cost, x - 1, y, depth + 1);
			if (x + 1 < max_num) if (visit[x + 1][y] == false) dfs(cost, x + 1, y, depth + 1);
			if (y + 1 < max_num) if (visit[x][y + 1] == false) dfs(cost, x, y + 1, depth + 1);
		}
	}


	visit[x][y] = false;
}

int main() {
	freopen("small.txt", "r", stdin);	// change "stdin" to "input.txt"

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// initialization
		min_num = 100000;
		cin >> max_num;
		char c;
		for (int i = 0; i < max_num; i++) {
			for (int j = 0; j < max_num; j++) {
				cin >> c;
				map[i][j] = atoi(&c);
				visit[i][j] = false;
			}
		}

		// routine search
		dfs(0, 0, 0, 0);
		cout << "#" << t << " " << min_num << endl;

	}
	return 0;
}