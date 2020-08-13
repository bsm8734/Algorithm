#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;

int N;
int map[101][101] = { 0 };
int xy[4][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
int change[4] = { 1, 2, 3, 0 }; // (��)����
stack<int> st;
vector<int> v;

int start_x, start_y, start_dir, gen;

void func(int cur_x, int cur_y, int cur_gen) {
	if (cur_gen == gen) return;

	int x = cur_x, y = cur_y;
	int v_size = v.size();
	for (int i = v_size - 1; i >= 0; i--) {
		int dir = change[v[i]];
		x = x + xy[dir][0];
		y = y + xy[dir][1];
		map[x][y] = 1;
		v.push_back(dir);
	}
	func(x, y, cur_gen + 1);
}

int check() {
	int ret = 0;
	for (int i = 0; i < 100; i++) 
		for (int j = 0; j < 100; j++) 
			if (map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] == 4) ret++;
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	while (N--) {
		cin >> start_x >> start_y >> start_dir >> gen; // ������(x, y) // ���۹��� // ����
		// 0����
		v.push_back(start_dir); // ���ݱ��� �� (��)���� ����
		int x = start_x + xy[start_dir][0];
		int y = start_y + xy[start_dir][1];
		map[start_x][start_y] = map[x][y] = 1;
		func(x, y, 0); // 0���� �������� // ������ �ѱ��
		v.clear();
	}

	cout << check() << '\n';

	return 0;
}
