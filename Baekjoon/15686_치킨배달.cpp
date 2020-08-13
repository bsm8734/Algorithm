#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int map[51][51] = { 0 };
int back_up[51][51] = { 0 };
vector<pair<int, int>> chicken, home;
vector<int> choice;
int min_ = -1;
int chicken_cnt = 0, home_cnt = 0;

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = back_up[i][j];
}

int chicken_dist() {
	int total = 0;
	for (int i = 0; i < home_cnt; i++) {
		int ret = home_cnt * N * 3;
		for (int j = 0; j < chicken_cnt; j++) {
			if (choice[j] == 0) continue;
			int dist = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
			ret = min(ret, dist);
		}
		total += ret;
	}
	return total;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << map[i][j] << ' ';
		cout << endl;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			back_up[i][j] = map[i][j];
			if (map[i][j] == 1) home.push_back({ i, j });
			else if (map[i][j] == 2) chicken.push_back({ i, j });
		}
			
	// initialize
	chicken_cnt = chicken.size();
	home_cnt = home.size();

	for (int i = 0; i < M; i++) choice.push_back(1);
	for (int i = M; i < chicken_cnt; i++) choice.push_back(0);

	// process: choose #M chicken
	do {
		if (min_ == -1) min_ = chicken_dist();
		else min_ = min(min_, chicken_dist());

	} while (prev_permutation(choice.begin(), choice.end()));
	
	cout << min_ << '\n';
	

	return 0;
}