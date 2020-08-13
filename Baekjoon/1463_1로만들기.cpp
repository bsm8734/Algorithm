#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N, cnt = 0;
bool visit[1000001] = { false };
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur = q.front();
			q.pop();
			if (cur == 1) return;

			if (cur % 3 == 0 && visit[cur / 3] == false) q.push(cur / 3);
			if (cur % 2 == 0 && visit[cur / 2] == false) q.push(cur / 2);
			if (visit[cur - 1] == false) q.push(cur - 1);
		}
		cnt++;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	visit[N] = true;
	q.push(N);
	BFS();
	cout << cnt << '\n';
	return 0;
}