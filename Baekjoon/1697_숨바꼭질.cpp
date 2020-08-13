#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int target, start;
bool visit[100001] = { false };
queue<int> q;
vector<int> v;

int BFS() {
	int result = 0;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = q.front();
			q.pop();

			if (x == target) return result;

			v.push_back(x + 1);
			v.push_back(x - 1);
			v.push_back(2 * x);
			
			for (int j = 0; j < 3; j++) {
				int x_ = v[j];
				if (x_ >= 0 && x_ <= 100000) {
					if (visit[x_] == false) {
						visit[x_] = true;
						q.push(x_);
					}
				}

			}
			for (int j = 0; j < 3; j++) v.pop_back();
		}
		result++;
	}
	return result;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> start >> target;

	q.push(start);
	visit[start] = true;

	cout << BFS() << '\n';

	return 0;
}