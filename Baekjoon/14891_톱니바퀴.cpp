#include <iostream>
#include <string.h>
#include <math.h> // $$$$$ if not, pow error in gcc compiler $$$$$
using namespace std;

// variables
int K, result = 0;
int	N, dir;
char arr[4][8] = { {'0', }, };
int top_point[4] = { 0 };
int change[4] = { 0 };

void left_side(int N, int dir) {
	if (N - 1 >= 0) {
		int tmp_N = (top_point[N] + 6) % 8;
		int tmp_M = (top_point[N - 1] + 2) % 8;
		if (arr[N][tmp_N] != arr[N - 1][tmp_M]) {
			change[N - 1] = (dir * -1);
			left_side(N - 1, dir * -1);
		}
		else return;
	}
	return;
}

void right_side(int N, int dir) {
	if (N + 1 < 4) {
		int tmp_N = (top_point[N] + 2) % 8;
		int tmp_M = (top_point[N + 1] + 6) % 8;
		if (arr[N][tmp_N] != arr[N + 1][tmp_M]) {
			change[N + 1] = (dir * -1);
			right_side(N + 1, dir * -1);
		}
		else return;
	}
	return;
}

void bi_side(int N, int dir) {
	// change my wheel
	change[N] = dir;

	// look for left wheel
	left_side(N, dir);

	// look for right wheel
	right_side(N, dir);
	
	// calculate all
	for (int i = 0; i < 4; i++) {
		top_point[i] += (8 + change[i]);
		top_point[i] %= 8;
		change[i] = 0;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	cin >> K;

	// process
	while (K--) {
		cin >> N >> dir;
		N--; // : start of arr = 0
		dir = dir * -1; // : reverse, clock cycle dir <-> arr seq

		bi_side(N, dir);
	}

	// output
	for (int i = 0; i < 4; i++) 
		if (arr[i][top_point[i]] == '1') result += pow(2, i);
		
	cout << result << '\n';

	return 0;
}