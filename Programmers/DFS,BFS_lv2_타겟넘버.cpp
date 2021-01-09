#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    int n = numbers.size();
    for (int i = 1; i < (1 << (n)); i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) { // 1
                tmp += numbers[j];
            }
            else { // 0
                tmp -= numbers[j];
            }
        if (tmp == target) answer++;
    }

    return answer;
}

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    cout << solution(a, 3) << endl;

    return 0;
}