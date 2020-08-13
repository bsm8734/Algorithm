#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, n;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}

	bool tf = next_permutation(v.begin(), v.end());
	if (tf == true) {
		for (auto j : v) cout << j << " ";
		cout << '\n';
	}
	else cout << "-1\n";

	return 0;
}