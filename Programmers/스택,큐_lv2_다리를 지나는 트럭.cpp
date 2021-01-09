#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weight) {
    int answer = 0;
    int ind = 0; 
    int n = truck_weight.size();
    int end_n = 0;
    queue<int> q;

    int cur_weight = 0;
    int target = truck_weight[ind];
    for (int i = 0; i < bridge_length; i++) q.push(0);

    while (end_n < n) {
        int f = q.front();
        cur_weight -= f;
        q.pop();

        if (cur_weight + target <= weight) { // ���� ������ ����
            cur_weight += target;
            q.push(target);

            // target ����
            ind++;
            if (ind < n) target = truck_weight[ind];
            else target = weight+1; // ��� Ʈ���� �ٸ��� ���������ְų� �������ٸ�, ���ߺ��� ū ���� �־ ū else ������ �����ϵ����Ѵ�.
        }
        else q.push(0);

        if (f != 0 && f != (weight + 1)) end_n++;
        
        answer++;
    }

    return answer;
}

int main() {
    int n, a, len, wei;
    cin >> n >> len >> wei;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    cout << solution(len, wei, v) << endl;

    return 0;
}