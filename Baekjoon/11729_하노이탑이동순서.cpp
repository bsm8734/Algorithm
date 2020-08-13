#include <iostream>
#include <string.h>
using namespace std;

int N;
int rest[6] = { 0,0,0,3,2,1 }; // 혹은 6 - (start + end) -> 경유지인 곳 알 수 있음

// set(N-1) start -> 경유지
// plate(N) start -> end
// set(N-1) 경유지 -> end


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

	// 시행횟수
	int ret = 0;
	for (int i = 0; i < N; i++)
		ret = ret * 2 + 1;
	cout << ret << '\n';

	// 원판움직이기
	set(N, 1, 3);

	return 0;
}