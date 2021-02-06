#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) v.push_back(1);
	for (int i = M; i < N; i++) v.push_back(0);

	do {
		for (int i = 0; i < N; i++) 
			if (v[i] == 1) cout << (i + 1) << ' ';
		cout << endl;

	} while (prev_permutation(v.begin(), v.end()));

	return 0;
}