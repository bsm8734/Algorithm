#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 사실은 string으로 안풀어도 되는 문제
// long long 형(long long int)가 (2^8)^8 = 8바이트 = 64비트 = 2^64라서 그냥 sort하면 됨


bool comp(string s1, string s2) {
	if (s1[0] == '-' && s2[0] == '-') // 음수 // >
		if (s1.size() == s2.size()) return s1 > s2; // 숫자개수같으면, 앞에서부터 비교해서 클수록 작음
		else return s1.size() > s2.size(); // 숫자 많을수록 작음
	else if (s1[0] != '-' && s2[0] != '-') { // <
		if (s1.size() == s2.size()) return s1 < s2; 
		else return s1.size() < s2.size();
	}
	else
		if (s1[0] == '-') return true;
		else return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	vector<string> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), comp);

	int cur_n = 0, max_n = 0;
	string cur_s, max_s;

	max_n = 0;
	max_s = v[0];
	cur_s = "";
	cur_n = 0;
	for (auto i : v) {
		if (cur_s == "") cur_s = i;
		 //cout << i << ' ';
		if (i == cur_s) cur_n++;
		else {
			if (max_n < cur_n) {
				max_s = cur_s;
				max_n = cur_n;
			}
			cur_n = 1;
			cur_s = i;
		}
		// cout << max_n << ' ' << max_s << endl;
		// cout << cur_s << ' ' <<cur_n << endl;
	}
	if (max_n < cur_n) max_s = cur_s;

	cout << max_s << '\n';

	return 0;
}