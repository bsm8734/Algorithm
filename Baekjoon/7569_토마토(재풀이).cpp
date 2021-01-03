#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int N, M, H;
int arr[101][101][101] = { 0, };
int green = 0;
int result = 0;
queue<pair<int, pair<int, int>>> q; // {H, {N, M}}
int xyz[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> H;
	for(int k = 0; k < H; k++)
		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 0) green++;
				else if (arr[k][i][j] == 1) q.push({ k, {i, j} });
			}

	while (!q.empty()) {
		result++;
		int q_size = q.size();
		for (int t = 0; t < q_size; t++) {
			int h = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int h_ = h + xyz[i][0];
				int x_ = x + xyz[i][1];
				int y_ = y + xyz[i][2];

				if (0 <= h_ && h_ < H && 0 <= x_ && x_ < N && 0 <= y_ && y_ < M)
					if (arr[h_][x_][y_] == 0) {
						q.push({ h_, {x_, y_} });
						arr[h_][x_][y_] = 1;
						green--;
					}
			}
		}
	}

	if (green != 0) cout << -1;
	else cout << result - 1;

	return 0;
}