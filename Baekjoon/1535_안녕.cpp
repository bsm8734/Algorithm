#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int result = 0;
int L[21] = {0,}; // 잃는 체력
int J[21] = {0,}; // 얻는 기쁨
vector<pair<int, int >> v;

void DFS(int cur, int cur_l, int cur_j) {
    for (int i = cur; i < N; i++){
        if (cur_l - v[i].first <= 0) return;

        result = max(result, cur_j + v[i].second);
        DFS(i + 1, cur_l - v[i].first, cur_j + v[i].second);
    }
}

bool comp(pair<int, int> i, pair<int, int> j) { 
    if(i.first < j.first) return true;
    else if (i.first == j.first) return i.second > j.second;
    else return false;
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // input
    cin >> N;
    for(int i = 0; i < N; i++) cin >> L[i];
    for(int i = 0; i < N; i++) {
        cin >> J[i];
        v.push_back({L[i], J[i]});
    }

    // sort // important - INEO(if not, error occurs)
    sort(v.begin(), v.end(), comp);

    //rec func
    DFS(0, 100, 0);
    
    cout << result << '\n';

    return 0;
}