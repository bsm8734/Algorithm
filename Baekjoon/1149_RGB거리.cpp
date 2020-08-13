#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int cost[1001][1001] = { 0 };
int map[1001][3] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	for (int i = 0; i < 3; i++) map[0][i] = cost[0][i];

	for (int i = 1; i < N; i++) {
		map[i][0] = min(map[i - 1][1], map[i - 1][2]) + cost[i][0];
		map[i][1] = min(map[i - 1][0], map[i - 1][2]) + cost[i][1];
		map[i][2] = min(map[i - 1][0], map[i - 1][1]) + cost[i][2];
	}

	cout << min(min(map[N - 1][0], map[N - 1][1]), map[N - 1][2]) << '\n';


	return 0;
}