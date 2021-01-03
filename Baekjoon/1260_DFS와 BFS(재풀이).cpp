#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// var
int N, M, V;
int a, b;
bool arr[2][1024][1024] = { false, };
queue<int> q;
stack<int> st;

void DFS(int v) { // arr[0][0:N+1][0:N+1]
	st.push(v);
	cout << v << ' ';
	arr[0][v][v] = true;

	while (!st.empty()) {
		int cur = st.top();
		// (����)���⼭ pop���� ����

		bool tf = false;
		for (int i = 1; i <= N; i++) {
			if (arr[0][cur][i] == true && arr[0][i][i] == false) { // edged && visited ?
				st.push(i);
				cout << i << ' ';
				arr[0][i][i] = true;
				tf = true;
				break; // (����) �ϳ��� �ְ� ���� top�� Ȯ���ؾ���
			}
		}
		if (tf == false) st.pop();
	}

	cout << '\n';
}

void BFS(int v) { // arr[1][0:N+1][0:N+1]
	q.push(v);
	arr[1][v][v] = true;

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' '; // q�� ������ ���� ������ �����ǹǷ� pop�ÿ� ��� ����
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[1][cur][i] == true && arr[1][i][i] == false) { // edged && visited ?
				q.push(i);
				arr[1][i][i] = true;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[0][a][b] = arr[0][b][a] = arr[1][a][b] = arr[1][b][a] = true;
	}
	cin >> V;

	// call func
	DFS(V);
	BFS(V);

	return 0;
}