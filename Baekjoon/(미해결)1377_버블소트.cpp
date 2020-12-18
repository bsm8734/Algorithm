#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/* 버블정렬의 스왑 횟수 세기 */

// swap을 종료시킬지 판단
bool match_all(int n, vector<int> &a, vector<int> &b) {
    for (int i = 0; i < n; i++) 
        if (a[i] != b[i]) return false;
    return true; // swap 끝
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    // variable
	int n, t, answer = 1;
    vector<int> res, v;
    stack<int> st;

    // input
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
        res.push_back(t);
    }

    // --  vector copy -- //
    // res.resize(v.size());
    //copy(v.begin(), v.end(), res.begin());

    sort(res.begin(), res.end()); // O(nlogn) quick sort
    for (auto i : res) st.push(i);

    while (!match_all(n, v, res)) {
        int target = st.top();
        for(int i = 0; i < n; i++)
    }

    // 주어진 코드
    bool change = false;
    for (int i = 0; i < n + 1; i++) {
        change = false;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                change = true;
                swap(a[j], a[j + 1]);
            }
        }
        if (change == false) {
            cout << i+1 << '\n';
            break;
        }
    }


	return 0;
}