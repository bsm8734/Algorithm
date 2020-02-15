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
			// push�� ������ �ϴ� ��Ȳ
			if (str[i] == '(') s.push('(');
			else if (str[i] == '[') s.push('[');
			// empty Ȯ�� + ��ȣ �� Ȯ�� -> pop�ϴ� ��Ȳ
			else if (str[i] == ')') {
				if (s.empty()) {
					success = false;
					break;
				}
				// �߿�::::stack�� ���������, top�� �˻��ϴ� �͸����ε� �����߻�
				// �׷��� ���� empty�� ����ó���� �̸� ���־����
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