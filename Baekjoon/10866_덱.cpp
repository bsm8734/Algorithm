#include <iostream>
#include <deque>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	deque <int>dq;

	int N;
	cin >> N;
	while (N--) {
		int x;
		string str;
		cin >> str;
		if (str == "push_front") {
			cin >> x;
			dq.push_front(x);
		} else if (str == "push_back") {
			cin >> x;
			dq.push_back(x);
		} else if (str == "pop_front") {
			if (dq.empty()) cout << "-1" << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		} else if (str == "pop_back") {
			if (dq.empty()) cout << "-1" << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		} else if (str == "size") {
			cout << dq.size() << "\n";
		} else if (str == "empty") {
			if (dq.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		} else if (str == "front") {
			if (dq.empty()) cout << "-1" << "\n";
			else cout << dq.front() << "\n";
		} else if (str == "back") {
			if (dq.empty()) cout << "-1" << "\n";
			else cout << dq.back() << "\n";
		}
		
	}

	return 0;
}