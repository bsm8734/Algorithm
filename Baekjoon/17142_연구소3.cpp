#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int arr[51][51] = { 0 };
bool visit[51][51] = { false };
int virus_cnt = 0;
int xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int, int>> q;
vector<pair<int, int>> v;
vector<int> np;
int result = -1;

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) visit[i][j] = false;
	while (!q.empty()) q.pop();
}

int BFS() {
	int bfs_timer = 0; int cnt = 0;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (arr[x][y] == 0) cnt++; // Á¶½É
			if (cnt == virus_cnt) return bfs_timer;

			for (int j = 0; j < 4; j++) {
				int x_ = x + xy[j][0];
				int y_ = y + xy[j][1];
				if (0 <= x_ && x_ < N && 0 <= y_ && y_ < N) {
					if (arr[x_][y_] != 1 && visit[x_][y_] == false) {
						visit[x_][y_] = true;
						q.push({ x_, y_ });
					}
				}
			}
		}
		bfs_timer++;
	}
	return -1; // fail
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) virus_cnt++;
			else if (arr[i][j] == 2) v.push_back({ i, j });
		}

	if (virus_cnt == 0) {
		cout << 0 << '\n';
		return 0;
	}

	// init
	int v_size = v.size();
	for (int i = 0; i < (v_size - M); i++) np.push_back(0);
	for (int i = v_size - M; i < v_size; i++) np.push_back(1);
	
	do {
		init();
		for (int i = 0; i < v_size; i++)
			if (np[i] == 1) {
				q.push({ v[i].first, v[i].second });
				visit[v[i].first][v[i].second] = true;
			}

		int res = BFS();
		if (res == -1) continue;
		if (result == -1) result = res;
		else result = min(result, res);
		
		
	} while (next_permutation(np.begin(), np.end()));

	cout << result << '\n';

	return 0;
}
