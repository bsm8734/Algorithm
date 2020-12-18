#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a;
	string c;
	vector<pair<int, pair<int, string>>> arr;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> c;
		arr.push_back({ a, {i, c} });
	}
	sort(arr.begin(), arr.end());
	for (auto i : arr)
		cout << i.first << ' ' << i.second.second << '\n';

	return 0;
}