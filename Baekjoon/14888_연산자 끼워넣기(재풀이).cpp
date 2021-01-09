#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int op[4] = { 0, };
int N, a;
vector<int> nums, nexper;
int result_min = 1000000001;
int result_max = -1000000001;

int get_min_max() {
	int k = 0;
	int ret = nums[k];
	for (auto i : nexper) {
		k++;
		if (i == 0)
			ret += nums[k];
		else if (i == 1)
			ret -= nums[k];
		else if (i == 2)
			ret *= nums[k];
		else if (i == 3)
			ret /= nums[k];
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		nums.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
		for (int j = 0; j < op[i]; j++)
			nexper.push_back(i);
	}
		
	do {
		int n = get_min_max();
		result_min = min(result_min, n);
		result_max = max(result_max, n);
	} while (next_permutation(nexper.begin(), nexper.end()));

	cout << result_max << '\n' << result_min;

	return 0;
}