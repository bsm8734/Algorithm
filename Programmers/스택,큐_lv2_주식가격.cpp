#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int j = 0;
        for (j = i + 1; j < n; j++) {
            if (prices[i] <= prices[j]) cnt++;
            else {
                answer.push_back(cnt + 1);
                break;
            }
        }
        if (j == n) answer.push_back(cnt);
    }

    return answer;
}
