#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, a;
vector<int> v1, v2;
int high, low, mid;

int binary_search(int target) {
	low = 0;
	high = N-1;
	while (low <= high) {
		mid = (high + low) / 2;
		if (target < v1[mid])
			high = mid - 1;
		else if (v1[mid] < target)
			low = mid + 1;
		else return 1;
	}
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v1.push_back(a);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a;
		v2.push_back(a);
	}
	
	// sort
	sort(v1.begin(), v1.end());

	// search
	for (int i = 0; i < M; i++)
		cout << binary_search(v2[i]) << ' ';

	return 0;
}