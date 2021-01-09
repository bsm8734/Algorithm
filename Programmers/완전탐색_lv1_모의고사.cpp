#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int s = answers.size();
    int num[3][10] = { {1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };
    int num_size[3] = { 5, 8, 10 };
    vector<pair<int, int>> score = { {0, 1}, {0, 2}, {0, 3} };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < s; j++) {
            if (answers[j] == num[i][(j % num_size[i])]) score[i].first++;
        }
    }

    sort(score.begin(), score.end());
    answer.push_back(score[2].second);
    for (int i = 2; i >= 1; i--)
        if (score[i].first == score[i - 1].first) {
            answer.push_back(score[i - 1].second);
        }
        else break;
    sort(answer.begin(), answer.end());

    return answer;
}