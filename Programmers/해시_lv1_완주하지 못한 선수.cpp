#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int val = 0;

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    bool tf = false;
    for (int i = 0; i < completion.size(); i++)
        if (completion[i].compare(participant[i])) {
            tf = true;
            answer = participant[i];
            break;
        }
    if (tf == false) answer = participant[participant.size() - 1];

    return answer;
}

int main() {
    vector<string> a, b;
    a.push_back("leo");
    a.push_back("kiki");
    a.push_back("eden");

    b.push_back("eden");
    b.push_back("kiki");

    cout << solution(a, b) << endl;

    return 0;
}
