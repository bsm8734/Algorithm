#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack <int>s;

	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;

		if (num == 0) s.pop();
		else {
			s.push(num);
		}
	}

	int result = 0;
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result;
	

	return 0;
}
