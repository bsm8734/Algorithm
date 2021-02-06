#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, H;
int a, b;
int c_len = 0, result = -1;
bool tf = false;
bool bridge[50][50] = { {false, }, };
vector<pair<int, int>> target;
vector<int> c;

bool permission_bridge() {
	target.clear();
	for (int i = 0; i < c_len; i++) {
		if (c[i] == 0) continue;

		int x = i / (N - 1);
		int y = i % (N - 1);

		if (bridge[x][y] == true) return false;
		else if (0 < y && bridge[x][y - 1] == true) return false;
		else if (y < N - 2 && bridge[x][y + 1] == true) return false;
		else if (0 < y && 0 < i && c[i - 1] == 1) return false;

		target.push_back({ x, y });
	}

	return true;
}

void connect_bridge() {
	for (auto i : target)
		bridge[i.first][i.second] = true;
	/*
	for (int i = 0; i < H; i++)
		bridge[i][N - 1] = false;
	*/
}
void disconnect_bridge() {
	for (auto i : target)
		bridge[i.first][i.second] = false;
}

bool search_successed() {
	connect_bridge();

	int ret = true;
	for (int t = 0; t < N - 1; t++) {
		int cur = t;
		for (int i = 0; i < H; i++) {
			if (bridge[i][cur] == true) { // => move right
				cur++;
			}
			else if (0 < cur && bridge[i][cur - 1] == true) { // <= move left
				cur--;
			}
		}
		if (cur != t) {
			ret = false;
			break;
		}
	}

	disconnect_bridge();
	return ret;
}

void make_bridge(int T) {
	if (c_len < T) return;
	for (int i = 0; i < c_len; i++) c[i] = 0;
	for (int i = 0; i < T; i++) c[i] = 1;

	do {
		if (permission_bridge() == false) continue;
		if (target.size() == T) { // if 없어도 된다
			if (search_successed() == true) {
				result = T;
				return;
			}
		}
	} while (prev_permutation(c.begin(), c.end()));
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// init
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		bridge[a][b] = true;
	}
	for (int i = 0; i < (N - 1) * H; i++) c.push_back(0);
	c_len = c.size();

	for (int T = 0; T <= 3; T++) {
		make_bridge(T);
		if (result != -1) break;
	}

	cout << result;

	return 0;
}