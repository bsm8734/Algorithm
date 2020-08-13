#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, n;
vector<int> v;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}

	bool tf = prev_permutation(v.begin(), v.end());
	
	if (tf == true) {
		for (auto i : v)cout << i << " ";
		cout << '\n';
	}
	else cout << "-1\n";

	return 0;
}