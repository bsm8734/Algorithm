#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M, a, b, c;
int low, high, mid, result = 0;
vector<pair<int, int>> arr[10001];
bool visit[10001] = { false };
queue<int> q;
int start_v, end_v;
int tmp = 0;

void init() {
    for (int i = 0; i < N; i++) visit[i] = false;
    while (!q.empty()) q.pop();
}

/* 
int find_weight(int src, int dst) {
    for (int i = 0; i < arr[src].size(); i++)
        if (arr[src][i].first == dst) {
            tmp = i;
            return arr[src][i].second;
        }
    return -1; // fail
}*/

bool BFS(int target) {
    init();
    q.push(start_v);
    visit[start_v] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == end_v) return true;

        // ������
        for (int i = 0; i < arr[cur].size(); i++) {
            int con_island = arr[cur][i].first;
            int con_weight = arr[cur][i].second;

            if (visit[con_island] == true) continue; // �̹� �湮�� ���̰ų�
            if (con_weight < target) continue; // �߷����ѿ� ���� �ʴ� ��� continue;
            q.push(con_island);
            visit[con_island] = true;
        }

        // ������ -> �ð��ʰ�
        /* for (int i = 0; i < N; i++) {
            int w = find_weight(cur, i);
            if (w == -1 || visit[i] == true) continue;
            if (w < target) continue;
            q.push(i);
            visit[i] = true;
        }
        */
        
    }
    return false;
}

void binary_search() {
    low = 1;
    high = pow(2, 30);
    while (low <= high) {
        mid = (low + high) / 2;
        if (BFS(mid)) {
            result = max(result, mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // init
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--; b--;
        arr[a].push_back({ b, c });
        arr[b].push_back({ a, c });
    }
    cin >> start_v >> end_v;
    start_v--;
    end_v--;

    // find proper weight
    binary_search();
    cout << result << '\n';

    return 0;
}

/*
�̺�Ž������ �߷��� Ž���ϴ� �ð��� ũ�� ����
�� �� ���̿� �ٸ��� ������ ���� �� ����. �׷��� �ٸ��� �߷������� ���� ū ���� ������Ʈ ���� �ʾƵ���. �׳� �ڿ� ���� push_back�ص� Ǯ��

# �޸��ʰ��� ����: int ������ �迭�� ����߱� ������ �޸𸮰� 400���� �ʰ���
���������� >> ����*������ �̹Ƿ� �迭���ٴ� ���Ḯ��Ʈ�� �� ����

# �ð��ʰ��� ����: ������ ����� ������ ã�� ���ؼ� ���� �迭�� �޸� ������ ���� Ž��
���� �� ������ �޸� �ٸ� ������ �������� -> �Ź� ����*������ŭ�� �ð��� �ҿ�
*/