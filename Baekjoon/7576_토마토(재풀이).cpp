#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

// var // global declaration (or not, stack overflow)
int N, M;
int arr[1010][1010] = { 0, };
int green = 0;	// un-ripe tomato
queue<pair<int, int>> q;
int xy[4][2] = { {1, 0},{0, 1},{-1, 0},{0, -1} };
int result = 0;
bool tf = false;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) green++;
			else if (arr[i][j] == 1) q.push({ i, j });
		}
	}

	while (!q.empty()) {
		int q_size = q.size();

		for (int t = 0; t < q_size; t++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int x_ = x + xy[i][0];
				int y_ = y + xy[i][1];

				if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M)
					if (arr[x_][y_] == 0) {
						tf = true;
						arr[x_][y_] = 1;
						q.push({ x_, y_ });
						green--;
					}
			}
		}
		result++;
	}

	if (tf == false) cout << 0;
	else if (green != 0) cout << -1;
	else cout << result-1;

	return 0;
}