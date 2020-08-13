#include <iostream>
#include <string.h>
using namespace std;

int n;
int DP[2000] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	DP[0] = 0;
	DP[2] = 3;

	if (n % 2 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	
	for (int i = 4; i <= n; i+=2) {
		for (int j = 4; j < i; j += 2)
			DP[i] += DP[j - 2] * 2;
		DP[i] += 2;
		DP[i] += DP[i - 2] * 3;
		//cout << i << ':' << DP[i] << endl;
	}
	

	cout << DP[n] << '\n';

	return 0;
}