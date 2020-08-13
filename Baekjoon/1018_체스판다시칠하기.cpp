#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// var
	int N, M;
	int turn1 = 0;
	int turn2 = 1;
	string map[51];
	string ans_str[2] = { "BWBWBWBW", "WBWBWBWB" };

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	// count
	int result = 64;
	for (int i = 0; i <= N-8; i++)
		for (int j = 0; j <= M-8; j++) { // left-top initialize
			int tmp1 = 0;
			int tmp2 = 0;

			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if (ans_str[turn1][b] != map[i + a][j + b]) tmp1++;
					if (ans_str[turn2][b] != map[i + a][j + b]) tmp2++;
				}

				turn1 = abs(turn1 - 1);
				turn2 = abs(turn2 - 1);
			}


			result = min(tmp1, result);
			result = min(tmp2, result);
		}
	
	cout << result << endl;
}