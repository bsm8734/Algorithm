#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M, a;
vector<int> v;
vector<int> num;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num.push_back(a);
	}
	for (int i = 0; i < M; i++) v.push_back(1);
	for (int i = M; i < N; i++) v.push_back(0);
	sort(num.begin(), num.end());
	do {
		for (int i = 0; i < N; i++) 
			if (v[i] == 1) 
				cout << num[i] << ' ';
		cout << '\n';
			
	} while (prev_permutation(v.begin(), v.end()));

	return 0;
}