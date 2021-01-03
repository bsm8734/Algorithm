#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

// var
int N;
int result = 0;
int arr[30][30] = { 0, };
string s;
int xy[4][2] = { {1, 0},{0, 1},{-1, 0},{0, -1} };
queue<pair<int, int>> q;
vector<int> v;

int BFS(int start_x, int start_y) {
	int ret = 1;
	q.push({ start_x, start_y });
	arr[start_x][start_y] = 0;
	
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur_x + xy[i][0];
			int y = cur_y + xy[i][1];

			if (0 <= x && x < N && 0 <= y && y < N) // in range
				if (arr[x][y] != 0) { // not visited
					arr[x][y] = 0;
					q.push({ x, y });
					ret++;
				}
		}
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			if (s[j] == '1') arr[i][j] = 1;
	}

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			if (arr[i][j] != 0) {
				v.push_back(BFS(i, j));
				result++;
			}

	cout << result << '\n';
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << '\n';

	return 0;
}