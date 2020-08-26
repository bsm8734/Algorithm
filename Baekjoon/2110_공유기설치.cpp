#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long N, C, a;
vector<long long> arr;
long long high, low, mid, result = 0;

bool is_success(long long target) {
	long long used_cnt = 1;
	long long cur_len = 0;
	// cout << "target: " << target << endl;
	//cout << arr[0] << " " << used_cnt << " " << cur_len << endl;
	for (int i = 1; i < N; i++) {
		// cout << "------------------------------------------" << endl;
		// cout << arr[i] << " " << used_cnt << " " << cur_len << endl;
		cur_len += (arr[i] - arr[i - 1]);
		if (cur_len >= target) { // cur_len √Ê¡∑
			// cout << "b" << endl;
			used_cnt++;
			cur_len = 0;
			if (used_cnt == C) return true;
		}
		// cout << arr[i] << " " << used_cnt << " " << cur_len << endl;
	}
	return false;
}

void find_max() {
	low = 1;
	high = pow(2, 30);
	while (low <= high) {
		// cout << "low:" << low <<  ", mid:" << mid << ", high:" << high << endl;
		mid = (low + high) / 2;
		if (is_success(mid)) {
			// cout << "success" << endl;
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
	}
	
	// sort
	sort(arr.begin(), arr.end());

	find_max();
	cout << result << '\n';

	return 0;
}