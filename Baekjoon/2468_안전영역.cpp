#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// variable
int N;
int max_zone_size = 1;
int xy[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int arr[101][101] = { 0 };
bool visit[101][101] = { false };
queue<pair<int, int>> q;
vector<int> rains;



// function flood
void flood(int r) {
	for (int i = 0; i < N; i++)
		memset(visit[i], false, sizeof(bool) * N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] <= r) visit[i][j] = true;
}

// function BFS
void BFS(int start_x, int start_y) {
	q.push({ start_x, start_y });
	visit[start_x][start_y] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];
			if (x_ >= 0 && y_ >= 0 && x_ < N && y_ < N) {
				if (visit[x_][y_] == false) {
					visit[x_][y_] = true;
					q.push({ x_, y_ });
				}
			}
		}
	}
}

// main
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			rains.push_back(arr[i][j]);
		}
	
	rains.push_back(0);
	sort(rains.begin(), rains.end());
	rains.erase(unique(rains.begin(), rains.end()), rains.end());

	for (int r = 0; r < rains.size(); r++) {
		flood(rains[r]);
		
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == false) {
					BFS(i, j);
					cnt++;
				}
			}
		
		max_zone_size = max(max_zone_size, cnt);
	}
	
	cout << max_zone_size << '\n';

	return 0;
}
