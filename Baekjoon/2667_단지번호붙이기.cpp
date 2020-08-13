#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
char arr[26][26];
bool visit[26][26] = { false };
int xy[4][2] = { {1,0},{0,1},{0,-1},{-1,0} };
queue<pair<int, int>> q;
vector<int> num;


int BFS(int x, int y) {
    int num = 1;
    q.push({ x, y });
    visit[x][y] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x_ = cur.first + xy[i][0];
            int y_ = cur.second + xy[i][1];

            if(x_ >= 0 && y_ >= 0 && x_ < N && y_ <N)
                if (visit[x_][y_] == false && arr[x_][y_] == '1') {
                    q.push({ x_, y_ });
                    visit[x_][y_] = true;
                    num++;
                }
            
        }
    }

    return num;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '1' && visit[i][j] == false) num.push_back(BFS(i, j));
        }
    }
    
    cout << num.size() << "\n";
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)cout << num[i] << endl;

    return 0;
 }