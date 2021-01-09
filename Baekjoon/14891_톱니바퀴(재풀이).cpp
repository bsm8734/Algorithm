#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string arr[4];
int starts[4];
int T;
int target, k;
int result = 0;

char get_left(int n) {
	int a = (starts[n] + 6) % 8;
	return arr[n][a];
}
char get_right(int n) {
	int a = (starts[n] + 2) % 8;
	return arr[n][a];
}
void turn_cw(int n) { // clockwise
	starts[n] = ((starts[n] - 1) + 8) % 8;
}
void turn_ccw(int n) { // counterclockwise
	starts[n] = (starts[n] + 1) % 8;
}

// 까다로웠던 부분 // sp 조건 없으면 무한루프
void rec(int n, int wise, int sp) {
	if (0 < n && sp <= 0) // check left
		if (get_left(n) != get_right(n - 1))
			rec(n - 1, wise * -1, -1); // recursive call

	if(n < 3 && sp >= 0) // check right
		if (get_right(n) != get_left(n + 1))
			rec(n + 1, wise * -1, 1); // recursive call
	
	// turn
	starts[n] = (starts[n] - wise + 8) % 8;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++) cin >> arr[i];

	cin >> T;
	while (T--) {
		cin >> target >> k;
		target--;
		rec(target, k, 0);
	}

	for (int i = 0; i < 4; i++) {
		if (arr[i][starts[i]] == '1')
			result += (pow(2, i));
	}

	cout << result;


	return 0;
}