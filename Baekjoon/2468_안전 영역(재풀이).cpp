// multimap 실습
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iterator>
using namespace std;

// var
int N;
int arr[102][102] = { 0, };
int visit[102][102] = { false, };
multimap<int, pair<int, int>> m;
multimap<int, pair<int, int>>::iterator iter;
queue<pair<int, int>> q;
int result = 1;
int xy[4][2] = { {0, 1},{1, 0},{-1, 0},{0, -1} };

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_ = x + xy[i][0];
			int y_ = y + xy[i][1];

			if (0 <= x_ && x_ < N && 0 <= y_ && y_ < N) {
				if (arr[x_][y_] != -1 && visit[x_][y_] == false) {
					visit[x_][y_] = true;
					q.push({ x_, y_ });
				}
			}
		}
	}
}

int make_BFS() {
	// init visit
	int num = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) visit[i][j] = false;
	
	// BFS
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != -1 && visit[i][j] == false) {
				num++;
				while (!q.empty()) q.pop(); // init q
				q.push({ i, j });
				BFS();
			}
		}
	}

	return num;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			m.insert({ arr[i][j], {i, j} });
		}

	result = max(result, make_BFS());
			
	// change cases & call BFS
	iter = m.begin();
	auto before_ = iter->first;
	
	while (iter != m.end()) {
		auto now_ = (iter->first);
		int a = (iter->second).first;
		int b = (iter->second).second;

		if(before_ != now_) // 없으면 에러
			result = max(result, make_BFS());

		arr[a][b] = -1; // 85번과 위치 바뀌면 "틀렸습니다"

		iter++;
		before_ = now_;
	}

	cout << result;


	return 0;
}