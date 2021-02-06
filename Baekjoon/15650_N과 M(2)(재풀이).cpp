#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<bool> v;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++) v.push_back(true);
	for (int i = M; i < N; i++) v.push_back(false);
	
	do {
		for (int i = 0; i < N; i++)
			if (v[i] == true)  cout << i + 1 << ' ';
		cout << '\n';
	} while (prev_permutation(v.begin(), v.end()));

	return 0;
}
// C++14 vector int형으로 풀었을때가 더 빠름
// C++17 vector bool, int형으로 풀었을때의 속도는 같음