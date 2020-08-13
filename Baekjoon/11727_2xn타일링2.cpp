#include <iostream>
#include <string.h>
using namespace std;

int n;
int DP[2000] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	DP[1] = 1;
	DP[2] = 3;

	for (int i = 3; i <= n; i++)
		DP[i] = (DP[i - 1] + (DP[i - 2] * 2)) % 10007;
	cout << DP[n] << '\n';

	return 0;
}