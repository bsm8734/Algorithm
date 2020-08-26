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

        // 변경후
        for (int i = 0; i < arr[cur].size(); i++) {
            int con_island = arr[cur][i].first;
            int con_weight = arr[cur][i].second;

            if (visit[con_island] == true) continue; // 이미 방문한 섬이거나
            if (con_weight < target) continue; // 중량제한에 맞지 않는 경우 continue;
            q.push(con_island);
            visit[con_island] = true;
        }

        // 변경전 -> 시간초과
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
이분탐색으로 중량을 탐색하는 시간을 크게 줄임
두 섬 사이에 다리가 여러개 있을 수 있음. 그러나 다리의 중량제한을 가장 큰 수로 업데이트 하지 않아도됌. 그냥 뒤에 전부 push_back해도 풀림

# 메모리초과의 이유: int 이차원 배열을 사용했기 때문에 메모리가 400으로 초과됨
정점의제곱 >> 정점*간선수 이므로 배열보다는 연결리스트가 더 적절

# 시간초과의 이유: 나에게 연결된 정점을 찾기 위해서 벡터 배열에 달린 본인을 전부 탐색
따라서 한 정점에 달린 다른 정점을 보기위해 -> 매번 정점*간선만큼의 시간을 소요
*/