#define _CRT_SECURE_NO_WARNINGS		// to avoid warning
#include <stdio.h>					// to avoid warning

#include <iostream>
#include <string>
using namespace std;

int map[100][100];
int max = 0;
int min = 100000;
bool visit[100][100];

void dfs(int cost, int x, int y) {
	visit[x][y] = true;
	cout << x << " " << y << endl;
	cost += map[x][y];

	if (x == max - 1 && y == max - 1) {
		if (cost < min) min = cost;
	}
	else {
		if (y - 1 >= 0 && visit[x][y - 1] == false) dfs(cost, x, y - 1);
		if (x - 1 >= 0 && visit[x - 1][y] == false) dfs(cost, x - 1, y);
		if (x + 1 < max && visit[x + 1][y] == false) dfs(cost, x + 1, y);
		if (y + 1 < max && visit[x][y + 1] == false) dfs(cost, x, y + 1);
	}

	visit[x][y] = false;
}

int main() {
	freopen("small.txt", "r", stdin);	// change "stdin" to "input.txt"

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// initialization
		min = 100000;
		cin >> max;
		char c;
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				cin >> c;
				map[i][j] = atoi(&c);
				visit[i][j] = false;
			}
		}
		
		// routine search
		dfs(0, 0, 0);
		cout << "#" << t << " " << min << endl;
		
	}
	return 0;
}