#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack <char>s;

	int T;
	cin >> T;
	
	while (T--) {
		bool correct = true;
		string ps;
		cin >> ps;

		for (int i = 0; i < ps.length(); i++) {
			if (ps[i] == '(') s.push('(');
			else {
				if (s.empty() || s.top() != '(') {
					correct = false;
					break;
				}
				else s.pop();
			}
		}
		

		while (!s.empty()) {
			correct = false;
			s.pop();
		}

		if (correct == true) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}