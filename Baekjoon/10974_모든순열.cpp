#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) v.push_back(i + 1);

	do {
		for (int i = 0; i < N; i++) cout << v[i] << ' ';
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
	

	return 0;
}