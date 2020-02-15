/*	���� �˰���
	����: 1260�� DFS�� BFS
	����� �˰���: DFS, BFS
	����� �ڷᱸ��: �迭
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool** map;
bool* visited; // used for DFS
bool* checker; // used for BFS
int V, E, start;
queue<int> q;

void DFS(int v) {
	visited[v] = true;
	cout << v << " ";

	for (int i = 0; i <= V; i++)
		if (visited[i] == false && map[v][i] == true)
			DFS(i);
		
}

void BFS(int v) {
	q.push(v);
	checker[v] = true;

	while (!q.empty()) {
		// �տ� ���Ҹ� ���� �����ص�
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		// ���� ���ҿ� ����� ���ҵ��� ť�� �־��ְ�
		// �� ���ҵ��� ��� �湮������ ǥ��
		for (int i = 1; i <= V; i++)
			if (checker[i] == false && map[cur][i] == true) {
				q.push(i);
				checker[i] = true;
			}
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> V >> E >> start;

	visited = new bool[V+1];
	checker = new bool[V+1];
	map = new bool*[V + 1];
	for (int i = 0; i <= V; i++) {
		map[i] = new bool[V+1];
		visited[i] = false;
		checker[i] = false;
	}

	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = true;
	}

	DFS(start);
	cout << '\n';
	BFS(start);

	system("pause");
	return 0;
}