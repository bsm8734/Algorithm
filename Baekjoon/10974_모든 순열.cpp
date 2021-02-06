#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    do {
        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}