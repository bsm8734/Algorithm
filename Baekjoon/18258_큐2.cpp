#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue <int>q;
	string str;
	int num;

	int N;
	cin >> N;
	while (N--) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (q.empty()) cout << "-1" << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "front") {
			if (q.empty()) cout << "-1" << "\n";
			else cout << q.front() << "\n";
		}
		else if (str == "back") {
			if (q.empty()) cout << "-1" << "\n";
			else cout << q.back() << "\n";
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (q.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
	}

	return 0;
}
