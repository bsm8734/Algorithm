#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// ��� ���ڿ��� ã���� �ٷ� �ٲپ� �ִ� ���� �ƴ϶�
// special _word��� ������ ���� ������ �����ְ�
// ���߿� ��ü ���� ���̿��� ���ش�.
// ���� key : c-dz=d- �� dz=dz=


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string dict[7] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
	string input;
	cin >> input;

	int special_word = 0;
	int result = input.length();

	input += "aaa";
	size_t pos1 = input.find("dz=");
	
	while (pos1 != string::npos) {
		input.replace(pos1, 2, "||"); // �ƹ��� ������ ���� ���ڸ� �־���
		// �Ʒ�ó�� �ϸ� �յ� �ܾ �����鼭 ���ο� special word ����
		// input.erase(pos1, pos1 + 2); 
		special_word += 2;
		pos1 = input.find("dz=");
	}

	for (int i = 0; i < 7; i++) {
		size_t pos = input.find(dict[i]);
		while (pos != string::npos) {
			special_word++;
			pos = input.find(dict[i], pos + 1);
		}
	}

	cout << result - special_word;

	return 0;
}