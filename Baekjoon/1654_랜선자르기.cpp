#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long N, K, a;
vector<long long> lan_have;
long long high, low, mid;
long long result = 0; // 가능한 최대 랜선 길이

bool is_success(long long target) { // target길이로 랜선을 통일시킬 수 있는가
	long long cnt = 0;
	for (long long i = 0; i < K; i++) {
		long long t = (lan_have[i] / target);
		cnt += t;
		if (t == 0 || cnt >= N) break;
	}
	if (cnt >= N) return true;
	return false;
}

void binary_search() {
	low = 1;
	high = pow(2, 31) - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (is_success(mid) == true) {
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
}

// 오름차순 함수
bool func(long long a, long long b) {
	if (a >= b) return true;
	else return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> K >> N;
	for (long long i = 0; i < K; i++) {
		cin >> a;
		lan_have.push_back(a);
	}

	// sort
	sort(lan_have.begin(), lan_have.end(), func);

	binary_search();
	cout << result << '\n';

	return 0;
}