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
		cin >> num >> target; // num: 문서의 개수 // target: 타깃 문서

		int *arr = new int[num];	// 크기 비교를 위해 first에 들어가는 값을 모두 저장
		pair<int, bool> p;			// 임시의 pair를 만들어주기위한 변수

		int tmp; /// 입력받기위한 변수
		for (int i = 0; i < num; i++) {
			// 원하는 대상이라면		pair<num, true>
			// 원하는 대상이 아니라면	pair<num, false>
			cin >> tmp;
			p.first = tmp;
			if (i == target) p.second = true;
			else p.second = false;
			q.push(p);

			// 모든 first값들을 저장
			arr[i] = tmp;
		}
		sort(arr, arr+(num), desc); // 값의 비교를 위해서 저장한 arr을 내림차순으로 정리
		
		int result = 1;
		int j = 0;
		while (1) {
			if (q.front().first == arr[j]) { // 만약 큐의 front가 큐 값들 중의 최대 값이라면
				if (q.front().second == true) { // 그리고 그 값이 타깃이라면 --> 출력 후, 탈출
					cout << result << "\n";
					break;
				}
				else { // 그리고 그 값이 타깃이 아니라면
					result++; j++;
					q.pop();
				}
			}
			else { // 만약 큐의 front가 현재 큐 값들 중에서 최대가 아니라면 뒤에 넣기
				q.push(q.front());
				q.pop();
			}
		}

		queue_clear();
	}
	return 0;
}
