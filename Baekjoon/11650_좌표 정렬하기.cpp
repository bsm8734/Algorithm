#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, x, y;
	vector<pair<int, int>> xy;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		xy.push_back({ x, y });
	}
	sort(xy.begin(), xy.end());
	
	for (auto i : xy) {
		cout << i.first << ' ' << i.second << '\n';
	}
	

	return 0;
}