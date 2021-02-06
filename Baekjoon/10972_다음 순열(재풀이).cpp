#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, a;
vector<int> v;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        v.push_back(a);
    }
        
    bool tf = next_permutation(v.begin(), v.end());
    
    if (tf == true)
        for (auto i : v)
            cout << i << ' ';
    else cout << -1;


    return 0;
}