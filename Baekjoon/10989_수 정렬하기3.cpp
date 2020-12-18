#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, n;
	int arr[10001] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		arr[n]++;
	}
	for (int i = 0; i < 10001; i++)
		for (int j = 0; j < arr[i]; j++)
			cout << i << '\n';

	return 0;
}