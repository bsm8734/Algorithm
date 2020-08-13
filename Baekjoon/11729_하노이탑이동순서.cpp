#include <iostream>
#include <string.h>
using namespace std;

int N;
int rest[6] = { 0,0,0,3,2,1 }; // Ȥ�� 6 - (start + end) -> �������� �� �� �� ����

// set(N-1) start -> ������
// plate(N) start -> end
// set(N-1) ������ -> end


void plate(int start, int end) {
	cout << start << ' ' << end << '\n';
}

void set(int depth, int start, int end) {
	if (depth == 1) {
		plate(start, end);
		return;
	}
	int tmp = rest[start + end];
	set(depth - 1, start, tmp);
	plate(start, end);
	set(depth - 1, tmp, end);
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	// ����Ƚ��
	int ret = 0;
	for (int i = 0; i < N; i++)
		ret = ret * 2 + 1;
	cout << ret << '\n';

	// ���ǿ����̱�
	set(N, 1, 3);

	return 0;
}