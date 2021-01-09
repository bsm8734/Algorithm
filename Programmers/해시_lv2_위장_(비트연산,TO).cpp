#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    int t = 0;
    /*
    // no val
        if (m.find(i[1]) == m.end()) {
            m.insert({ i[1], 1 });
            t++;
        } // val
        else {
            m.find(i[1])->second += 1;
        }*/

    vector<pair<string, string>> v;
    for (auto i : clothes) {
        v.push_back({ i[1], i[0] });
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    int n_ = v.size();
    vector<int> vv;
    vv.push_back(1);
    for (int i = 0; i < n_ - 1; i++)
        if ((v[i].first).compare(v[i + 1].first)) vv.push_back(1);
        else vv[vv.size() - 1] ++;
    t = vv.size();

    int n = t;
    for (int i = 1; i < (1 << (n)); i++) {
        int k = 1;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) {
                k *= vv[j];
            }
        answer += k;
    }


    return answer;
}

/*
 vector<int> vv;
    for (auto M : m) {
        vv.push_back(M.second);
        answer += M.second;
    }

    vector<int> tmp;

    for (int i = 0; i < t - 2; i++)¤±
        tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(1);
    int n = tmp.size();

    for (int T = 0; T < t - 1; T++) {
        sort(tmp.begin(), tmp.end());
        do {
            int k = 1;
            for (int i = 0; i < n; i++)
                if (tmp[i] == 1) k *= vv[i];
            answer += k;
        } while (next_permutation(tmp.begin(), tmp.end()));
        tmp[0] = 1;
    }
*/
int main() {
    vector<vector<string>> a;
    a = { {"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } };
    cout << solution(a) << endl;

    return 0;
}


/*

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

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
    vector<int> vv;
    for (auto M : m) vv.push_back(M.second);

    int n = t;
    for (int i = 1; i < (1 << (n)); i++) {
        int k = 1;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) {
                k *= vv[j];
            }
        answer += k;
    }


    return answer;
}

/*
 vector<int> vv;
    for (auto M : m) {
        vv.push_back(M.second);
        answer += M.second;
    }

    vector<int> tmp;

    for (int i = 0; i < t - 2; i++)
        tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(1);
    int n = tmp.size();

    for (int T = 0; T < t - 1; T++) {
        sort(tmp.begin(), tmp.end());
        do {
            int k = 1;
            for (int i = 0; i < n; i++)
                if (tmp[i] == 1) k *= vv[i];
            answer += k;
        } while (next_permutation(tmp.begin(), tmp.end()));
        tmp[0] = 1;
    }
// /
int main() {
    vector<vector<string>> a;
    a = { {"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } };
    cout << solution(a) << endl;

    return 0;
}

*/