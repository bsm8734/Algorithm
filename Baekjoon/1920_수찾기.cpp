#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int to_find[100001] = { 0 };
int N, T;
int low, high, mid;
int target;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N; int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	cin >> T;
	for (int i = 0; i < T; i++)
		cin >> to_find[i];
	
	for (int i = 0; i < T; i++) {
		low = 0; high = N - 1;
		target = to_find[i];

		int result = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (arr[mid] < target)
				low = mid + 1;
			else if (target < arr[mid])
				high = mid - 1;
			else {
				result = mid;
				break;
			}
		}
		if (result == -1) cout << 0 << '\n';
		else cout << 1 << '\n';
	}

	return 0;
}