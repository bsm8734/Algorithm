#include <iostream>
#include <string>
using namespace std;

int map[4][4];
bool res_map[10000000];
int res_num = 0;

void recursive_func(string str, int i, int j) {
	str += to_string(map[i][j]);

	// if the length is full, turn on the bit of res_map
	if (str.length() == 7) {
		int on = atoi(str.c_str());
		if (res_map[on] == false) {
			res_num++;
			// cout << on << endl;
		}
		res_map[on] = true;
	}
	else {
		if (i == 0 && j == 0) {
			recursive_func(str, i, j + 1);
			recursive_func(str, i + 1, j);
		}
		else if (i == 0 && j != 0) {
			if (j != 3) {
				recursive_func(str, i, j + 1);
				recursive_func(str, i, j - 1);
				recursive_func(str, i + 1, j);
			}
			else if (j == 3) {
				recursive_func(str, i, j - 1);
				recursive_func(str, i + 1, j);
			}
		}
		else if (i != 0 && j == 0) {
			if (i != 3) {
				recursive_func(str, i, j + 1);
				recursive_func(str, i + 1, j);
				recursive_func(str, i - 1, j);
			}
			else if (i == 3) {
				recursive_func(str, i, j + 1);
				recursive_func(str, i - 1, j);
			}
		}
		else if (i != 0 && j != 0) {
			if (i != 3 && j != 3) {
				recursive_func(str, i, j + 1);
				recursive_func(str, i, j - 1);
				recursive_func(str, i + 1, j);
				recursive_func(str, i - 1, j);
			}
			else if (i != 3 && j == 3) {
				recursive_func(str, i, j - 1);
				recursive_func(str, i + 1, j);
				recursive_func(str, i - 1, j);
			}
			else if (i == 3 && j != 3) {
				recursive_func(str, i, j + 1);
				recursive_func(str, i, j - 1);
				recursive_func(str, i - 1, j);
			}
			else if (i == 3 && j == 3) {
				recursive_func(str, i, j - 1);
				recursive_func(str, i - 1, j);
			}

			
		}
		else cout << "exception !" << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// init res_map, res_num
		for (int i = 0; i < 10000000; i++) res_map[i] = false;
		res_num = 0;

		// input map (initialization map)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> map[i][j];

		// call recursive function
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				recursive_func("", i, j);

		// print result
		cout << "#" << t << " " << res_num << endl;
			
	}
	return 0;
}