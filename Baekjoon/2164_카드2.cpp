#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue <int>q;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) q.push(i);
	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();

	return 0;
}