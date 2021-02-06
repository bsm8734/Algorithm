#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int c_len = 0, h_size = 0;
int result = 10000000;
int arr[60][60] = { 0, };
vector<pair<int, int>> house, chicken;
vector<int> c;

int dist(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) + abs(y1 - y2));
}

int sum_of_dist() {
	int ret = 0;
	for (int i = 0; i < h_size; i++) {
		int min_ = 1000;
		for (int j = 0; j < c_len; j++) {
			if (c[j] == 0) continue;
			int x1 = house[i].first;
			int y1 = house[i].second;
			int x2 = chicken[j].first;
			int y2 = chicken[j].second;
			min_ = min(min_, dist(x1, y1, x2, y2));
		}
		ret += min_;
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// init
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) //house
				house.push_back({ i, j });
			else if (arr[i][j] == 2) {
				chicken.push_back({ i, j });
				c.push_back(0);
			}
		}
	for (int i = 0; i < M; i++) c[i] = 1;
	h_size = house.size();
	c_len = c.size();

	do {
		result = min(result, sum_of_dist());
	} while (prev_permutation(c.begin(), c.end()));
	
	cout << result;

	return 0;
}