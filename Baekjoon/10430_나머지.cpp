#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << '\n' << ((a % c) + (b % c)) % c << '\n'
		<< (a * b) % c << '\n' << ((a % c) * (b % c)) % c << '\n';

	return 0;
}