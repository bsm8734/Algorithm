#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(string s1, string s2) {
    if (s1 + s2 > s2 + s1) return 1;
    else return 0;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> p;
    int n_size = numbers.size();

    for (auto i : numbers) p.push_back(to_string(i));

    sort(p.begin(), p.end(), comp);

    for (auto i: p) answer += i;
        
    return answer;
}

int main() {
    vector<int> a;
    a.push_back(2133);
    a.push_back(2);
    a.push_back(22);
    a.push_back(20);
    a.push_back(0);
    cout << solution(a) << endl;

    return 0;
}