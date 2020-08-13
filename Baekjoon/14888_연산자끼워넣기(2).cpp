#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int N, n;
vector<int> num, op;
int result_min = 0;
int result_max = 0;
// + - x % 

int cal() {
	int result = num[0];
	
	for (int i = 0; i < N - 1; i++) {
		if (op[i] == 0)
			result = result + num[i + 1];
		else if (op[i] == 1)
			result = result - num[i + 1];
		else if (op[i] == 2)
			result = result * num[i + 1];
		else if (op[i] == 3)
			result = result / num[i + 1];
		}
	return result;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		num.push_back(n);
	}
	for (int i = 0; i < 4; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) op.push_back(i);
	}

	result_min = result_max = cal();
	
	while (next_permutation(op.begin(), op.end())) {
		int tmp = cal();
		result_max = max(result_max, tmp);
		result_min = min(result_min, tmp);
	}

	cout << result_max << '\n' << result_min << '\n';

	return 0;
}