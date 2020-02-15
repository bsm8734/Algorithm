#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 메모리 3684KB, 시간 16ms --> 줄이기
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	stack <int>target, tmp;
	stack <int>pocket;
	stack <int>s;

	int j;
	bool success = true;
	int num;
	string result = "";
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> j;
		tmp.push(j);
		pocket.push((num - i));
	}
	
	for (int i = 0; i < num; i++)
	{
		target.push(tmp.top());
		tmp.pop();
	}

	while (!pocket.empty()) {
		s.push(pocket.top()); pocket.pop(); result+="+\n";
		while (1){
			if (s.empty()) break;
			else if (target.top() == s.top()) {
				s.pop(); target.pop();
				result += "-\n";
			}
			else break;
		}
	}

	if (!s.empty() || !target.empty()) success = false;

	if (success == false) cout << "NO";
	else cout << result;

	return 0;
}