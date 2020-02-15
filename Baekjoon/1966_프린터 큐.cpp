#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue < pair<int, bool>>q;


bool desc(int a, int b) {
	return a > b;
}

void queue_clear() {
	while (!q.empty())
		q.pop();
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;
	while (TC--) {
	
		int num, target;
		cin >> num >> target; // num: ������ ���� // target: Ÿ�� ����

		int *arr = new int[num];	// ũ�� �񱳸� ���� first�� ���� ���� ��� ����
		pair<int, bool> p;			// �ӽ��� pair�� ������ֱ����� ����

		int tmp; /// �Է¹ޱ����� ����
		for (int i = 0; i < num; i++) {
			// ���ϴ� ����̶��		pair<num, true>
			// ���ϴ� ����� �ƴ϶��	pair<num, false>
			cin >> tmp;
			p.first = tmp;
			if (i == target) p.second = true;
			else p.second = false;
			q.push(p);

			// ��� first������ ����
			arr[i] = tmp;
		}
		sort(arr, arr+(num), desc); // ���� �񱳸� ���ؼ� ������ arr�� ������������ ����
		
		int result = 1;
		int j = 0;
		while (1) {
			if (q.front().first == arr[j]) { // ���� ť�� front�� ť ���� ���� �ִ� ���̶��
				if (q.front().second == true) { // �׸��� �� ���� Ÿ���̶�� --> ��� ��, Ż��
					cout << result << "\n";
					break;
				}
				else { // �׸��� �� ���� Ÿ���� �ƴ϶��
					result++; j++;
					q.pop();
				}
			}
			else { // ���� ť�� front�� ���� ť ���� �߿��� �ִ밡 �ƴ϶�� �ڿ� �ֱ�
				q.push(q.front());
				q.pop();
			}
		}

		queue_clear();
	}
	return 0;
}
