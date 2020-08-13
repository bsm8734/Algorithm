#include <iostream>
#include <string.h>
using namespace std;

int N, len, result = 0;
int arr[300][300] = { 0 };
bool slope[300][300] = { false };

bool slope_made(int i) {
	int success = true;

	for (int j = 0; j < N - 1; j++) {
		if (success == false) break;				// failed
		if (arr[i][j] == arr[i][j + 1]) continue;	// flat, pass
		else if (arr[i][j] == arr[i][j + 1] + 1) {	// [j] > [j+1]
			//int lev = arr[i][j + 1];
			for (int k = 0; k < len; k++) {
				if (j + 1 + k < N && arr[i][j + 1 + k] == arr[i][j + 1] && slope[i][j + 1 + k] == false) {
					slope[i][j + 1 + k] = true;
				}
				else {
					success = false;
					break;
				}
			}
		}
		else if (arr[i][j] + 1 == arr[i][j + 1]) {	// [j] < [j+1]
			for (int k = 0; k < len; k++) {
				if (j - k >= 0 && arr[i][j] == arr[i][j - k] && slope[i][j - k] == false) {
					slope[i][j - k] = true;
				}
				else {
					success = false;
					break;
				}
			}
		}
		else success = false; // slope impossible
	}

	return success;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N >> len;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	// one direction
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[N + i][j] = arr[j][i];

	// tf process
	for (int i = 0; i < 2* N; i++) 
		if(slope_made(i)) result++;

	// output
	cout << result << '\n';


	return 0;
}