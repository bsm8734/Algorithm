#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// var
int N, M, n;
int arr[10][10] = { 0 };
bool visit[10][10] = { false, };
vector<pair<int, int>> empty_pair, virus_pair; // 초기 안전지대 위치, 초기 바이러스 위치
vector<int> empty_case; // 벽을 어디에 세울지 정하기 위함
queue<pair<int, int>> q;
int min_ = 1000; // 바이러스가 퍼지기 시작하면 감염되는 (비)안전지대의 수
int xy[4][2] = { {1, 0},{0, 1},{0, -1},{-1, 0} };


void init() { // queue, visit init
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visit[i][j] = false;

	while (!q.empty()) q.pop();
	for (auto t : virus_pair) {
		q.push({ t.first, t.second });
		visit[t.first][t.second] = true;
	}
}

int BFS() {
	int cnt = 0; // num of new virus

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];

			if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M) 
				if (visit[x_][y_] == false && arr[x_][y_] == 0) {
					visit[x_][y_] = true;
					q.push({ x_, y_ });
					cnt++;
				}
		}
		if (cnt > min_) return min_;
	}

	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> n;
			arr[i][j] = n;
			if (n == 0) { // get empty place
				empty_pair.push_back({ i, j });
				empty_case.push_back(0);
			}
			else if (n == 2) virus_pair.push_back({ i, j }); // get virus place
		}

	// next_permutation
	empty_case[0] = empty_case[1] = empty_case[2] = 1;

	do {
		init();

		for (int i = 0; i < empty_pair.size(); i++)
			if (empty_case[i] == 1) { // make wall
				int f = empty_pair[i].first;
				int s = empty_pair[i].second;
				visit[f][s] = true;
			}

		min_ = min(min_, BFS());

	} while (prev_permutation(empty_case.begin(), empty_case.end()));

	int result =  empty_pair.size() - min_ - 3;
	cout << result;

	return 0;
}