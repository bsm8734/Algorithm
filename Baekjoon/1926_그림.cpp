#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// var
	int N, M;
	int map[501][501] = { 0 };
	int xy[4][2] = { {0,1}, {1,0}, {-1, 0}, {0, -1} };
	int scale = 0;
	int num = 0; int max_scale = 0;
	queue < pair<int, int>> q;

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	// BFS
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 

			// BFS for 1 group
			if (map[i][j] == 1) {
				scale = 1;
				num++;

				q.push({ i, j });
				map[i][j] = 0;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop(); 

					int x = cur.first;
					int y = cur.second;
					for (int k = 0; k < 4; k++) {
						int x_ = x + xy[k][0];
						int y_ = y + xy[k][1];
						if(x_ >= 0 && x_ < N && y_ >= 0 && y_ < M)
							if (map[x_][y_] == 1) {
								q.push({x_, y_});
								map[x_][y_] = 0;
								scale++;
							}
					}
				}

				max_scale = max(max_scale, scale);
			}

	cout << num << '\n' << max_scale << '\n';

	return 0;
}