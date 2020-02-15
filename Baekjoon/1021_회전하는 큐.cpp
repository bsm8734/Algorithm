#include <iostream>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, t;
	int result = 0;
	cin >> n >> m;
	deque <int>dq;	// 비교의 대상이 되는 큐
	queue <int>q;	// 추출을 원하는 큐
	
	/* input */
	for (int i = 1; i <= n; i++) dq.push_back(i);
	for (int i = 1; i <= m; i++) {
		cin >> t;
		q.push(t);
	}
	// 추출하려는 수만큼 돌리기
	for (int i = 0; i < m; i++) {
		int cnt = 0;

		while (dq.front() != q.front()) {
			// 한바퀴 돌리기
			int tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
			cnt++;
		}

		if (dq.front() == q.front()) {
			result += min((int)(dq.size() - cnt), cnt);
			q.pop(); dq.pop_front();
			continue;
		}
	}
	cout << result;

	return 0;
}