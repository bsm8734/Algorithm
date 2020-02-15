#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char a[4];
	char b[4];
	int check = 1;

	cin >> a >> b;

	for (int i = 2; i >= 0; i--) {
		if (a[i] < b[i]) {
			check = 2; break;
		}
		else if (a[i] > b[i]) {
			check = 1; break;
		}
	}
	if (check == 1) cout << a[2] << a[1] << a[0];
	else cout << b[2] << b[1] << b[0]; 

	return 0;
}