#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    int t = 0;
    map<string, int> m;
    for (auto i : clothes) {
        // no val
        if (m.find(i[1]) == m.end()) {
            m.insert({ i[1], 1 });
            t++;
        } // val
        else {
            m.find(i[1])->second += 1;
        }
    }

    for (auto M : m)
        answer *= (M.second + 1);

    return answer - 1;
}

int main() {
    vector<vector<string>> a;
    a = { {"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } };
    cout << solution(a) << endl;

    return 0;
}
