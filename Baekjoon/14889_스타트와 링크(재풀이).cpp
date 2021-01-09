#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int S[21][21] = { 0, };
vector<int> v;
int res = 10000;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i < (N / 2)) v.push_back(0);
		else v.push_back(1);

		for (int j = 0; j < N; j++)cin >> S[i][j];
	}
	
	do {
		vector<int> tmp[2];
		int a = 0, b = 0;
		for (int i = 0; i < N; i++) {
			if (v[i] == 0) tmp[0].push_back(i);
			else tmp[1].push_back(i);
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				int i_ = tmp[0][i];
				int j_ = tmp[0][j];
				a += (S[i_][j_] + S[j_][i_]);
			}		
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				int i_ = tmp[1][i];
				int j_ = tmp[1][j];
				b += (S[i_][j_] + S[j_][i_]);
			}
		}

		res = min(res, abs(a - b));
	} while (next_permutation(v.begin(), v.end()));

	cout << res;

	return 0;
}