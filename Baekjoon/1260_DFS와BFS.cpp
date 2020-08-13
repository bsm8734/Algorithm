#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// var
	int N, M, start;
	bool visit[2][1001] = { false }; // 0: DFS, 1: BFS
	bool map[1001][1001] = { false };
	stack<int> st;
	queue<int> q;

	// input
	cin >> N >> M >> start;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = true;
	}

	// DFS
	st.push(start);
	visit[0][start] = true;
	cout << start << " ";

	while (!st.empty()) {
		int cur = st.top();
		for (int i = 1; i <= N; i++) {
			if (map[cur][i] == true && visit[0][i] == false) {
				st.push(i);
				visit[0][i] = true;
				cout << i << " ";
				break;
			}
		}
		if(st.top() == cur) st.pop();
	}
	cout << '\n';
	

	// BFS
	q.push(start);
	visit[1][start] = true;

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << " ";
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (map[cur][i] == true && visit[1][i] == false) {
				q.push(i);
				visit[1][i] = true;
			}
		}
	}

	return 0;
}
