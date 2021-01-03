#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;
queue<int> q;
bool arr[100001] = { false, };
int x[3];
int result = 0;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	q.push(N);
	while (!q.empty()) {
		int q_size = q.size();
		for (int t = 0; t < q_size; t++) {
			int cur = q.front();
			q.pop();

			if (cur == K) {
				cout << result;
				return 0;
			}

			x[0] = cur - 1;
			x[1] = cur + 1;
			x[2] = cur * 2;

			for(int i =0 ; i < 3; i++) 
				if (0 <= x[i] && x[i] < 100001) 
					if (arr[x[i]] == false) {
						arr[x[i]] = true;
						q.push(x[i]);
					}
		}
		result++;
	}

	return 0;
}