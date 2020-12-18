#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, pair<int, string>> ppp;

bool compare(ppp v1, ppp v2) {
	if (v1.first.first != v2.first.first) return v1.first.first > v2.first.first;
	else if (v1.first.second != v2.first.second) return v1.first.second < v2.first.second;
	else if (v1.second.first != v2.second.first) return v1.second.first > v2.second.first;
	else return v1.second.second < v2.second.second;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, b, c;
	string name;
	vector<ppp> vppp;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> a >> b >> c;
		vppp.push_back({ {a, b}, {c, name} });
	}
	sort(vppp.begin(), vppp.end(), compare);

	for (auto i : vppp) cout << i.second.second << '\n';


	return 0;
}