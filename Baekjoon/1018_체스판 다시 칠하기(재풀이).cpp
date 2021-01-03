#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// variable
	int N, M;
	char c;
	bool arr[60][60] = {false, }; // B:true, W:false
	bool check_arr[8][8][2] = { false, };

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == 'B') arr[i][j] = true;
		}

	// make {bwbw, wbwb ...} array[8][8]
	bool tf = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (j % 2 == 1) { // 홀수
				check_arr[i][j][0] = tf;
				check_arr[i][j][1] = !(tf);
			}
			else {
				check_arr[i][j][0] = !(tf);
				check_arr[i][j][1] = tf;
			}
		}
		tf = (!tf);
	}
	
	// count minimum
	int min_ = 64;
	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M-8; j++) {

			if (min_ == 0) break;
			int tmp_0 = 0;
			int tmp_1 = 0;

			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {

					if (arr[i + a][j + b] != check_arr[a][b][0]) tmp_0++;
					if (arr[i + a][j + b] != check_arr[a][b][1]) tmp_1++;

					if (tmp_0 > min_) tmp_0 = 10000;		// problem1
					if (tmp_1 > min_) tmp_1 = 10000;		// problem1

					if ((tmp_0 + tmp_1) == 20000) break;	// problem1
				}
				if ((tmp_0 + tmp_1) == 20000) break;		// problem1
			}
			// if ((tmp_0 + tmp_1) == 20000) break;			//  problem1 --> 오류 원인

			min_ = min(min_, min(tmp_0, tmp_1));
		}
	}

	cout << min_;


	return 0;
}