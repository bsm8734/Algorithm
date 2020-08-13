#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// variable
int N, M, H;
int a, b;
int map[50][50] = { 0 };
int depth = 4;

// check right pair made
bool checker() {
	for (int i = 0; i < M; i++) {
		int ind = i;
		for (int j = 0; j < N; j++)
			ind = ind + map[j][ind];
		if (ind != i) return false;
	}
	return true;
}

// ��������� ã�ư�����, 3��° �׾����� �ٷ� 3�� �����ϸ� Ʋ��
// 1 > 2 > 3(ã��!) > 2(ã��!) > 1 �����϶�, ����� 2�̾����

// make all case (0~3)
void func(int t) { // t�� ���� �߰��� �ٸ��� ���� ��ȣ

	if (t == 4) return;

	for (int i = 0; i < (M - 1) * N; i++) { // i: �߰��ϰ����ϴ� ��ٸ� ��ȣ(1����)
		//  �ٸ��� ���� �� �ִ��� Ȯ��
		int x = i / (M - 1);
		int y = i % (M - 1);
		if (map[x][y] == 1 || map[x][y] == -1 || map[x][y + 1] == 1) continue;

		// �ٸ��� ����
		map[x][y] = 1;
		map[x][y + 1] = -1;

		// üũ�� ��
		if (checker() == true) {
			depth = t;
			map[x][y] = map[x][y + 1] = 0;
			return;
		}

		// +1 �� ���̿��� ã�� ���߾��ٸ�, �� ���� ����
		if(t + 1 < depth) func(t + 1);

		// �ٸ��� ����
		map[x][y] = map[x][y + 1] = 0;
	}

	return;
}

// main
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input & init
	cin >> M >> H >> N;
	for (int i = 0; i < H; i++) {
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = -1;
	}

	// check with no additional bridge
	if (checker() == true) {
		cout << '0' << '\n';
		return 0;
	}

	func(1);
	if (depth != 4) cout << depth << '\n';
	else cout << -1 << '\n';

	return 0;
}