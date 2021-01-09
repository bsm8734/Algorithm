#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int N, L, res = 0;
int arr[101][101] = { 0, };
bool visit[101] = { false, };
vector<int> v;
stack<int> st;
int cnt, target, size_;

void init() {
	for (int i = 0; i < N; i++) visit[i] = false;
	cnt = 0;
	size_ = v.size();
}

bool checker() {
	init();
	
	target = v[0];
	for (int i = 1; i < size_; i++) {
		if (target == v[i]) continue;					// same height
		else if (abs(target - v[i]) > 1) return false;	// height difference > 1

		// front > back
		else if (target > v[i]) {	
			for (int j = 0; j < L; j++) {
				if (i + j >= N) return false;			// out of range
				if (v[i + j] != v[i]) return false;		// insufficient length
				else visit[i + j] = true;				// correct case
			}
		}

		// front < back
		else if (target < v[i]) {	
			for (int j = 1; j <= L; j++) {
				if (i - j < 0) return false;			// out of range
				if (v[i - j] != target) return false;	// insufficient length
				if (visit[i - j] == true) return false; // already visit
				else visit[i - j] = true;				// correct case
			}
		}
		target = v[i];
	}

	return true;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> arr[i][j];

	// left right
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v.push_back(arr[i][j]);
		}
		if (checker()) res++;
		v.clear();
	}
		
	// top down
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			v.push_back(arr[i][j]);
		}
		if (checker()) res++;
		v.clear();
	}

	cout << res;

	return 0;
}