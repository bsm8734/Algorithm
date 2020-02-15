#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	char *arr = new char[num];
	cin >> arr;

	int sum = 0;
	for (int i = 0; i < num; i++)
		sum += ((int)arr[i] - 48);
	cout << sum << "\n";


	return 0;
}