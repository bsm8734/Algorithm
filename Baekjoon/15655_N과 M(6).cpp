#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, n;
vector<int> v, tf;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
		if (i < M) tf.push_back(0);
		else tf.push_back(1);
	}

	sort(v.begin(), v.end());
	do {
		for (int i = 0; i < N; i++) 
			if (tf[i] == 0) cout << v[i] << ' ';
		cout << '\n';
	} while (next_permutation(tf.begin(), tf.end()));
	
	return 0;
}