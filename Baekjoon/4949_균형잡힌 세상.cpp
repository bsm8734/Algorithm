#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack <char>s;
	string str;
	while (1) {
		bool success = true;
		getline(cin, str, '.');
		cin.clear();

		if (str[0] == '\n' && str.length() == 1) break;

		for (int i = 0; i < str.length(); i++) {
			// push를 언제나 하는 상황
			if (str[i] == '(') s.push('(');
			else if (str[i] == '[') s.push('[');
			// empty 확인 + 괄호 쌍 확인 -> pop하는 상황
			else if (str[i] == ')') {
				if (s.empty()) {
					success = false;
					break;
				}
				// 중요::::stack이 비어있을때, top을 검사하는 것만으로도 에러발생
				// 그래서 위의 empty로 예외처리를 미리 해주어야함
				else if (s.top() == '(') s.pop(); 
				else{
					success = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (s.empty()) {
					success = false;
					break;
				}
				else if (s.top() == '[') s.pop();
				else {
					success = false;
					break;
				}
			}
		}

		while (!s.empty()) {
			success = false;
			s.pop();
		}

		if (success == true) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

	return 0;
}