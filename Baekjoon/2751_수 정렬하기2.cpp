#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, n;
	vector<int> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n'; // endl 사용시 시간초과

	return 0;
}